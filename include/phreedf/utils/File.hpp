#include "../Core.hpp"

namespace phdf
{
    /**
     * @brief Get the Standard Log Folder object
     *
     * Get the standard log folder for the application
     * based on the operating system.
     *
     * @note This function is only implemented for MacOS currently.
     * @return std::string
     */
    std::string GetStandardLogFolder();
}