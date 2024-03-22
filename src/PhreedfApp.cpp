#include <phreedf/PhreedfApp.h>

std::string GetStandardLogFolder()
{
    // Get the HOME environment variable
    const char *homeDir = getenv("HOME");
    if (homeDir == nullptr)
    {
        std::cerr << "Error: HOME environment variable not found." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Construct the path to the standard log folder
    std::string logsDir = std::string(homeDir) + "/Library/Logs/";
    std::string appName = "PhreeDF/"; // Replace with your application name

    return logsDir + appName;
}

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
    MainFrame *frame = new MainFrame(wxT("Phreedf - The Free PDF Editor"));
    // Show it
    frame->Show(true);
    // Start the event loop
    return true;
}

IMPLEMENT_APP(PhreedfApp)