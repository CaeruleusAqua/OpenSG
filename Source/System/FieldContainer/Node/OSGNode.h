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

#ifndef _OSGNODE_H_
#define _OSGNODE_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGReflexiveContainer.h"
#include "OSGMatrix.h"
#include "OSGFieldContainer.h"
#include "OSGAttachmentContainer.h"

#include "OSGDynamicVolumeFields.h"
#include "OSGUInt32Fields.h"

#include "OSGNodeFields.h"
#include "OSGNodeCoreFields.h"
#include "OSGContainerPtrFuncs.h"
#include "OSGFieldContainerFactory.h"

#include <boost/assign/list_of.hpp>

OSG_BEGIN_NAMESPACE

/**
 * A Node in OpenSG is a node in the graph.
 *
 * Nodes are responsible for holding children nodes and a link to their parent node.
 *
 * \ingroup baselib
 */
class OSG_SYSTEM_DLLMAPPING Node : public AttachmentContainer
{
    /*==========================  PUBLIC  =================================*/

  public:

    typedef AttachmentContainer                    Inherited;
    typedef AttachmentContainer                    ParentContainerx;

    typedef PointerBuilder<Node>::ObjPtr           ObjPtr;
    typedef PointerBuilder<Node>::ObjPtrConst      ObjPtrConst;
    typedef PointerBuilder<Node>::ObjConstPtr      ObjConstPtr;
    typedef PointerBuilder<Node>::ObjConstPtrConst ObjConstPtrConst;

    typedef PointerBuilder<Node>::ObjPtrArg        ObjPtrArg;
    typedef PointerBuilder<Node>::ObjPtrConstArg   ObjPtrConstArg;
    typedef PointerBuilder<Node>::ObjConstPtrArg   ObjConstPtrArg;

    typedef Inherited::TypeObject                  TypeObject;

    typedef Node                                   Self;

    OSG_RC_FIRST_FIELD_DECL(Volume            );

    OSG_RC_FIELD_DECL      (TravMask, Volume  );
    OSG_RC_FIELD_DECL      (Parent,   TravMask);
    OSG_RC_FIELD_DECL      (Core,     Parent  );
    OSG_RC_FIELD_DECL      (Children, Core    );

    OSG_RC_LAST_FIELD_DECL (Children          );

    static const BitVector bLocalFieldMask   = (VolumeFieldMask    |
                                                TravMaskFieldMask  |
                                                ParentFieldMask    |
                                                ChildrenFieldMask  |
                                                CoreFieldMask      );

    static const BitVector bInvLocalFieldMask = ~bLocalFieldMask;

    /*---------------------------------------------------------------------*/
    /*! \name                      dcast                                   */
    /*! \{                                                                 */

    OSG_FIELD_CONTAINER_DECL;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name        General Fieldcontainer Declaration                    */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    NodeCorePtr getCore(void                    );
    NodeCorePtr getCore(void                    ) const;

    void        setCore(NodeCorePtrConstArg core);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructor                                 */
    /*! \{                                                                 */

