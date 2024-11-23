#!/bin/bash

./tests/build/app/app_tests -c -v
./tests/build/drivers/drivers_tests -c -v
./tests/build/utils/utils_tests -c -v
