#pragma once

#include "Core.h"
#include "MainFrame.h"
#include <spdlog/sinks/basic_file_sink.h>
#include <cstdlib>

// Declare the application class
class MyApp : public wxApp
{
public:
    // Called on application startup
    virtual bool OnInit();
};

// Implements MyApp& wxGetApp()
DECLARE_APP(MyApp)