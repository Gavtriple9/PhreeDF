#include <Phreedf/MyApp.h>

bool MyApp::OnInit()
{
    // Create the main application window
    MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));
    // Show it
    frame->Show(true);
    // Start the event loop
    return true;
}

// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(MyApp)