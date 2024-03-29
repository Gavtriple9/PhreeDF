#pragma once

#include "../Core.hpp"
#include <podofo/main/PdfMetadata.h>

namespace phdf
{
    /**
     * @brief Get the string representation of the PdfPermissions object
     *
     * @param permission The PdfPermissions object to convert to a string
     * @return std::string The string representation of the PdfPermissions object
     */
    std::string PdfPermissionsToString(PoDoFo::PdfPermissions permission);

    /**
     * @brief Get the string representation of the PdfPageMode object
     *
     * @param mode The PdfPageMode object to convert to a string
     * @return std::string The string representation of the PdfPageMode object
     */
    std::string PdfPageModeToString(PoDoFo::PdfPageMode mode);

    /**
     * @brief Get the string representation of the PdfEncryptAlgorithm object
     *
     * @param algorithm The PdfEncryptAlgorithm object to convert to a string
     * @return std::string The string representation of the PdfEncryptAlgorithm object
     */
    std::string PdfEncryptAlgorithmToString(PoDoFo::PdfEncryptAlgorithm algorithm);

    /**
     * @brief Get the string representation of the PdfVersion object
     *
     * @param version The PdfVersion object to convert to a string
     * @return std::string The string representation of the PdfVersion object
     */
    std::string PdfVersionToString(PoDoFo::PdfVersion version);
}