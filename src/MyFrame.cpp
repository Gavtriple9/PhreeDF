#include <Phreedf/MyFrame.h>
#include "logo.xpm"

MyFrame::MyFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title)
{
    // Set the frame icon
    SetIcon(wxIcon(logo));
    // Create a menu bar
    wxMenu *fileMenu = new wxMenu;
    // The “About” item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("& About...\tF1"),
                     wxT("Show about dialog"));
    fileMenu->Append(wxID_EXIT, wxT("E & xit\tAlt - X"),
                     wxT("Quit this program"));
    // Now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("& File"));
    menuBar->Append(helpMenu, wxT("& Help"));
    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
    // Create a status bar just for fun
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome to wxWidgets !"));
}

void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg;
    msg.Printf(wxT("Hello and welcome to % s"),
               wxVERSION_STRING);
    wxMessageBox(msg, wxT("About Minimal"),
                 wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent &event)
{
    // Destroy the frame
    Close();
}

// Event table for MyFrame
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()