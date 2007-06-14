/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2003 by the OpenSG Forum                   *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

#ifndef _OSGGLU_H_
#define _OSGGLU_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"

#include "OSGGL.h"

#ifndef OSG_WINCE

#ifdef OSG_NOGLSUBDIR
#include <glu.h>
#elif defined(__APPLE__)
#include <OpenGL/glu.h>
#else
#include <GL/glu.h>
#endif

// _GLUfuncptr doesn't exist on all platforms.
#if defined(WIN32)
typedef void (CALLBACK *OSGGLUfuncptr)();
#elif defined(__linux)
#  ifdef GLAPIENTRY
typedef void (GLAPIENTRY *OSGGLUfuncptr)();
#  elif defined(APIENTRY)
typedef void (APIENTRY *OSGGLUfuncptr)();
#  else
typedef void (*OSGGLUfuncptr)();
#  endif
#elif defined(__APPLE__)
typedef GLvoid (*OSGGLUfuncptr)(...);
#else
typedef void (*OSGGLUfuncptr)();
#endif

#endif

#if defined(OSG_DEBUG) && !defined(OSG_WINCE)
#define glErr(text)                                 \
{                                                   \
    GLenum glerr;                                   \
                                                    \
    while((glerr = glGetError()) != GL_NO_ERROR)    \
    {                                               \
        FWARNING(("(%s,%d): %s failed: %s (%#x)\n", \
                __FILE__, __LINE__,                 \
                (text),                             \
                gluErrorString(glerr),              \
                glerr));                            \
    }                                               \
}
#else
#define glErr(text)
#endif

#endif /* _OSGGLU_H_ */
