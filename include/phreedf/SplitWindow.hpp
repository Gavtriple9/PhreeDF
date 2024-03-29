#pragma once

#include "Core.hpp"
#include <wx/splitter.h>
#include "MainFrame.hpp"

namespace phdf
{
    class PHREEDF_API SplitWindow : public wxSplitterWindow
    {
    public:
        SplitWindow(MainFrame *parent);
        void OnSplitVertical();
        void OnSplitHorizontal();
        void OnUnsplit();

    private:
        wxScrolledWindow *m_leftWindow;
        wxScrolledWindow *m_rightWindow;
    };

} // namespace phdf