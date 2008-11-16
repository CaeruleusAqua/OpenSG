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


#ifndef _OSGSHADEREXECUTABLECHUNKFIELDS_H_
#define _OSGSHADEREXECUTABLECHUNKFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class ShaderExecutableChunk;

#if !defined(OSG_DO_DOC) // created as a dummy class, remove to prevent doubles
//! ShaderExecutableChunkPtr

OSG_GEN_CONTAINERPTR(ShaderExecutableChunk);

#endif

#if !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)
/*! \ingroup GrpSystemFieldTraits
 */
#if !defined(OSG_DOC_DEV_TRAITS)
/*! \hideinhierarchy */
#endif

template <>
struct FieldTraits<ShaderExecutableChunk *> :
    public FieldTraitsFCPtrBase<ShaderExecutableChunk *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<ShaderExecutableChunk *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFShaderExecutableChunkPtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFShaderExecutableChunkPtr"; }
};

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakShaderExecutableChunkPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderExecutableChunk *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdShaderExecutableChunkPtr"; 
}

#if !defined(OSG_DOC_DEV_TRAITS)
/*! \class  FieldTraitsTemplateBase<ShaderExecutableChunkPtr, 0>
    \hideinhierarchy
 */
#endif

#endif // !defined(OSG_DO_DOC) || (OSG_DOC_LEVEL >= 3)


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpSystemFieldSingle */

typedef PointerSField<ShaderExecutableChunk *,
                      RecordedRefCountPolicy  > SFRecShaderExecutableChunkPtr;
typedef PointerSField<ShaderExecutableChunk *,
                      UnrecordedRefCountPolicy> SFUnrecShaderExecutableChunkPtr;
typedef PointerSField<ShaderExecutableChunk *,
                      WeakRefCountPolicy      > SFWeakShaderExecutableChunkPtr;
typedef PointerSField<ShaderExecutableChunk *,
                      NoRefCountPolicy        > SFUncountedShaderExecutableChunkPtr;
#endif


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_FIELD_TYPEDEFS)
/*! \ingroup GrpSystemFieldMulti */

typedef PointerMField<ShaderExecutableChunk *,
                      RecordedRefCountPolicy  > MFRecShaderExecutableChunkPtr;
typedef PointerMField<ShaderExecutableChunk *,
                      UnrecordedRefCountPolicy> MFUnrecShaderExecutableChunkPtr;
typedef PointerMField<ShaderExecutableChunk *,
                      WeakRefCountPolicy      > MFWeakShaderExecutableChunkPtr;
typedef PointerMField<ShaderExecutableChunk *,
                      NoRefCountPolicy        > MFUncountedShaderExecutableChunkPtr;
#endif


OSG_END_NAMESPACE

#endif /* _OSGSHADEREXECUTABLECHUNKFIELDS_H_ */