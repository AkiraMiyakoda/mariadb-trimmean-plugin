// Copyright (c) 2021 Akira Miyakoda
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>

#include "trimmean.h"

namespace
{
    ////////////////////////////////////////////////////////////////////////////
    // Internal implementation
    ////////////////////////////////////////////////////////////////////////////

    struct TRIMMEAN_CONTEXT
    {
        std::vector<double> values_ {};
    };

    void set_context_(UDF_INIT *initid, TRIMMEAN_CONTEXT *context)
    {
        initid->ptr = static_cast<char *>(static_cast<void *>(context));
    }

    TRIMMEAN_CONTEXT *get_context_(UDF_INIT *initid)
    {
        return static_cast<TRIMMEAN_CONTEXT *>(static_cast<void *>(initid->ptr));
    }

    template <int percent>
    bool trimmean_init_(UDF_INIT *initid, UDF_ARGS *args, char *message)
    {
        static_assert(0 < percent && percent < 100);

        if (args->arg_count != 1) {
            std::snprintf(message, 64, "TRIMMEAN_%02d() requires just one argument.", percent);
            return true;
        }

        if ((args->arg_type[0] != INT_RESULT) && (args->arg_type[0] != REAL_RESULT)) {
            std::snprintf(message, 64, "TRIMMEAN_%02d() requires REAL or INT argument.", percent);
            return true;
        }

        const auto context { new (std::nothrow) TRIMMEAN_CONTEXT() };
        if (!context) {
            std::snprintf(message, 64, "TRIMMEAN_%02d() failed to allocate memory.", percent);
            return true;
        }

        set_context_(initid, context);
        return false;
    }

    void trimmean_deinit_(UDF_INIT *initid)
    {
        delete get_context_(initid);
    }

    void trimmean_clear_(UDF_INIT *initid, unsigned char *, unsigned char *)
    {
        *get_context_(initid) = TRIMMEAN_CONTEXT();
    }

    void trimmean_add_(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
    {
        if (!args->args[0]) {
            return;
        }

        auto &values { get_context_(initid)->values_ };

        if (args->arg_type[0] == REAL_RESULT) {
            values.push_back(*static_cast<double *>(static_cast<void *>(args->args[0])));
        }
        else if (args->arg_type[0] == INT_RESULT) {
            values.push_back(*static_cast<int64_t *>(static_cast<void *>(args->args[0])));
        }
    }

    template <int percent>
    double trimmean_(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
    {
        static_assert(0 < percent && percent < 100);

        auto &values { get_context_(initid)->values_ };
        if (values.empty()) {
            *is_null = 1;
            return 0.0;
        }

        const auto trim { static_cast<size_t>(values.size() * (percent / 100.0)) / 2 };
        if (trim > 0) {
            std::sort(values.begin(), values.end());
        }

        const auto sum { std::accumulate(values.cbegin() + trim, values.cend() - trim, 0.0) };

        *is_null = 0;
        return sum / (values.size() - trim * 2);
    }
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_10
////////////////////////////////////////////////////////////////////////////////

bool trimmean_10_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<10>(initid, args, message);
}

void trimmean_10_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_10_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_10_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_10(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<10>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_20
////////////////////////////////////////////////////////////////////////////////

bool trimmean_20_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<20>(initid, args, message);
}

void trimmean_20_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_20_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_20_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_20(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<20>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_30
////////////////////////////////////////////////////////////////////////////////

bool trimmean_30_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<30>(initid, args, message);
}

void trimmean_30_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_30_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_30_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_30(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<30>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_40
////////////////////////////////////////////////////////////////////////////////

bool trimmean_40_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<40>(initid, args, message);
}

void trimmean_40_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_40_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_40_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_40(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<40>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_50
////////////////////////////////////////////////////////////////////////////////

bool trimmean_50_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<50>(initid, args, message);
}

void trimmean_50_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_50_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_50_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_50(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<50>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_60
////////////////////////////////////////////////////////////////////////////////

bool trimmean_60_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<60>(initid, args, message);
}

void trimmean_60_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_60_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_60_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_60(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<60>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_70
////////////////////////////////////////////////////////////////////////////////

bool trimmean_70_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<70>(initid, args, message);
}

void trimmean_70_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_70_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_70_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_70(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<70>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_80
////////////////////////////////////////////////////////////////////////////////

bool trimmean_80_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<80>(initid, args, message);
}

void trimmean_80_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_80_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_80_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_80(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<80>(initid, nullptr, is_null, nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// TRIMMEAN_90
////////////////////////////////////////////////////////////////////////////////

bool trimmean_90_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return trimmean_init_<90>(initid, args, message);
}

void trimmean_90_deinit(UDF_INIT *initid)
{
    trimmean_deinit_(initid);
}

void trimmean_90_clear(UDF_INIT *initid, unsigned char *, unsigned char *)
{
    trimmean_clear_(initid, nullptr, nullptr);
}

void trimmean_90_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *)
{
    trimmean_add_(initid, args, nullptr, nullptr);
}

double trimmean_90(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *)
{
    return trimmean_<90>(initid, nullptr, is_null, nullptr);
}
