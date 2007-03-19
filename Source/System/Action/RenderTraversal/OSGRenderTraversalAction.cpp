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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#ifdef OSG_CLEANED_RENDERACTION

#include "OSGRenderTraversalAction.h"

#include "OSGRenderPartitionPool.h"
#include "OSGRenderTreeNodePool.h"
#include "OSGStateOverride.h"
#include "OSGStateSorter.h"

#include "OSGWindow.h"

#include "OSGTextureBaseChunk.h"
#include "OSGMaterialChunk.h"
#include "OSGSHLChunk.h"

#include "OSGVolumeDraw.h"
#include "OSGTreeBuilderBase.h"

OSG_USING_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/***************************************************************************\
 *                               Types                                     *
\***************************************************************************/

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/



/*! \brief the prototype which is copied to create new actions
 */

RenderTraversalAction *RenderTraversalAction::_pPrototype = NULL;

/*! \brief Default functors for instantiation
 */

std::vector<
    Action::Functor> *RenderTraversalAction::_vDefaultEnterFunctors = NULL;
std::vector<
    Action::Functor> *RenderTraversalAction::_vDefaultLeaveFunctors = NULL;


StatElemDesc<StatTimeElem> RenderTraversalAction::statDrawTime     (
    "RT-DrawTime",
    "time for draw tree traversal");

StatElemDesc<StatIntElem > RenderTraversalAction::statNStates      (
    "RT-States",
    "number of material changes");
StatElemDesc<StatIntElem > RenderTraversalAction::statNMatrices    (
    "RT-NMatrices",
    "number of matrix changes");
StatElemDesc<StatIntElem > RenderTraversalAction::statNGeometries  (
    "RT-NGeometries",
    "number of Geometry nodes");
StatElemDesc<StatIntElem > RenderTraversalAction::statNShaders     (
    "RT-Shaders",
    "number of shader changes");
StatElemDesc<StatIntElem > RenderTraversalAction::statNShaderParams(
    "RT-ShaderParams",
    "number of shader params changes");
StatElemDesc<StatIntElem > RenderTraversalAction::statNTriangles   (
    "RT-Triangles", 
    "number of triangles");

/*
StatElemDesc<StatIntElem > RenderTraversalAction::statNTransGeometries(
    "shNTransGeometries",
    "number of transformed Geometry nodes");
 */

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

bool RenderTraversalAction::terminateEnter(void)
{
    FDEBUG_GV(("Terminate RenderTraversalAction Enter\n"));

    delete _vDefaultEnterFunctors;

    _vDefaultEnterFunctors = NULL;

    return true;
}

bool RenderTraversalAction::terminateLeave(void)
{
    FDEBUG_GV(("Terminate RenderTraversalAction Leave\n"));

    delete _vDefaultLeaveFunctors;

    _vDefaultLeaveFunctors = NULL;

    return true;
}

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/

/*! \brief Default registration. static, so it can be called during static init
 */

void RenderTraversalAction::registerEnterDefault(
    const FieldContainerType &type,
    const Action::Functor    &func)
{
    if(_vDefaultEnterFunctors == NULL)
    {
        _vDefaultEnterFunctors = new std::vector<Action::Functor>;

        addPostFactoryExitFunction(&RenderTraversalAction::terminateEnter);
    }

    while(type.getId() >= _vDefaultEnterFunctors->size())
    {
        _vDefaultEnterFunctors->push_back(&Action::_defaultEnterFunction);
    }

    FDEBUG_GV(("Register rendertrav for %s\n", type.getCName()));

    (*_vDefaultEnterFunctors)[type.getId()] = func;
}

void RenderTraversalAction::registerLeaveDefault(
    const FieldContainerType &type,
    const Action::Functor    &func)
{
    if(_vDefaultLeaveFunctors == NULL)
    {
        _vDefaultLeaveFunctors = new std::vector<Action::Functor>;

        addPostFactoryExitFunction(&RenderTraversalAction::terminateLeave);
    }

    while(type.getId() >= _vDefaultLeaveFunctors->size())
    {
        _vDefaultLeaveFunctors->push_back(&Action::_defaultLeaveFunction);
    }

    FDEBUG_GV(("Register rendertrav leave for %s\n", type.getCName()));

    (*_vDefaultLeaveFunctors)[type.getId()] = func;
}


