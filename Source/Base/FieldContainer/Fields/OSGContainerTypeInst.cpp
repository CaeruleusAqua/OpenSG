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

DataType FieldTraits<FieldContainer          *>::_type(
    "FieldContainerPtr",
    NULL);

DataType FieldTraits<Attachment              *>::_type(
    "AttachmentPtr",
    "FieldContainerPtr");

DataType FieldTraits<AttachmentContainer     *>::_type(
    "AttachmentContainerPtr",
    "FieldContainerPtr");

DataType FieldTraits<NodeCore                *>::_type(
    "NodeCorePtr",
    "AttachmentContainerPtr");

DataType FieldTraits<Node                   *>::_type(
    "NodePtr",
    "AttachmentContainerPtr");

DataType FieldTraits<ChangedFunctorCallback  >::_type(
    "ChangedFunctorCallback",
    NULL);
 
OSG_FIELDTRAITS_GETTYPE   (FieldContainer         *)

OSG_FIELDTRAITS_GETTYPE   (Attachment             *)
OSG_FIELDTRAITS_GETTYPE   (AttachmentContainer    *)
OSG_FIELDTRAITS_GETTYPE   (NodeCore               *)
OSG_FIELDTRAITS_GETTYPE   (Node                   *)
OSG_FIELDTRAITS_GETTYPE   (ChangedFunctorCallback  )

DataType &FieldTraits< FieldContainer *, 1 >::getType(void)
{                                                           
    return FieldTraits<FieldContainer *, 0>::getType();
}

DataType &FieldTraits< NodeCore *, 1 >::getType(void)
{                                                           
    return FieldTraits<NodeCore *, 0>::getType();
}

DataType &FieldTraits< Node *, 1 >::getType(void)
{                                                           
    return FieldTraits<Node *, 0>::getType();
}

// FieldContainer

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           FieldContainer *, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           FieldContainer *, 
                           0);

// Node

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           Node *, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           Node *, 
                           0);

// NodeCore

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           NodeCore *, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           NodeCore *, 
                           0);

// AttachmentContainer

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           AttachmentContainer *, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           AttachmentContainer *, 
                           0);

// FieldContainerAttachment

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField, 
                           Attachment *, 
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField, 
                           Attachment *, 
                           0);

// FieldContainerChildNodeCore


OSG_EXPORT_PTR_SFIELD(ChildPointerSField,
                      NodeCore *,
                      UnrecordedRefCountPolicy, 
                      1);

OSG_EXPORT_PTR_MFIELD(ChildPointerMField,
                      NodeCore *,
                      UnrecordedRefCountPolicy, 
                      1);

// NodeChildNode
OSG_EXPORT_PTR_MFIELD(ChildPointerMField,
                      Node *,
                      UnrecordedRefCountPolicy, 
                      1);


// ParentFieldContainer

OSG_SFIELDTYPE_INST(ParentPointerSField,
                    FieldContainer *, 
                    NoRefCountPolicy,
                    1);
OSG_MFIELDTYPE_INST(ParentPointerMField, 
                    FieldContainer *, 
                    NoRefCountPolicy,
                    1);

OSG_FIELD_DLLEXPORT_DEF3(ParentPointerSField, 
                         FieldContainer *, 
                         NoRefCountPolicy,
                         1);
OSG_FIELD_DLLEXPORT_DEF3(ParentPointerMField, 
                         FieldContainer *, 
                         NoRefCountPolicy,
                         1);


OSG_SFIELDTYPE_INST_X(ParentPointerSField,
                      Node *,
                      NoRefCountPolicy,
                      1);
OSG_MFIELDTYPE_INST_X(ParentPointerMField,
                      Node *,
                      NoRefCountPolicy,
                      1);

OSG_FIELD_DLLEXPORT_DEF3(ParentPointerSField,
                         Node *,
                         NoRefCountPolicy,
                         1);
OSG_FIELD_DLLEXPORT_DEF3(ParentPointerMField,
                         Node *,
                         NoRefCountPolicy,
                         1);

// ChangeFunctor

OSG_FIELD_DLLEXPORT_DEF1(SField, ChangedFunctorCallback);
OSG_FIELD_DLLEXPORT_DEF1(MField, ChangedFunctorCallback);

OSG_END_NAMESPACE
