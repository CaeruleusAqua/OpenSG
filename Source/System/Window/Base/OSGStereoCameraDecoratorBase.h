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
 **     class StereoCameraDecorator
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSTEREOCAMERADECORATORBASE_H_
#define _OSGSTEREOCAMERADECORATORBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGBaseTypes.h"

#include "OSGCameraDecorator.h" // Parent

#include "OSGBoolFields.h" // LeftEye type
#include "OSGReal32Fields.h" // EyeSeparation type

#include "OSGStereoCameraDecoratorFields.h"

OSG_BEGIN_NAMESPACE

class StereoCameraDecorator;

//! \brief StereoCameraDecorator Base Class.

class OSG_SYSTEM_DLLMAPPING StereoCameraDecoratorBase : public CameraDecorator
{
  public:

    typedef CameraDecorator Inherited;
    typedef CameraDecorator ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    typedef PointerFwdBuilder<CameraDecoratorPtr, 
                              CameraDecoratorConstPtr, 
                              StereoCameraDecorator>::ObjPtr         ObjPtr;
    typedef PointerFwdBuilder<CameraDecoratorPtr, 
                              CameraDecoratorConstPtr, 
                              StereoCameraDecorator>::ObjPtrConst    ObjPtrConst;
    typedef PointerFwdBuilder<CameraDecoratorPtr, 
                              CameraDecoratorConstPtr,
                              StereoCameraDecorator>::ObjConstPtr    ObjConstPtr;
    typedef PointerFwdBuilder<CameraDecoratorPtr, 
                              CameraDecoratorConstPtr,
                              StereoCameraDecorator>::ObjPtrArg      ObjPtrArg;
    typedef PointerFwdBuilder<CameraDecoratorPtr, 
                              CameraDecoratorConstPtr,
                              StereoCameraDecorator>::ObjConstPtrArg ObjConstPtrArg;
    typedef PointerFwdBuilder<CameraDecoratorPtr, 
                              CameraDecoratorConstPtr,
                              StereoCameraDecorator>::ObjPtrConstArg ObjPtrConstArg;

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        LeftEyeFieldId = Inherited::NextFieldId,
        EyeSeparationFieldId = LeftEyeFieldId + 1,
        NextFieldId = EyeSeparationFieldId + 1
    };

    static const OSG::BitVector LeftEyeFieldMask = 
        (TypeTraits<BitVector>::One << LeftEyeFieldId);
    static const OSG::BitVector EyeSeparationFieldMask = 
        (TypeTraits<BitVector>::One << EyeSeparationFieldId);
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
           SFBool *getSFLeftEye(void);
#endif
           SFBool *editSFLeftEye(void);
     const SFBool *getSFLeftEye (void) const;

#ifdef OSG_1_COMPAT
           SFReal32 *getSFEyeSeparation(void);
#endif
           SFReal32 *editSFEyeSeparation(void);
     const SFReal32 *getSFEyeSeparation (void) const;


#ifdef OSG_1_COMPAT
           bool &getLeftEye(void);
#endif
           bool &editLeftEye(void);
     const bool &getLeftEye (void) const;

#ifdef OSG_1_COMPAT
           Real32 &getEyeSeparation(void);
#endif
           Real32 &editEyeSeparation(void);
     const Real32 &getEyeSeparation (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

     void setLeftEye(const bool &value);
     void setEyeSeparation(const Real32 &value);

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

    SFBool _sfLeftEye;
    SFReal32 _sfEyeSeparation;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    StereoCameraDecoratorBase(void);
    StereoCameraDecoratorBase(const StereoCameraDecoratorBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~StereoCameraDecoratorBase(void); 

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
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

            void execSync (      StereoCameraDecoratorBase *pFrom,
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

            void execSync (      StereoCameraDecoratorBase *pFrom,
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
    void operator =(const StereoCameraDecoratorBase &source);
};

typedef StereoCameraDecoratorBase *StereoCameraDecoratorBaseP;

/** Type specific RefPtr type for StereoCameraDecorator. */
typedef RefPtr<StereoCameraDecoratorPtr> StereoCameraDecoratorRefPtr;

typedef osgIF<
    StereoCameraDecoratorBase::isNodeCore,

    CoredNodePtr<StereoCameraDecorator>,
    FieldContainer::attempt_to_create_CoredNodePtr_on_non_NodeCore_FC>::_IRet

        StereoCameraDecoratorNodePtr;

OSG_END_NAMESPACE

#define OSGSTEREOCAMERADECORATORBASE_HEADER_CVSID "@(#)$Id: $"

#endif /* _OSGSTEREOCAMERADECORATORBASE_H_ */
