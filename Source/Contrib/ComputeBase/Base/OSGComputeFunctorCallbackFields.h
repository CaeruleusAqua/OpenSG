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

#ifndef _OSGCOMPUTEFUNCTORCALLBACKFIELDS_H_
#define _OSGCOMPUTEFUNCTORCALLBACKFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGSField.h"
#include "OSGMField.h"
#include "OSGComputeFunctorFieldTraits.h"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS) 

typedef SField<ComputeFunctorCallback> SFComputeFunctorCallback;

#endif

// there is no good way of comparing boost function objects
template<> inline
bool SField<ComputeFunctorCallback, 0>::operator ==(
    const SField<ComputeFunctorCallback, 0> &source) const
{
    return false;
}


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS) 

typedef MField<ComputeFunctorCallback> MFComputeFunctorCallback;

#endif

// there is no good way of comparing boost function objects
template<> inline
bool MField<ComputeFunctorCallback, 0>::operator ==(
    const MField<ComputeFunctorCallback, 0> & OSG_CHECK_ARG(source)) const
{
    return false;
}


OSG_END_NAMESPACE

#endif /* _OSGCOMPUTECALLBACKFUNCTORFIELDS_H_ */
