#!/bin/bash

set -ex

# This is a script to build the project and run the test suite in the base
# Docker container.

# CjyxExecutionModel
mkdir -p /usr/src/CjyxExecutionModel-build && cd $_
cmake \
  -G Ninja \
  -DCMAKE_BUILD_TYPE:STRING=Release \
  -DBUILDNAME:STRING=$1 \
    /usr/src/CjyxExecutionModel
ctest -VV -D Experimental
