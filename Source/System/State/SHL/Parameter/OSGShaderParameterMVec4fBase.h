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
 **     class ShaderParameterMVec4f
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSHADERPARAMETERMVEC4FBASE_H_
#define _OSGSHADERPARAMETERMVEC4FBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGStateDef.h"

#include "OSGBaseTypes.h"

#include "OSGShaderParameter.h" // Parent

#include "OSGVec4fFields.h" // Value type

#include "OSGShaderParameterMVec4fFields.h"

OSG_BEGIN_NAMESPACE

class ShaderParameterMVec4f;

//! \brief ShaderParameterMVec4f Base Class.

class OSG_STATE_DLLMAPPING ShaderParameterMVec4fBase : public ShaderParameter
{
  public:

    typedef ShaderParameter Inherited;
    typedef ShaderParameter ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(ShaderParameterMVec4f);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        ValueFieldId = Inherited::NextFieldId,
        NextFieldId = ValueFieldId + 1
    };

    static const OSG::BitVector ValueFieldMask =
        (TypeTraits<BitVector>::One << ValueFieldId);
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


#ifdef OSG_1_GET_COMPAT
                  MFVec4f             *getMFValue           (void);
#endif
                  MFVec4f             *editMFValue          (void);
            const MFVec4f             *getMFValue           (void) const;


#ifdef OSG_1_GET_COMPAT
                  Vec4f               &getValue           (const UInt32 index);
                  MFVec4f             &getValue          (void);
#endif
                  Vec4f               &editValue          (const UInt32 index);
            const Vec4f               &getValue           (const UInt32 index) const;
                  MFVec4f             &editValue          (void);
            const MFVec4f             &getValue          (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */


    void pushToValue                       (const Vec4f     &value   );
    void insertIntoValue                   (      UInt32     uiIndex,
                                            const Vec4f     &value   );
    void replaceInValue                    (      UInt32     uiIndex,
                                            const Vec4f     &value   );
    void replaceInValue                    (const Vec4f     &pOldElem,
                                            const Vec4f     &pNewElem);
    void removeFromValue                   (      UInt32     uiIndex );
    void removeFromValue                   (const Vec4f     &value   );
    void clearValue                        (      void               );


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

    static  ShaderParameterMVec4fTransitPtr create          (void);
    static  ShaderParameterMVec4fPtr        createEmpty     (void);

    static  ShaderParameterMVec4fTransitPtr createLocal     (
                                              BitVector bFlags = FCLocal::All);

    static  ShaderParameterMVec4fPtr        createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerTransitPtr shallowCopy     (void) const;
    virtual FieldContainerTransitPtr shallowCopyLocal(
                                       BitVector bFlags = FCLocal::All) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static TypeObject _type;

    static void   classDescInserter(TypeObject &oType);
    static Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    MFVec4f           _mfValue;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    ShaderParameterMVec4fBase(void);
    ShaderParameterMVec4fBase(const ShaderParameterMVec4fBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~ShaderParameterMVec4fBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleValue           (void) const;
    EditFieldHandlePtr editHandleValue          (void);

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

            void execSync (      ShaderParameterMVec4fBase *pFrom,
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
    virtual FieldContainerPtr createAspectCopy(void) const;
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

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const ShaderParameterMVec4fBase &source);
};

typedef ShaderParameterMVec4fBase *ShaderParameterMVec4fBaseP;

OSG_END_NAMESPACE

#endif /* _OSGSHADERPARAMETERMVEC4FBASE_H_ */
