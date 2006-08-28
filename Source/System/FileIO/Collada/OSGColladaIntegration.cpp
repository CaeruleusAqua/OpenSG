/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2006 by the OpenSG Forum                   *
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

/*! \file OSgColladaIntegration.cpp
    \ingroup GrpFoundationLoader
 */

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>

#include "OSGConfig.h"
#include "OSGBaseTypes.h"

#include <iostream>

#include "OSGColladaIntegration.h"

#include "OSGGroup.h"
#include "OSGMaterialGroup.h"
#include "OSGMaterialChunk.h"

#include "dom/domVisual_scene.h"
#include "dom/domNode.h"
#include "dom/domGeometry.h"
#include "dom/domInstance_geometry.h"
#include "dom/domMesh.h"
#include "dom/domMaterial.h"
#include "dom/domEffect.h"
#include "dom/domProfile_GLSL.h"
#include "dom/domProfile_CG.h"

#include "dae/daeSmartRef.h"
#include "dae/daeMetaElementAttribute.h"

OSG_USING_NAMESPACE

daeMetaElement *ColladaIntegrationBase::_pMeta = NULL;

void ColladaIntegrationBase::createFrom(daeElementRef pElement)
{
    fprintf(stderr, "ColladaIntegrationBase::createFrom %s\n", 
            pElement->getTypeName());

	_pElement = pElement;
}

void ColladaIntegrationBase::fromCOLLADA(void)
{
    fprintf(stderr, "ColladaIntegrationBase::fromCollada for %s\n", 
            _pElement->getTypeName());
}

void ColladaIntegrationBase::fromCOLLADAPostProcess(void)
{
    fprintf(stderr, "ColladaIntegrationBase::fromColladaPostproc\n");
}

void ColladaIntegrationBase::createTo(void *userData)
{
    fprintf(stderr, "ColladaIntegrationBase::createTo\n");
}

void ColladaIntegrationBase::toCOLLADA(void)
{
    fprintf(stderr, "ColladaIntegrationBase::toCollada\n");
}

void ColladaIntegrationBase::toCOLLADAPostProcess(void)
{
    fprintf(stderr, "ColladaIntegrationBase::toColladaPostProc\n");
}

daeElementRef ColladaIntegrationBase::create(daeInt bytes)
{
    fprintf(stderr, "ColladaIntegrationBase::create\n");

	ColladaIntegrationBaseRef ref = new(bytes) ColladaIntegrationBase;

	return ref;
}

daeMetaElement *ColladaIntegrationBase::registerElement(void)
{
    fprintf(stderr, "ColladaIntegrationBase::regElem\n");

    if(_pMeta != NULL) 
        return _pMeta;

    // The one seen

    _pMeta = new daeMetaElement;

    _pMeta->setName("ColladaIntegrationBase");

	_pMeta->registerConstructor(ColladaIntegrationBase::create);

	_pMeta->setElementSize(sizeof(ColladaIntegrationBase));

	_pMeta->validate();

	return _pMeta;
}
	
ColladaIntegrationBase::ColladaIntegrationBase(void) :
    _pElement(NULL)
{
}

ColladaIntegrationBase::~ColladaIntegrationBase(void)
{
}


//---------------------------------------------------------------------------
//  VisualSceneIntegration
//---------------------------------------------------------------------------


daeMetaElement *VisualSceneIntegration::_pMeta = NULL;

VisualSceneIntegration::VisualSceneIntegration(void) :
     Inherited(      ),
    _pScene   (NullFC)
{
}

VisualSceneIntegration::~VisualSceneIntegration(void)
{
    OSG::subRef(_pScene);
}

daeElementRef VisualSceneIntegration::create(daeInt bytes)
{
    fprintf(stderr, "VisualSceneIntegration::create\n");

	VisualSceneIntegrationRef ref = new(bytes) VisualSceneIntegration;

	return ref;
}

daeMetaElement *VisualSceneIntegration::registerElement(void)
{
    fprintf(stderr, "VisualSceneIntegration::regElem\n");

    if(_pMeta != NULL )
        return _pMeta;
    

    _pMeta = new daeMetaElement;

    _pMeta->setName("VisualSceneIntegration");
	_pMeta->registerConstructor(VisualSceneIntegration::create);

	domVisual_scene::_Meta->setMetaIntegration(_pMeta);

	_pMeta->setElementSize(sizeof(VisualSceneIntegration));
	_pMeta->validate();

    return _pMeta;
}

NodePtr VisualSceneIntegration::getScene(void)
{
    return _pScene;
}

