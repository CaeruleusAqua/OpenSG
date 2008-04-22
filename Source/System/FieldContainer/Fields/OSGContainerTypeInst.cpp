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

#define OSG_COMPILECONTAINERFIELDINST

#include <OSGField.h>

#include <OSGSField.h>
#include <OSGSField.ins>

#include <OSGMField.h>
#include <OSGMField.ins>

#include "OSGFieldContainerSFields.h"
#include "OSGFieldContainerMFields.h"

#include "OSGAttachmentSFields.h"
#include "OSGAttachmentMFields.h"

#include "OSGAttachmentContainerSFields.h"
#include "OSGAttachmentContainerMFields.h"

#include "OSGNodeSFields.h"
#include "OSGNodeMFields.h"

#include "OSGNodeCoreSFields.h"
#include "OSGNodeCoreMFields.h"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)

DataType FieldTraits<FieldContainerPtr          >::_type(
    "FieldContainerPtr",
    NULL);

DataType FieldTraits<AttachmentPtr>::_type(
    "AttachmentPtr",
    "FieldContainerPtr");

DataType FieldTraits<AttachmentContainerPtr     >::_type(
    "AttachmentContainerPtr",
    "FieldContainerPtr");

DataType FieldTraits<NodeCorePtr                >::_type(
    "NodeCorePtr",
    "AttachmentContainerPtr");

DataType FieldTraits<NodePtr                    >::_type(
    "NodePtr",
    "AttachmentContainerPtr");

DataType FieldTraits<ChangedFunctorCallback     >::_type(
    "ChangedFunctorCallback",
    NULL);
 
OSG_FIELDTRAITS_GETTYPE   (FieldContainerPtr          )

OSG_FIELDTRAITS_GETTYPE   (AttachmentPtr              )
OSG_FIELDTRAITS_GETTYPE   (AttachmentContainerPtr     )
OSG_FIELDTRAITS_GETTYPE   (NodeCorePtr                )
OSG_FIELDTRAITS_GETTYPE   (NodePtr                    )
OSG_FIELDTRAITS_GETTYPE   (ChangedFunctorCallback     )

DataType &FieldTraits< FieldContainerPtr, 1 >::getType(void)
{                                                           
    return FieldTraits<FieldContainerPtr, 0>::getType();
}

DataType &FieldTraits< NodeCorePtr, 1 >::getType(void)
{                                                           
    return FieldTraits<NodeCorePtr, 0>::getType();
}

DataType &FieldTraits< NodePtr, 1 >::getType(void)
{                                                           
    return FieldTraits<NodePtr, 0>::getType();
}

#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)

// FieldContainer

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           FieldContainerPtr, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           FieldContainerPtr, 
                           0);

// Node

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           NodePtr, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           NodePtr, 
                           0);

// NodeCore

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           NodeCorePtr, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           NodeCorePtr, 
                           0);

// AttachmentContainer

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           AttachmentContainerPtr, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           AttachmentContainerPtr, 
                           0);

// FieldContainerAttachment

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           AttachmentPtr, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           AttachmentPtr, 
                           0);

// FieldContainerChildNodeCore


OSG_EXPORT_PTR_SFIELD(ChildPointerSField,
                      NodeCorePtr,
                      UnrecordedRefCountPolicy, 
                      1);

OSG_EXPORT_PTR_MFIELD(ChildPointerMField,
                      NodeCorePtr,
                      UnrecordedRefCountPolicy, 
                      1);

// NodeChildNode
OSG_EXPORT_PTR_MFIELD(ChildPointerMField,
                      NodePtr,
                      UnrecordedRefCountPolicy, 
                      1);


// ParentFieldContainer

OSG_SFIELDTYPE_INST(ParentPointerSField,
                    FieldContainerPtr, 
                    NoRefCountPolicy,
                    1);
OSG_MFIELDTYPE_INST(ParentPointerMField, 
                    FieldContainerPtr, 
                    NoRefCountPolicy,
                    1);

OSG_FIELD_DLLEXPORT_DEF3(ParentPointerSField, 
                         FieldContainerPtr, 
                         NoRefCountPolicy,
                         1);
OSG_FIELD_DLLEXPORT_DEF3(ParentPointerMField, 
                         FieldContainerPtr, 
                         NoRefCountPolicy,
                         1);


// ChangeFunctor

OSG_FIELD_DLLEXPORT_DEF1(SField, ChangedFunctorCallback);
OSG_FIELD_DLLEXPORT_DEF1(MField, ChangedFunctorCallback);

OSG_END_NAMESPACE