/*! \brief  prototype access
 *  after setting the prototype all new DrawActions are clones of it
 */

void RenderTraversalAction::setPrototype(
    RenderTraversalAction *pPrototype)
{
    _pPrototype = pPrototype;
}

RenderTraversalAction *RenderTraversalAction::getPrototype(void)
{
    return _pPrototype;
}

/*-------------------------------------------------------------------------*\
 -  protected                                                              -
\*-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------*\
 -  private                                                                -
\*-------------------------------------------------------------------------*/



/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/

/*------------- constructors & destructors --------------------------------*/

RenderTraversalAction::RenderTraversalAction(void) :
     Inherited            (    ),
    _doCullOnly           (false),
    _numBuffers           (0),
    _currentBuffer        (0),
    _uiKeyGen             (0),
    _pPartitionPools      (),
    _pNodePools           (),
    _pStatePools          (),
    _pTreeBuilderPools    (),

    _pActivePartition     (NULL),

    _vRenderPartitions    (    ),
    _sRenderPartitionStack(    ),
    _bvPassMask           (    ),
    _bUseGLFinish         (false),
    _occlusionCulling     (false),
    _occlusionCullingDebug(false),
    _occDMTested          (0xffffffff), 
    _occDMCulled          (0xffffffff), 
    _occDMVisible         (0xffffffff),
    _occMinFeatureSize    (0),
    _occVisibilityThreshold(0),
    _occCoveredThreshold  (0.7f),
    _occQueryBufferSize   (1000),
    _occMinimumTriangleCount(500),
    _scrlodCoverageThreshold(0.01),
    _scrlodNumLODsToUse(0),
    _scrlodDegradationFactor(1.0)
{
    if(_vDefaultEnterFunctors != NULL)
        _enterFunctors = *_vDefaultEnterFunctors;

    if(_vDefaultLeaveFunctors != NULL)
        _leaveFunctors = *_vDefaultLeaveFunctors;

    setNumBuffers(1);


    UInt32 uiSId = SHLChunk        ::getStaticClassId() & 0x000003FF;
    UInt32 uiTId = TextureBaseChunk::getStaticClassId() & 0x000003FF;
    UInt32 uiMId = MaterialChunk   ::getStaticClassId() & 0x000003FF;

//    _uiKeyGen = (uiTId | (uiMId << 10) | (State::Key1Mask << 20));

    _uiKeyGen = (uiSId) | (uiTId << 10) | (uiMId << 20);

/*
    fprintf(stderr, "CreateKeyGen (RT) (%p) from %d %d %d -> %08x\n",
            this,
            SHLChunk     ::getStaticClassId(),
            TextureChunk ::getStaticClassId(),
            MaterialChunk::getStaticClassId(),
            _uiKeyGen);
 */

}

RenderTraversalAction::RenderTraversalAction(
    const RenderTraversalAction &source) :

     Inherited            (source),
    _doCullOnly           (false),
    _numBuffers           (0),
    _currentBuffer        (0),
    _uiKeyGen             (source._uiKeyGen),
    _pPartitionPools      (),
    _pNodePools           (),
    _pStatePools          (),
    _pTreeBuilderPools    (),

    _pActivePartition     (NULL),

    _vRenderPartitions    (    ),
    _sRenderPartitionStack(    ),
    _bvPassMask           (source._bvPassMask),
    _bUseGLFinish         (source._bUseGLFinish),
    _occlusionCulling     (source._occlusionCulling),
    _occlusionCullingDebug(source._occlusionCullingDebug),
    _occDMTested          (source._occDMTested), 
    _occDMCulled          (source._occDMCulled), 
    _occDMVisible         (source._occDMVisible),
    _occMinFeatureSize    (source._occMinFeatureSize),
    _occVisibilityThreshold(source._occVisibilityThreshold),
    _occCoveredThreshold  (source._occCoveredThreshold),
    _occQueryBufferSize   (source._occQueryBufferSize),
    _occMinimumTriangleCount(source._occMinimumTriangleCount),
    _scrlodCoverageThreshold(source._scrlodCoverageThreshold),
    _scrlodNumLODsToUse(source._scrlodNumLODsToUse),
    _scrlodDegradationFactor(source._scrlodDegradationFactor)
{
    setNumBuffers(source._numBuffers);
}