void VisualSceneIntegration::fromCOLLADA(void)
{
    fprintf(stderr, "VisualSceneIntegration::fromCollada for %s\n", 
            _pElement->getTypeName());

    domVisual_scene *pDomScene = 
        dynamic_cast<domVisual_scene *>(_pElement);

    fprintf(stderr, "got dom scene %p\n", pDomScene);

    domNode_Array &aChildren = pDomScene->getNode_array();

    fprintf(stderr, "got %d children\n", aChildren.getCount());

    _pScene = Node::create();

    _pScene->setCore(Group::create());

    for(UInt32 i = 0; i < aChildren.getCount(); ++i)
    {
        fprintf(stderr, "gotNode %p int %p\n",
                &*(aChildren[i]),
                aChildren[i]->getIntObject());

        NodeIntegration *pNodeInt = 
            dynamic_cast<NodeIntegration *>(aChildren[i]->getIntObject());
        
        pNodeInt->fromCOLLADAChecked();
        
        if(pNodeInt != NULL)
        {
            _pScene->addChild(pNodeInt->getNode());
        }
    }
}


//---------------------------------------------------------------------------
//  NodeIntegration
//---------------------------------------------------------------------------

daeMetaElement *NodeIntegration::_pMeta = NULL;


bool NodeIntegration::handleNode(daeElementRef pElem)
{
    domNode *pNode = dynamic_cast<domNode *>(static_cast<daeElement *>(pElem));

    if(pNode == NULL)
        return false;

    fprintf(stderr, "Handle Node\n");

    NodeIntegration *pNodeInt = 
        dynamic_cast<NodeIntegration *>(pNode->getIntObject());

    if(pNodeInt != NULL)
    {
        pNodeInt->fromCOLLADAChecked();
        
        _pNode->addChild(pNodeInt->getNode());
    }

    return true;
}

bool NodeIntegration::handleTranslate(daeElementRef pElem)
{
    domTranslate *pTrans = 
        dynamic_cast<domTranslate *>(static_cast<daeElement *>(pElem));

    if(pTrans == NULL)
        return false;

    fprintf(stderr, "Handle Trans\n");

    return true;
}

bool NodeIntegration::handleRotate(daeElementRef pElem)
{
    domRotate *pRot = 
        dynamic_cast<domRotate *>(static_cast<daeElement *>(pElem));

    if(pRot == NULL)
        return false;

    fprintf(stderr, "Handle Rot\n");

    return true;
}

bool NodeIntegration::handleScale(daeElementRef pElem)
{
    domScale *pScale = 
        dynamic_cast<domScale *>(static_cast<daeElement *>(pElem));

    if(pScale == NULL)
        return false;

    fprintf(stderr, "Handle Scale\n");

    return true;
}


bool NodeIntegration::handleInstance(daeElementRef pElem)
{
    InstanceIntegration *pInt = NULL;

    domInstance_geometry *pInstGeo = 
        dynamic_cast<domInstance_geometry *>(static_cast<daeElement *>(pElem));

    if(pInstGeo != NULL)
    {
        pInt = dynamic_cast<InstanceIntegration *>(pInstGeo->getIntObject());
    }

    domInstance_node *pInstNode = 
        dynamic_cast<domInstance_node *>(static_cast<daeElement *>(pElem));

    if(pInstNode != NULL)
    {
        pInt = dynamic_cast<InstanceIntegration *>(pInstGeo->getIntObject());
    }

    if(pInt == NULL)
        return false;

    pInt->fromCOLLADAChecked();

    fprintf(stderr, "Handle Inst\n");

    _pNode->addChild(pInt->getInstance());

    return true;
}

NodeIntegration::NodeIntegration(void) :
     Inherited(      ),
    _pNode    (NullFC)
{
}

NodeIntegration::~NodeIntegration(void)
{
    OSG::subRef(_pNode);
}

daeElementRef NodeIntegration::create(daeInt bytes)
{
    fprintf(stderr, "NodeIntegration::create\n");

	NodeIntegrationRef ref = new(bytes) NodeIntegration;

	return ref;
}

daeMetaElement *NodeIntegration::registerElement(void)
{
    fprintf(stderr, "NodeIntegration::regElem\n");

    if(_pMeta != NULL )
        return _pMeta;
    
    _pMeta = new daeMetaElement;

    _pMeta->setName("NodeIntegration");
	_pMeta->registerConstructor(NodeIntegration::create);

	domNode::_Meta->setMetaIntegration(_pMeta);

	_pMeta->setElementSize(sizeof(NodeIntegration));
	_pMeta->validate();

    return _pMeta;
}

NodePtr NodeIntegration::getNode(void)
{
    return _pNode;
}

