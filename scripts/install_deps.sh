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
  -DCMAKE_BUILD_TYPE=Debug \
  -DPODOFO_BUILD_STATIC=ON \
  -DCMAKE_FIND_FRAMEWORK=NEVER \
  -DCMAKE_PREFIX_PATH=`brew --prefix` \
  -DFontconfig_INCLUDE_DIR=`brew --prefix fontconfig`/include \
  -DOPENSSL_ROOT_DIR=`brew --prefix openssl@3` \
  ../podofo 
make -j $(nproc)
make install
cd ..

# Build spdlog
mkdir -p spdlog_build
cd spdlog_build
cmake \
  -DCMAKE_BUILD_TYPE=Debug \
  ../spdlog
make -j $(nproc)
make install
cd ..