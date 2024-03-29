#include <phreedf/MainFrame.hpp>
#include <phreedf/SplitWindow.hpp>
#include "images/logo.xpm"

namespace phdf
{
    MainFrame::MainFrame(const wxString &title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 800))
    {
        // Create a menu bar
        wxMenu *fileMenu = new wxMenu;
        wxMenu *helpMenu = new wxMenu;
        helpMenu->Append(wxID_ABOUT, wxT("& About...\tF1"),
                         wxT("Show about dialog"));
        fileMenu->Append(wxID_EXIT, wxT("E & xit\tAlt-X"),
                         wxT("Quit this program"));

        wxMenuBar *menuBar = new wxMenuBar();
        menuBar->Append(fileMenu, wxT("& File"));
        menuBar->Append(helpMenu, wxT("& Help"));
        SetMenuBar(menuBar);

        CreateStatusBar(2);
        SetStatusText(wxT("Welcome to PhreeDF!"));

        // Create a Toolbar
        auto *toolBar = new wxToolBar(this, wxID_ANY,
                                      wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL | wxNO_BORDER);
        wxBitmap bmpOpen(logo_xpm);
        wxBitmap bmpSave(logo_xpm);
        toolBar->AddCheckTool(wxID_OPEN, wxT("Open"), bmpOpen);
        toolBar->AddCheckTool(wxID_SAVE, wxT("Save"), bmpSave);
        toolBar->AddSeparator();
        toolBar->Realize();

        SetToolBar(toolBar);

        // Create a child window
        auto splitWindow = new SplitWindow(this);
        splitWindow->Show(true);

        splitWindow->OnSplitVertical();

        // Add child window to sizer
        auto sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(splitWindow, 1, wxEXPAND);
        SetSizer(sizer);
        Layout();
    }

    void MainFrame::OnAbout(wxCommandEvent &event)
    {
        wxString msg;
        msg.Printf(wxT("Hello and welcome to % s"),
                   phdfVERSION_STRING);
        wxMessageBox(msg, wxT("About PhreeDF"),
                     wxOK | wxICON_INFORMATION, this);
    }

    void MainFrame::OnQuit(wxCommandEvent &event)
    {
        // Destroy the frame
        Close();
    }

    void MainFrame::OnButtonOK(wxCommandEvent &event)
    {
        wxMessageBox(wxT("OK button clicked"), wxT("OK"), wxOK, this);
        spdlog::debug("Button clicked");
    }

} // namespace phdf

// Event table for MainFrame
// clang-format off
BEGIN_EVENT_TABLE(phdf::MainFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, phdf::MainFrame::OnAbout)
    EVT_MENU(wxID_EXIT, phdf::MainFrame::OnQuit)
    EVT_BUTTON(wxID_OK, phdf::MainFrame::OnButtonOK)
END_EVENT_TABLE()
// clang-format on