RenderTraversalAction *RenderTraversalAction::create(void)
{
    RenderTraversalAction *returnValue;

    if(_pPrototype)
    {
        returnValue = new RenderTraversalAction(*_pPrototype);
    }
    else
    {
        returnValue = new RenderTraversalAction();
    }

    return returnValue;
}


RenderTraversalAction::~RenderTraversalAction(void)
{
    for(UInt16 i = 0; i < _numBuffers; ++i)
    {
        delete _pPartitionPools[i];
        delete _pNodePools[i];
        delete _pStatePools[i];
        delete _pTreeBuilderPools[i];
    }
}

/*------------------------------ access -----------------------------------*/

/*------------------------ multi-buffer stuff -----------------------------*/

void RenderTraversalAction::setDoCullOnly(bool val)
{
    _doCullOnly = val;
}

bool RenderTraversalAction::getDoCullOnly(void)
{
    return _doCullOnly;
}

void RenderTraversalAction::setNumBuffers(UInt32 n)
{
    if(n < 1)
    {
        FWARNING(("RenderTraversalAction::setNumBuffers: need at least one "
                  "buffer!\n"));
        n = 1;
    }

    if(n > _numBuffers)
    {
        for(UInt16 i = _numBuffers; i < n; ++i)
        {
            _pPartitionPools  .push_back(new RenderPartitionPool);
            _pNodePools       .push_back(new RenderTreeNodePool);
            _pStatePools      .push_back(new StateOverridePool);
            _pTreeBuilderPools.push_back(new TreeBuilderPool);
        }

    }
    else if(n < _numBuffers)
    {
        for(UInt16 i = _numBuffers - 1; i >= n; --i)
        {
            delete _pPartitionPools[i];
            delete _pNodePools[i];
            delete _pStatePools[i];
            delete _pTreeBuilderPools[i];
        }
        _pPartitionPools  .resize(n);
        _pNodePools       .resize(n);
        _pStatePools      .resize(n);
        _pTreeBuilderPools.resize(n);
    }
    _numBuffers = n;
    _vRenderPartitions.resize(n);
}

UInt32 RenderTraversalAction::getNumBuffers(void)
{
    return _numBuffers;
}

void  RenderTraversalAction::setCurrentBuffer(UInt32 b)
{
    _currentBuffer = b;
}

UInt32 RenderTraversalAction::getCurrentBuffer(void)
{
    return _currentBuffer;
}


/*-------------------------- your_category---------------------------------*/

ActionBase::ResultE RenderTraversalAction::recurceNoNodeCallbacks(
    NodePtrConstArg node)
{
    if(node == NullFC)
        return Continue;

    if((node->getTravMask() & getTravMask()) == 0)
        return Continue;

    NodeCorePtr core = node->getCore();

    if(core == NullFC)
    {
        SWARNING << "recurse: core is Null,  don't know what to do!"
                 << std::endl;
        return Quit;
    }

    Action::ResultE result;

    _actList = NULL;
    _actNode = node;


    if(! _newList.empty())
    {
        result = callNewList();
    }
    else if(! _useNewList) // new list is empty, but not used?
    {
        std::vector<NodePtr>::const_iterator it;

        for(  it  = node->getMFChildren()->begin();
              it != node->getMFChildren()->end();
            ++it)
        {
            result = recurse(*it);

            if(result != Continue)
                break;
        }
    }

    _actNode = node;

    if(result == Skip)
        return Continue;

    return result;
}

