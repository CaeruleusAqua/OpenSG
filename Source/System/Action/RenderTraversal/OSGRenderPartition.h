/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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

#ifndef _OSGRENDERPARTITION_H_
#define _OSGRENDERPARTITION_H_
#ifdef __sgi
#pragma once
#endif

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <boost/function.hpp>

#include "OSGRenderTravDef.h"
#include "OSGRenderPartitionBase.h"
#include "OSGRenderTraversalFwd.h"
#include "OSGDrawEnv.h"
#include "OSGStatIntElem.h"
#include "OSGFrustumVolume.h"

#include "OSGViewport.h"
#include "OSGBackground.h"
#include "OSGMaterial.h"
#include "OSGNamedPool.h"

#include <stack>

OSG_BEGIN_NAMESPACE

//---------------------------------------------------------------------------
//  Forward References
//---------------------------------------------------------------------------

class State;
class FrameBufferObject;
class RenderTraversalAction;

//---------------------------------------------------------------------------
//   Types
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  Class
//---------------------------------------------------------------------------

/*! \brief RenderPartition is the core class for keeping track of the actions 
            necessary to draw a scene. 
 */

class OSG_RENDERTRAV_DLLMAPPING RenderPartition : public RenderPartitionBase
{
  public:

    //-----------------------------------------------------------------------
    //   constants                                                             
    //-----------------------------------------------------------------------

    /*! Number of nodes tested for culling */
    static StatElemDesc<StatIntElem>  statCullTestedNodes; 

    /*! Number of nodes culled */
    static StatElemDesc<StatIntElem>  statCulledNodes;

    //-----------------------------------------------------------------------
    //   enums                                                               
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   types                                                               
    //-----------------------------------------------------------------------

    /*! MatrixStore is stored internally to keep track of the current matrix.
        The UInt32 is used to quickly identify the same matrix without having
        to compare actual matrix elements.
    */
    typedef std::pair<UInt32, Matrix>               MatrixStore;
    
    /*! DrawFunctor is the signature for the methods that are called 
        from within the draw tree
    */
    typedef Material::DrawFunctor                   DrawFunctor;

    /*! SimpleDrawCallback is the type of functions that are used for simple
        partitions (i.e. the ones that only call one function and do not draw
        Nodes
    */
    typedef boost::function<void (DrawEnv *)>       SimpleDrawCallback;

    /*! BuildKeyMap is used to index from the material's sortKey to the 
        StateSorter that keeps the tree for that sort key
     */
    typedef std::map<Int32, 
                     TreeBuilderBase *> BuildKeyMap;
    typedef std::map<Int32, 
                     TreeBuilderBase *>::iterator       BuildKeyMapIt;
    typedef std::map<Int32, 
                     TreeBuilderBase *>::const_iterator BuildKeyMapConstIt;

    /*! VisibilityStack keeps track of the planes of the current frustum that
        need to be tested. If a bounding volume is inside all
        planes, none need to be tested for its children.
    */
    typedef std::vector<FrustumVolume::PlaneSet>    VisibilityStack;

    /*! OverrideStack keeps track of active StateOverrides during traversal */
    typedef std::stack<StateOverride *>             OverrideStack;

    /*! MatrixStack keeps track of matrices during traversal */
    typedef std::vector<MatrixStore>                MatrixStack;

    typedef std::vector<RenderPartition *>          GroupStore;

    //-----------------------------------------------------------------------
    //   class functions                                                     
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   class functions                                                     
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   instance functions                                                  
    //-----------------------------------------------------------------------

    /*------------------------- your_category -------------------------------*/

    void setAction         (RenderTraversalAction *pAction         );

    void setNodePool       (RenderTreeNodePool    *pNodePool       );
    void setStatePool      (StateOverridePool     *pStatePool      );
    void setTreeBuilderPool(TreeBuilderPool       *pTreeBuilderPool);
    void setStatCollector  (StatCollectorP         pStatCollector  );

    /*------------------------- your_operators ------------------------------*/

    StatCollectorP getStatCollector(void);

    /*------------------------- your_operators ------------------------------*/

    void      setViewport  (Viewport   *pViewport  );
    Viewport *getViewport  (void                   );

    void      setWindow    (Window     *pWindow    );
    Window   *getWindow    (void                   );

