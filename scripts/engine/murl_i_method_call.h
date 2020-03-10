// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_I_METHOD_CALL_H__
#define __MURL_I_METHOD_CALL_H__

#include "murl_types.h"

namespace Murl
{
    /**
     * @ingroup MurlInterfaces
     * @interface IMethodCall
     * @brief The method call interface.
     * Method call objects can be created by Util::CreateMethodCall.
     */
    class IMethodCall
    {
    public:
        /**
         * @brief Invoke the method pointer.
         * @return The return value from the method called.
         */
        virtual Bool Invoke() const = 0;
        
    protected:
        virtual ~IMethodCall() {}
    };
}

#endif  // __MURL_I_METHOD_CALL_H__