Action::ResultE RenderTraversalAction::start(void)
{
    Inherited::start();

#if 0 // Not needed done by the partition setup anyway.
    if(_pWindow != NULL && !_doCullOnly)
    {
        _pWindow->resizeGL();
    }
#endif

    _vRenderPartitions[_currentBuffer].clear   ();

    _pPartitionPools  [_currentBuffer]->freeAll();
    _pNodePools       [_currentBuffer]->freeAll();
    _pStatePools      [_currentBuffer]->freeAll();
    _pTreeBuilderPools[_currentBuffer]->freeAll();

    _pActivePartition = _pPartitionPools[_currentBuffer]->create();

    _vRenderPartitions[_currentBuffer].push_back(_pActivePartition);

    _pActivePartition->setKeyGen         (_uiKeyGen                         );
    _pActivePartition->setAction         ( this                             );
    _pActivePartition->setNodePool       (_pNodePools       [_currentBuffer]);
    _pActivePartition->setStatePool      (_pStatePools      [_currentBuffer]);
    _pActivePartition->setTreeBuilderPool(_pTreeBuilderPools[_currentBuffer]);

    _pActivePartition->setFrustum        (_oFrustum        );

    _pActivePartition->setFrustumCulling (_bFrustumCulling );
    _pActivePartition->setVolumeDrawing  (_bVolumeDrawing  );

    _pActivePartition->init();

    bool full = true;

    if(_pViewport != NULL)
    {
        _pActivePartition->setViewport(_pViewport);
        _pActivePartition->setWindow  (_pWindow  );

        _pActivePartition->setViewportDimension(_pViewport->getPixelLeft  (),
                                                _pViewport->getPixelBottom(),
                                                _pViewport->getPixelRight (),
                                                _pViewport->getPixelTop   (),
                                                _pViewport->isFullWindow  ());

        if(_pCamera != NULL)
        {
            Matrix m, t;

            // set the projection
            _pCamera->getProjection          ( m,
                                              _pViewport->getPixelWidth (),
                                              _pViewport->getPixelHeight());

            _pCamera->getProjectionTranslation( t,
                                               _pViewport->getPixelWidth (),
                                               _pViewport->getPixelHeight());

            _pActivePartition->setupProjection(m, t);

            _pCamera->getViewing( m,
                                 _pViewport->getPixelWidth (),
                                 _pViewport->getPixelHeight());


            _pActivePartition->setupViewing(m);

            _pActivePartition->setNear(_pCamera->getNear());
            _pActivePartition->setFar (_pCamera->getFar ());
        }

        _pActivePartition->initVPMatricesFromCamera();

        _pActivePartition->setBackground(_pBackground);
    }

//    fprintf(stderr, "Start\n");

    return Action::Continue;
}

Action::ResultE RenderTraversalAction::stop(ResultE res)
{
//    fprintf(stderr, "Stop\n");

    Inherited::stop(res);

    if(!_doCullOnly)
    {
        drawBuffer(_currentBuffer);

        if(getVolumeDrawing())
            drawVolume(_oFrustum);

        UInt32 uiNMatrix      = 0;
        UInt32 uiNState       = 0;
        UInt32 uiNShader      = 0;
        UInt32 uiNShaderParam = 0;
        UInt32 uiNTriangles   = 0;

        for(Int32 i = 0; i < _vRenderPartitions[_currentBuffer].size(); ++i)
        {
            uiNMatrix +=
                _vRenderPartitions[_currentBuffer][i]->getNumMatrixChanges();

            uiNState  +=
                _vRenderPartitions[_currentBuffer][i]->getNumStateChanges();

            uiNShader +=
                _vRenderPartitions[_currentBuffer][i]->getNumShaderChanges();

            uiNShaderParam +=
                _vRenderPartitions[_currentBuffer][i]->getNumShaderParamChanges();

            uiNTriangles +=
                _vRenderPartitions[_currentBuffer][i]->getNumTriangles();
        }

        getStatistics()->getElem(statNMatrices    )->set(uiNMatrix     );
        getStatistics()->getElem(statNStates      )->set(uiNState      );
        getStatistics()->getElem(statNShaders     )->set(uiNShader     );
        getStatistics()->getElem(statNShaderParams)->set(uiNShaderParam);
        getStatistics()->getElem(statNTriangles   )->set(uiNTriangles);
    }

    return Action::Continue;
}

void RenderTraversalAction::drawBuffer(UInt32 buf)
{
    getStatistics()->getElem(statDrawTime)->start();

    _vRenderPartitions[buf][0]->setupExecution();


    // Quick fix, have to check GV
    glPushAttrib(GL_VIEWPORT_BIT);

    for(Int32 i = _vRenderPartitions[buf].size() - 1; i > 0; --i)
    {
        _vRenderPartitions[buf][i]->execute();
        _vRenderPartitions[buf][i]->exit();
    }

    // Quick fix, have to check GV
     glPopAttrib();

    _vRenderPartitions[buf][0]->doExecution();
    _vRenderPartitions[buf][0]->exit();

    if(_bUseGLFinish == true)
    {
        glFinish();
    }

    getStatistics()->getElem(statDrawTime)->stop();
}

void RenderTraversalAction::dropFunctor(Material::DrawFunctor &func,
                                        State                 *pState,
                                        UInt32                 uiSortKey)
{
    _pActivePartition->dropFunctor(func, pState, uiSortKey);
}