void NodeIntegration::fromCOLLADA(void)
{
    fprintf(stderr, "NodeIntegration::fromCollada for %s\n", 
            _pElement->getTypeName());

    _pNode = Node::create();

    OSG::addRef(_pNode);

    daeMetaElement *pMeta = _pElement->getMeta();

	if(pMeta->getContents() != NULL) 
    {
		daeElementRefArray *era = 
            (daeElementRefArray*) pMeta->getContents()->getWritableMemory(
                _pElement);

		int elemCnt = (int) era->getCount();

		for(int i = 0; i < elemCnt; i++) 
        {
			daeElementRef elem = (daeElementRef) era->get(i);

			if(elem != NULL) 
            {
                fprintf(stderr, "CT %d %p %s\n",
                        i,
                        &*(elem),
                        elem->getTypeName());
			}

            if(handleNode(elem) == true)
                continue;

            if(handleTranslate(elem) == true)
                continue;

            if(handleRotate(elem) == true)
                continue;

            if(handleScale(elem) == true)
                continue;

            if(handleInstance(elem) == true)
                continue;
		}
	}

    if(_pNode->getCore() == NullFC)
        _pNode->setCore(Group::create());
}


//---------------------------------------------------------------------------
//  InstanceIntegration
//---------------------------------------------------------------------------

InstanceIntegration::InstanceIntegration(void) :
    Inherited(      ),
   _pNode    (NullFC),
   _uiCount  (     0)
{
}

InstanceIntegration::~InstanceIntegration(void)
{
    OSG::subRef(_pNode);
}

NodePtr InstanceIntegration::getInstance(void)
{
    if(_pNode == NullFC)
        return NullFC;

    if(_uiCount == 0)
    {
        ++_uiCount;

        return _pNode;
    }
    else
    {
        ++_uiCount;

        return cloneTree(_pNode);
    }
}


//---------------------------------------------------------------------------
//  GeometryInstanceIntegration
//---------------------------------------------------------------------------

daeMetaElement *GeometryInstanceIntegration::_pMeta = NULL;

GeometryInstanceIntegration::GeometryInstanceIntegration(void) :
     Inherited(),
    _mMatMap  ()
{
}

GeometryInstanceIntegration::~GeometryInstanceIntegration(void)
{
}

daeElementRef GeometryInstanceIntegration::create(daeInt bytes)
{
    fprintf(stderr, "GeometryInstanceIntegration::create %p\n", (void *)bytes);

	GeometryInstanceIntegrationRef ref = 
        new(bytes) GeometryInstanceIntegration;

	return ref;
}

daeMetaElement *GeometryInstanceIntegration::registerElement(void)
{
    fprintf(stderr, "GeometryInstanceIntegration::regElem\n");

    if(_pMeta != NULL )
        return _pMeta;
    

    _pMeta = new daeMetaElement;

    _pMeta->setName("GeometryInstanceIntegration");
	_pMeta->registerConstructor(GeometryInstanceIntegration::create);

	domInstance_geometry::_Meta->setMetaIntegration(_pMeta);

	_pMeta->setElementSize(sizeof(GeometryInstanceIntegration));
	_pMeta->validate();

    return _pMeta;
}

