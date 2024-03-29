#include <phreedf/SplitWindow.hpp>

namespace phdf
{
    SplitWindow::SplitWindow(MainFrame *parent)
        : wxSplitterWindow(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_LIVE_UPDATE)
    {
        // Create the left and right panels
        m_leftWindow = new wxScrolledWindow(this, wxID_ANY);
        m_rightWindow = new wxScrolledWindow(this, wxID_ANY);

        // m_leftWindow->SetScrollbars(20, 20, 50, 50);
        m_rightWindow->SetScrollbars(20, 20, 50, 50);
        // m_rightWindow->Show(false);

        m_leftWindow->SetMinSize(wxSize(200, 200));
        m_leftWindow->SetVirtualSize(200, 200);
        m_leftWindow->SetScrollRate(1, 1);

        SetMinimumPaneSize(2);

        m_leftWindow->Show(true);
        m_rightWindow->Show(true);

        Initialize(m_leftWindow);
        Initialize(m_rightWindow);

        // Create a button to print the current page
        auto button = new wxButton(m_leftWindow, wxID_ANY, wxT("Print Page"));
        button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonOK, parent);

        // Create a menu bar
        wxMenu *viewMenu = new wxMenu;
        viewMenu->Append(1, wxT("Split &Vertical\tCtrl-V"),
                         wxT("Split the window vertically"));
        viewMenu->Append(1, wxT("Split &Horizontal\tCtrl-H"),
                         wxT("Split the window horizontally"));
        viewMenu->Append(1, wxT("&Unsplit\tCtrl-U"),
                         wxT("Unsplit the window"));

        wxMenuBar *menuBar = new wxMenuBar();
        menuBar->Append(viewMenu, wxT("&View"));
        parent->SetMenuBar(menuBar);
    }

    void SplitWindow::OnSplitVertical()
    {
        if (IsSplit())
            Unsplit();
        m_leftWindow->Show(true);
        m_rightWindow->Show(true);
        SplitVertically(m_leftWindow, m_rightWindow);
    }
    void SplitWindow::OnSplitHorizontal()
    {
        if (IsSplit())
            Unsplit();
        m_leftWindow->Show(true);
        m_rightWindow->Show(true);
        SplitHorizontally(m_leftWindow, m_rightWindow);
    }
    void SplitWindow::OnUnsplit()
    {
        if (IsSplit())
            Unsplit();
    }

} // namespace phdf
