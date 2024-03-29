#include <phreedf/PhreedfApp.hpp>

namespace phdf
{
    bool PhreedfApp::OnInit()
    {
        // Set up file sink
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(GetStandardLogFolder() + "phreedf.log", true);
        auto logger = std::make_shared<spdlog::logger>(spdlog::logger("phreedf", {file_sink}));
        logger->flush_on(spdlog::level::trace);

        // Set the global logger to use the file sink
        spdlog::register_logger(logger);
        spdlog::set_default_logger(logger);
        spdlog::set_level(spdlog::level::debug);

        // Create the main application window
        MainFrame *frame = new MainFrame(wxT("Phreedf"));

        // Show it
        frame->Show(true);
        DisplayDebugPDFInfo();

        // Start the event loop
        return true;
    }

} // namespace phdf

IMPLEMENT_APP(phdf::PhreedfApp)
