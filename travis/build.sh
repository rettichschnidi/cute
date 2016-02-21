#!/usr/bin/env bash

#Exit on first error
set -e

#Configure, build and test
mkdir -p build
cd build
cmake ../ -DCUTE_ENABLE_COVERALLS=ON -DCMAKE_BUILD_TYPE=Debug \
 -DCUTE_BUILD_TESTS=ON -DCUTE_ENABLE_GCOV=ON
make VERBOSE=1
make test coveralls
