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
 **     Do not change this file, changes should be done in the derived      **
 **     class GeoProperty
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGGEOPROPERTYBASE_H_
#define _OSGGEOPROPERTYBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGDrawableDef.h"

#include "OSGBaseTypes.h"

#include "OSGStateChunk.h" // Parent

#include "OSGBoolFields.h" // UseVBO type
#include "OSGUInt32Fields.h" // GLId type
#include "OSGInt32Fields.h" // Usage type

#include "OSGGeoPropertyFields.h"

OSG_BEGIN_NAMESPACE

class GeoProperty;

//! \brief GeoProperty Base Class.

class OSG_DRAWABLE_DLLMAPPING GeoPropertyBase : public StateChunk
{
  public:

    typedef StateChunk Inherited;
    typedef StateChunk ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    typedef PointerFwdBuilder<StateChunkPtr, 
                              StateChunkConstPtr, 
                              GeoProperty>::ObjPtr         ObjPtr;
    typedef PointerFwdBuilder<StateChunkPtr, 
                              StateChunkConstPtr, 
                              GeoProperty>::ObjPtrConst    ObjPtrConst;
    typedef PointerFwdBuilder<StateChunkPtr, 
                              StateChunkConstPtr,
                              GeoProperty>::ObjConstPtr    ObjConstPtr;
    typedef PointerFwdBuilder<StateChunkPtr, 
                              StateChunkConstPtr,
                              GeoProperty>::ObjPtrArg      ObjPtrArg;
    typedef PointerFwdBuilder<StateChunkPtr, 
                              StateChunkConstPtr,
                              GeoProperty>::ObjConstPtrArg ObjConstPtrArg;
    typedef PointerFwdBuilder<StateChunkPtr, 
                              StateChunkConstPtr,
                              GeoProperty>::ObjPtrConstArg ObjPtrConstArg;

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        UseVBOFieldId = Inherited::NextFieldId,
        GLIdFieldId = UseVBOFieldId + 1,
        UsageFieldId = GLIdFieldId + 1,
        NextFieldId = UsageFieldId + 1
    };

    static const OSG::BitVector UseVBOFieldMask = 
        (TypeTraits<BitVector>::One << UseVBOFieldId);
    static const OSG::BitVector GLIdFieldMask = 
        (TypeTraits<BitVector>::One << GLIdFieldId);
    static const OSG::BitVector UsageFieldMask = 
        (TypeTraits<BitVector>::One << UsageFieldId);
    static const OSG::BitVector NextFieldMask = 
        (TypeTraits<BitVector>::One << NextFieldId);


    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static FieldContainerType &getClassType   (void); 
    static UInt32              getClassTypeId (void); 
    static UInt16              getClassGroupId(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType         (void); 
    virtual const FieldContainerType &getType         (void) const; 

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */


#ifdef OSG_1_COMPAT
           SFBool *getSFUseVBO(void);
#endif
           SFBool *editSFUseVBO(void);
     const SFBool *getSFUseVBO (void) const;


#ifdef OSG_1_COMPAT
           bool &getUseVBO(void);
#endif
           bool &editUseVBO(void);
     const bool &getUseVBO (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setUseVBO(const bool &value);

    /*! \}                                                                 */
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual UInt32 getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static TypeObject _type;

    static void   classDescInserter(TypeObject &oType);
    static Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFBool _sfUseVBO;
    SFUInt32 _sfGLId;
    SFInt32 _sfUsage;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    GeoPropertyBase(void);
    GeoPropertyBase(const GeoPropertyBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~GeoPropertyBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */


#ifdef OSG_1_COMPAT
           SFUInt32 *getSFGLId(void);
#endif
           SFUInt32 *editSFGLId(void);
     const SFUInt32 *getSFGLId (void) const;

#ifdef OSG_1_COMPAT
           SFInt32 *getSFUsage(void);
#endif
           SFInt32 *editSFUsage(void);
     const SFInt32 *getSFUsage (void) const;


#ifdef OSG_1_COMPAT
           UInt32 &getGLId(void);
#endif
           UInt32 &editGLId(void);
     const UInt32 &getGLId(void) const;

#ifdef OSG_1_COMPAT
           Int32 &getUsage(void);
#endif
           Int32 &editUsage(void);
     const Int32 &getUsage(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setGLId(const UInt32 &value);
     void setUsage(const Int32 &value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#ifdef OSG_MT_FIELDCONTAINERPTR
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo,
                                 UInt32             uiCopyOffset);

            void execSync (      GeoPropertyBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo,
                                 UInt32             uiCopyOffset);
#endif
#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      GeoPropertyBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

#if 0
    virtual void execBeginEditV(ConstFieldMaskArg whichField, 
                                UInt32            uiAspect,
                                UInt32            uiContainerSize);

            void execBeginEdit (ConstFieldMaskArg whichField, 
                                UInt32            uiAspect,
                                UInt32            uiContainerSize);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Aspect Create                            */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const GeoPropertyBase &source);
};

typedef GeoPropertyBase *GeoPropertyBaseP;

/** Type specific RefPtr type for GeoProperty. */
typedef RefPtr<GeoPropertyPtr> GeoPropertyRefPtr;

typedef osgIF<
    GeoPropertyBase::isNodeCore,

    CoredNodePtr<GeoProperty>,
    FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC>::_IRet

        GeoPropertyNodePtr;

OSG_END_NAMESPACE

#define OSGGEOPROPERTYBASE_HEADER_CVSID "@(#)$Id: $"

#endif /* _OSGGEOPROPERTYBASE_H_ */
