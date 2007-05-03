/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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

#ifndef _OSGBASEINITFUNCTIONS_H_
#define _OSGBASEINITFUNCTIONS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGBaseTypes.h"

#include <vector>
#include <boost/function.hpp>

OSG_BEGIN_NAMESPACE

/*---------------------------------------------------------------------*/
/*                           Initialization                            */

/*! \ingroup GrpBaseBaseInitExit
 */

enum SystemState
{
    Startup  = 0x01,
    Running  = 0x02,
    Shutdown = 0x03
};

extern OSG_BASE_DLLMAPPING SystemState GlobalSystemState;

// Init sequence:
//
// * PreMP
// * MP              internal call
// * PreFactories
// * Factories       internal call
// * PostFactories

typedef boost::function<bool (void)> InitFuncF;

// Shutdown sequence:
//
// * PreFactories
// * Factories       internal call
// * PostFactories
// * MP              internal call
// * PostMP

typedef boost::function<bool (void)> ExitFuncF;

struct OSG_BASE_DLLMAPPING InitFuncWrapper
{
    /*---------------------------------------------------------------------*/
    /*! \name                      Constructors                            */
    /*! \{                                                                 */

    InitFuncWrapper(const InitFuncF func);

    /*! \}                                                                 */
};


struct OSG_BASE_DLLMAPPING StaticInitFuncWrapper
{
    /*---------------------------------------------------------------------*/
    /*! \name                      Constructors                            */
    /*! \{                                                                 */

    StaticInitFuncWrapper(const InitFuncF func);

    /*! \}                                                                 */
};


OSG_BASE_DLLMAPPING 
void addPreMPInitFunction      (InitFuncF initFunc);

OSG_BASE_DLLMAPPING 
void addPreFactoryInitFunction (InitFuncF initFunc);

OSG_BASE_DLLMAPPING 
void addPostFactoryInitFunction(InitFuncF initFunc);


OSG_BASE_DLLMAPPING 
void addPreFactoryExitFunction (ExitFuncF exitFunc);

OSG_BASE_DLLMAPPING 
void addPostFactoryExitFunction(ExitFuncF exitFunc);

OSG_BASE_DLLMAPPING 
void addPreMPExitFunction      (ExitFuncF exitFunc);

OSG_BASE_DLLMAPPING 
void addPostMPExitFunction     (ExitFuncF exitFunc);

OSG_BASE_DLLMAPPING
void preloadSharedObject(const TChar *szName);

OSG_BASE_DLLMAPPING
void addLibraryVersion(const Char8 *szName);

#ifdef _DEBUG  
# define OSG_INIT_DEBUG true
#else
# define OSG_INIT_DEBUG false
#endif
#ifdef _DLL  
# define OSG_INIT_DLL   true
#else
# define OSG_INIT_DLL   false
#endif
#ifdef _MT  
#define OSG_INIT_MT     true
#else
#define OSG_INIT_MT     false
#endif

OSG_BASE_DLLMAPPING 
bool osgInit(Int32    argc, 
             Char8  **argv,
             UInt16   major   = OSG_MAJOR_VERSION, 
             UInt16   minor   = OSG_MINOR_VERSION, 
             UInt16   release = OSG_RELEASE_VERSION,
             bool     debug   = OSG_INIT_DEBUG,
             bool     dll     = OSG_INIT_DLL,
             bool     mt      = OSG_INIT_MT        );

OSG_BASE_DLLMAPPING 
bool osgExit(void);

OSG_END_NAMESPACE

#define OSGBASEINITFUNCTIONS_HEADER_CVSID "@(#)$Id$"

#endif /* OSGBASEINITFUNCTIONS_H */
