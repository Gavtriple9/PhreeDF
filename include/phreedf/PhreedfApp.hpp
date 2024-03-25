#pragma once

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

#include "Core.hpp"
#include "MainFrame.hpp"
#include "utils/File.hpp"
#include "debug/DisplayPdfInfo.hpp"

namespace phdf
{
    /**
     * @brief The application class
     *
     * This class is the main application class. It is responsible for creating the
     * main frame of the application and starting the event loop.
     */
    class PHREEDF_API PhreedfApp final : public wxApp
    {
    public:
        /**
         * @brief Initializes the application.
         *
         * This function initializes the application. It creates the main frame of the
         * application and shows it.
         */
        virtual bool OnInit();
    };
}

// This macro tells wxWidgets to create an instance of the application class
DECLARE_APP(phdf::PhreedfApp)