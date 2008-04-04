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

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGFCDSPARTESTFCFIELDS_H_
#define _OSGFCDSPARTESTFCFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGFieldContainerPtrSField.h"
#include "OSGFieldContainerPtrMField.h"


OSG_BEGIN_NAMESPACE

class FCDSParTestFC;

#if !defined(OSG_DO_DOC) // created as a dummy class, remove to prevent doubles
//! FCDSParTestFCPtr

OSG_GEN_CONTAINERPTR(FCDSParTestFC);

#endif

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)
/*! \ingroup GrpSystemFieldTraits
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif

template <>
struct FieldTraits<FCDSParTestFCPtr> :
    public FieldTraitsFCPtrBase<FCDSParTestFCPtr>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<FCDSParTestFCPtr>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFFCDSParTestFCPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFFCDSParTestFCPtr"; }
};

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getSName<RecordedRefCounts>(void)
{
    return "SFRecFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getSName<UnrecordedRefCounts>(void)
{
    return "SFUnrecFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getSName<WeakRefCounts>(void)
{
    return "SFWeakFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getSName<NoRefCounts>(void)
{
    return "SFUnrefdFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getMName<RecordedRefCounts>(void)
{
    return "MFRecFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getMName<UnrecordedRefCounts>(void)
{
    return "MFUnrecFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getMName<WeakRefCounts>(void)
{
    return "MFWeakFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 0>::getMName<NoRefCounts>(void)
{
    return "MFUnrefdFCDSParTestFCPtr"; 
}

#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsTemplateBase<FCDSParTestFCPtr, 0>
    \hideinhierarchy
 */
#endif


template <>
struct FieldTraits<FCDSParTestFCPtr, 1> :
    public FieldTraitsFCPtrBase<FCDSParTestFCPtr, 1>
{
  private:

  public:

    typedef FieldTraits<FCDSParTestFCPtr, 1>  Self;
    typedef FieldContainerPtr           ParentType;

    static const FieldCardinality eFieldCard = SingleField;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFFCDSParTestFCPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFFCDSParTestFCPtr"; }
};

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getSName<RecordedRefCounts>(void)
{
    return "SFRecFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getSName<UnrecordedRefCounts>(void)
{
    return "SFUnrecFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getSName<WeakRefCounts>(void)
{
    return "SFWeakFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getSName<NoRefCounts>(void)
{
    return "SFUnrefdFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getMName<RecordedRefCounts>(void)
{
    return "MFRecFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getMName<UnrecordedRefCounts>(void)
{
    return "MFUnrecFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getMName<WeakRefCounts>(void)
{
    return "MFWeakFieldContainerChildFCDSParTestFCPtr"; 
}

template<> inline
const Char8 *FieldTraits<FCDSParTestFCPtr, 1>::getMName<NoRefCounts>(void)
{
    return "MFUnrefdFieldContainerChildFCDSParTestFCPtr"; 
}


#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpSystemFieldSingle */

typedef FieldContainerPtrSField<FCDSParTestFCPtr,
                                RecordedRefCounts  > SFRecFCDSParTestFCPtr;
typedef FieldContainerPtrSField<FCDSParTestFCPtr,
                                UnrecordedRefCounts> SFUnrecFCDSParTestFCPtr;
typedef FieldContainerPtrSField<FCDSParTestFCPtr,
                                WeakRefCounts      > SFWeakFCDSParTestFCPtr;
typedef FieldContainerPtrSField<FCDSParTestFCPtr,
                                NoRefCounts        > SFUncountedFCDSParTestFCPtr;
#endif


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpSystemFieldMulti */

typedef FieldContainerPtrMField<FCDSParTestFCPtr,
                                RecordedRefCounts  > MFRecFCDSParTestFCPtr;
typedef FieldContainerPtrMField<FCDSParTestFCPtr,
                                UnrecordedRefCounts> MFUnrecFCDSParTestFCPtr;
typedef FieldContainerPtrMField<FCDSParTestFCPtr,
                                WeakRefCounts      > MFWeakFCDSParTestFCPtr;
typedef FieldContainerPtrMField<FCDSParTestFCPtr,
                                NoRefCounts        > MFUncountedFCDSParTestFCPtr;
#endif



typedef FieldContainerPtrChildSField<
          FCDSParTestFCPtr, 
          UnrecordedRefCounts,
          1                  > SFUnrecFieldContainerChildFCDSParTestFCPtr;

typedef SFUnrecFieldContainerChildFCDSParTestFCPtr 
    SFUnrecChildFCDSParTestFCPtr;


typedef FieldContainerPtrChildMField<
          FCDSParTestFCPtr, 
          UnrecordedRefCounts,
          1                  > MFUnrecFieldContainerChildFCDSParTestFCPtr;

typedef MFUnrecFieldContainerChildFCDSParTestFCPtr
    MFUnrecChildFCDSParTestFCPtr;

OSG_END_NAMESPACE

#endif /* _OSGFCDSPARTESTFCFIELDS_H_ */