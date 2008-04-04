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

#ifndef _OSGFIELDCONTAINERFIELDTRAITS_H_
#define _OSGFIELDCONTAINERFIELDTRAITS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGFieldTraits.h"
#include "OSGDataType.h"

#include "OSGContainerForwards.h"
#include "OSGFieldContainerFactory.h"
#include "OSGContainerPtrFuncs.h"
#include "OSGRefCountPolicies.h"

OSG_BEGIN_NAMESPACE

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)

#ifdef OSG_DOC_FILES_IN_MODULE
/*! \file 
    \ingroup 
    \ingroup 
*/
#endif

template<class ValueT, Int32 iNamespace = 0>
struct FieldTraitsFCPtrBase : 
    public FieldTraitsTemplateBase<ValueT, iNamespace>
{
    static const bool bIsPointerField = true;

    typedef FieldContainerPtr ParentContainerPtr;

    static const Char8 *getSPName(void)
    {
        return "FieldContainerPtrSFieldBase";   
    }

    static const Char8 *getMPName(void) 
    {
        return "FieldContainerPtrMFieldBase";   
    }

    static UInt32 getBinSize(const FieldContainerPtr &)
    {
        return sizeof(UInt32);
    }

    static UInt32 getBinSize(const FieldContainerPtr *,
                                   UInt32             uiNumObjects)
    {
        return sizeof(UInt32) * uiNumObjects;
    }

    static void copyToBin(      BinaryDataHandler &pMem, 
                          const FieldContainerPtr &pObject)
    {
        UInt32 containerId;

        if(pObject == NullFC)
        {
            // containerId=0 indicates an Null Ptr
            containerId = 0;
        }
        else
        {
            containerId = getContainerId(pObject);
        }

        pMem.putValue(containerId);
    }

    static void copyToBin(      BinaryDataHandler &pMem, 
                          const FieldContainerPtr *pObjectStore,
                                UInt32             uiNumObjects)
    {
        for(UInt32 i = 0; i < uiNumObjects; i++)
        {
            copyToBin(pMem, pObjectStore[i]);
        }
    }

    static void copyFromBin(BinaryDataHandler &pMem, 
                            FieldContainerPtr &pObject)
    {
        UInt32 containerId;

        pMem.getValue(containerId);

        if(0 != containerId)
        {
            pObject = 
                FieldContainerFactory::the()->getMappedContainer(containerId);
        }
        else
        {
            pObject = NullFC;
        }
    }

    static void copyFromBin(BinaryDataHandler &pMem, 
                            FieldContainerPtr *pObjectStore,
                            UInt32             uiNumObjects)
    {
        for(UInt32 i = 0; i < uiNumObjects; i++)
        {
            copyFromBin(pMem, pObjectStore[i]);
        }
    }   
};

/*! \ingroup 
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif

template <>
struct FieldTraits<FieldContainerPtr> : 
    public FieldTraitsFCPtrBase<FieldContainerPtr>
{
  private:

    static  DataType                       _type;

  public:

    static const bool bIsPointerField = true;

    typedef FieldTraits<FieldContainerPtr>  Self;


    enum             { Convertible = Self::NotConvertible                 };

    static OSG_SYSTEM_DLLMAPPING
                 DataType &getType (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName(void);
};


template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getSName<RecordedRefCounts>(void)
{
    return "SFFieldContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getSName<UnrecordedRefCounts>(void)
{
    return "SFUnrecFieldContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getSName<WeakRefCounts>(void)
{
    return "SFWeakFieldContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getSName<NoRefCounts>(void)
{
    return "SFUnrefdFieldContainerPtr"; 
}



template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0               >::getMName<RecordedRefCounts>(void)
{
    return "MFFieldContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getMName<UnrecordedRefCounts>(void)
{
    return "MFUnrecFieldContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getMName<WeakRefCounts>(void)
{
    return "MFWeakFieldContainerPtr"; 
}

template<> inline
const Char8 *FieldTraits<FieldContainerPtr, 
                         0                >::getMName<NoRefCounts>(void)
{
    return "MFUnrefdFieldContainerPtr"; 
}


#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsTemplateBase<FieldContainerPtr> */
/*! \hideinhierarchy                         */
#endif


/*! \ingroup 
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif
template <>
struct FieldTraits<FieldContainerPtr, 1> : 
    public FieldTraitsFCPtrBase<FieldContainerPtr, 1>
{
  private:

    static  DataType                                _type;

  public:

    static const bool bIsPointerField = true;

    typedef FieldTraits<FieldContainerPtr, 1>        Self;


    enum             { Convertible = Self::NotConvertible };
    
    static OSG_SYSTEM_DLLMAPPING
                 DataType &getType (void);

    static const Char8    *getSName(void) 
    {
        return "SFParentFieldContainerPtr"; 
    }

    static const Char8    *getMName(void) 
    { 
        return "MFParentFieldContainerPtr"; 
    }
};

#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsTemplateBase<ParentFieldContainerPtr> */
/*! \hideinhierarchy                         */
#endif

#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)


OSG_END_NAMESPACE

#endif /* _OSGFIELDCONTAINERFIELDTRAITS_H_ */
