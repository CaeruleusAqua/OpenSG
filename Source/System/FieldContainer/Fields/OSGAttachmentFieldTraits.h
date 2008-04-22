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

#ifndef _OSGATTACHMENTFIELDTRAITS_H_
#define _OSGATTACHMENTFIELDTRAITS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGFieldContainerFieldTraits.h"
#include "OSGDataType.h"

#include "OSGContainerForwards.h"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)

#ifdef OSG_DOC_FILES_IN_MODULE
/*! \file 
    \ingroup 
    \ingroup 
*/
#endif

/*! \ingroup 
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif

template <>
struct FieldTraits<AttachmentPtr>
    : public FieldTraitsFCPtrBase<AttachmentPtr>
{
  private:

    static  DataType                                  _type;

  public:

    typedef FieldTraits<AttachmentPtr>  Self;


    enum             { Convertible = Self::NotConvertible              };

    static OSG_SYSTEM_DLLMAPPING
                 DataType &getType      (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName(void);
};


template<> inline
const Char8 *FieldTraits<AttachmentPtr, 
                         0            >::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecAttachmentPtr"; 
}

template<> inline
const Char8 *
    FieldTraits<AttachmentPtr, 
                0            >::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecAttachmentPtr"; 
}

template<> inline
const Char8 *FieldTraits<AttachmentPtr, 
                         0            >::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakAttachmentPtr"; 
}

template<> inline
const Char8 *FieldTraits<AttachmentPtr, 
                         0                >::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdAttachmentPtr"; 
}



template<> inline
const Char8 *FieldTraits<AttachmentPtr, 
                         0            >::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecAttachmentPtr"; 
}

template<> inline
const Char8 *
  FieldTraits<AttachmentPtr, 
              0            >::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecAttachmentPtr"; 
}

template<> inline
const Char8 *FieldTraits<AttachmentPtr, 
                         0            >::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakAttachmentPtr"; 
}

template<> inline
const Char8 *FieldTraits<AttachmentPtr, 
                         0                >::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdAttachmentPtr"; 
}

#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsTemplateBase<AttachmentPtr>
    \hideinhierarchy
 */
#endif

#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)

OSG_END_NAMESPACE

#endif /* _OSGATTACHMENTFIELDTRAITS_H_ */