void RenderTraversalAction::pushState(void)
{
    _pActivePartition->pushState();
}

void RenderTraversalAction::popState(void)
{
    _pActivePartition->popState();
}

void RenderTraversalAction::addOverride(UInt32 uiSlot, StateChunk *pChunk)
{
    _pActivePartition->addOverride(uiSlot, pChunk);
}

Int32 RenderTraversalAction::allocateLightIndex(void)
{
    return _pActivePartition->allocateLightIndex();
}

void  RenderTraversalAction::releaseLightIndex(void)
{
    _pActivePartition->releaseLightIndex();
}

void RenderTraversalAction::pushMatrix(const Matrix &matrix)
{
    _pActivePartition->pushMatrix(matrix);
}

void RenderTraversalAction::popMatrix(void)
{
    _pActivePartition->popMatrix();
}

const Matrix &RenderTraversalAction::topMatrix(void)
{
    return _pActivePartition->topMatrix();
}

void RenderTraversalAction::overrideMaterial(Material        *pMaterial,
                                             NodePtrConstArg  pNode    )
{
    _pActivePartition->overrideMaterial(pMaterial, pNode);
}

Material *RenderTraversalAction::getMaterial(void)
{
    return _pActivePartition->getMaterial();
}

void RenderTraversalAction::pushPartition(UInt32                uiCopyOnPush,
                                          RenderPartition::Mode eMode       )
{
    _sRenderPartitionStack.push(_pActivePartition);

    _pActivePartition = _pPartitionPools[_currentBuffer]->create(eMode);

    _vRenderPartitions[_currentBuffer].push_back(_pActivePartition);

    _pActivePartition->setKeyGen         (_uiKeyGen                         );
    _pActivePartition->setAction         ( this                             );
    _pActivePartition->setNodePool       (_pNodePools       [_currentBuffer]);
    _pActivePartition->setStatePool      (_pStatePools      [_currentBuffer]);
    _pActivePartition->setTreeBuilderPool(_pTreeBuilderPools[_currentBuffer]);

    _pActivePartition->initFrom(_sRenderPartitionStack.top(),
                                _vRenderPartitions[_currentBuffer][0],
                                 uiCopyOnPush               );
}

void RenderTraversalAction::popPartition(void)
{
    _pActivePartition = _sRenderPartitionStack.top();

    _sRenderPartitionStack.pop();
}

RenderPartition *RenderTraversalAction::getActivePartition(void)
{
    return _pActivePartition;
}

bool RenderTraversalAction::isVisible(Node *node)
{
    return _pActivePartition->isVisible(node);
}

bool RenderTraversalAction::pushVisibility(void)
{
    if(_pActivePartition->pushVisibility(getActNode()) == false)
    {
        useNodeList(); // ignore all children
        return false;
    }

    return true;
}

void RenderTraversalAction::popVisibility(void)
{
    _pActivePartition->popVisibility();
}

// control activation of frustum culling
bool RenderTraversalAction::getFrustumCulling(void) const
{
    if(_pActivePartition != NULL)
        return _pActivePartition->getFrustumCulling();
    else
        return Inherited::getFrustumCulling();
}

void RenderTraversalAction::setFrustumCulling(bool val)
{
    if(_pActivePartition != NULL)
        _pActivePartition->setFrustumCulling(val);
    else
        Inherited::setFrustumCulling(val);

}

// control frustum
const FrustumVolume &RenderTraversalAction::getFrustum(void) const
{
    if(_pActivePartition != NULL)
        return _pActivePartition->getFrustum();
    else
        return Inherited::getFrustum();
}

void RenderTraversalAction::setFrustum(FrustumVolume &frust)
{
    if(_pActivePartition != NULL)
        _pActivePartition->setFrustum(frust);
    else
        Inherited::setFrustum(frust);
}

#if 0

// initialisation