void GeometryInstanceIntegration::fromCOLLADA(void)
{
    fprintf(stderr, "GeometryInstanceIntegration::fromCollada for %s %p %p\n", 
            _pElement->getTypeName(),
            this,
            &(*_pElement));

    domInstance_geometry *pInstGeo = 
        dynamic_cast<domInstance_geometry *>(_pElement);

    fprintf(stderr, "got dom geometry %p\n", pInstGeo);

    if(pInstGeo == NULL)
        return;

    daeURI oUri = pInstGeo->getUrl();


    fprintf(stderr, "uri %s %d\n", oUri.getURI(), oUri.getState());
            
    daeElementRef pElem = oUri.getElement();
                
    fprintf(stderr, "elem %p %s %s\n", 
            &*pElem, 
            pElem->getTypeName(),
            pElem->getElementName());
    
    domGeometry         *pGeo    = dynamic_cast<domGeometry         *>(
        static_cast<daeElement *>(pElem));

    GeometryIntegration *pGeoInt = dynamic_cast<GeometryIntegration *>(
        pGeo->getIntObject());

    if(pGeo == NULL)
        return;

    fprintf(stderr, "Got geo %p %p\n", pGeo, pGeoInt);


    pGeoInt->fromCOLLADAChecked();

    _pNode = Node::create();

    _pNode->setCore(Group::create());

    const domBind_materialRef pMatBindings = pInstGeo->getBind_material();
    
    domTechnique_Array &aTechnique = pMatBindings->getTechnique_array(); 

    bool bMatHandled = false;
        
    fprintf(stderr, "Num Tech %d\n", aTechnique.getCount());

    if(aTechnique.getCount() != 0)
    {
        for(UInt32 i = 0; i < aTechnique.getCount(); ++i)
        {
            daeElementRefArray &aTechniqueCont = aTechnique[i]->getContents();
            
            for(UInt32 j = 0; j < aTechniqueCont.getCount(); ++j)
            {
                daeElement *pElem = aTechniqueCont[i];
                
                fprintf(stderr, "elem %p %s %s\n", 
                        &*pElem, 
                        pElem->getTypeName(),
                        pElem->getElementName());
            }
        }
    }


    if(bMatHandled == false)
    {
        domBind_material::domTechnique_commonRef pTechnique = 
            pMatBindings->getTechnique_common();

        domInstance_material_Array &aInstMat = 
                pTechnique->getInstance_material_array();

        fprintf(stderr, "Got %d comm tech mat inst\n", aInstMat.getCount());

        for(UInt32 i = 0; i < aInstMat.getCount(); ++i)
        {
            fprintf(stderr, "%s %s\n", 
                    aInstMat[i]->getSymbol(),
                    aInstMat[i]->getTarget().getURI());

            daeElementRef pElem = aInstMat[i]->getTarget().getElement();

            domMaterial *pMat = 
                dynamic_cast<domMaterial *>(
                    static_cast<daeElement *>(pElem));

            if(pMat == NULL)
                continue;

            const domInstance_effectRef pEffect =
                pMat->getInstance_effect();

            xsAnyURI oEffectURI = pEffect->getUrl();
            
            fprintf(stderr, "uri %s %d\n", 
                    oEffectURI.getURI(), 
                    oEffectURI.getState());

            daeElementRef pEffectElem = oEffectURI.getElement();

            fprintf(stderr, "elem %p %s %s\n", 
                    &*pEffectElem, 
                    pEffectElem->getTypeName(),
                    pEffectElem->getElementName());

            EffectIntegration *pEffectInt = 
                dynamic_cast<EffectIntegration *>(pEffectElem->getIntObject());

            fprintf(stderr, "Got Eff Integration %p\n",
                    pEffectInt);

            pEffectInt->fromCOLLADAChecked();

            std::string effectKey = aInstMat[i]->getSymbol();

            _mMatMap[effectKey] = pEffectInt->getMaterial();
        }
    }
    

    GeometryIntegration::MatGeoMapIt geoIt  = pGeoInt->beginGeo();
    GeometryIntegration::MatGeoMapIt geoEnd = pGeoInt->endGeo  ();

    while(geoIt != geoEnd)
    {
        for(UInt32 i = 0; i < geoIt->second.size(); ++i)
        {
            MaterialGroupPtr pMatGroup     = MaterialGroup::create();
            NodePtr          pMatGroupNode = Node         ::create();
            
            NodePtr          pGeoNode      = Node         ::create();

            fprintf(stderr, "%s\n", geoIt->first.c_str());
            
            MaterialMapIt matIt = _mMatMap.find( geoIt->first);

            ChunkMaterialPtr pApp = NullFC;
            
            if(matIt != _mMatMap.end())
            {
                pApp = matIt->second;
            }
           
            pGeoNode     ->setCore    (geoIt->second[i]);

            pMatGroup    ->setMaterial(pApp            );
            pMatGroupNode->setCore    (pMatGroup       );

            pMatGroupNode->addChild   (pGeoNode        );
            
            _pNode       ->addChild   (pMatGroupNode   );
        }
        
        ++geoIt;
    }
}


//---------------------------------------------------------------------------
//  GeometryIntegration
//---------------------------------------------------------------------------

daeMetaElement *GeometryIntegration::_pMeta = NULL;

