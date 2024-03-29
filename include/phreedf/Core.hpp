#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

#include <wx/wx.h>
#include <spdlog/spdlog.h>
#include <podofo/podofo.h>

// If on Windows, define the PHREEDF_API macro
// clang-format off
#ifdef _WIN32
    #ifdef PHREEDF_EXPORTS
        #define PHREEDF_API __declspec(dllexport)
    #else
        #define PHREEDF_API __declspec(dllimport)
    #endif
#else
    #define PHREEDF_API
#endif
// clang-format on

#define phdfVERSION_STRING "PhreeDF 0.1.0"