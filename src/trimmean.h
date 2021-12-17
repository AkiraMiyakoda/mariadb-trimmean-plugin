// Copyright (c) 2021 Akira Miyakoda
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef E669F52B_B72E_432B_8E57_893024881735
#define E669F52B_B72E_432B_8E57_893024881735

#include <mysql.h>

extern "C" {
    bool trimmean_10_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_10_deinit(UDF_INIT *initid);
    void trimmean_10_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_10_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_10(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_20_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_20_deinit(UDF_INIT *initid);
    void trimmean_20_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_20_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_20(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_30_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_30_deinit(UDF_INIT *initid);
    void trimmean_30_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_30_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_30(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_40_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_40_deinit(UDF_INIT *initid);
    void trimmean_40_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_40_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_40(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_50_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_50_deinit(UDF_INIT *initid);
    void trimmean_50_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_50_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_50(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_60_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_60_deinit(UDF_INIT *initid);
    void trimmean_60_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_60_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_60(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_70_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_70_deinit(UDF_INIT *initid);
    void trimmean_70_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_70_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_70(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_80_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_80_deinit(UDF_INIT *initid);
    void trimmean_80_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_80_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_80(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);

    bool trimmean_90_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
    void trimmean_90_deinit(UDF_INIT *initid);
    void trimmean_90_clear(UDF_INIT *initid, unsigned char *, unsigned char *);
    void trimmean_90_add(UDF_INIT *initid, UDF_ARGS *args, unsigned char *, unsigned char *);
    double trimmean_90(UDF_INIT *initid, UDF_ARGS *, unsigned char *is_null, unsigned char *);
}

#endif /* E669F52B_B72E_432B_8E57_893024881735 */
