#include <Phreedf/Phreedf.h>

DECLARE_APP(GrApp);

IMPLEMENT_APP(GrApp);

// Event table for GrFrame
BEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
EVT_MENU(wxID_EXIT, MainFrame::OnQuit)
END_EVENT_TABLE()