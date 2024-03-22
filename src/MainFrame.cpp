#include <phreedf/MainFrame.hpp>

MainFrame::MainFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title)
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
    SetStatusText(wxT("Welcome to wxWidgets !"));
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg;
    msg.Printf(wxT("Hello and welcome to % s"),
               wxVERSION_STRING);
    wxMessageBox(msg, wxT("About Minimal"),
                 wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnQuit(wxCommandEvent &event)
{
    // Destroy the frame
    Close();
}
void MainFrame::OnSize(wxSizeEvent &event)
{
    wxSize size = event.GetSize();
    wxString msg;
    msg.Printf(wxT("Size: %d x %d"), size.x, size.y);
    SetStatusText(msg);
}

void MainFrame::OnButtonOK(wxCommandEvent &event)
{
    wxMessageBox(wxT("OK button clicked"), wxT("OK"), wxOK, this);
    spdlog::debug("Button clicked");
}

// Event table for MainFrame
// clang-format off
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
    EVT_SIZE(MainFrame::OnSize)
    EVT_BUTTON(wxID_OK, MainFrame::OnButtonOK)
END_EVENT_TABLE()
// clang-format on