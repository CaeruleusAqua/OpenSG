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

#ifndef _OSGNODEMFIELDS_H_
#define _OSGNODEMFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGMField.h"
#include "OSGMFieldAdaptor.h"
#include "OSGNodeFieldTraits.h"
#include "OSGFieldContainerMFields.h"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS) 
/*! \ingroup  */

typedef MFieldAdaptor   <NodePtr, 
                         MFFieldContainerPtr> MFNodePtr;

#ifdef FDFOO
typedef FieldDescription<NodePtrFieldDesc,
                         MultiField         > MNodePtrFieldDescription;
#endif
#endif

#ifndef OSG_COMPILECONTAINERFIELDINST
OSG_FIELD_DLLEXPORT_DECL1(MField, NodePtr, OSG_SYSTEM_DLLTMPLMAPPING)
#endif


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS) 
/*! \ingroup  */

typedef MField          <ParentNodePtr, 
                         1                    > MFParentNodePtr;
#ifdef FDFOO
typedef FieldDescription<ParentNodePtrFieldDesc,
                         MultiField           > MParentNodePtrFieldDescription;
#endif
#endif

#ifndef OSG_COMPILECONTAINERFIELDINST
OSG_FIELD_DLLEXPORT_DECL2(MField, ParentNodePtr, 1, OSG_SYSTEM_DLLTMPLMAPPING)
#endif

OSG_END_NAMESPACE

#define OSGNODEMFIELDS_HEADER_CVSID "@(#)$Id$"

#endif /* _OSGNODEMFIELDS_H_ */
