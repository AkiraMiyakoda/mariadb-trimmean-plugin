## Trimmean plugin for MariaDB/MySQL

This is a MariaDB/MySQL plugin offers a set of aggregate functions inspired by
TRIMMEAN() of Microsoft Excel.

## Usage

**TRIMMEAN_10(expr)**

TRIMMEAN_10 is an aggregate function returns the mean of the interior of a data set. TRIMMEAN_10 calculates the mean taken by excluding 10 percent of data points from the top and bottom tails of a data set.

TRIMMEAN_10 rounds the number of excluded data points down to the nearest multiple of 2. 10 percent of 30 data points equals 3 points. For symmetry, TRIMMEAN excludes a single value from the top and bottom of the data set.

**TRIMMEAN_20()** ~ **TRIMMEAN_90()** are basically the same thing except for the excluded percentage.

## Dependencies

```
C++17 compiler
cmake
libmariadb-dev
```

## Installation

**From source**
```
mkdir build
cd build/
cmake -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```

Don't forget to run these SQL to define the functions in MariaDB/MySQL.
You can safely ignore some of them if they are not necessary.
```
CREATE AGGREGATE FUNCTION trimmean_10 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_20 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_30 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_40 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_50 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_60 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_70 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_80 RETURNS REAL SONAME 'libtrimmean_plugin.so';
CREATE AGGREGATE FUNCTION trimmean_90 RETURNS REAL SONAME 'libtrimmean_plugin.so';
```

## Example

```
CREATE TABLE test (x REAL);
INSERT INTO test (x) VALUES (1), (2), (4), (8), (16), (32), (64), (128), (256), (512);

SELECT TRIMMEAN_10(x) FROM test; <- 102.3  = 1023 / 10
SELECT TRIMMEAN_20(x) FROM test; <-  63.75 =  510 /  8
SELECT TRIMMEAN_30(x) FROM test; <-  63.75 =  510 /  8
SELECT TRIMMEAN_40(x) FROM test; <-  42    =  252 /  6
SELECT TRIMMEAN_50(x) FROM test; <-  42    =  252 /  6
SELECT TRIMMEAN_60(x) FROM test; <-  30    =  120 /  4
SELECT TRIMMEAN_70(x) FROM test; <-  30    =  120 /  4
SELECT TRIMMEAN_80(x) FROM test; <-  24    =   48 /  2
SELECT TRIMMEAN_90(x) FROM test; <-  24    =   48 /  2
```
