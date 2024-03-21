#pragma once

#include "Core.h"

// Declare our main frame class
class MainFrame : public wxFrame
{
public:
    // Constructor
    MainFrame(const wxString &title);
    // Event handlers
    void OnQuit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);
    void OnSize(wxSizeEvent &event);
    void OnButtonOK(wxCommandEvent &event);

private:
    // This class handles events
    DECLARE_EVENT_TABLE()
};