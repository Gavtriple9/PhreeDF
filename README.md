# PhreeDF

> A free interactive PDF processor

## Project Site

[gavtriple9.github.io/PhreeDF](https://gavtriple9.github.io/PhreeDF/)

## Installation

### MacOS and Linux

1. clone phreedf using `git clone git@github.com:Gavtriple9/PhreeDF.git`
2. `cd phreedf`
3. `git submodule update --init --recursive` to clone the submodules
4. run `scripts/install_deps.sh` to install the dependencies

> [!NOTE]
> if you are met with `bash: scripts/install_deps.sh: Permission denied`
> 
> run `chmod +x scripts/install_deps.sh` to make the script executable

5. `mkdir build` and `cd build` to create the build directory
6. run `cmake .. && make -j $(nproc)`

### Windows

> [!NOTE]
> Windows is currently not supported.

## Acknowledgements

1. PDF (Portable Document Format) is a document format developed by Adobe Inc. and released to the public in 2008 by the International Organization for Standardization (ISO). There have been proprietary updates to the standard by Adobe in 2017 and 2020, but ISO 32000-2 encapsulates those changes and once again is provided to the public free of charge. This project will solely work with ISO 32000-1:2008 and ISO 32000-2 standards to avoid infringing on the copyrights owned by Adobe Inc.
