/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *           Copyright (C) 2003 by the OpenSG Forum                          *
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

#ifndef _OSGCONTAINERPTRFUNCS_H_
#define _OSGCONTAINERPTRFUNCS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGBaseTypes.h"
#include "OSGContainerBase.h"

#include "OSGFieldContainer.h"

OSG_BEGIN_NAMESPACE

#ifdef OSG_1_COMPAT
inline
UInt32 getContainerId(FieldContainer * const objectP)
{
    return objectP->getId();
}

inline
void addRefCP(FieldContainer * const)
{
}

inline
void subRefCP(FieldContainer * const)
{
}

template<class T> inline
const T *getCPtr(const T * const pObj)
{
    return pObj;
}

template<class T> inline
T *getCPtr(T * const pObj)
{
    return pObj;
}

template <class PtrT> inline
void beginEditCP(const PtrT      objectP,
                       BitVector whichField = FieldBits    ::AllFields,
                       UInt32    origin     = ChangedOrigin::External)
{
}

template <class PtrT> inline
void endEditCP(const PtrT      objectP,
                     BitVector whichField = FieldBits    ::AllFields,
                     UInt32    origin     = ChangedOrigin::External)
{
}

template <class StoreT, class SourceT> inline
void setRefdCPX(StoreT  &pTarget,
                SourceT  pSource)
{
    setRefdX(pTarget, pSource);
}

template <class OutPtrT> inline
OutPtrT dynamic_fcptr_cast(FieldContainer * const pPtr)
{
    return dynamic_cast<OutPtrT>(pPtr);
}
#endif

OSG_END_NAMESPACE

#include "OSGContainerPtrFuncs.inl"

#endif /* _OSGCONTAINERPTRFUNCS_H_ */
