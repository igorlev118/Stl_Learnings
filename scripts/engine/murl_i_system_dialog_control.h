// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_SYSTEM_DIALOG_CONTROL_H__
#define __MURL_I_SYSTEM_DIALOG_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_system_dialog.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface ISystemDialogControl
     * @brief The ISystemDialogControl interface.
     */
    class ISystemDialogControl : public IControlable
    {
    public:
        /**
         * @brief Create a system-dialog object with a variable number of buttons.
         * Buttons are added using the ISystemDialog::AddButton() method.
         * @param title The title string for the system-dialog object.
         * @param message The message string for the system-dialog object.
         * @return The system-dialog object or null if creation failed.
         */
        virtual ISystemDialog* CreateSystemDialog(const String& title, const String& message) = 0;
        
        /**
         * @brief Destroy a system-dialog object.
         * @param dialog A reference to the system-dialog object to destroy.
         *  After destruction the pointer is set to null.
         */
        virtual void DestroySystemDialog(ISystemDialog*& dialog) = 0;
        
    protected:
        virtual ~ISystemDialogControl() {}
    };
}

#endif  // __MURL_I_SYSTEM_DIALOG_CONTROL_H__