Action::ResultE ShadingAction::start(void)
{
    Inherited::start();

    if(_window != NULL)
    {
        _window->resizeGL();
    }

    _uiMatrixId = 1;

    _currMatrix.first = 1;
    _currMatrix.second.setIdentity();

    bool full = true;

    if(_viewport != NULL)
    {
        GLint pl  = _viewport->getPixelLeft();
        GLint pr  = _viewport->getPixelRight();
        GLint pb  = _viewport->getPixelBottom();
        GLint pt  = _viewport->getPixelTop();

        GLint pw  = pr - pl + 1;
        GLint ph  = pt - pb + 1;

        full = _viewport->isFullWindow();

        glViewport(pl, pb, pw, ph);

        if(full == false)
        {
            glScissor (pl, pb, pw, ph);
            glEnable(GL_SCISSOR_TEST);
        }

        if(_camera != NULL)
        {
            _camera->setupProjection(this, *_viewport);

            // set the viewing

            _camera->getViewing(_currMatrix.second,
                                _viewport->getPixelWidth (),
                                _viewport->getPixelHeight());

            _camInverse.invertFrom(_currMatrix.second);

            glMatrixMode(GL_MODELVIEW);
        }

        if(_background != NULL)
        {
            _background->clear(this, _viewport);
        }
    }

#if 0
    _mMatMap.clear();

#if defined(OSG_OPT_DRAWTREE)
    _pNodePool->freeAll();
#else
    subRefP(_pRoot);
    subRefP(_pMatRoot);
    subRefP(_pTransMatRoot);
#endif

/*
    if(_pRoot != NULL)
    {
        fprintf(stderr, "CDN %d DDN %d ODN %d ",
                DrawTreeNode::_iCreateCount,
                DrawTreeNode::_iDeleteCount,
                DrawTreeNode::_iCreateCount - DrawTreeNode::_iDeleteCount);
    }
    */

    DrawTreeNode::_iCreateCount = 0;
    DrawTreeNode::_iDeleteCount = 0;

#if defined(OSG_OPT_DRAWTREE)
    _pRoot = _pNodePool->create();
#else
    _pRoot         = new DrawTreeNode;
    addRefP(_pRoot);
#endif

#if defined(OSG_OPT_DRAWTREE)
    _pMatRoot = _pNodePool->create();
#else
    _pMatRoot      = new DrawTreeNode;

//    _pRoot->addChild(_pMatRoot);
    addRefP(_pMatRoot);
#endif

#if defined(OSG_OPT_DRAWTREE)
    _pTransMatRoot = _pNodePool->create();
#else
    _pTransMatRoot = new DrawTreeNode;

//    _pRoot->addChild(_pTransMatRoot);
    addRefP(_pTransMatRoot);
#endif

    _pActiveState   = NULL;

    _uiActiveMatrix = 0;

    _uiNumMaterialChanges = 0;
    _uiNumMatrixChanges   = 0;
    _uiNumGeometries      = 0;
    _uiNumTransGeometries = 0;

    _vLights.clear();
#endif

    if(_viewport != NULL && full == false)
    {
        glDisable(GL_SCISSOR_TEST);
    }

    return Action::Continue;
}

Action::ResultE ShadingAction::stop(ResultE res)
{
    if(!_ownStat)
       getStatistics()->getElem(statDrawTime)->start();

#if 0
    UInt32 i;

//    dump(_pRoot, 0);
//    dump(_pMatRoot, 0);
//    dump(_pTransMatRoot, 0);

#if defined(OSG_OPT_DRAWTREE)
    //    _pNodePool->printStat();
#endif

    for(i = 0; i < _vLights.size(); i++)
    {
        glLoadMatrixf(_vLights[i].second.getValues());
        _vLights[i].first->activate(this, i);
    }

    draw(_pMatRoot->getFirstChild());

    if(!_bZWriteTrans)
        glDepthMask(false);

    draw(_pTransMatRoot->getFirstChild());

    if(!_bZWriteTrans)
        glDepthMask(true);

    if(_pActiveState != NULL)
    {
        _pActiveState->deactivate(this);
    }

    for(i = 0; i < _vLights.size(); i++)
    {
        _vLights[i].first->deactivate(this, i);
    }

    if(!_ownStat)
    {
        glFinish();
        getStatistics()->getElem(statDrawTime)->stop();

        getStatistics()->getElem(statNMaterials      )->set(
            _uiNumMaterialChanges);
        getStatistics()->getElem(statNMatrices       )->set(
            _uiNumMatrixChanges);
        getStatistics()->getElem(statNGeometries     )->set(
            _uiNumGeometries);
        getStatistics()->getElem(statNTransGeometries)->set(
            _uiNumTransGeometries);
    }


//    FINFO (("Material %d Matrix %d Geometry %d Transparent %d\r",
//            _uiNumMaterialChanges,
//            _uiNumMatrixChanges,
//            _uiNumGeometries,
//            _uiNumTransGeometries));
#endif

    Inherited::stop(res);
    return res;
}

