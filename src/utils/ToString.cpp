#include <phreedf/utils/ToString.hpp>

namespace phdf
{
    std::string PdfPermissionsToString(PoDoFo::PdfPermissions permission)
    {
        switch (permission)
        {
        case PoDoFo::PdfPermissions::None:
            return "None";
        case PoDoFo::PdfPermissions::Print:
            return "Print";
        case PoDoFo::PdfPermissions::Edit:
            return "Edit";
        case PoDoFo::PdfPermissions::Copy:
            return "Copy";
        case PoDoFo::PdfPermissions::EditNotes:
            return "EditNotes";
        case PoDoFo::PdfPermissions::FillAndSign:
            return "FillAndSign";
        case PoDoFo::PdfPermissions::Accessible:
            return "Accessible";
        case PoDoFo::PdfPermissions::DocAssembly:
            return "DocAssembly";
        case PoDoFo::PdfPermissions::HighPrint:
            return "HighPrint";
        case PoDoFo::PdfPermissions::Default:
            return "Default";
        default:
            return "Unknown";
        }
    }

    std::string PdfPageModeToString(PoDoFo::PdfPageMode mode)
    {
        switch (mode)
        {
        case PoDoFo::PdfPageMode::DontCare:
            return "DontCare";
        case PoDoFo::PdfPageMode::UseNone:
            return "UseNone";
        case PoDoFo::PdfPageMode::UseThumbs:
            return "UseThumbs";
        case PoDoFo::PdfPageMode::UseBookmarks:
            return "UseBookmarks";
        case PoDoFo::PdfPageMode::FullScreen:
            return "FullScreen";
        case PoDoFo::PdfPageMode::UseOC:
            return "UseOC";
        case PoDoFo::PdfPageMode::UseAttachments:
            return "UseAttachments";
        default:
            return "Unknown";
        }
    }

    std::string PdfEncryptAlgorithmToString(PoDoFo::PdfEncryptAlgorithm algorithm)
    {
        switch (algorithm)
        {
        case PoDoFo::PdfEncryptAlgorithm::None:
            return "None";
        case PoDoFo::PdfEncryptAlgorithm::RC4V1:
            return "RC4 Version 1";
        case PoDoFo::PdfEncryptAlgorithm::RC4V2:
            return "RC4 Version 2";
        case PoDoFo::PdfEncryptAlgorithm::AESV2:
            return "AES Version 2";
        case PoDoFo::PdfEncryptAlgorithm::AESV3:
            return "AES Version 3";
        case PoDoFo::PdfEncryptAlgorithm::AESV3R6:
            return "AES Version 3 Revision 6";
        default:
            return "Unknown";
        }
    }

    std::string PdfVersionToString(PoDoFo::PdfVersion version)
    {
        switch (version)
        {
        case PoDoFo::PdfVersion::V1_0:
            return "1.0";
        case PoDoFo::PdfVersion::V1_1:
            return "1.1";
        case PoDoFo::PdfVersion::V1_2:
            return "1.2";
        case PoDoFo::PdfVersion::V1_3:
            return "1.3";
        case PoDoFo::PdfVersion::V1_4:
            return "1.4";
        case PoDoFo::PdfVersion::V1_5:
            return "1.5";
        case PoDoFo::PdfVersion::V1_6:
            return "1.6";
        case PoDoFo::PdfVersion::V1_7:
            return "1.7";
        case PoDoFo::PdfVersion::V2_0:
            return "2.0";
        default:
            return "Unknown";
        }
    }
}