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
 **     class ComplexSceneManager
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGCOMPLEXSCENEMANAGERBASE_H_
#define _OSGCOMPLEXSCENEMANAGERBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGContribCSMDef.h"

//#include "OSGBaseTypes.h"

#include "OSGFieldContainer.h" // Parent

#include "OSGFieldContainerFields.h"    // Globals type
#include "OSGCSMDrawManagerFields.h"    // DrawManager type
#include "OSGBaseFields.h"              // StartTime type
#include "OSGSysFields.h"               // ConstantTime type

#include "OSGComplexSceneManagerFields.h"

OSG_BEGIN_NAMESPACE

class ComplexSceneManager;

//! \brief ComplexSceneManager Base Class.

class OSG_CONTRIBCSM_DLLMAPPING ComplexSceneManagerBase : public FieldContainer
{
  public:

    typedef FieldContainer Inherited;
    typedef FieldContainer ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(ComplexSceneManager);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        GlobalsFieldId = Inherited::NextFieldId,
        DrawManagerFieldId = GlobalsFieldId + 1,
        StartTimeFieldId = DrawManagerFieldId + 1,
        TimeScaleFieldId = StartTimeFieldId + 1,
        ConstantTimeStepFieldId = TimeScaleFieldId + 1,
        ConstantTimeFieldId = ConstantTimeStepFieldId + 1,
        PausedFieldId = ConstantTimeFieldId + 1,
        DumpFrameStartFieldId = PausedFieldId + 1,
        NextFieldId = DumpFrameStartFieldId + 1
    };

    static const OSG::BitVector GlobalsFieldMask =
        (TypeTraits<BitVector>::One << GlobalsFieldId);
    static const OSG::BitVector DrawManagerFieldMask =
        (TypeTraits<BitVector>::One << DrawManagerFieldId);
    static const OSG::BitVector StartTimeFieldMask =
        (TypeTraits<BitVector>::One << StartTimeFieldId);
    static const OSG::BitVector TimeScaleFieldMask =
        (TypeTraits<BitVector>::One << TimeScaleFieldId);
    static const OSG::BitVector ConstantTimeStepFieldMask =
        (TypeTraits<BitVector>::One << ConstantTimeStepFieldId);
    static const OSG::BitVector ConstantTimeFieldMask =
        (TypeTraits<BitVector>::One << ConstantTimeFieldId);
    static const OSG::BitVector PausedFieldMask =
        (TypeTraits<BitVector>::One << PausedFieldId);
    static const OSG::BitVector DumpFrameStartFieldMask =
        (TypeTraits<BitVector>::One << DumpFrameStartFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef MFRecFieldContainerPtr MFGlobalsType;
    typedef SFUnrecCSMDrawManagerPtr SFDrawManagerType;
    typedef SFTime            SFStartTimeType;
    typedef SFTime            SFTimeScaleType;
    typedef SFTime            SFConstantTimeStepType;
    typedef SFBool            SFConstantTimeType;
    typedef SFBool            SFPausedType;
    typedef SFBool            SFDumpFrameStartType;

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

            const MFRecFieldContainerPtr *getMFGlobals        (void) const;
                  MFRecFieldContainerPtr *editMFGlobals        (void);
            const SFUnrecCSMDrawManagerPtr *getSFDrawManager    (void) const;
                  SFUnrecCSMDrawManagerPtr *editSFDrawManager    (void);

                  SFTime              *editSFStartTime      (void);
            const SFTime              *getSFStartTime       (void) const;

                  SFTime              *editSFTimeScale      (void);
            const SFTime              *getSFTimeScale       (void) const;

                  SFTime              *editSFConstantTimeStep(void);
            const SFTime              *getSFConstantTimeStep (void) const;

                  SFBool              *editSFConstantTime   (void);
            const SFBool              *getSFConstantTime    (void) const;

                  SFBool              *editSFPaused         (void);
            const SFBool              *getSFPaused          (void) const;

                  SFBool              *editSFDumpFrameStart (void);
            const SFBool              *getSFDumpFrameStart  (void) const;


                  FieldContainer * getGlobals        (const UInt32 index) const;

                  CSMDrawManager * getDrawManager    (void) const;

                  Time                &editStartTime      (void);
            const Time                &getStartTime       (void) const;

                  Time                &editTimeScale      (void);
            const Time                &getTimeScale       (void) const;

                  Time                &editConstantTimeStep(void);
            const Time                &getConstantTimeStep (void) const;

                  bool                &editConstantTime   (void);
                  bool                 getConstantTime    (void) const;

                  bool                &editPaused         (void);
                  bool                 getPaused          (void) const;

                  bool                &editDumpFrameStart (void);
                  bool                 getDumpFrameStart  (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setDrawManager    (CSMDrawManager * const value);
            void setStartTime      (const Time &value);
            void setTimeScale      (const Time &value);
            void setConstantTimeStep(const Time &value);
            void setConstantTime   (const bool value);
            void setPaused         (const bool value);
            void setDumpFrameStart (const bool value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr Field Set                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    void pushToGlobals             (FieldContainer * const value   );
    void assignGlobals            (const MFRecFieldContainerPtr &value);
    void removeFromGlobals (UInt32               uiIndex );
    void removeObjFromGlobals(FieldContainer * const value   );
    void clearGlobals               (void                         );

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
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  ComplexSceneManagerTransitPtr  create          (void);
    static  ComplexSceneManager           *createEmpty     (void);

    static  ComplexSceneManagerTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  ComplexSceneManager            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  ComplexSceneManagerTransitPtr  createDependent  (BitVector bFlags);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerTransitPtr shallowCopy     (void) const;
    virtual FieldContainerTransitPtr shallowCopyLocal(
                                       BitVector bFlags = FCLocal::All) const;
    virtual FieldContainerTransitPtr shallowCopyDependent(
                                                      BitVector bFlags) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    MFRecFieldContainerPtr _mfGlobals;
    SFUnrecCSMDrawManagerPtr _sfDrawManager;
    SFTime            _sfStartTime;
    SFTime            _sfTimeScale;
    SFTime            _sfConstantTimeStep;
    SFBool            _sfConstantTime;
    SFBool            _sfPaused;
    SFBool            _sfDumpFrameStart;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    ComplexSceneManagerBase(void);
    ComplexSceneManagerBase(const ComplexSceneManagerBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ComplexSceneManagerBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const ComplexSceneManager *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleGlobals         (void) const;
    EditFieldHandlePtr editHandleGlobals        (void);
    GetFieldHandlePtr  getHandleDrawManager     (void) const;
    EditFieldHandlePtr editHandleDrawManager    (void);
    GetFieldHandlePtr  getHandleStartTime       (void) const;
    EditFieldHandlePtr editHandleStartTime      (void);
    GetFieldHandlePtr  getHandleTimeScale       (void) const;
    EditFieldHandlePtr editHandleTimeScale      (void);
    GetFieldHandlePtr  getHandleConstantTimeStep (void) const;
    EditFieldHandlePtr editHandleConstantTimeStep(void);
    GetFieldHandlePtr  getHandleConstantTime    (void) const;
    EditFieldHandlePtr editHandleConstantTime   (void);
    GetFieldHandlePtr  getHandlePaused          (void) const;
    EditFieldHandlePtr editHandlePaused         (void);
    GetFieldHandlePtr  getHandleDumpFrameStart  (void) const;
    EditFieldHandlePtr editHandleDumpFrameStart (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      ComplexSceneManagerBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Aspect Create                            */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual FieldContainer *createAspectCopy(
                                    const FieldContainer *pRefAspect) const;
#endif

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
    /*---------------------------------------------------------------------*/

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const ComplexSceneManagerBase &source);
};

typedef ComplexSceneManagerBase *ComplexSceneManagerBaseP;

OSG_END_NAMESPACE

#endif /* _OSGCOMPLEXSCENEMANAGERBASE_H_ */
