#pragma once

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

    /**
     * @brief Save a frame as a PNG image.
     *
     * @param[in] buffer The buffer containing the frame data.
     * @param[in] format The format of the frame data.
     * @param[in] width The width of the frame.
     * @param[in] height The height of the frame.
     */
    void SaveFramePng(const char *buffer, PoDoFo::PdfPixelFormat format, int width, int height);
}