void GeometryIntegration::handlePolygon(domPolygonsRef &pPoly)
{
    domInputLocalOffset_Array &aInput = pPoly->getInput_array();

    daeURI oSource;
    std::string szGeoRef;
    std::string szMatRef;

    GeoUInt32PropertyPtr pLengths = NullFC;
    GeoUInt8PropertyPtr  pTypes   = NullFC;

    szGeoRef += pPoly->getMaterial();
    szMatRef  = pPoly->getMaterial();

    for(UInt32 i = 0; i < aInput.getCount(); ++i)
    {
        oSource = aInput[i]->getSource();


        fprintf(stderr, "%u %s %s %s\n", 
                aInput[i]->getOffset(), 
                aInput[i]->getSemantic(),
                oSource.getID(),
                oSource.getURI());

        szGeoRef += oSource.getID();
    }

    fprintf(stderr, "GeoRef %s\n", szGeoRef.c_str());

    GeoMapIt iCurrGeo = _mGeosMap.find(szGeoRef);

    GeometryPtr pGeo = NullFC;

    if(iCurrGeo == _mGeosMap.end())
    {
        pGeo = Geometry::create();

        _mGeosMap  [szGeoRef] = pGeo;
        _mGeosByMat[szMatRef].push_back(pGeo);

        for(UInt32 i = 0; i < aInput.getCount(); ++i)
        {
            UInt32 uiPropIdx = 
                SemanticToPropGeoIndex(aInput[i]->getSemantic());

            GeoUInt32PropertyPtr pProp = GeoUInt32Property::create();
                
            pGeo->setIndex(pProp,
                           uiPropIdx);
            
            fprintf(stderr, "added prop %d %p\n", uiPropIdx, &(*pProp));
            
            fillVecProp(pGeo, uiPropIdx, aInput[i]->getSource());
        }
            
        pLengths = GeoUInt32Property::create();
        pTypes   = GeoUInt8Property ::create();

        pGeo->setLengths(pLengths);
        pGeo->setTypes  (pTypes  );
    }
    else
    {
        pGeo = iCurrGeo->second;

        pLengths = cast_static<GeoUInt32PropertyPtr>(pGeo->getLengths());
        pTypes   = cast_static<GeoUInt8PropertyPtr >(pGeo->getTypes  ());
    }

    PropVec aProps;

    for(UInt32 i = 0; i < aInput.getCount(); ++i)
    {
        if(aProps.size() <= aInput[i]->getOffset())
        {
            aProps.resize(aInput[i]->getOffset() + 1);
        }

        UInt32 uiPropIdx = SemanticToPropGeoIndex(aInput[i]->getSemantic());

        fprintf(stderr, "%d %d %d %s %d %p\n", 
                i, 
                aProps.size(), 
                aInput[i]->getOffset(),
                aInput[i]->getSemantic(),
                uiPropIdx,
                &(*(pGeo->getIndex(uiPropIdx))));

        aProps[aInput[i]->getOffset()] =
            cast_static<GeoUInt32PropertyPtr>(pGeo->getIndex(uiPropIdx));
    }

    for(UInt32 i = 0; i < aProps.size(); i++)
    {
        fprintf(stderr, "%d : %p\n", i, &(*(aProps[i])));
    }
    

    fprintf(stderr, "P %s\n", pPoly->getMaterial());
    
    domP_Array &oPArray = pPoly->getP_array();

    UInt32 uiCurr   = 0;
    UInt32 uiLength = 0;

    for(UInt32 j = 0; j < oPArray.getCount(); j++)
    {
        domListOfUInts &oPList = oPArray[j]->getValue();
        
        for(UInt32 k = 0; k < oPList.getCount(); ++k)
        {
            aProps[uiCurr]->push_back(oPList[k]);
            
            uiCurr++;

            if(uiCurr == aProps.size())
            {
                uiCurr = 0;
                ++uiLength;
            }
        }

        pTypes  ->push_back(GL_POLYGON);
        pLengths->push_back(uiLength  );

        uiLength = 0;
    }
}

UInt32 GeometryIntegration::SemanticToPropGeoIndex(const char *szSemantic)
{
    UInt32 returnValue = 0xFFFF;

    std::string szSem = szSemantic;

    if(szSem == "VERTEX")
    {
        returnValue = Geometry::PositionsIndex;
    }
    else if(szSem == "NORMAL")
    {
        returnValue = Geometry::NormalsIndex;
    }
    else if(szSem == "TEXCOORD")
    {
        returnValue = Geometry::TexCoordsIndex;
    }

    return returnValue;
}

void GeometryIntegration::fillVecProp(GeometryPtrArg pGeo,
                                      UInt32         uiPropIdx,
                                      daeURI         oSource )
{
    fprintf(stderr, "uri %s %d\n", oSource.getURI(), oSource.getState());
    
    daeElementRef pElem = oSource.getElement();
    
    fprintf(stderr, "elem %p %s %s\n", 
            &*pElem, 
            pElem->getTypeName(),
            pElem->getElementName());

    domVertices *pVert = 
        dynamic_cast<domVertices *>(static_cast<daeElement *>(pElem));

    domSource   *pSource = 
        dynamic_cast<domSource *>(static_cast<daeElement *>(pElem));

    if(pVert != NULL)
    {
        domInputLocal_Array &aInput = pVert->getInput_array();

        fprintf(stderr, "Got vert %d\n", aInput.getCount());

        daeURI sourceDesc = aInput[0]->getSource();

        pElem = sourceDesc.getElement();

        fprintf(stderr, "elem %p %s %s\n", 
                &*pElem, 
                pElem->getTypeName(),
                pElem->getElementName());

        pSource = 
            dynamic_cast<domSource *>(static_cast<daeElement *>(pElem));
    }
    
    if(pSource != NULL)
    {
        fprintf(stderr, "Got source\n");
        
        SourceIntegration *pSourceInt = 
            dynamic_cast<SourceIntegration *>(pSource->getIntObject());

        pSourceInt->fromCOLLADAChecked();

        if(uiPropIdx == Geometry::NormalsIndex)
        {
            GeoVec3fPropertyPtr pProp = pSourceInt->getAsVec3fProp();

            pGeo->setProperty(pProp, uiPropIdx);
        }

        if(uiPropIdx == Geometry::PositionsIndex)
        {
            GeoPnt3fPropertyPtr pProp = pSourceInt->getAsPnt3fProp();

            pGeo->setProperty(pProp, uiPropIdx);
        }
    }
}
             
