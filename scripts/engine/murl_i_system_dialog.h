// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_SYSTEM_DIALOG_H__
#define __MURL_I_SYSTEM_DIALOG_H__

#include "murl_string.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface ISystemDialog
     * @brief The system-dialog interface.
     * The ISystemDialog object can be created by the ISystemDialogControl object.
     */
    class ISystemDialog
    {
    public:
        /**
         * @brief Get the title string.
         * @return The title string.
         */
        virtual const String& GetTitle() const = 0;
        /**
         * @brief Get the message string.
         * @return The message string.
         */
        virtual const String& GetMessage() const = 0;
        
        /**
         * @brief Get the number of buttons.
         * @return the number of buttons.
         */
        virtual UInt32 GetNumberOfButtons() const = 0;
        /**
         * @brief Get a button label string by index.
         * A valid button index is [0 .. GetNumberOfButtons() - 1].
         * @param index The zero-based index of the button.
         * @return The button label string.
         */
        virtual const String& GetButtonLabel(UInt32 index) const = 0;
        /**
         * @brief Add a button to the dialog.
         * Button appearance is platform dependent but it is ensured that the negative
         * button is always button 0 on dialogs with more than 1 button.
         * On Android the maximum number of visible dialog buttons is limited to 3.
         * @param label The button label string.
         * @return true if successful.
         */
        virtual Bool AddButton(const String& label) = 0;
        
        /**
         * @brief Open (show) the dialog.
         * @return true if successful.
         */
        virtual Bool Open() = 0;
        /**
         * @brief Close (hide) the dialog.
         * A valid button index is [0 .. GetNumberOfButtons() - 1].
         * @param clickedButtonIndex The zero-based index of the clicked button.
         * @return true if successful.
         */
        virtual Bool Close(SInt32 clickedButtonIndex) = 0;
        
        /**
         * @brief Check if the dialog is open.
         * @return true if the dialog is open.
         */
        virtual Bool IsOpen() const = 0;
        /**
         * @brief Check if the dialog was closed in the most recent tick.
         * @return true if the dialog was closed in the most recent tick.
         */
        virtual Bool WasClosed() const = 0;
        
        /**
         * @brief Get the clicked button index.
         * ButtonIndex 0 is the default (selected) button,
         * button appearance is right to left or bottom up.
         * @return The zero-based index of the clicked button,
         *  or -1 if no button was selected.
         */
        virtual SInt32 GetClickedButtonIndex() const = 0;
        
    protected:
        virtual ~ISystemDialog() {}
    };
}

#endif  // __MURL_I_SYSTEM_DIALOG_H__
