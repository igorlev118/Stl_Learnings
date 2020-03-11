// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_SYSTEM_OPENGL_H__
#define __MURL_SYSTEM_OPENGL_H__

#include "murl_types.h"

namespace Murl
{
    namespace System
    {
        namespace OpenGl
        {
            // Startup/Shutdown code
            Bool Init(Bool enableChecks);
            Bool DeInit();
        }
    }
}

#endif  // __MURL_SYSTEM_OPENGL_H__