GeometryIntegration::GeometryIntegration(void) :
     Inherited (),
    _mGeosByMat(),
    _mGeosMap  ()
{
}

GeometryIntegration::~GeometryIntegration(void)
{
}

daeElementRef GeometryIntegration::create(daeInt bytes)
{
    fprintf(stderr, "GeometryIntegration::create %p\n", (void *)bytes);

	GeometryIntegrationRef ref = 
        new(bytes) GeometryIntegration;

	return ref;
}

daeMetaElement *GeometryIntegration::registerElement(void)
{
    fprintf(stderr, "GeometryIntegration::regElem\n");

    if(_pMeta != NULL )
        return _pMeta;
    

    _pMeta = new daeMetaElement;

    _pMeta->setName("GeometryIntegration");
	_pMeta->registerConstructor(GeometryIntegration::create);

	domGeometry::_Meta->setMetaIntegration(_pMeta);

	_pMeta->setElementSize(sizeof(GeometryIntegration));
	_pMeta->validate();

    return _pMeta;
}

void GeometryIntegration::fromCOLLADA(void)
{
    fprintf(stderr, "GeometryIntegration::fromCollada for %s %p %p\n", 
            _pElement->getTypeName(),
            this,
            &(*_pElement));

    domGeometry *pGeo = dynamic_cast<domGeometry *>(_pElement);

    fprintf(stderr, "got dom geometry %p\n", pGeo);

    if(pGeo == NULL)
        return;

    domMeshRef pMesh = pGeo->getMesh();

    fprintf(stderr, "got mesh %p\n", &(*pMesh));

    if(pMesh == NULL)
        return;

    domPolygons_Array &aPolys = pMesh->getPolygons_array();

    fprintf(stderr, "got %d polys\n", aPolys.getCount());

    for(UInt32 i = 0; i < aPolys.getCount(); ++i)
    {
        handlePolygon(aPolys[i]);
    }
}


GeometryIntegration::MatGeoMapIt GeometryIntegration::beginGeo(void)
{
    return _mGeosByMat.begin();
}

GeometryIntegration::MatGeoMapIt GeometryIntegration::endGeo(void)
{
    return _mGeosByMat.end();
}

//---------------------------------------------------------------------------
//  SourceIntegration
//---------------------------------------------------------------------------

daeMetaElement *SourceIntegration::_pMeta = NULL;

SourceIntegration::SourceIntegration(void) :
     Inherited (      ),
    _pVec3fProp(NullFC),
    _pPnt3fProp(NullFC)
{
}

SourceIntegration::~SourceIntegration(void)
{
    OSG::subRef(_pVec3fProp);
    OSG::subRef(_pPnt3fProp);
}

daeElementRef SourceIntegration::create(daeInt bytes)
{
    fprintf(stderr, "SourceIntegration::create %p\n", (void *)bytes);

	SourceIntegrationRef ref = new(bytes) SourceIntegration;

	return ref;
}

daeMetaElement *SourceIntegration::registerElement(void)
{
    fprintf(stderr, "SourceIntegration::regElem\n");

    if(_pMeta != NULL )
        return _pMeta;
    

    _pMeta = new daeMetaElement;

    _pMeta->setName("SourceIntegration");
	_pMeta->registerConstructor(SourceIntegration::create);

	domSource::_Meta->setMetaIntegration(_pMeta);

	_pMeta->setElementSize(sizeof(SourceIntegration));
	_pMeta->validate();

    return _pMeta;
}

void SourceIntegration::fromCOLLADA(void)
{
    fprintf(stderr, "SournceIntegration::fromCollada for %s %p %p\n", 
            _pElement->getTypeName(),
            this,
            &(*_pElement));
}

GeoVec3fPropertyPtr SourceIntegration::getAsVec3fProp(void)
{
    if(_pVec3fProp != NULL)
        return _pVec3fProp;

    domSource *pSource = dynamic_cast<domSource *>(_pElement);

    if(pSource == NULL)
        return _pVec3fProp;

    const domFloat_arrayRef aData = pSource->getFloat_array();

    _pVec3fProp = GeoVec3fProperty::create();

    OSG::addRef(_pVec3fProp);

    UInt32 uiCurr = 0;
    Vec3f  tmpVec;
    
    for(UInt32 i = 0; i < aData->getCount(); ++i)
    {
        tmpVec[uiCurr] = aData->getValue()[i];
        
        ++uiCurr;
        
        if(uiCurr == 3)
        {
            _pVec3fProp->push_back(tmpVec);
            
            uiCurr = 0;
        }
    }
    
    return _pVec3fProp;
}

