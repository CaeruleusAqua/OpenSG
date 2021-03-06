/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: Alexander Lang                                                   *
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
 **     class DepthPeelingStageData
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGDEPTHPEELINGSTAGEDATABASE_H_
#define _OSGDEPTHPEELINGSTAGEDATABASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGEffectGroupsDef.h"

//#include "OSGBaseTypes.h"

#include "OSGStageData.h" // Parent

#include "OSGSysFields.h"               // Width type
#include "OSGBackgroundFields.h"        // Background type
#include "OSGFrameBufferObjectFields.h" // PeelPingFBO type
#include "OSGChunkMaterialFields.h"     // BlendMaterial type
#include "OSGDepthChunkFields.h"        // DepthChunk type
#include "OSGShaderProgramVariableChunkFields.h" // SpvIsPeelChunk type

#include "OSGDepthPeelingStageDataFields.h"

OSG_BEGIN_NAMESPACE


class DepthPeelingStageData;

//! \brief DepthPeelingStageData Base Class.

class OSG_EFFECTGROUPS_DLLMAPPING DepthPeelingStageDataBase : public StageData
{
  public:

    typedef StageData Inherited;
    typedef StageData ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(DepthPeelingStageData);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        WidthFieldId = Inherited::NextFieldId,
        HeightFieldId = WidthFieldId + 1,
        BackgroundFieldId = HeightFieldId + 1,
        PeelPingFBOFieldId = BackgroundFieldId + 1,
        PeelPongFBOFieldId = PeelPingFBOFieldId + 1,
        BlendFBOFieldId = PeelPongFBOFieldId + 1,
        BlendMaterialFieldId = BlendFBOFieldId + 1,
        BlendFinalMaterialFieldId = BlendMaterialFieldId + 1,
        PeelPingMaterialFieldId = BlendFinalMaterialFieldId + 1,
        PeelPongMaterialFieldId = PeelPingMaterialFieldId + 1,
        DepthChunkFieldId = PeelPongMaterialFieldId + 1,
        SpvIsPeelChunkFieldId = DepthChunkFieldId + 1,
        SpvIsInitialChunkFieldId = SpvIsPeelChunkFieldId + 1,
        NextFieldId = SpvIsInitialChunkFieldId + 1
    };

    static const OSG::BitVector WidthFieldMask =
        (TypeTraits<BitVector>::One << WidthFieldId);
    static const OSG::BitVector HeightFieldMask =
        (TypeTraits<BitVector>::One << HeightFieldId);
    static const OSG::BitVector BackgroundFieldMask =
        (TypeTraits<BitVector>::One << BackgroundFieldId);
    static const OSG::BitVector PeelPingFBOFieldMask =
        (TypeTraits<BitVector>::One << PeelPingFBOFieldId);
    static const OSG::BitVector PeelPongFBOFieldMask =
        (TypeTraits<BitVector>::One << PeelPongFBOFieldId);
    static const OSG::BitVector BlendFBOFieldMask =
        (TypeTraits<BitVector>::One << BlendFBOFieldId);
    static const OSG::BitVector BlendMaterialFieldMask =
        (TypeTraits<BitVector>::One << BlendMaterialFieldId);
    static const OSG::BitVector BlendFinalMaterialFieldMask =
        (TypeTraits<BitVector>::One << BlendFinalMaterialFieldId);
    static const OSG::BitVector PeelPingMaterialFieldMask =
        (TypeTraits<BitVector>::One << PeelPingMaterialFieldId);
    static const OSG::BitVector PeelPongMaterialFieldMask =
        (TypeTraits<BitVector>::One << PeelPongMaterialFieldId);
    static const OSG::BitVector DepthChunkFieldMask =
        (TypeTraits<BitVector>::One << DepthChunkFieldId);
    static const OSG::BitVector SpvIsPeelChunkFieldMask =
        (TypeTraits<BitVector>::One << SpvIsPeelChunkFieldId);
    static const OSG::BitVector SpvIsInitialChunkFieldMask =
        (TypeTraits<BitVector>::One << SpvIsInitialChunkFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFInt32           SFWidthType;
    typedef SFInt32           SFHeightType;
    typedef SFUnrecBackgroundPtr SFBackgroundType;
    typedef SFUnrecFrameBufferObjectPtr SFPeelPingFBOType;
    typedef SFUnrecFrameBufferObjectPtr SFPeelPongFBOType;
    typedef SFUnrecFrameBufferObjectPtr SFBlendFBOType;
    typedef SFUnrecChunkMaterialPtr SFBlendMaterialType;
    typedef SFUnrecChunkMaterialPtr SFBlendFinalMaterialType;
    typedef SFUnrecChunkMaterialPtr SFPeelPingMaterialType;
    typedef SFUnrecChunkMaterialPtr SFPeelPongMaterialType;
    typedef SFUnrecDepthChunkPtr SFDepthChunkType;
    typedef SFUnrecShaderProgramVariableChunkPtr SFSpvIsPeelChunkType;
    typedef SFUnrecShaderProgramVariableChunkPtr SFSpvIsInitialChunkType;

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


                  SFInt32             *editSFWidth          (void);
            const SFInt32             *getSFWidth           (void) const;

                  SFInt32             *editSFHeight         (void);
            const SFInt32             *getSFHeight          (void) const;
            const SFUnrecBackgroundPtr *getSFBackground     (void) const;
                  SFUnrecBackgroundPtr *editSFBackground     (void);
            const SFUnrecFrameBufferObjectPtr *getSFPeelPingFBO    (void) const;
                  SFUnrecFrameBufferObjectPtr *editSFPeelPingFBO    (void);
            const SFUnrecFrameBufferObjectPtr *getSFPeelPongFBO    (void) const;
                  SFUnrecFrameBufferObjectPtr *editSFPeelPongFBO    (void);
            const SFUnrecFrameBufferObjectPtr *getSFBlendFBO       (void) const;
                  SFUnrecFrameBufferObjectPtr *editSFBlendFBO       (void);
            const SFUnrecChunkMaterialPtr *getSFBlendMaterial  (void) const;
                  SFUnrecChunkMaterialPtr *editSFBlendMaterial  (void);
            const SFUnrecChunkMaterialPtr *getSFBlendFinalMaterial(void) const;
                  SFUnrecChunkMaterialPtr *editSFBlendFinalMaterial(void);
            const SFUnrecChunkMaterialPtr *getSFPeelPingMaterial(void) const;
                  SFUnrecChunkMaterialPtr *editSFPeelPingMaterial(void);
            const SFUnrecChunkMaterialPtr *getSFPeelPongMaterial(void) const;
                  SFUnrecChunkMaterialPtr *editSFPeelPongMaterial(void);
            const SFUnrecDepthChunkPtr *getSFDepthChunk     (void) const;
                  SFUnrecDepthChunkPtr *editSFDepthChunk     (void);
            const SFUnrecShaderProgramVariableChunkPtr *getSFSpvIsPeelChunk (void) const;
                  SFUnrecShaderProgramVariableChunkPtr *editSFSpvIsPeelChunk (void);
            const SFUnrecShaderProgramVariableChunkPtr *getSFSpvIsInitialChunk(void) const;
                  SFUnrecShaderProgramVariableChunkPtr *editSFSpvIsInitialChunk(void);


                  Int32               &editWidth          (void);
                  Int32                getWidth           (void) const;

                  Int32               &editHeight         (void);
                  Int32                getHeight          (void) const;

                  Background * getBackground     (void) const;

                  FrameBufferObject * getPeelPingFBO    (void) const;

                  FrameBufferObject * getPeelPongFBO    (void) const;

                  FrameBufferObject * getBlendFBO       (void) const;

                  ChunkMaterial * getBlendMaterial  (void) const;

                  ChunkMaterial * getBlendFinalMaterial(void) const;

                  ChunkMaterial * getPeelPingMaterial(void) const;

                  ChunkMaterial * getPeelPongMaterial(void) const;

                  DepthChunk * getDepthChunk     (void) const;

                  ShaderProgramVariableChunk * getSpvIsPeelChunk (void) const;

                  ShaderProgramVariableChunk * getSpvIsInitialChunk(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setWidth          (const Int32 value);
            void setHeight         (const Int32 value);
            void setBackground     (Background * const value);
            void setPeelPingFBO    (FrameBufferObject * const value);
            void setPeelPongFBO    (FrameBufferObject * const value);
            void setBlendFBO       (FrameBufferObject * const value);
            void setBlendMaterial  (ChunkMaterial * const value);
            void setBlendFinalMaterial(ChunkMaterial * const value);
            void setPeelPingMaterial(ChunkMaterial * const value);
            void setPeelPongMaterial(ChunkMaterial * const value);
            void setDepthChunk     (DepthChunk * const value);
            void setSpvIsPeelChunk (ShaderProgramVariableChunk * const value);
            void setSpvIsInitialChunk(ShaderProgramVariableChunk * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr Field Set                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual SizeT  getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  DepthPeelingStageDataTransitPtr  create          (void);
    static  DepthPeelingStageData           *createEmpty     (void);

    static  DepthPeelingStageDataTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  DepthPeelingStageData            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  DepthPeelingStageDataTransitPtr  createDependent  (BitVector bFlags);

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

    SFInt32           _sfWidth;
    SFInt32           _sfHeight;
    SFUnrecBackgroundPtr _sfBackground;
    SFUnrecFrameBufferObjectPtr _sfPeelPingFBO;
    SFUnrecFrameBufferObjectPtr _sfPeelPongFBO;
    SFUnrecFrameBufferObjectPtr _sfBlendFBO;
    SFUnrecChunkMaterialPtr _sfBlendMaterial;
    SFUnrecChunkMaterialPtr _sfBlendFinalMaterial;
    SFUnrecChunkMaterialPtr _sfPeelPingMaterial;
    SFUnrecChunkMaterialPtr _sfPeelPongMaterial;
    SFUnrecDepthChunkPtr _sfDepthChunk;
    SFUnrecShaderProgramVariableChunkPtr _sfSpvIsPeelChunk;
    SFUnrecShaderProgramVariableChunkPtr _sfSpvIsInitialChunk;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    DepthPeelingStageDataBase(void);
    DepthPeelingStageDataBase(const DepthPeelingStageDataBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~DepthPeelingStageDataBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const DepthPeelingStageData *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

     GetFieldHandlePtr  getHandleWidth           (void) const;
     EditFieldHandlePtr editHandleWidth          (void);
     GetFieldHandlePtr  getHandleHeight          (void) const;
     EditFieldHandlePtr editHandleHeight         (void);
     GetFieldHandlePtr  getHandleBackground      (void) const;
     EditFieldHandlePtr editHandleBackground     (void);
     GetFieldHandlePtr  getHandlePeelPingFBO     (void) const;
     EditFieldHandlePtr editHandlePeelPingFBO    (void);
     GetFieldHandlePtr  getHandlePeelPongFBO     (void) const;
     EditFieldHandlePtr editHandlePeelPongFBO    (void);
     GetFieldHandlePtr  getHandleBlendFBO        (void) const;
     EditFieldHandlePtr editHandleBlendFBO       (void);
     GetFieldHandlePtr  getHandleBlendMaterial   (void) const;
     EditFieldHandlePtr editHandleBlendMaterial  (void);
     GetFieldHandlePtr  getHandleBlendFinalMaterial (void) const;
     EditFieldHandlePtr editHandleBlendFinalMaterial(void);
     GetFieldHandlePtr  getHandlePeelPingMaterial (void) const;
     EditFieldHandlePtr editHandlePeelPingMaterial(void);
     GetFieldHandlePtr  getHandlePeelPongMaterial (void) const;
     EditFieldHandlePtr editHandlePeelPongMaterial(void);
     GetFieldHandlePtr  getHandleDepthChunk      (void) const;
     EditFieldHandlePtr editHandleDepthChunk     (void);
     GetFieldHandlePtr  getHandleSpvIsPeelChunk  (void) const;
     EditFieldHandlePtr editHandleSpvIsPeelChunk (void);
     GetFieldHandlePtr  getHandleSpvIsInitialChunk (void) const;
     EditFieldHandlePtr editHandleSpvIsInitialChunk(void);

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

            void execSync (      DepthPeelingStageDataBase *pFrom,
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
    void operator =(const DepthPeelingStageDataBase &source);
};

typedef DepthPeelingStageDataBase *DepthPeelingStageDataBaseP;

OSG_END_NAMESPACE

#endif /* _OSGDEPTHPEELINGSTAGEDATABASE_H_ */
