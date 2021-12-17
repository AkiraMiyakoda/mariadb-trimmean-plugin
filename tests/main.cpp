#include <array>

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <trimmean.h>

// typedef struct st_udf_args
// {
//   unsigned int arg_count;		/* Number of arguments */
//   enum Item_result *arg_type;		/* Pointer to item_results */
//   char **args;				/* Pointer to argument */
//   unsigned long *lengths;		/* Length of string arguments */
//   char *maybe_null;			/* Set to 1 for all maybe_null args */
// } UDF_ARGS;

//   /* This holds information about the result */

// typedef struct st_udf_init
// {
//   my_bool maybe_null;			/* 1 if function can return NULL */
//   unsigned int decimals;		/* for real functions */
//   unsigned int max_length;		/* For string functions */
//   char	  *ptr;				/* free pointer for function data */
//   my_bool const_item;			/* 0 if result is independent of arguments */
// } UDF_INIT;

namespace
{
    const UDF_INIT udf_init {
        true,
        0,
        0,
        nullptr,
        1
    };

    std::array<Item_result, 1> arg_type { REAL_RESULT };
    std::array<double, 10> values { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    std::array<double *, 1> value_ptrs {};

    UDF_ARGS udf_args {
        1,
        arg_type.data(),
        reinterpret_cast<char **>(value_ptrs.data()),
        nullptr,
        nullptr
    };

    std::array<char, 1024> messages {};
}

TEST_CASE("TRIMEAN_10")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_10_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_10_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_10(&i, nullptr, &is_null, nullptr) == Approx(102.3));
    REQUIRE(is_null == 0);

    trimmean_10_deinit(&i);
}

TEST_CASE("TRIMEAN_10 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_10_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_10(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_10_deinit(&i);
}

TEST_CASE("TRIMEAN_20")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_20_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_20_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_20(&i, nullptr, &is_null, nullptr) == Approx(63.75));
    REQUIRE(is_null == 0);

    trimmean_20_deinit(&i);
}

TEST_CASE("TRIMEAN_20 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_20_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_20(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_20_deinit(&i);
}

TEST_CASE("TRIMEAN_30")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_30_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_30_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_30(&i, nullptr, &is_null, nullptr) == Approx(63.75));
    REQUIRE(is_null == 0);

    trimmean_30_deinit(&i);
}

TEST_CASE("TRIMEAN_30 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_30_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_30(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_30_deinit(&i);
}

TEST_CASE("TRIMEAN_40")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_40_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_40_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_40(&i, nullptr, &is_null, nullptr) == Approx(42));
    REQUIRE(is_null == 0);

    trimmean_40_deinit(&i);
}

TEST_CASE("TRIMEAN_40 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_40_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_40(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_40_deinit(&i);
}

TEST_CASE("TRIMEAN_50")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_50_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_50_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_50(&i, nullptr, &is_null, nullptr) == Approx(42));
    REQUIRE(is_null == 0);

    trimmean_50_deinit(&i);
}

TEST_CASE("TRIMEAN_50 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_50_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_50(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_50_deinit(&i);
}

TEST_CASE("TRIMEAN_60")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_60_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_60_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_60(&i, nullptr, &is_null, nullptr) == Approx(30));
    REQUIRE(is_null == 0);

    trimmean_60_deinit(&i);
}

TEST_CASE("TRIMEAN_60 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_60_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_60(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_60_deinit(&i);
}

TEST_CASE("TRIMEAN_70")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_70_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_70_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_70(&i, nullptr, &is_null, nullptr) == Approx(30));
    REQUIRE(is_null == 0);

    trimmean_70_deinit(&i);
}

TEST_CASE("TRIMEAN_70 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_70_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_70(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_70_deinit(&i);
}

TEST_CASE("TRIMEAN_80")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_80_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_80_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_80(&i, nullptr, &is_null, nullptr) == Approx(24));
    REQUIRE(is_null == 0);

    trimmean_80_deinit(&i);
}

TEST_CASE("TRIMEAN_80 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_80_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_80(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_80_deinit(&i);
}

TEST_CASE("TRIMEAN_90")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_90_init(&i, &a, messages.data());

    for (auto &v : values) {
        value_ptrs[0] = &v;
        trimmean_90_add(&i, &a, nullptr, nullptr);
    }

    unsigned char is_null = 0;
    REQUIRE(trimmean_90(&i, nullptr, &is_null, nullptr) == Approx(24));
    REQUIRE(is_null == 0);

    trimmean_90_deinit(&i);
}

TEST_CASE("TRIMEAN_90 empty")
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_90_init(&i, &a, messages.data());

    unsigned char is_null = 0;
    REQUIRE(trimmean_90(&i, nullptr, &is_null, nullptr) == Approx(0));
    REQUIRE(is_null);

    trimmean_90_deinit(&i);
}

