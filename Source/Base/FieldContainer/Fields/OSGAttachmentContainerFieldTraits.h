/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                   Copyright (C) 2007 by the OpenSG Forum                  *
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

#ifndef _OSGATTACHMENTCONTAINERFIELDTRAITS_H_
#define _OSGATTACHMENTCONTAINERFIELDTRAITS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGFieldContainerFieldTraits.h"
#include "OSGDataType.h"

#include "OSGContainerForwards.h"

OSG_BEGIN_NAMESPACE

/*! \ingroup GrpBaseFieldContainerFieldTraits
    \ingroup GrpLibOSGBase
 */

template <>
struct FieldTraits<AttachmentContainer *>
    : public FieldTraitsFCPtrBase<AttachmentContainer *>
{
    static  DataType                           _type;
    typedef FieldTraits<AttachmentContainer *>  Self;


    enum             { Convertible = Self::NotConvertible              };

    static OSG_BASE_DLLMAPPING
                 DataType &getType      (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName(void);
};

template<> inline
const Char8 *FieldTraits<AttachmentContainer *, 
                         0                  >::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecAttachmentContainerPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                >::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecAttachmentContainerPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                     >::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakAttachmentContainerPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                     >::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdAttachmentContainerPtr"; 
}



template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                  >::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecAttachmentContainerPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                >::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecAttachmentContainerPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                     >::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakAttachmentContainerPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentContainer *, 
              0                     >::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdAttachmentContainerPtr"; 
}

OSG_END_NAMESPACE

#endif /* _OSGATTACHMENTCONTAINERFIELDTRAITS_H_ */
