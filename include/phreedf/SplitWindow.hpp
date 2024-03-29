#pragma once

#include "Core.hpp"
#include <wx/splitter.h>
#include "MainFrame.hpp"

namespace phdf
{
    /**
     * @brief This window is the parent for the main content and the side bar.
     *
     * This window is a wxSplitterWindow that contains two wxScrolledWindows.
     * The right window is the main content and the left window is the side bar.
     *
     * @see MainFrame
     * @see wxSplitterWindow
     */
    class PHREEDF_API SplitWindow : public wxSplitterWindow
    {
    public:
        SplitWindow(MainFrame *parent);

        /**
         * @brief Split the window vertically.
         */
        void SplitVertical();

        /**
         * @brief Minimize the side bar
         *
         * This function minimizes the side bar by setting the sash position to 0.
         * The side bar can be restored by calling SplitVertical().
         */
        void Unsplit();

    private:
        wxScrolledWindow *m_leftWindow;
        wxScrolledWindow *m_rightWindow;
    };

} // namespace phdf