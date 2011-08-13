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
 **     class KDTreeIntersectProxyAttachment
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGKDTREEINTERSECTPROXYATTACHMENTBASE_H_
#define _OSGKDTREEINTERSECTPROXYATTACHMENTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGDrawableDef.h"

//#include "OSGBaseTypes.h"

#include "OSGIntersectProxyAttachment.h" // Parent

#include "OSGGeometryFields.h"          // Geometry type
#include "OSGSysFields.h"               // MaxDepth type
#include "OSGIntersectKDTreeNodeFields.h" // TreeNodes type

#include "OSGKDTreeIntersectProxyAttachmentFields.h"

OSG_BEGIN_NAMESPACE

class KDTreeIntersectProxyAttachment;

//! \brief KDTreeIntersectProxyAttachment Base Class.

class OSG_DRAWABLE_DLLMAPPING KDTreeIntersectProxyAttachmentBase : public IntersectProxyAttachment
{
  public:

    typedef IntersectProxyAttachment Inherited;
    typedef IntersectProxyAttachment ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(KDTreeIntersectProxyAttachment);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        GeometryFieldId = Inherited::NextFieldId,
        MaxDepthFieldId = GeometryFieldId + 1,
        TreeNodesFieldId = MaxDepthFieldId + 1,
        TriIndicesFieldId = TreeNodesFieldId + 1,
        NextFieldId = TriIndicesFieldId + 1
    };

    static const OSG::BitVector GeometryFieldMask =
        (TypeTraits<BitVector>::One << GeometryFieldId);
    static const OSG::BitVector MaxDepthFieldMask =
        (TypeTraits<BitVector>::One << MaxDepthFieldId);
    static const OSG::BitVector TreeNodesFieldMask =
        (TypeTraits<BitVector>::One << TreeNodesFieldId);
    static const OSG::BitVector TriIndicesFieldMask =
        (TypeTraits<BitVector>::One << TriIndicesFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecGeometryPtr SFGeometryType;
    typedef SFInt32           SFMaxDepthType;
    typedef MFIntersectKDTreeNode MFTreeNodesType;
    typedef MFUInt32          MFTriIndicesType;

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

            const SFUnrecGeometryPtr  *getSFGeometry       (void) const;
                  SFUnrecGeometryPtr  *editSFGeometry       (void);

                  SFInt32             *editSFMaxDepth       (void);
            const SFInt32             *getSFMaxDepth        (void) const;


                  Geometry * getGeometry       (void) const;

                  Int32               &editMaxDepth       (void);
                  Int32                getMaxDepth        (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setGeometry       (Geometry * const value);
            void setMaxDepth       (const Int32 value);

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

    virtual UInt32 getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  KDTreeIntersectProxyAttachmentTransitPtr  create          (void);
    static  KDTreeIntersectProxyAttachment           *createEmpty     (void);

    static  KDTreeIntersectProxyAttachmentTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  KDTreeIntersectProxyAttachment            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  KDTreeIntersectProxyAttachmentTransitPtr  createDependent  (BitVector bFlags);

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

    SFUnrecGeometryPtr _sfGeometry;
    SFInt32           _sfMaxDepth;
    MFIntersectKDTreeNode _mfTreeNodes;
    MFUInt32          _mfTriIndices;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    KDTreeIntersectProxyAttachmentBase(void);
    KDTreeIntersectProxyAttachmentBase(const KDTreeIntersectProxyAttachmentBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~KDTreeIntersectProxyAttachmentBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const KDTreeIntersectProxyAttachment *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

    GetFieldHandlePtr  getHandleGeometry        (void) const;
    EditFieldHandlePtr editHandleGeometry       (void);
    GetFieldHandlePtr  getHandleMaxDepth        (void) const;
    EditFieldHandlePtr editHandleMaxDepth       (void);
    GetFieldHandlePtr  getHandleTreeNodes       (void) const;
    EditFieldHandlePtr editHandleTreeNodes      (void);
    GetFieldHandlePtr  getHandleTriIndices      (void) const;
    EditFieldHandlePtr editHandleTriIndices     (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */


                  MFIntersectKDTreeNode *editMFTreeNodes      (void);
            const MFIntersectKDTreeNode *getMFTreeNodes       (void) const;

                  MFUInt32            *editMFTriIndices     (void);
            const MFUInt32            *getMFTriIndices      (void) const;


                  IntersectKDTreeNode &editTreeNodes      (const UInt32 index);
            const IntersectKDTreeNode &getTreeNodes       (const UInt32 index) const;

                  UInt32              &editTriIndices     (const UInt32 index);
                  UInt32               getTriIndices      (const UInt32 index) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

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

            void execSync (      KDTreeIntersectProxyAttachmentBase *pFrom,
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
    void operator =(const KDTreeIntersectProxyAttachmentBase &source);
};

typedef KDTreeIntersectProxyAttachmentBase *KDTreeIntersectProxyAttachmentBaseP;

OSG_END_NAMESPACE

#endif /* _OSGKDTREEINTERSECTPROXYATTACHMENTBASE_H_ */
