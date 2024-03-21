#!/bin/bash

cd lib
 
# Build wxWidgets
cd wxWidgets
mkdir -p buildurx # Unicode, Release, Static
cd buildurx
cmake -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=../../install \
    -DwxBUILD_SHARED=OFF \
    -DwxBUILD_USE_STATIC_RUNTIME=ON \
    -DwxBUILD_UNICODE=ON \
    -DwxBUILD_SAMPLES=OFF \
    -DwxBUILD_TESTS=OFF \
    ..
make -j 4
cd ../..

# # Build podofo
# cd podofo
# mkdir -p build
# cd build
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../../install ..
# make -j 4
# cd ../..

# # Build spdlog
# cd spdlog
# mkdir -p build
# cd build
# cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=../../install ..
# make -j 4

