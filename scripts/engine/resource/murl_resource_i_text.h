// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_RESOURCE_I_TEXT_H__
#define __MURL_RESOURCE_I_TEXT_H__

#include "murl_string.h"
#include "murl_i_enums.h"

namespace Murl
{
    namespace Resource
    {
        /**
         * @ingroup MurlResourceObjectInterfaces
         * @interface IText
         * @brief The base interface for a text resource.
         */
        class IText
        {
        public:
            /**
             * @brief Get the ID of the text resource.
             * @return The text ID.
             */
            virtual const String& GetId() const = 0;
            /**
             * @brief Get the string value of the text resource.
             * @return The string value.
             */
            virtual const String& GetValue() const = 0;
            
        protected:
            virtual ~IText() {}
        };
    }
}

#endif // __MURL_RESOURCE_I_TEXT_H__
