// Copyright 2010-2014 Spraylight GmbH

#ifndef __MURL_SYSTEM_PLATFORM_H__
#define __MURL_SYSTEM_PLATFORM_H__

#include "murl_defines.h"

#if defined(MURL_TARGET_OS_WIN32)
#   include <windows.h>
#   undef GetClassInfo
#   undef FileType
#   undef FILE_TYPE_UNKNOWN
#endif

#endif  // __MURL_SYSTEM_PLATFORM_H__
