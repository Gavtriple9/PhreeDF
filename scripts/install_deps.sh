#!/bin/bash

cd lib
 
# Build wxWidgets
mkdir -p wx_build_urx
cd wx_build_urx
  # --prefix=$(pwd)/../installurx \
../wxWidgets/configure \
  --disable-tests \
  --enable-debug \
  --disable-shared \
  --enable-macosx_arch=arm64 \
  --with-macosx-version-min=11.0
make -j $(nproc)
make install
cd ..

# # Build podofo
mkdir -p podofo_build
cd podofo_build
cmake \
  -DPODOFO_BUILD_STATIC=TRUE \
  -DCMAKE_BUILD_TYPE=Debug \
  ../podofo 
make -j $(nproc)
make install
cd ..

# # Build spdlog
mkdir -p spdlog_build
cd spdlog_build
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  ../spdlog
make -j $(nproc)
make install
cd ..

