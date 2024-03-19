#include <phreedf/MyFrame.h>
#include "logo.xpm"

MyFrame::MyFrame(const wxString &title)
    : wxFrame(NULL, wxID_ANY, title)
{
    wxIcon icon;
    icon.CopyFromBitmap(wxBitmap(logo_xpm));

    // Set the frame icon
    SetIcon(icon);

    wxClientDC dc(this);

    dc.DrawIcon(icon, 200, 200);
    // Create a menu bar
    wxMenu *fileMenu = new wxMenu;
    // The “About” item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("& About...\tF1"),
                     wxT("Show about dialog"));
    fileMenu->Append(wxID_EXIT, wxT("E & xit\tAlt-X"),
                     wxT("Quit this program"));

    wxStaticBox *staticBox = new wxStaticBox(this, wxID_STATIC,
                                             wxT("& Static box"), wxDefaultPosition, wxSize(100, 100));

    wxButton *button = new wxButton(staticBox, wxID_OK, wxT("OK"), wxPoint(10, 10), wxDefaultSize, wxBU_EXACTFIT);
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
void MyFrame::OnSize(wxSizeEvent &event)
{
    wxSize size = event.GetSize();
    wxString msg;
    msg.Printf(wxT("Size: %d x %d"), size.x, size.y);
    SetStatusText(msg);
}

void MyFrame::OnButtonOK(wxCommandEvent &event)
{
    wxMessageBox(wxT("OK button clicked"), wxT("OK"), wxOK, this);
}

// Event table for MyFrame
// clang-format off
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
    EVT_SIZE(MyFrame::OnSize)
    EVT_BUTTON(wxID_OK, MyFrame::OnButtonOK)
END_EVENT_TABLE()
// clang-format on