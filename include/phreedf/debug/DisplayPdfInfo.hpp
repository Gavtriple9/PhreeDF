#pragma once

#include "../Core.hpp"
#include <phreedf/utils/ToString.hpp>
#include <phreedf/utils/File.hpp>

// #define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/one-page.pdf"
#define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/one-page-w-image.pdf"
// #define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/example1.pdf"
// #define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/example2.pdf"
// #define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/example3.pdf"
// #define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/example4.pdf"
// #define DEBUG_PDF_FILE_PATH "/Users/gavin/Documents/Github/personal/PhreeDF/pdfs/example5.pdf"

namespace phdf
{
    /**
     * @brief Displays debug information about a PDF file.
     *
     * This function displays debug information about a PDF file. It is used for
     * debugging purposes.
     */
    void DisplayDebugPDFInfo();
}