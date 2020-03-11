// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_EMAIL_H__
#define __MURL_I_EMAIL_H__

#include "murl_data.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IEMail
     * @brief The e-mail interface.
     * The IEMail object can be created by the IWebControl object.
     */
    class IEMail
    {
    public:
        /**
         * @brief Set the e-mail subject string.
         * @param subject The e-mail subject string.
         * @return true if successful.
         */
        virtual Bool SetSubject(const String& subject) = 0;
        /**
         * @brief Set the e-mail message string.
         * @param message The e-mail message string.
         * @return true if successful.
         */
        virtual Bool SetMessage(const String& message) = 0;
        
        /**
         * @brief Add a receipient e-mail address string to the TO field.
         * @param address The e-mail address string.
         * @return true if successful.
         */
        virtual Bool AddToRecipient(const String& address) = 0;
        /**
         * @brief Add a receipient e-mail address string to the carbon copy field.
         * @param address The e-mail address string.
         * @return true if successful.
         */
        virtual Bool AddCcRecipient(const String& address) = 0;
        /**
         * @brief Add a receipient e-mail address string to the blind carbon copy field.
         * @param address The e-mail address string.
         * @return true if successful.
         */
        virtual Bool AddBccRecipient(const String& address) = 0;
        /**
         * @brief Add an attachment to the e-mail.
         * Currently only supported on iOS devices.
         * @param fileName The name of the attachment.
         * @param mimeType The MIME type of the attachment (e.g. "image/png").
         * @param data The data of the attachment.
         * @return true if successful.
         */
        virtual Bool AddAttachment(const String& fileName, const String& mimeType, const Data& data) = 0;
        
        /**
         * @brief Get the e-mail subject string.
         * @return subject The e-mail subject string.
         */
        virtual const String& GetSubject() const = 0;
        /**
         * @brief Get the e-mail message string.
         * @return message The e-mail message string.
         */
        virtual const String& GetMessage() const = 0;
        
        /**
         * @brief Get the number of available receipients of the TO field.
         * @return The number of available receipients.
         */
        virtual UInt32 GetNumberOfToRecipients() const = 0;
        /**
         * @brief Get the receipients e-mail address string from the TO field.
         * A valid index is [0 .. GetNumberOfToRecipients() - 1].
         * @param index The zero-based index of the receipients.
         * @return The receipients e-mail address string.
         */
        virtual const String& GetToRecipient(UInt32 index) const = 0;
        
        /**
         * @brief Get the number of available receipients of the carbon copy field.
         * @return The number of available receipients.
         */
        virtual UInt32 GetNumberOfCcRecipients() const = 0;
        /**
         * @brief Get the receipients e-mail address string from the carbon copy field.
         * A valid index is [0 .. GetNumberOfToRecipients() - 1].
         * @param index The zero-based index of the receipients.
         * @return The receipients e-mail address string.
         */
        virtual const String& GetCcRecipient(UInt32 index) const = 0;
        
        /**
         * @brief Get the number of available receipients of the blind carbon copy field.
         * @return The number of available receipients.
         */
        virtual UInt32 GetNumberOfBccRecipients() const = 0;
        /**
         * @brief Get the receipients e-mail address string from the blind carbon copy field.
         * A valid index is [0 .. GetNumberOfToRecipients() - 1].
         * @param index The zero-based index of the receipients.
         * @return The receipients e-mail address string.
         */
        virtual const String& GetBccRecipient(UInt32 index) const = 0;
        
        /**
         * @brief Get the number of attachments.
         * @return The number of attachments.
         */
        virtual UInt32 GetNumberOfAttachments() const = 0;
        /**
         * @brief Get the name of an attachment.
         * A valid index is [0 .. GetNumberOfAttachments() - 1].
         * @param index The zero-based index of the attachment.
         * @return The name of the attachment.
         */
        virtual const String& GetAttachmentFileName(UInt32 index) const = 0;
        /**
         * @brief Get the MIME type of an attachment.
         * A valid index is [0 .. GetNumberOfAttachments() - 1].
         * @param index The zero-based index of the attachment.
         * @return The MIME type of the attachment.
         */
        virtual const String& GetAttachmentMimeType(UInt32 index) const = 0;
        /**
         * @brief Get the data of an attachment.
         * A valid index is [0 .. GetNumberOfAttachments() - 1].
         * @param index The zero-based index of the attachment.
         * @return The data of the attachment.
         */
        virtual const Data& GetAttachmentData(UInt32 index) const = 0;
        
        /**
         * @brief Send the e-mail.
         * @return true if successful.
         */
        virtual Bool Send() = 0;
        
        /**
         * @brief Check if the e-mail is in the send queue.
         * @return true if the e-mail is in the send queue.
         */
        virtual Bool IsInQueue() const = 0;
        /**
         * @brief Check if the e-mail is currently sent.
         * @return true if the e-mail is currently sent.
         */
        virtual Bool IsSending() const = 0;
        
        /**
         * @brief Check if the e-mail was sent in the most recent tick.
         * @return true if the e-mail was sent in the most recent tick.
         */
        virtual Bool WasSent() const = 0;
        /**
         * @brief Check if the e-mail was saved in the most recent tick.
         * @return true if the e-mail was saved in the most recent tick.
         */
        virtual Bool WasSaved() const = 0;
        /**
         * @brief Check if the e-mail was cancelled in the most recent tick.
         * @return true if the e-mail was cancelled in the most recent tick.
         */
        virtual Bool WasCancelled() const = 0;
        /**
         * @brief Check if the e-mail was rejected in the most recent tick.
         * @return true if the e-mail was rejected in the most recent tick.
         */
        virtual Bool WasRejected() const = 0;
        
    protected:
        virtual ~IEMail() {}
    };
}

#endif  // __MURL_I_EMAIL_H__
