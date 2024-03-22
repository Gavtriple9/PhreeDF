#pragma once

#include "Core.hpp"

/** \brief Main frame of the application
 *
 * This class is the main frame of the application. It contains the main window
 * and all the widgets that are displayed in it.
 */
class MainFrame : public wxFrame
{
public:
    /** \brief Constructor
     *
     * This constructor creates the main frame of the application.
     */
    MainFrame(const wxString &title);

    /**
     * @brief Event handler for the quit event
     *
     * @param[in] event A wxCommandEvent reference
     *
     * This function is called when the user clicks on the quit button in the
     * menu bar. It closes the application.
     */
    void OnQuit(wxCommandEvent &event);

    /**
     * @brief Event handler for the about event
     *
     * @param[in] event A wxCommandEvent reference
     *
     * This function is called when the user clicks on the about button in the
     * menu bar. It displays an about dialog.
     */
    void OnAbout(wxCommandEvent &event);

    /**
     * @brief Event handler for the open event
     *
     * @param[in] event A wxCommandEvent reference
     *
     * This function is called when the user clicks on the open button in the
     * menu bar. It opens a file dialog to select a file to open.
     */
    void OnSize(wxSizeEvent &event);

    /**
     * @brief Event handler for the open event
     *
     * @param[in] event A wxCommandEvent reference
     *
     * This function is called when the user clicks on the open button in the
     * menu bar. It opens a file dialog to select a file to open.
     */
    void OnButtonOK(wxCommandEvent &event);

private:
    // This class handles events
    DECLARE_EVENT_TABLE()
};