    void      setBackground(Background *pBackground);
  
    /*------------------------- your_operators ------------------------------*/


          void      setupProjection     (const Matrix4f &projection,
					 const Matrix4f &translation);

    const Matrix4f &getFullProjection   (      void                 );
    const Matrix4f &getProjection       (      void                 );
    const Matrix4f &getProjectionTrans  (      void                 );

    const Matrix4f &getVPFullProjection (      void                 );
    const Matrix4f &getVPProjection     (      void                 );
    const Matrix4f &getVPProjectionTrans(      void                 );

          void      setupViewing        (const Matrix4f &matrix     );

    const Matrix4f &getViewing          (      void                 );
    const Matrix4f &getCameraToWorld    (      void                 );
    const Matrix4f &getVPViewing        (      void                 );
    const Matrix4f &getVPCameraToWorld  (      void                 );

    /*------------------------- your_operators ------------------------------*/

    void addPartition(RenderPartition *pPart);

    /*------------------------- your_operators ------------------------------*/

    void   setNear(Real32 camNear);
    void   setFar (Real32 camFar );

    Real32 getNear(void          );
    Real32 getFar (void          );

    /*------------------------- your_operators ------------------------------*/

    void  calcFrustum          (void                );
    
    void  setViewportDimension (Int32  iPixelLeft,
                                Int32  iPixelBottom,
                                Int32  iPixelRight,
                                Int32  iPixelTop,
                                bool   bFull        );

    void  calcViewportDimension(Real32 rLeft,
                                Real32 rBottom,
                                Real32 rRight,
                                Real32 rTop,
                                
                                UInt16 iTargetWidth,
                                UInt16 iTargetHeight);

    Int32 getViewportWidth     (void                );
    Int32 getViewportHeight    (void                );


    /*------------------------- your_operators ------------------------------*/

    void setSetupMode            (SetupMode        eSetupMode  );

    void initFrom                (RenderPartition *pSource,
				  RenderPartition *pInitial,
				  Int32            uiCopyOnPush);

    void initVPMatricesFromCamera(void                         );

    /*------------------------- your_operators ------------------------------*/

    void execute(void);
    void disable(void);

    /*------------------------- assignment ----------------------------------*/
    
          void    pushMatrix(const Matrix &matrix);
          void    popMatrix (      void          );

    const Matrix &topMatrix (      void          );

    /*------------------------- comparison ----------------------------------*/

    void dropFunctor(DrawFunctor &func, 
                     State       *pState,
                     Int32        uiBuildKey);

    void dropFunctor(SimpleDrawCallback &oFunc);

    /*------------------------- comparison ----------------------------------*/

    void pushState  (void              );
    void popState   (void              );

    void addOverride(UInt32      uiSlot, 
                     StateChunk *pChunk);
   
    /*-------------------------- comparison ---------------------------------*/

    Int32 allocateLightIndex(void);
    void  releaseLightIndex (void);

    /*-------------------------- comparison ---------------------------------*/

    void setKeyGen(UInt32 uiKeyGen);

    /*-------------------------- comparison ---------------------------------*/

    void      overrideMaterial(Material        *pMaterial,
                               NodePtrConstArg  pNode    );

    Material *getMaterial     (void                      );

    /*-------------------------- comparison ---------------------------------*/

    void               setRenderTarget(FrameBufferObject *pTarget);
    FrameBufferObject *getRenderTarget(void                      );

    /*-------------------------- comparison ---------------------------------*/

    // test a single node
    bool isVisible      (Node            *pNode);
    
    // visibility levels
    bool  pushVisibility(NodePtrConstArg  pNode);
    void  popVisibility (void                  );

    /*-------------------------- comparison ---------------------------------*/

    // control activation of frustum culling
    bool                 getFrustumCulling(void                ) const;
    void                 setFrustumCulling(bool val = true     );
    
    // control drawing of checked volumes
    bool                 getVolumeDrawing (void                ) const;
    void                 setVolumeDrawing (bool val = false    );
    
    // control frustum
    const FrustumVolume &getFrustum       (void                ) const;
    void                 setFrustum       (FrustumVolume &frust);    

    /*-------------------------- comparison ---------------------------------*/

