// Copyright 2010-2013 Spraylight GmbH

#ifndef __MURL_I_KEYBOARD_CONTROL_H__
#define __MURL_I_KEYBOARD_CONTROL_H__

#include "murl_i_controlable.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IKeyboardControl
     * @brief The IKeyboardControl interface.
     * Methods to control the on-screen keyboard.
     */
    class IKeyboardControl : public IControlable
    {
    public:
        /**
         * @brief Definition of the keyboard types.
         * The PAD keyboard types may not offer a return key (e.g. Phone iOS).
         */
        enum KeyboardType
        {
            /** @brief The default keyboard. */
            KEYBOARD_DEFAULT,
            /** @brief A keyboard optimized for URL entry. */
            KEYBOARD_URL,
            /** @brief A keyboard optimized for specifying email addresses. */
            KEYBOARD_EMAIL,
            /** @brief The numbers and punctuation keyboard. */
            KEYBOARD_NUMBERS,
            /** @brief A numeric keypad designed for PIN entry. */
            KEYBOARD_PAD_NUMBERS,
            /** @brief A keypad designed for entering telephone numbers. */
            KEYBOARD_PAD_PHONE,

            NUM_KEYBOARD_TYPES
        };

        /**
         * @brief Definition of the return key types.
         * The text of the return key is translated to the current language.
         */
        enum ReturnKeyType
        {
            /** @brief Set the text of the return key to "return". */
            RETURN_KEY_DEFAULT,
            /** @brief Set the text of the return key to "Go". */
            RETURN_KEY_GO,
            /** @brief Set the text of the return key to "Join". */
            RETURN_KEY_JOIN,
            /** @brief Set the text of the return key to "Next". */
            RETURN_KEY_NEXT,
            /** @brief Set the text of the return key to "Route". */
            RETURN_KEY_ROUTE,
            /** @brief Set the text of the return key to "Search". */
            RETURN_KEY_SEARCH,
            /** @brief Set the text of the return key to "Send". */
            RETURN_KEY_SEND,
            /** @brief Set the text of the return key to "Done". */
            RETURN_KEY_DONE,

            NUM_RETURN_KEY_TYPES
        };

        /**
         * @brief Set the keyboard type of the on-screen keyboard.
         * @param keyboardType The keyboard type.
         */
        virtual void SetKeyboardType(KeyboardType keyboardType) = 0;

        /**
         * @brief Set the return key type of the on-screen keyboard.
         * @param returnKeyType The return key type.
         */
        virtual void SetReturnKeyType(ReturnKeyType returnKeyType) = 0;

        /**
         * @brief Show the on-screen keyboard.
         */
        virtual void Show() = 0;

        /**
         * @brief Hide the on-screen keyboard.
         */
        virtual void Hide() = 0;

        /**
         * @brief Check if the on-screen keyboard is showing.
         * @return true if the on-screen keyboard is showing.
         */
        virtual Bool IsShowing() const = 0;

        /**
         * @brief Check if the on-screen keyboard was closed
         * in the most recent tick.
         * @return true if the on-screen keyboard was closed.
         */
        virtual Bool WasClosed() const = 0;

        /**
         * @brief Check if the on-screen keyboard has a text field for editing.
         * The on-screen keyboard text field is currently supported on tvOS only.
         * @return true if the on-screen keyboard has a text field for editing.
         */
        virtual Bool HasTextfield() const = 0;

        /**
         * @brief Set the title string for the text field.
         * The title string is a text displayed above the text field,
         * containing one line with automatic font size fitting.
         * @param title The title string for the text field.
         */
        virtual void SetTitle(const String& title) = 0;

        /**
         * @brief Set the description string for the text field.
         * The description string is a text displayed below the title text,
         * containing two lines with automatic line break.
         * @param description The description string for the text field.
         */
        virtual void SetDescription(const String& description) = 0;

        /**
         * @brief Set the initial editing string for the text field.
         * The initial editing string must be set before Show() the keyboard.
         * @param text The initial editing string for the text field.
         */
        virtual void SetText(const String& text) = 0;

        /**
         * @brief Get the editing string from the text field.
         * The edited string is available when the keyboard WasClosed().
         * @return The editing string from the text field.
         */
        virtual const String& GetText() const = 0;

    protected:
        virtual ~IKeyboardControl() {}
    };
}

#endif  // __MURL_I_KEYBOARD_CONTROL_H__
