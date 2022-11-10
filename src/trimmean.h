// Copyright (c) 2021 Akira Miyakoda
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#ifndef MARIADB_TRIMMEAN_61448DDB_77AB_4ACE_9E65_15850736E4DD
#define MARIADB_TRIMMEAN_61448DDB_77AB_4ACE_9E65_15850736E4DD

typedef struct st_udf_args UDF_ARGS;
typedef struct st_udf_init UDF_INIT;

extern "C" {

bool trimmean_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
void trimmean_deinit(UDF_INIT *initid);
void trimmean_clear(UDF_INIT *initid, char *is_null, char *is_error);
void trimmean_add(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *is_error);
double trimmean(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *is_error);

}

#endif // MARIADB_TRIMMEAN_61448DDB_77AB_4ACE_9E65_15850736E4DD