    UInt32 getNumMatrixChanges     (void);
    UInt32 getNumStateChanges      (void);
    UInt32 getNumShaderChanges     (void);
    UInt32 getNumShaderParamChanges(void);
    UInt32 getNumTriangles         (void);

    /*-------------------------- comparison ---------------------------------*/

    void init(void);
    void exit(void);

    /*-------------------------- comparison ---------------------------------*/

#ifdef OSG_DEBUG
    void setDebugString(std::string szDebugString);
#endif

  protected:

    //-----------------------------------------------------------------------
    //   enums                                                               
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   types                                                               
    //-----------------------------------------------------------------------

    typedef RenderPartitionBase Inherited;

    //-----------------------------------------------------------------------
    //   class variables                                                     
    //-----------------------------------------------------------------------

    Mode                _eMode;
    SetupMode           _eSetupMode;
    bool                _bDone;

    GroupStore          _vGroupStore;

    DrawEnv             _oDrawEnv;

    SimpleDrawCallback  _oSimpleDrawCallback;

    Background         *_pBackground;

    // Transform

    UInt32              _uiMatrixId;

    MatrixStore         _currMatrix;
    Matrix              _accMatrix;

    MatrixStack         _vMatrixStack;

    // Roots

    RenderTreeNodePool *_pNodePool;

    BuildKeyMap          _mMatRoots;
    BuildKeyMap          _mTransMatRoots;

    // What to do

    bool                _bSortTrans;
    bool                _bZWriteTrans;
    bool                _bCorrectTwoSidedLighting;

    // Active Elements

    UInt32              _uiActiveMatrix;
    
    // State

    StateOverridePool  *_pStatePool;
    
    OverrideStack       _sStateOverrides;

    TreeBuilderPool    *_pTreeBuilderPool;

    // State

    Int32               _iNextLightIndex;
    UInt32              _uiKeyGen;
    
    // Material Override

    Material           *_pMaterial;
    NodePtr             _pMaterialNode;
    
    // Target

    FrameBufferObject  *_pRenderTarget;

    Int32               _iPixelLeft;
    Int32               _iPixelRight;
    Int32               _iPixelBottom;
    Int32               _iPixelTop;

    bool                _bFull;

    // Stat

    UInt32              _uiNumMatrixChanges;
    UInt32              _uiNumTriangles;

    // Culling

    VisibilityStack     _visibilityStack;

    bool                _bFrustumCulling;
    bool                _bVolumeDrawing;
    bool                _bAutoFrustum;
    FrustumVolume       _oFrustum;


#ifdef OSG_DEBUG
     // Debug

    std::string         _szDebugString;
#endif

    //-----------------------------------------------------------------------
    //   class functions                                                     
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   instance variables                                                  
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   instance functions                                                  
    //-----------------------------------------------------------------------

    RenderPartition(Mode eMode = StateSorting);

    virtual ~RenderPartition(void); 

    /*-------------------------- comparison ---------------------------------*/

    void reset(Mode eMode = StateSorting);

    void updateTopMatrix(void);

    /*-------------------------- comparison ---------------------------------*/

    // Roots

    void setupExecution(void);
    void doExecution   (void);

  private:

    //-----------------------------------------------------------------------
    //   enums                                                               
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   types                                                               
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   friend classes                                                      
    //-----------------------------------------------------------------------

    friend class SimplePool<RenderPartition, PoolDefaultTag, NoLockPolicy>;
    friend class RenderTraversalAction;
    friend class TreeBuilderBase;
    friend class OcclusionCullingTreeBuilder;

    //-----------------------------------------------------------------------
    //   friend functions                                                    
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   class variables                                                     
    //-----------------------------------------------------------------------
   
    //-----------------------------------------------------------------------
    //   class functions                                                     
    //-----------------------------------------------------------------------

    //-----------------------------------------------------------------------
    //   instance variables                                                  
    //-----------------------------------------------------------------------
    
    //-----------------------------------------------------------------------
    //   instance functions                                                  
    //-----------------------------------------------------------------------

    /*!\brief prohibit default function (move to 'public' if needed) */
    RenderPartition(const RenderPartition &source);
    void operator =(const RenderPartition &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------

OSG_END_NAMESPACE

#include "OSGRenderPartition.inl"

#endif /* _OSGRENDERPARTITION_H_ */


