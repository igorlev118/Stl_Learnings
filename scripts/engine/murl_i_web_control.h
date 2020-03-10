// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_WEB_CONTROL_H__
#define __MURL_I_WEB_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_email.h"
#include "murl_i_url_request.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IWebControl
     * @brief The IWebControl interface.
     */
    class IWebControl : public IControlable
    {
    public:
        /**
         * @brief Open a url in the system's default browser.
         * @param url The url string to open.
         * @return true if successful.
         */
        virtual Bool OpenUrlInSystemBrowser(const String& url) = 0;
        
        /**
         * @brief Create a url-request object.
         * @return The url-request object or null if creation failed.
         */
        virtual IUrlRequest* CreateUrlRequest() = 0;
        /**
         * @brief Destroy a url-request object.
         * @param urlRequest A reference to the url-request object to destroy.
         *  After destruction the pointer is set to null.
         */
        virtual void DestroyUrlRequest(IUrlRequest*& urlRequest) = 0;
        
        /**
         * @brief Create a e-mail object.
         * @param subject The subject string for the e-mail object.
         * @param message The message string for the e-mail object.
         * @return The e-mail object or null if creation failed
         * @return The e-mail object or null if sending e-mail is not configured.
         */
        virtual IEMail* CreateEMail(const String& subject, const String& message) = 0;
        /**
         * @brief Create a e-mail object.
         * @param subject The subject string for the e-mail object.
         * @param message The message string for the e-mail object.
         * @param recipientAddress The recipient address string for the e-mail object.
         * @return The e-mail object or null if sending e-mail is not configured.
         */
        virtual IEMail* CreateEMail(const String& subject, const String& message, const String& recipientAddress) = 0;
        /**
         * @brief Destroy a e-mail object.
         * @param eMail A reference to the e-mail object to destroy.
         *  After destruction the pointer is set to null.
         */
        virtual void DestroyEMail(IEMail*& eMail) = 0;
        
    protected:
        virtual ~IWebControl() {}
    };
}

#endif  // __MURL_I_WEB_CONTROL_H__
