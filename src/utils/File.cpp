#include <phreedf/utils/File.hpp>

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