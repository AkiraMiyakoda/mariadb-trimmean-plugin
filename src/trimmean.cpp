// Copyright (c) 2021 Akira Miyakoda
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "trimmean.h"

#include <mysql.h>

#include <algorithm>
#include <cstring>
#include <numeric>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// Internal implementation

namespace {

struct TRIMMEAN_CONTEXT {
  std::vector<double> values_{};
};

template <typename T, typename U>
T *context_cast(U *p) {
  return static_cast<T *>(static_cast<void *>(p));
}

void set_context(UDF_INIT *initid, TRIMMEAN_CONTEXT *context) {
  initid->ptr = context_cast<char>(context);
}

TRIMMEAN_CONTEXT *get_context(UDF_INIT *initid) {
  return context_cast<TRIMMEAN_CONTEXT>(initid->ptr);
}
}  // namespace

////////////////////////////////////////////////////////////////////////////////
// Exported functions

bool trimmean_init(UDF_INIT *initid, UDF_ARGS *args, char *message) {
  if (args->arg_count != 2) {
    std::strcpy(message, "TRIMMEAN(): Requires 2 one arguments.");
    return true;
  }

  args->arg_type[0] = REAL_RESULT;
  args->arg_type[1] = REAL_RESULT;
  initid->maybe_null = 1;

  const auto context{new (std::nothrow) TRIMMEAN_CONTEXT()};
  if (!context) {
    std::strcpy(message, "TRIMMEAN(): Failed to allocate memory.");
    return true;
  }

  ::set_context(initid, context);
  return false;
}

void trimmean_deinit(UDF_INIT *initid) { delete ::get_context(initid); }

void trimmean_clear(UDF_INIT *initid, char *, char *) {
  auto &values{::get_context(initid)->values_};
  std::vector<double>().swap(values);
}

void trimmean_add(UDF_INIT *initid, UDF_ARGS *args, char *, char *) {
  if (args->args[0] == nullptr) {
    return;
  }

  auto &values{::get_context(initid)->values_};
  values.push_back(*::context_cast<double>(args->args[0]));
}

double trimmean(UDF_INIT *initid, UDF_ARGS *args, char *is_null,
                char *is_error) {
  if (args->args[1] == nullptr) {
    *is_null = 1;
    *is_error = 1;
    return 0.0;
  }

  const auto exclude_proportion{*::context_cast<double>(args->args[1])};
  if (exclude_proportion < 0.0 || 1.0 <= exclude_proportion) {
    *is_null = 1;
    *is_error = 1;
    return 0.0;
  }

  auto &values{::get_context(initid)->values_};
  if (values.empty()) {
    *is_null = 1;
    *is_error = 0;
    return 0.0;
  }

  const auto exclude{static_cast<size_t>(values.size() * exclude_proportion) /
                     2};
  if (exclude > 0) {
    std::sort(values.begin(), values.end());
  }

  *is_null = 0;
  *is_error = 0;
  const auto first{values.cbegin() + exclude};
  const auto last{values.cend() - exclude};
  return std::accumulate(first, last, 0.0) / std::distance(first, last);
}
