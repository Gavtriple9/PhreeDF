#include <phreedf/debug/DisplayPdfInfo.hpp>

namespace phdf
{
    void DisplayDebugPDFInfo()
    {
        PoDoFo::PdfMemDocument pdf;
        pdf.Load(DEBUG_PDF_FILE_PATH);

        auto catalog = pdf.GetCatalog();
        auto encrypt = pdf.GetEncrypt();
        // auto meta = pdf.GetMetadata();
        auto names = pdf.GetNames();
        // auto objects = pdf.GetObjects();
        auto pages = pdf.GetPages();
        auto outlines = pdf.GetOutlines();
        auto exts = pdf.GetPdfExtensions();
        auto trailer = pdf.GetTrailer();

        // ---------- Info Section -----------
        const PoDoFo::PdfInfo *info = pdf.GetInfo();
        if (info)
        {
            auto title = info->GetTitle();
            auto author = info->GetAuthor();
            auto subject = info->GetSubject();
            auto keywords = info->GetKeywords();
            auto creator = info->GetCreator();
            auto producer = info->GetProducer();
            auto creation_date = info->GetCreationDate();
            auto mod_date = info->GetModDate();

            spdlog::info("Title: {}", title.has_value() ? title.value().GetString() : "N/A");
            spdlog::info("Author: {}", author.has_value() ? author.value().GetString() : "N/A");
            spdlog::info("Subject: {}", subject.has_value() ? subject.value().GetString() : "N/A");
            spdlog::info("Keywords: {}", keywords.has_value() ? keywords.value().GetString() : "N/A");
            spdlog::info("Creator: {}", creator.has_value() ? creator.value().GetString() : "N/A");
            spdlog::info("Producer: {}", producer.has_value() ? producer.value().GetString() : "N/A");
            spdlog::info("Creation Date: {}", creation_date.has_value() ? creation_date.value().ToString() : "N/A");
            spdlog::info("Mod Date: {}\n\n", mod_date.has_value() ? mod_date.value().ToString() : "N/A");
        }

        // ---------- Catalog Section -----------
        spdlog::info("Catalog: {");
        spdlog::info("\t Dictionary: {}", catalog.GetDictionary().ToString());
        spdlog::info("\t LangObject: {}", catalog.GetLangObject() ? catalog.GetLangObject()->ToString() : "N/A");
        spdlog::info("\t LangString: {}", catalog.GetMarkInfoObject() ? catalog.GetMarkInfoObject()->ToString() : "N/A");
        spdlog::info("\t PageMode: {}", catalog.GetMetadataObject() ? catalog.GetMetadataObject()->ToString() : "N/A");
        spdlog::info("\t PageLayout: {}", catalog.GetMetadataStreamValue());
        spdlog::info("\t Object: \n{}EndObject", catalog.GetObject().ToString());
        spdlog::info("\t PageMode: {}", PdfPageModeToString(catalog.GetPageMode()));
        spdlog::info("\t StructTreeRootObject: {}", catalog.GetStructTreeRootObject() ? catalog.GetStructTreeRootObject()->ToString() : "N/A");
        spdlog::info("}\n\n");

        // ---------- Pages Section -----------
        spdlog::info("Pages: {");
        unsigned int pages_count = pages.GetCount();
        spdlog::info("\t Count: {}", pages_count);
        spdlog::info("\t Dictionary: {}", pages.GetDictionary().ToString());
        spdlog::info("\t Document: {}", pages.GetDocument().GetOutlines() ? pages.GetDocument().GetOutlines()->GetTitle() : "N/A");
        spdlog::info("\t Object: \n{}EndObject\n", pages.GetObject().ToString());
        for (int i = 0; i < pages_count; i++)
        {
            PoDoFo::PdfPage &page = pages.GetPageAt(i);
            spdlog::info("\t Page-{}:", i);
            spdlog::info("\t {{");
            spdlog::info("\t\t Dictionary: {}", page.GetDictionary().ToString());
            spdlog::info("\t\t Document: {}", page.GetDocument().GetOutlines() ? page.GetDocument().GetOutlines()->GetTitle() : "N/A");
            spdlog::info("\t\t Object: \n{}EndObject", page.GetObject().ToString());
            spdlog::info("\t\t PageIndex: {}", page.GetIndex());
            spdlog::info("\t }}\n");
        }
        spdlog::info("}\n\n");

        // ---------- Trailer Section -----------
        spdlog::info("Trailer: {");
        spdlog::info("\t Dictionary: {}", trailer.GetDictionary().ToString());
        spdlog::info("\t Document-Pages-Count: {}", trailer.GetDocument().GetPages().GetCount());
        spdlog::info("\t Object: \n{}EndObject", trailer.GetObject().ToString());
        spdlog::info("}\n\n");

        // ---------- Extensions Section -----------
        spdlog::info("Extensions: {");
        int i = 0;
        for (auto ext : exts)
        {
            spdlog::info("\t Extension-{}: {{", i++);
            spdlog::info("\t Version: {}", PdfVersionToString(ext.GetBaseVersion()));
            spdlog::info("\t Level: {}", ext.GetLevel());
            spdlog::info("\t Namespace: {}", ext.GetNamespace());
            spdlog::info("\t }},");
        }
        spdlog::info("}\n\n");

        // ---------- Encrypt Section -----------
        spdlog::info("Encrypt: {");
        if (encrypt)
        {
            spdlog::info("\t EnabledEncryptionAlgorithms: {}", PdfEncryptAlgorithmToString(encrypt->GetEnabledEncryptionAlgorithms()));
            spdlog::info("\t IsEncryptionNoneEnabled: {}", encrypt->IsEncryptionEnabled(PoDoFo::PdfEncryptAlgorithm::None));
            spdlog::info("\t IsEncryptionAESV2Enabled: {}", encrypt->IsEncryptionEnabled(PoDoFo::PdfEncryptAlgorithm::AESV2));
            spdlog::info("\t IsEncryptionAESV3Enabled: {}", encrypt->IsEncryptionEnabled(PoDoFo::PdfEncryptAlgorithm::AESV3));
            spdlog::info("\t IsEncryptionAESV3R6Enabled: {}", encrypt->IsEncryptionEnabled(PoDoFo::PdfEncryptAlgorithm::AESV3R6));
            spdlog::info("\t IsEncryptionRC4V1Enabled: {}", encrypt->IsEncryptionEnabled(PoDoFo::PdfEncryptAlgorithm::RC4V1));
            spdlog::info("\t IsEncryptionRC4V2Enabled: {}", encrypt->IsEncryptionEnabled(PoDoFo::PdfEncryptAlgorithm::RC4V2));

            spdlog::info("\t EncryptionAlgorithms: {}", PdfEncryptAlgorithmToString(encrypt->GetEncryptAlgorithm()));
            spdlog::info("\t EncryptionKey: {}", *encrypt->GetEncryptionKey());
            spdlog::info("\t PValue: {}", PdfPermissionsToString((*encrypt).GetPValue()));
            spdlog::info("\t KeyLength: {}", encrypt->GetKeyLength());
            spdlog::info("\t OValue: {}", *encrypt->GetOValue());
            spdlog::info("\t Revision: {}", encrypt->GetRevision());
            spdlog::info("\t UValue: {}", *encrypt->GetUValue());

            spdlog::info("\t {}", encrypt->IsAccessibilityAllowed());
            spdlog::info("\t {}", encrypt->IsCopyAllowed());
            spdlog::info("\t {}", encrypt->IsDocAssemblyAllowed());
            spdlog::info("\t {}", encrypt->IsEditAllowed());
            spdlog::info("\t {}", encrypt->IsEditNotesAllowed());
            spdlog::info("\t {}", encrypt->IsFillAndSignAllowed());
            spdlog::info("\t {}", encrypt->IsHighPrintAllowed());
            spdlog::info("\t {}", encrypt->IsMetadataEncrypted());
            spdlog::info("\t {}", encrypt->IsOwnerPasswordSet());
            spdlog::info("\t {}", encrypt->IsPrintAllowed());
        }
        spdlog::info("}\n\n");

        // ---------- Metadata Section -----------
        // spdlog::info("Metadata: {}", meta);

        // ---------- Names Section -----------
        if (names)
        {
            spdlog::info("Names: {");
            spdlog::info("\t DestsNode: \n{}EndDestNode", names->GetDestsNode() ? names->GetDestsNode()->ToString() : "N/A");
            spdlog::info("\t Dictionary: {}", names->GetDictionary().ToString());
            spdlog::info("\t Document-Outlines-Title: {}", names->GetDocument().GetOutlines() ? names->GetDocument().GetOutlines()->GetTitle() : "N/A");
            spdlog::info("\t JavaScriptNode: {}", names->GetJavaScriptNode() ? names->GetJavaScriptNode()->ToString() : "N/A");
            spdlog::info("\t Object: \n{}EndObject", names->GetObject().ToString());
            spdlog::info("}\n\n");
        }

        // ----------- Objects Section -----------
        // spdlog::info("Objects: {}", objects);

        // ---------- Outlines Section -----------
        spdlog::info("Outlines: {");
        if (outlines)
        {
            spdlog::info("\t Action-Dictionary: {}", outlines->GetAction().has_value() ? outlines->GetAction().value().GetDictionary().ToString() : "N/A");
            spdlog::info("\t Destination: {}", outlines->GetDestination().has_value() ? outlines->GetDestination().value().GetArray().GetSize() : -1);
            spdlog::info("\t TextColor: ({}, {}, {})", outlines->GetTextColor().GetRed(), outlines->GetTextColor().GetGreen(), outlines->GetTextColor().GetBlue());
        }
        spdlog::info("}");
    }
} // namespace phdf