GeoPnt3fPropertyPtr SourceIntegration::getAsPnt3fProp(void)
{
    if(_pPnt3fProp != NULL)
        return _pPnt3fProp;

    domSource *pSource = dynamic_cast<domSource *>(_pElement);

    if(pSource == NULL)
        return _pPnt3fProp;

    const domFloat_arrayRef aData = pSource->getFloat_array();

    _pPnt3fProp = GeoPnt3fProperty::create();

    OSG::addRef(_pPnt3fProp);

    UInt32 uiCurr = 0;
    Vec3f  tmpVec;
    
    for(UInt32 i = 0; i < aData->getCount(); ++i)
    {
        tmpVec[uiCurr] = aData->getValue()[i];
        
        ++uiCurr;
        
        if(uiCurr == 3)
        {
            _pPnt3fProp->push_back(tmpVec);
            
            uiCurr = 0;
        }
    }
    
    return _pPnt3fProp;
}


//---------------------------------------------------------------------------
//  SourceIntegration
//---------------------------------------------------------------------------

daeMetaElement *EffectIntegration::_pMeta = NULL;

void EffectIntegration::handlePhongColor(DomColor *pDiffuse,
                                         DomColor *pAmbient,
                                         DomColor *pSpecular,
                                         DomColor *pEmission,
                                         Real32    fShininess,
                                         Real32    fTransparency)
{
    MaterialChunkPtr pMatChunk = MaterialChunk::create();

    Color4f colVal;

    colVal[3] = fTransparency;

    if(pDiffuse != NULL)
    {
        domFx_color_common &color = pDiffuse->getValue();

        colVal[0] = color[0];
        colVal[1] = color[1];
        colVal[2] = color[2];

        pMatChunk->setDiffuse(colVal);
    }

    if(pAmbient != NULL)
    {
        domFx_color_common &color = pAmbient->getValue();

        colVal[0] = color[0];
        colVal[1] = color[1];
        colVal[2] = color[2];

        pMatChunk->setAmbient(colVal);
    }

    if(pSpecular != NULL)
    {
        domFx_color_common &color = pSpecular->getValue();

        colVal[0] = color[0];
        colVal[1] = color[1];
        colVal[2] = color[2];

        pMatChunk->setSpecular(colVal);
    }

/*
    if(pEmission != NULL)
    {
        domFx_color_common &color = pEmission->getValue();

        colVal[0] = color[0];
        colVal[1] = color[1];
        colVal[2] = color[2];

        pMatChunk->setEmission(colVal);
    }
 */

    pMatChunk->setShininess(fShininess);

    _pMaterial->addChunk(pMatChunk);
}

void EffectIntegration::fillElements(
    domCommon_color_or_texture_type             *pIn,
    domCommon_color_or_texture_type::domColor   *&pColOut,
    domCommon_color_or_texture_type::domTexture *&pTexOut)
{
    if(pIn != NULL)
    {
        pColOut = pIn->getColor  ();
        pTexOut = pIn->getTexture();
    }
}

void EffectIntegration::handleCommonProfile(domProfile_COMMON *pCommon)
{
    domProfile_COMMON::domTechnique *pTechnique = pCommon->getTechnique(); 

    if(pTechnique == NULL)
    {
        return;
    }
    
    if(_pMaterial == NullFC)
    {
        _pMaterial = ChunkMaterial::create();
    }
/*
    domCommon_color_or_texture_typeRef elemReflective;
    domCommon_float_or_param_typeRef   elemReflectivity;
    domCommon_transparent_typeRef      elemTransparent;
    domCommon_float_or_param_typeRef   elemIndex_of_refraction;
 */

    if(pTechnique->getConstant() != NULL)
    {
        fprintf(stderr, "Constant\n");
    }
    else if(pTechnique->getLambert() != NULL)
    {
        fprintf(stderr, "Lambert\n");
    }
    else if(pTechnique->getPhong())
    {
        fprintf(stderr, "Phong\n");
      
        domCommon_color_or_texture_type::domColor   *pDiffuseCol;
        domCommon_color_or_texture_type::domTexture *pDiffuseTex;

        domCommon_color_or_texture_type::domColor   *pAmbientCol;
        domCommon_color_or_texture_type::domTexture *pAmbientTex;

        domCommon_color_or_texture_type::domColor   *pSpecularCol;
        domCommon_color_or_texture_type::domTexture *pSpecularTex;

        domCommon_color_or_texture_type::domColor   *pEmissionCol;
        domCommon_color_or_texture_type::domTexture *pEmissionTex;


        fillElements(pTechnique->getPhong()->getDiffuse(),
                     pDiffuseCol,
                     pDiffuseTex);

        fillElements(pTechnique->getPhong()->getAmbient(),
                     pAmbientCol,
                     pAmbientTex);

        fillElements(pTechnique->getPhong()->getSpecular(),
                     pSpecularCol,
                     pSpecularTex);

        fillElements(pTechnique->getPhong()->getEmission(),
                     pEmissionCol,
                     pEmissionTex);

        domCommon_float_or_param_type   *pShininess =
            pTechnique->getPhong()->getShininess();

        domCommon_float_or_param_type   *pTransparency =
            pTechnique->getPhong()->getTransparency();

        Real32 rShininess    = 10.f;
        Real32 rTransparency = 1.f;

        if(pShininess != NULL && pShininess->getFloat() != NULL)
            rShininess = pShininess->getFloat()->getValue();

        if(pTransparency != NULL && pTransparency->getFloat() != NULL)
            rTransparency = pTransparency->getFloat()->getValue();

        handlePhongColor(pDiffuseCol,
                         pAmbientCol,
                         pSpecularCol,
                         pEmissionCol,
                         rShininess,
                         rTransparency);
                        

    }
    else if(pTechnique->getBlinn())
    {
        fprintf(stderr, "Blinn\n");
    }
    else
    {
        fprintf(stderr, "Unknown technique\n");
    }
}