#endif



/*------------------------ Occlusion Culling -----------------------------*/

void RenderTraversalAction::setOcclusionCulling(const bool val)
{
    _occlusionCulling = val;
}

bool RenderTraversalAction::getOcclusionCulling(void)
{
    return _occlusionCulling;
}

void RenderTraversalAction::setOcclusionCullingDebug(const bool val)
{
    _occlusionCullingDebug = val;
}

bool RenderTraversalAction::getOcclusionCullingDebug(void)
{
    return _occlusionCullingDebug;
}

void RenderTraversalAction::setOcclusionDebugMasks(const UInt32 tested, const UInt32 culled, const UInt32 visible)
{
    _occDMTested  = tested;
    _occDMCulled  = culled;
    _occDMVisible = visible;
}

UInt32 RenderTraversalAction::getOcclusionTestedDebugMask(void)
{
    return _occDMTested;
}

UInt32 RenderTraversalAction::getOcclusionCulledDebugMask(void)
{
    return _occDMCulled;
}

UInt32 RenderTraversalAction::getOcclusionVisibleDebugMask(void)
{
    return _occDMVisible;
}

void RenderTraversalAction::setOcclusionCullingMinimumFeatureSize(const UInt32 pixels)
{
    _occMinFeatureSize = pixels;
}

UInt32 RenderTraversalAction::getOcclusionCullingMinimumFeatureSize(void)
{
    return _occMinFeatureSize;
}

void RenderTraversalAction::setOcclusionCullingVisibilityThreshold(const UInt32 pixels)
{
    _occVisibilityThreshold = pixels;
}

UInt32 RenderTraversalAction::getOcclusionCullingVisibilityThreshold(void)
{
    return _occVisibilityThreshold;
}

void RenderTraversalAction::setOcclusionCullingCoveredThreshold(const Real32 percent)
{
    _occCoveredThreshold = percent;
}

Real32 RenderTraversalAction::getOcclusionCullingCoveredThreshold(void)
{
    return _occCoveredThreshold;
}

void RenderTraversalAction::setOcclusionCullingQueryBufferSize(const UInt32 size)
{
    _occQueryBufferSize = size;
}

UInt32 RenderTraversalAction::getOcclusionCullingQueryBufferSize(void)
{
    return _occQueryBufferSize;
}

void RenderTraversalAction::setOcclusionCullingMinimumTriangleCount(const UInt32 count)
{
    _occMinimumTriangleCount = count;
}

UInt32 RenderTraversalAction::getOcclusionCullingMinimumTriangleCount(void)
{
    return _occMinimumTriangleCount;
}

void RenderTraversalAction::setScreenLODCoverageThreshold(const Real32 percent)
{
    _scrlodCoverageThreshold = percent;
}

Real32 RenderTraversalAction::getScreenLODCoverageThreshold(void)
{
    return _scrlodCoverageThreshold;
}

void RenderTraversalAction::setScreenLODNumLevels(const UInt32 levels)
{
    _scrlodNumLODsToUse = levels;
}

UInt32 RenderTraversalAction::getScreenLODNumLevels(void)
{
    return _scrlodNumLODsToUse;
}

void RenderTraversalAction::setScreenLODDegradationFactor(const Real32 percent)
{
    _scrlodDegradationFactor = percent;
}

Real32 RenderTraversalAction::getScreenLODDegradationFactor(void)
{
    return _scrlodDegradationFactor;
}

/*-------------------------- assignment -----------------------------------*/

/** \brief assignment
 */

/*-------------------------- comparison -----------------------------------*/


/*-------------------------------------------------------------------------*\
 -  protected                                                              -
\*-------------------------------------------------------------------------*/


std::vector<Action::Functor> *
    RenderTraversalAction::getDefaultEnterFunctors(void)
{
    return _vDefaultEnterFunctors;
}

std::vector<Action::Functor> *
    RenderTraversalAction::getDefaultLeaveFunctors(void)
{
    return _vDefaultLeaveFunctors;
}

/*-------------------------------------------------------------------------*\
 -  private                                                                -
\*-------------------------------------------------------------------------*/

#endif
