/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGWindowDrawThread.h"
#include "OSGThreadManager.h"
#include "OSGWindow.h"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

MPThreadType WindowDrawThread::_type(
    "OSGWindowDrawThread",
    "OSGHardwareContextThread",
    static_cast<CreateThreadF>(WindowDrawThread::create),
    NULL);

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

WindowDrawThread *WindowDrawThread::find(Char8 *szName)
{
    BaseThread *pThread = ThreadManager::the()->findThread(szName);

    return dynamic_cast<WindowDrawThread *>(pThread);
}

WindowDrawThread::ObjTransitPtr WindowDrawThread::get(Char8 *szName,
                                                      bool   bGlobal) 
{
    BaseThreadTransitPtr pThread = 
        ThreadManager::the()->getThread(szName,
                                        bGlobal,
                                        "OSGWindowDrawThread");

    return dynamic_pointer_cast<WindowDrawThread>(pThread);
}



BaseThread *WindowDrawThread::create(const Char8  *szName, 
                                           UInt32  uiId,
                                           bool    bGlobal)
{
    return new WindowDrawThread(szName, uiId, bGlobal);
}

WindowDrawThread::WindowDrawThread(const Char8 *szName, 
                                         UInt32 uiId,
                                         bool   bGlobal) :
      Inherited(szName, 
                uiId  ,
                bGlobal),
     _oEnv     (       )
{
    Inherited::_pEnv = &_oEnv;
}

WindowDrawThread::~WindowDrawThread(void)
{
    Inherited::_pEnv = NULL;
}

void WindowDrawThread::setWindow (Window *pWindow)
{
    Inherited::setContext(pWindow);

    _oEnv.setWindow(pWindow);
}

OSG_END_NAMESPACE
