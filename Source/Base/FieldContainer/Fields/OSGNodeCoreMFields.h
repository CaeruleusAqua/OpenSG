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

#ifndef _OSGNODECOREMFIELDS_H_
#define _OSGNODECOREMFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGNodeCoreFieldTraits.h"
#include "OSGPointerMField.h"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS) 
/*! \ingroup  */

typedef PointerMField     <NodeCore *, 
                           RecordedRefCountPolicy  > MFNodeCorePtr;
typedef PointerMField     <NodeCore *, 
                           UnrecordedRefCountPolicy> MFUnrecNodeCorePtr;
typedef PointerMField     <NodeCore *, 
                           WeakRefCountPolicy      > MFWeakNodeCorePtr;
typedef PointerMField     <NodeCore *, 
                           NoRefCountPolicy        > MFUncountedNodeCorePtr;

typedef ChildPointerMField<NodeCore *, 
                           UnrecordedRefCountPolicy,
                           1                       > MFUnrecChildNodeCorePtr;

#endif


OSG_END_NAMESPACE

#endif /* _OSGNODECOREMFIELDS_H_ */
