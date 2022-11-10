#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <array>
#include <mysql.h>
#include <trimmean.h>

// typedef struct st_udf_args
// {
//   unsigned int arg_count;        /* Number of arguments */
//   enum Item_result *arg_type;    /* Pointer to item_results */
//   char **args;                   /* Pointer to argument */
//   unsigned long *lengths;        /* Length of string arguments */
//   char *maybe_null;              /* Set to 1 for all maybe_null args */
// } UDF_ARGS;

//   /* This holds information about the result */

// typedef struct st_udf_init
// {
//   my_bool maybe_null;        /* 1 if function can return NULL */
//   unsigned int decimals;     /* for real functions */
//   unsigned int max_length;   /* For string functions */
//   char *ptr;                 /* free pointer for function data */
//   my_bool const_item;        /* 0 if result is independent of arguments */
// } UDF_INIT;

namespace
{
    const UDF_INIT udf_init {
        1,
        0,
        0,
        nullptr,
        1
    };

    std::array<Item_result, 2> arg_type{};
    std::array<double *, 2> arg_ptrs{};

    UDF_ARGS udf_args {
        2,
        arg_type.data(),
        reinterpret_cast<char **>(arg_ptrs.data()),
        nullptr,
        nullptr
    };

    std::array<double, 10> values { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    std::array<char, 1024> messages{};

    double test_trimmean_normal(int n, char *is_null, char *is_error)
    {
        auto i { udf_init };
        auto a { udf_args };

        trimmean_init(&i, &a, messages.data());

        for (auto &v : values) {
            arg_ptrs[0] = &v;
            trimmean_add(&i, &a, nullptr, nullptr);
        }

        double p{ n / 100.0 };
        arg_ptrs[1] = &p;
        const auto mean{ trimmean(&i, &a, is_null, is_error) };

        trimmean_deinit(&i);

        return mean;
    }

    double test_trimmean_empty(int n, char *is_null, char *is_error)
    {
        auto i { udf_init };
        auto a { udf_args };

        trimmean_init(&i, &a, messages.data());

        double p{ n / 100.0 };
        arg_ptrs[1] = &p;
        const auto mean{ trimmean(&i, &a, is_null, is_error) };

        trimmean_deinit(&i);

        return mean;
    }

}

BOOST_AUTO_TEST_CASE(trimmean_normal_10)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(10, &is_null, &is_error)};

    BOOST_CHECK(mean == 102.3);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_10)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(10, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_20)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(20, &is_null, &is_error)};

    BOOST_CHECK(mean == 63.75);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_20)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(20, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_30)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(30, &is_null, &is_error)};

    BOOST_CHECK(mean == 63.75);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_30)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(30, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_40)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(40, &is_null, &is_error)};

    BOOST_CHECK(mean == 42);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_40)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(40, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_50)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(50, &is_null, &is_error)};

    BOOST_CHECK(mean == 42);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_50)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(50, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_60)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(60, &is_null, &is_error)};

    BOOST_CHECK(mean == 30);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_60)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(60, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_70)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(70, &is_null, &is_error)};

    BOOST_CHECK(mean == 30);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_70)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(70, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_80)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(80, &is_null, &is_error)};

    BOOST_CHECK(mean == 24);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_80)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(80, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_normal_90)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_normal(90, &is_null, &is_error)};

    BOOST_CHECK(mean == 24);
    BOOST_CHECK(is_null  == 0);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_empty_90)
{
    char is_null;
    char is_error;
    const auto mean{::test_trimmean_empty(90, &is_null, &is_error)};

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 0);
}

BOOST_AUTO_TEST_CASE(trimmean_proportion_too_small)
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_init(&i, &a, messages.data());

    for (auto &v : values) {
        arg_ptrs[0] = &v;
        trimmean_add(&i, &a, nullptr, nullptr);
    }

    double p{ -0.1 };
    arg_ptrs[1] = &p;
    char is_null;
    char is_error;
    const auto mean{ trimmean(&i, &a, &is_null, &is_error) };

    trimmean_deinit(&i);

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 1);
}

BOOST_AUTO_TEST_CASE(trimmean_proportion_too_large)
{
    auto i { udf_init };
    auto a { udf_args };

    trimmean_init(&i, &a, messages.data());

    for (auto &v : values) {
        arg_ptrs[0] = &v;
        trimmean_add(&i, &a, nullptr, nullptr);
    }

    double p{ 1.1 };
    arg_ptrs[1] = &p;
    char is_null;
    char is_error;
    const auto mean{ trimmean(&i, &a, &is_null, &is_error) };

    trimmean_deinit(&i);

    BOOST_CHECK(mean == 0.0);
    BOOST_CHECK(is_null  == 1);
    BOOST_CHECK(is_error == 1);
}
