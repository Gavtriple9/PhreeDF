#include <phreedf/MyApp.h>

bool MyApp::OnInit()
{

    // Create the main application window
    MyFrame *frame = new MyFrame(wxT("Phreedf - The Free PDF Editor"));
    // Show it
    frame->Show(true);
    // Start the event loop
    return true;
}

IMPLEMENT_APP(MyApp)