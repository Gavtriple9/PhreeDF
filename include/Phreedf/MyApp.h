#include "Core.h"
#include "MyFrame.h"

// Declare the application class
class MyApp : public wxApp
{
public:
    // Called on application startup
    virtual bool OnInit();
};

// Implements MyApp& wxGetApp()
DECLARE_APP(MyApp)