    NodePtr getParent(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Helper                                    */
    /*! \{                                                                 */

    UInt32  getNChildren  (void                      ) const;

    void    addChild      (NodePtrConstArg childP    );

    void    insertChild   (UInt32          childIndex,
                           NodePtrConstArg childP    );

    void    replaceChild  (UInt32          childIndex,
                           NodePtrConstArg childP    );

    bool    replaceChildBy(NodePtrConstArg childP,
                           NodePtrConstArg newChildP );

    Int32   findChild     (NodePtrConstArg childP    ) const;

    void    subChild      (NodePtrConstArg childP    );
    void    subChild      (UInt32          childIndex);

    NodePtr getChild      (UInt32          childIndex);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Get                                     */
    /*! \{                                                                 */

    void   setTravMask(UInt32 uiMask);
    UInt32 getTravMask(void         ) const;

#ifdef OSG_1_COMPAT
    bool   getActive  (void         ) const;
    void   setActive  (bool      val);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Set                                     */
    /*! \{                                                                 */

    virtual void pushToField     (      FieldContainerPtrConstArg pNewElement,
                                  const UInt32                    uiFieldId  );

    virtual void insertIntoMField(const UInt32                    uiIndex,
                                        FieldContainerPtrConstArg pNewElement,
                                  const UInt32                    uiFieldId  );

    virtual void replaceInMField (const UInt32                    uiIndex,
                                        FieldContainerPtrConstArg pNewElement,
                                  const UInt32                    uiFieldId  );

    virtual void replaceInMField (      FieldContainerPtrConstArg pOldElement,
                                        FieldContainerPtrConstArg pNewElement,
                                  const UInt32                    uiFieldId  );

    virtual void removeFromMField(const UInt32                    uiIndex,
                                  const UInt32                    whichField );

    virtual void removeFromMField(      FieldContainerPtrConstArg pElement,
                                  const UInt32                    whichField );

    virtual void clearField      (const UInt32                    whichField );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   your_category                              */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Container Access                             */
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
    /*! \name                   your_operators                             */
    /*! \{                                                                 */

    Matrixr getToWorld(void           );

    void    getToWorld(Matrixr &result);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Assignment                                */
    /*! \{                                                                 */

#ifdef OSG_1_COMPAT
            DynamicVolume &getVolume       (bool update = false  );
#endif

            DynamicVolume &editVolume      (bool update = false  );

    const   DynamicVolume &getVolume       (void                 ) const;

            void           getWorldVolume  (DynamicVolume &result);

            void           updateVolume    (void                 );

    virtual void           invalidateVolume(void                 );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Comparison                                */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                        Dump                                  */
    /*! \{                                                                 */

    virtual void dump(      UInt32    uiIndent = 0,
                      const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                        Dump                                  */
    /*! \{                                                                 */

          SFDynamicVolume *editSFVolume  (void);
    const SFDynamicVolume *getSFVolume   (void) const;

          SFUInt32        *editSFTravMask(void);
    const SFUInt32        *getSFTravMask (void) const;

    const SFNodePtr       *getSFParent   (void) const;
    const SFNodeCorePtr   *getSFCore     (void) const;
    const MFNodePtr       *getMFChildren (void) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                  Type information                            */
    /*! \{                                                                 */

    static TypeObject _type;

    static void   classDescInserter(TypeObject &oType);
    static Char8 *getClassname     (void             );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFDynamicVolume _sfVolume;

    SFUInt32        _sfTravMask;

    SFNodePtr       _sfParent;
    MFNodePtr       _mfChildren;

    SFNodeCorePtr   _sfCore;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Member                                  */
    /*! \{                                                                 */

    Node(void);
    Node(const Node &source);

    virtual ~Node(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Changed                                 */
    /*! \{                                                                 */

    void setParent(const NodePtr &parent);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   MT Destruction                             */
    /*! \{                                                                 */

    NodePtr getPtr(void);

#ifdef OSG_MT_CPTR_ASPECT
    virtual ObjPtr createAspectCopy(void) const;
#endif

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

            void execSync (      Node              *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo,
                                 UInt32             uiCopyOffset);
#endif
#ifdef OSG_MT_CPTR_ASPECT
    OSG_SYSTEM_DLLMAPPING
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

    OSG_SYSTEM_DLLMAPPING
            void execSync (      Node              *pFrom,
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
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    template<class ContainerFactoryT>
    friend struct CPtrConstructionFunctions;

    template<class ContainerFactoryT>
    friend struct PtrConstructionFunctions;

    friend struct PointerFuncs;
    friend struct CPointerFuncs;

    /*!\brief prohibit default function (move to 'public' if needed) */
    void operator =(const Node &source);
};

typedef Node::ObjPtr           NodePtr;
typedef Node::ObjPtrConst      NodePtrConst;
typedef Node::ObjConstPtr      NodeConstPtr;
typedef Node::ObjConstPtrConst NodeConstPtrConst;

typedef Node::ObjPtrArg        NodePtrArg;
typedef Node::ObjPtrConstArg   NodePtrConstArg;
typedef Node::ObjConstPtrArg   NodeConstPtrArg;

typedef RefPtr<NodePtr>        NodeRefPtr;

OSG_SYSTEM_DLLMAPPING
NodePtr
cloneTree(      NodePtrConstArg                          rootNode,
          const std::vector<std::string>                &cloneTypeNames,
          const std::vector<std::string>                &ignoreTypeNames   =
              std::vector<std::string>(),
          const std::vector<std::string>                &cloneGroupNames   =
              std::vector<std::string>(),
          const std::vector<std::string>                &ignoreGroupNames  =
              std::vector<std::string>()                                     );

OSG_SYSTEM_DLLMAPPING
NodePtr
cloneTree(      NodePtrConstArg                          rootNode,
          const std::vector<UInt16>                     &cloneGroupIds,
          const std::vector<UInt16>                     &ignoreGroupIds    =
              std::vector<UInt16>()                                          );

OSG_SYSTEM_DLLMAPPING
NodePtr
cloneTree(      NodePtrConstArg                          rootNode,
          const std::string                             &cloneTypesString,
          const std::string                             &ignoreTypesString =
              std::string()                                                  );

#ifdef OSG_1_COMPAT
OSG_SYSTEM_DLLMAPPING
NodePtr
cloneTree(      NodePtrConstArg                          rootNode,
          const std::vector<const FieldContainerType *> &cloneTypes        =
              std::vector<const FieldContainerType *>(),
          const std::vector<const FieldContainerType *> &ignoreTypes       =
              boost::assign::list_of(
                  &FieldContainerAttachment::getClassType()),
          const std::vector<UInt16>                     &cloneGroupIds     =
              std::vector<UInt16>(),
          const std::vector<UInt16>                     &ignoreGroupIds    =
              std::vector<UInt16>()                                          );
#else
OSG_SYSTEM_DLLMAPPING
NodePtr
cloneTree(      NodePtrConstArg                          rootNode,
          const std::vector<const FieldContainerType *> &cloneTypes        =
              std::vector<const FieldContainerType *>(),
          const std::vector<const FieldContainerType *> &ignoreTypes       =
              std::vector<const FieldContainerType *>(),
          const std::vector<UInt16>                     &cloneGroupIds     =
              std::vector<UInt16>(),
          const std::vector<UInt16>                     &ignoreGroupIds    =
              std::vector<UInt16>()                                          );
#endif

OSG_SYSTEM_DLLMAPPING
NodePtr
deepCloneTree(      NodePtrConstArg                          rootNode,
              const std::vector<std::string>                &shareTypeNames,
              const std::vector<std::string>                &ignoreTypeNames  =
                  std::vector<std::string>(),
              const std::vector<std::string>                &shareGroupNames  =
                  std::vector<std::string>(),
              const std::vector<std::string>                &ignoreGroupNames =
                  std::vector<std::string>()                                  );

OSG_SYSTEM_DLLMAPPING
NodePtr
deepCloneTree(      NodePtrConstArg                          rootNode,
              const std::vector<UInt16>                     &shareGroupIds,
              const std::vector<UInt16>                     &ignoreGroupIds   =
                  std::vector<UInt16>()                                       );

OSG_SYSTEM_DLLMAPPING
NodePtr
deepCloneTree(      NodePtrConstArg                          rootNode,
              const std::string                             &shareTypesString,
              const std::string                             &ignoreTypesString =
                  std::string()                                               );

OSG_SYSTEM_DLLMAPPING
NodePtr
deepCloneTree(      NodePtrConstArg                          rootNode,
              const std::vector<const FieldContainerType *> &shareTypes     =
                  std::vector<const FieldContainerType *>(),
              const std::vector<const FieldContainerType *> &ignoreTypes    =
                  std::vector<const FieldContainerType *>(),
              const std::vector<UInt16>                     &shareGroupIds  =
                  std::vector<UInt16>(),
              const std::vector<UInt16>                     &ignoreGroupIds =
                  std::vector<UInt16>()                                       );

template <class Core> inline
NodePtr makeCoredNode(typename Core::ObjPtr *coreP = NULL);

template <class CorePtr> inline
NodePtr makeNodeFor(CorePtr core);

OSG_END_NAMESPACE

#define OSGNODE_HEADER_CVSID "@(#)$Id$"

#include "OSGNode.inl"
#include "OSGCoredNodePtr.h"

#endif /* _OSGNODE_H_ */