void EffectIntegration::handleGLSLProfile(domProfile_GLSL *pGLSL)
{
}

void EffectIntegration::handleCGProfile(domProfile_CG *pCG)
{
}

EffectIntegration::EffectIntegration(void) :
     Inherited(      ),
    _pMaterial(NullFC)
{
}

EffectIntegration::~EffectIntegration(void)
{
    OSG::subRef(_pMaterial);
}

daeElementRef EffectIntegration::create(daeInt bytes)
{
    fprintf(stderr, "EffectIntegration::create %p\n", (void *)bytes);

	EffectIntegrationRef ref = new(bytes) EffectIntegration;

	return ref;
}

daeMetaElement *EffectIntegration::registerElement(void)
{
    fprintf(stderr, "EffectIntegration::regElem\n");

    if(_pMeta != NULL )
        return _pMeta;
    

    _pMeta = new daeMetaElement;

    _pMeta->setName("EffectIntegration");
	_pMeta->registerConstructor(EffectIntegration::create);

	domEffect::_Meta->setMetaIntegration(_pMeta);

	_pMeta->setElementSize(sizeof(EffectIntegration));
	_pMeta->validate();

    return _pMeta;
}

void EffectIntegration::fromCOLLADA(void)
{
    fprintf(stderr, "EffectIntegration::fromCollada for %s %p %p\n", 
            _pElement->getTypeName(),
            this,
            &(*_pElement));

    domEffect *pEffect = dynamic_cast<domEffect *>(_pElement);

    fprintf(stderr, "got dom effect %p %s\n", pEffect, pEffect->getId());

    if(pEffect == NULL)
        return;

    UInt32 uiNumProfiles = 
        pEffect->getFx_profile_abstract_array().getCount(); 

    fprintf(stderr, "Effect %s has %d profile\n", 
            pEffect->getId(), 
            uiNumProfiles);

    for(UInt32 i = 0; i < uiNumProfiles; ++i)
    {
        fprintf(stderr, "[%d] %s\n", 
                i,
                pEffect->getFx_profile_abstract_array()[i]->getTypeName()); 

        domProfile_COMMON *pCommon = 
            dynamic_cast<domProfile_COMMON *>(
                &(*(pEffect->getFx_profile_abstract_array()[i])));

        domProfile_GLSL   *pGLSL   = 
            dynamic_cast<domProfile_GLSL *>(
                &(*(pEffect->getFx_profile_abstract_array()[i])));

        domProfile_CG     *pCG     = 
            dynamic_cast<domProfile_CG *>(
                &(*(pEffect->getFx_profile_abstract_array()[i])));

        if(pCommon != NULL)
        {
            handleCommonProfile(pCommon);
        }
        else if(pGLSL != NULL)
        {
            handleGLSLProfile(pGLSL);
        }
        else if(pCG != NULL)
        {
            handleCGProfile(pCG);
        }
        else
        {
            fprintf(stderr, "Unknown profile %p %p %p\n",
                    pCommon,
                    pGLSL,
                    pCG);
            
        }
    }
}

ChunkMaterialPtr EffectIntegration::getMaterial(void)
{
    return _pMaterial;
}


OSG_BEGIN_NAMESPACE

void initColladaIntegration(void)
{
    ColladaIntegrationBase::registerElement();

    VisualSceneIntegration     ::registerElement();
    NodeIntegration            ::registerElement();
    GeometryInstanceIntegration::registerElement();
    GeometryIntegration        ::registerElement();
    SourceIntegration          ::registerElement();
    EffectIntegration          ::registerElement();
}

OSG_END_NAMESPACE

/*-------------------------------------------------------------------------*/
/*                              cvs id's                                   */

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace 
{
    static Char8 cvsid_cpp[] = "@(#)$Id: $";
    static Char8 cvsid_hpp[] = OSGCOLLADAINTEGRATION_HEADER_CVSID;
}

#endif
