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

// AMZ disabled for now.

#define OSG_COMPILEVRMLLOADERINST

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include <iostream>

#include "OSGVRMLFile.h"

#include "OSGFieldType.h"
#include "OSGMathMFields.h"
#include "OSGMathSFields.h"
#include "OSGVecMFields.h"
#include "OSGVecSFields.h"


#include "OSGAction.h"
#include "OSGMaterial.h"
#include "OSGMaterialGroup.h"
#include "OSGNameAttachment.h"

#include "OSGGroup.h"

#include "OSGBlendChunk.h"
#include "OSGTextureObjChunk.h"
#include "OSGTextureEnvChunk.h"


#include "OSGSceneFileHandler.h"

#define OSG_DEBUG_VRML

OSG_USING_NAMESPACE

/*! \class OSG::VRMLFile
 */

OSG::Time startTime = 0.;
OSG::Time useTime   = 0.;
OSG::Time findTime  = 0.;

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

VRMLFile::VRMLFile(void) :
    Inherited(),

    _pSceneRootNode     (NullFC),

    _pLightRoot         (NullFC),
    _pCurrentGlobalLight(NullFC),

    _pCurrNodeHelper(NULL),
    _sNodeHelpers   (),

    _pCurrentFC       (NullFC),
    _pCurrentFieldFC  (NullFC),
    _pCurrentField    (NULL),
    _pCurrentFieldDesc(NULL),

    _fcStack  (),
    _fStack   (),
    _fdStack  (),

    _nameFCMap    (),
    _nameHelperMap()
{
    Self::setReferenceHeader("#VRML V2.0 ");

    initIntExtFieldTypeMapper();
    initExtIntFieldTypeMapper();
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

VRMLFile::~VRMLFile(void)
{
}

/*-------------------------------------------------------------------------*/
/*                           Skel Replacements                             */

void VRMLFile::scanStream(std::istream &is)
{
    startTime = getSystemTime();

    _pSceneRootNode      = NullFC;
    _pLightRoot          = NullFC;
    _pCurrentGlobalLight = NullFC;

    _nameFCMap.clear();

#ifdef OSG_DEBUG_VRML
    VRMLNodeHelper::resetIndent();
#endif

    if(is)
    {
        Inherited::scanStream(is);
    }

    SceneFileHandler::the()->updateReadProgress(100);

    FINFO(("Full Time : %lf | Use Time %lf\n",
            getSystemTime() - startTime,
            useTime));
}

void VRMLFile::handleError(const Char8 *szErrorText)
{
    Inherited::handleError(szErrorText);
    // on an error we destroy the incomplete scene.

#if 0
    if(_pSceneRootNode != NullFC)
    {
        subRef(_pSceneRootNode);

        _pSceneRootNode = NullFC;
    }
#endif
}

void VRMLFile::beginNode(const Char8 *szNodeTypename,
                         const Char8 *szNodename)
{
    SceneFileHandler::the()->updateReadProgress();

    FieldContainerPtr pNewNode;

#ifdef OSG_DEBUG_VRML
    indentLog(VRMLNodeHelper::getIndent(), PINFO);
    PINFO << "Begin Node " << szNodeTypename << std::endl;

    VRMLNodeHelper::incIndent();
#endif

    VRMLNodeHelper *pOldHelper = _pCurrNodeHelper;

    _pCurrNodeHelper = findNodeHelper(szNodeTypename);

    if(_pCurrNodeHelper == NULL)
        return;

    _sNodeHelpers.push(_pCurrNodeHelper);

    _pCurrNodeHelper->reset();

    pNewNode = _pCurrNodeHelper->beginNode( szNodeTypename,
                                            szNodename,
                                           _pCurrentFC);


#if 0
    if(szNodename != NULL)
    {
        if(pNewNode != NullFC)
        {
            if(pNewNode->getType().isNode() == true)
            {
#ifdef OSG_DEBUG_VRML
                indentLog(VRMLNodeDesc::getIndent(), PINFO);
                PINFO << "Node named : " << szNodename << std::endl;
#endif

                NodePtr pNode     = cast_dynamic<NodePtr>(pNewNode);
                NamePtr pNodename = Name::create();

                pNodename->editFieldPtr()->getValue().assign(szNodename);

                pNode->addAttachment(pNodename);

                NameContainerMap::iterator mIt =
                    _nameFCMap.find(IDStringLink(szNodename));

                if(mIt == _nameFCMap.end())
                {
                    _nameFCMap[IDString(szNodename)] = pNewNode;

#ifdef OSG_DEBUG_VRML
                    indentLog(VRMLNodeDesc::getIndent(), PINFO);
                    PINFO << "Fieldcontainer " << szNodename
                          << " added to map " << std::endl;
#endif
                }
            }
            else if(pNewNode->getType().isNodeCore() == true)
            {
#ifdef OSG_DEBUG_VRML
                indentLog(VRMLNodeDesc::getIndent(), PINFO);
                PINFO << "Nodecore named : " << szNodename << std::endl;
#endif
                NodeCorePtr pNodeCore = cast_dynamic<NodeCorePtr>(pNewNode);
                NamePtr     pNodename = Name::create();

                pNodename->editFieldPtr()->getValue().assign(szNodename);
                pNodeCore->addAttachment(pNodename);

                NameContainerMap::iterator mIt =
                    _nameFCMap.find(IDStringLink(szNodename));

                if(mIt == _nameFCMap.end())
                {
                    _nameFCMap[IDString(szNodename)] = pNewNode;

#ifdef OSG_DEBUG_VRML
                    indentLog(VRMLNodeDesc::getIndent(), PINFO);
                    PINFO << "Fieldcontainer " << szNodename
                          << " added to map " << std::endl;
#endif
                }
            }
            else
            {
#ifdef OSG_DEBUG_VRML
                indentLog(VRMLNodeDesc::getIndent(), PINFO);
                PINFO << "Fieldcontainer " << szNodeTypename
                      << " is neither node nor nodecore " << std::endl;
#endif

                NameContainerMap::iterator mIt =
                    _nameFCMap.find(IDStringLink(szNodename));

                if(mIt == _nameFCMap.end())
                {
                    _nameFCMap[IDString(szNodename)] = pNewNode;

#ifdef OSG_DEBUG_VRML
                    indentLog(VRMLNodeDesc::getIndent(), PINFO);
                    PINFO << "Fieldcontainer " << szNodename
                          << " added to map " << std::endl;
#endif
                }

            }

            _nameDescMap[IDString(szNodename)] = _pCurrNodeDesc;

#ifdef OSG_DEBUG_VRML
            indentLog(VRMLNodeDesc::getIndent(), PINFO);
            PINFO << "Desc for "
                  << szNodename
                  << " added to map "
                  << std::endl;
#endif
        }
        else
        {
#ifdef OSG_DEBUG_VRML
            indentLog(VRMLNodeDesc::getIndent(), PINFO);
            PINFO << "Fieldcontainer "
                  << szNodeTypename
                  << "is empty, save on end "
                  << std::endl;
#endif

            if(_pCurrNodeDesc != NULL)
                _pCurrNodeDesc->setOnEndSave(szNodename);

            _nameDescMap[IDString(szNodename)] = _pCurrNodeDesc;

#ifdef OSG_DEBUG_VRML
            indentLog(VRMLNodeDesc::getIndent(), PINFO);
            PINFO << "Desc for "
                  << szNodename
                  << " added to map "
                  << std::endl;
#endif
        }
    }

#endif

    if(pOldHelper != NULL)
    {
        pOldHelper->setContainerFieldValue( pNewNode,
                                           _pCurrentFieldDesc,
                                           _pCurrentFieldFC  );
    }

    _pCurrentFC = pNewNode;

    _fcStack.push(_pCurrentFC);

    if(_fcStack.size() == 1)
    {
        NodePtr pNode = cast_dynamic<NodePtr>(_pCurrentFC);

        if(_pSceneRootNode == NullFC)
        {
            GroupPtr pGroup = Group::create();

            _pSceneRootNode = Node::create();

            _pSceneRootNode->setCore(pGroup);
        }

        _pSceneRootNode->addChild(pNode);
    }
}

void VRMLFile::endNode(void)
{
    SceneFileHandler::the()->updateReadProgress();

    if(_pCurrNodeHelper == NULL)
    {
#ifdef OSG_DEBUG_VRML
        VRMLNodeHelper::decIndent();

        indentLog(VRMLNodeHelper::getIndent(), PINFO);
        PINFO << "End Node " << std::endl;
#endif
        return;
    }

    _pCurrNodeHelper->endNode(_pCurrentFC);

#if 0
    if(_pCurrNodeDesc->getOnEndSave() == true)
    {
        SLOG << "Fieldcontainer " <<  _pCurrNodeDesc->getSavename()
             << " on end Save " << std::endl;

        NameContainerMap::iterator mIt =
            _nameFCMap.find(IDStringLink(_pCurrNodeDesc->getSavename()));

        if(mIt == _nameFCMap.end())
        {
            _nameFCMap[IDString(_pCurrNodeDesc->getSavename())] =
                _pCurrNodeDesc->getSaveFieldContainer();

            SLOG << "Fieldcontainer " << _pCurrNodeDesc->getSavename()
                 << " added to map " << std::endl;
        }

        _pCurrNodeDesc->clearOnEndSave();
    }
#endif

    _sNodeHelpers.pop();

    if(_sNodeHelpers.size() != 0)
    {
        _pCurrNodeHelper = _sNodeHelpers.top();
    }
    else
    {
        _pCurrNodeHelper = NULL;
    }

    if(_pCurrentFC != NullFC)
    {
        if(_pCurrentFC->getType().isNode() == true)
        {
            NodePtr pNode = cast_dynamic<NodePtr>(_pCurrentFC);

            if(pNode->getCore() == NullFC)
            {
                GroupPtr pGroup = Group::create();

                pNode->setCore(pGroup);
            }
        }
    }

    _fcStack.pop();

    if(_fcStack.size() != 0)
    {
        _pCurrentFC = _fcStack.top();
    }
    else
    {
        _pCurrentFC = NullFC;
    }

    if(_pCurrentFieldDesc != NULL)
    {
        _pCurrentFieldFC = _pCurrentFC;
    }
#ifdef OSG_DEBUG_VRML
    VRMLNodeHelper::decIndent();

    indentLog(VRMLNodeHelper::getIndent(), PINFO);
    PINFO << "End Node " << std::endl;
#endif
}

void VRMLFile::beginScript(const Char8 *szNodename)
{
    beginNode("Script", szNodename);
}

void VRMLFile::endScript(void)
{
    endNode();
}

void VRMLFile::beginField(const Char8  *szFieldname,
                          const UInt32  OSG_VRML_ARG(uiFieldTypeId))
{
    if(szFieldname == NULL)
        return;

#ifdef OSG_DEBUG_VRML
    indentLog(VRMLNodeHelper::getIndent(), PINFO);
    PINFO << "VRMLFile::beginField : looking for "
          << szFieldname
          << " ("
          << uiFieldTypeId
          << " | "
          << _pCurrentField
          << " | "
          << _pCurrentFieldDesc
          << ") "
          << ScanParseSkel::OSGmfNode
          << std::endl;

    VRMLNodeHelper::incIndent();
#endif

    _fStack .push(_pCurrentField    );
    _fdStack.push(_pCurrentFieldDesc);
}

void VRMLFile::endField(void)
{
    _fStack.pop();

    if(_fStack.size() != 0)
    {
        _pCurrentField = _fStack.top();
    }
    else
    {
        _pCurrentField = NULL;
    }


    _fdStack.pop();

    if(_fdStack.size() != 0)
    {
        _pCurrentFieldDesc = _fdStack.top();
    }
    else
    {
        _pCurrentFieldDesc = NULL;
    }

#ifdef OSG_DEBUG_VRML
    VRMLNodeHelper::decIndent();

    indentLog(VRMLNodeHelper::getIndent(), PINFO);
    PINFO << "VRMLFile::endField " << std::endl;
#endif
}


void VRMLFile::addFieldValue(const Char8 *szFieldVal)
{
    if(_pCurrNodeHelper != NULL)
    {
        _pCurrNodeHelper->addFieldValue(_pCurrentField, 
                                        _pCurrentFieldDesc,
                                        szFieldVal);
    }
}

void VRMLFile::beginProto(const Char8 *szProtoname)
{
    Inherited::beginProto(szProtoname);

    _pCurrNodeHelper = Inherited::_pCurrentHelper;
}

void VRMLFile::endProtoInterface(void)
{
    Inherited::endProtoInterface();
}

void VRMLFile::endProto(void)
{
    Inherited::endProto();

    if(_sNodeHelpers.size() != 0)
    {
        _pCurrNodeHelper = _sNodeHelpers.top();
    }
}


void VRMLFile::beginFieldDecl(const Char8  *szFieldType,
                              const UInt32  uiFieldTypeId,
                              const Char8  *szFieldName)
{
    Inherited::beginFieldDecl(szFieldType, uiFieldTypeId, szFieldName);

    getFieldType(szFieldName);

    beginField(szFieldName, uiFieldTypeId);
}

void VRMLFile::endFieldDecl(void)
{
    Inherited::endFieldDecl();

    endField();
}


UInt32 VRMLFile::getFieldType(const Char8 *szFieldname)
{
    UInt32   returnValue = 0;

    if(_pCurrNodeHelper == NULL)
        return returnValue;

    if(szFieldname == NULL)
        return returnValue;

    _pCurrentFieldFC   = NullFC;
    _pCurrentField     = NULL;
    _pCurrentFieldDesc = NULL;

    _pCurrNodeHelper->getFieldAndDesc(_pCurrentFC,
                                       szFieldname,
                                      _pCurrentFieldFC,
                                      _pCurrentField,
                                      _pCurrentFieldDesc);

    if(_pCurrentFieldDesc != NULL)
        returnValue = _pCurrentFieldDesc->getFieldType().getId();

#ifdef OSG_DEBUG_VRML
    indentLog(VRMLNodeHelper::getIndent(), PINFO);
    PINFO << "VRMLFile::getFieldType : Got Field and type "
          << returnValue        << " "
          << _pCurrentField     << " "
          << _pCurrentFieldDesc << " ";

    if(_pCurrentFieldDesc != NULL)
        PINFO << _pCurrentFieldDesc->getFieldType().getName() << std::endl;
    else
        PINFO << std::endl;
#endif

    return returnValue;
}

void VRMLFile::use(const Char8 *szName)
{
    SceneFileHandler::the()->updateReadProgress();
    Time beginUse = getSystemTime();

    FieldContainerPtr pUsedFC;

    // try to find a container with the given name attachment

#ifdef OSG_DEBUG_VRML
    indentLog(VRMLNodeHelper::getIndent(), PINFO);
    PINFO << "VRMLFile::use : looking for "
          << szName
          << std::endl;

    VRMLNodeHelper::incIndent();
#endif

#if 0

    pUsedFC = findReference(szName);

    if(pUsedFC == NullFC)
    {
        PWARNING << "No fieldContainer with name found to use"
                 << szName
                 << std::endl;
    }
    else
    {
        // assign nodepointer to current sf|mf field

        VRMLNodeDesc *pDesc = NULL;

        NameDescriptionMap::iterator mIt         =
            _nameDescMap.find(IDStringLink(szName));

        if(mIt != _nameDescMap.end())
        {
            pDesc = mIt->second;
        }

        if(pUsedFC->getType().isNode())
        {
            NodePtr pRootNode = cast_dynamic<NodePtr>(pUsedFC);

            pUsedFC = cloneTree(pRootNode);
        }

        if(pDesc != NULL)
        {
            if(pDesc->use(pUsedFC) == false)
            {
                setContainerFieldValue(pUsedFC);
            }
        }
        else
        {
            setContainerFieldValue(pUsedFC);
        }
    }
#endif

#ifdef OSG_DEBUG_VRML
    VRMLNodeHelper::decIndent();
#endif

    useTime += (getSystemTime() - beginUse);
}

/*-------------------------------------------------------------------------*/
/*                          Helper                                         */

void VRMLFile::scanStandardPrototypes(const Char8  *szFilename)
{
#ifdef OSG_DEBUG_VRML
    VRMLNodeHelper::resetIndent();
#endif

    preStandardProtos();
    scanFile(szFilename);
    postStandardProtos();
}

static Action::ResultE modifyMaterial(NodePtrConstArg node)
{   
    MaterialGroupPtr mg = cast_dynamic<MaterialGroupPtr>(node->getCore());
    
    if(mg == NullFC)
        return Action::Continue; 
    
    ChunkMaterialPtr cmat = cast_dynamic<ChunkMaterialPtr>(mg->getMaterial());
    
    if(cmat == NullFC)
        return Action::Continue; 
    
    TextureObjChunkPtr texc = 
        cast_dynamic<TextureObjChunkPtr>(
            cmat->find(TextureObjChunk::getClassType()));
    
    if(texc == NullFC)
        return Action::Continue;
    
    MaterialChunkPtr matc = 
        cast_dynamic<MaterialChunkPtr>(
            cmat->find(MaterialChunk::getClassType()));

    TextureEnvChunkPtr texe = 
        cast_dynamic<TextureEnvChunkPtr>(
            cmat->find(TextureEnvChunk::getClassType()));
    
    if(texe == NullFC)
    {
        texe = TextureEnvChunk::create();
        cmat->addChunk(texe);
    }

    if(matc == NullFC)
    {
        // no material chunk so we use the replace mode.
        texe->setEnvMode(GL_REPLACE);
        return Action::Continue;
    }
    
    if(matc != NullFC)
    {
        ImagePtr img = texc->getImage();

        texe->setEnvMode(GL_MODULATE);

        if(img != NullFC && img->getBpp() > 2)
        {
            // for color textures the texture replaces only the diffuse part.
            matc->setDiffuse(Color4f(1.0f, 1.0f, 1.0f, 1.0f));
        }
        
        
        // check for textures with alpha
        if(!matc->isTransparent()           && 
            img                   != NullFC &&
            img->getBpp()         ==      4   )
        {
            BlendChunkPtr blendc = 
                cast_dynamic<BlendChunkPtr>(
                    cmat->find(BlendChunk::getClassType()));

            if(blendc == NullFC)
            {
                blendc = OSG::BlendChunk::create();

                blendc->setSrcFactor (GL_SRC_ALPHA);
                blendc->setDestFactor(GL_ONE_MINUS_SRC_ALPHA);
    
                cmat->addChunk(blendc);
            }
        }
    }

    return Action::Continue;
}

NodePtr VRMLFile::getRoot(void)
{
    // now walk through all materials and modify them.
    if(_pSceneRootNode != NullFC)
    {
        // Should be handled in appearance
//        traverse(_pSceneRootNode, modifyMaterial);
    }
    
    return _pSceneRootNode;
}

/*-------------------------------------------------------------------------*/
/*                           Member                                        */

void VRMLFile::initIntExtFieldTypeMapper(void)
{
    Self::setIntExtMapping(SFBool::getClassType().getId(),
                           ScanParseSkel::OSGsfBool);

    Self::setIntExtMapping(SFColor3f::getClassType().getId(),
                           ScanParseSkel::OSGsfColor);

    Self::setIntExtMapping(SFReal32::getClassType().getId(),
                           ScanParseSkel::OSGsfFloat);

    Self::setIntExtMapping(SFImagePtr::getClassType().getId(),
                           ScanParseSkel::OSGsfImage);

    Self::setIntExtMapping(SFInt32::getClassType().getId(),
                           ScanParseSkel::OSGsfInt32);

    Self::setIntExtMapping(SFGLenum::getClassType().getId(),
                           ScanParseSkel::OSGsfInt32);


    Self::setIntExtMapping(SFQuaternion::getClassType().getId(),
                           ScanParseSkel::OSGsfRotation);

    Self::setIntExtMapping(SFString::getClassType().getId(),
                           ScanParseSkel::OSGsfString);

    Self::setIntExtMapping(SFTime::getClassType().getId(),
                           ScanParseSkel::OSGsfTime);

    Self::setIntExtMapping(SFVec2f::getClassType().getId(),
                           ScanParseSkel::OSGsfVec2f);

    Self::setIntExtMapping(SFVec3f::getClassType().getId(),
                           ScanParseSkel::OSGsfVec3f);



    Self::setIntExtMapping(MFColor3f::getClassType().getId(),
                           ScanParseSkel::OSGmfColor);

    Self::setIntExtMapping(MFReal32::getClassType().getId(),
                           ScanParseSkel::OSGmfFloat);

    Self::setIntExtMapping(MFInt32::getClassType().getId(),
                           ScanParseSkel::OSGmfInt32);

    Self::setIntExtMapping(MFGLenum::getClassType().getId(),
                           ScanParseSkel::OSGmfInt32);

    Self::setIntExtMapping(MFQuaternion::getClassType().getId(),
                           ScanParseSkel::OSGmfRotation);

    Self::setIntExtMapping(MFString::getClassType().getId(),
                           ScanParseSkel::OSGmfString);

    Self::setIntExtMapping(MFTime::getClassType().getId(),
                           ScanParseSkel::OSGmfTime);

    Self::setIntExtMapping(MFVec3f::getClassType().getId(),
                           ScanParseSkel::OSGmfVec3f);

    Self::setIntExtMapping(MFVec2f::getClassType().getId(),
                           ScanParseSkel::OSGmfVec2f);


    Self::setIntExtMapping(SFFieldContainerPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(MFFieldContainerPtr::getClassType().getId(),
                           ScanParseSkel::OSGmfNode);

    Self::setIntExtMapping(SFNodePtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(MFNodePtr::getClassType().getId(),
                           ScanParseSkel::OSGmfNode);

    /* To Base Type Mappings */

    Self::setIntExtMapping(SFUInt8::getClassType().getId(),
                           ScanParseSkel::OSGsfInt32);

    Self::setIntExtMapping(MFUInt8::getClassType().getId(),
                           ScanParseSkel::OSGmfInt32);

    Self::setIntExtMapping(SFUInt32::getClassType().getId(),
                           ScanParseSkel::OSGsfInt32);

    Self::setIntExtMapping(MFUInt32::getClassType().getId(),
                           ScanParseSkel::OSGmfInt32);

    /* To Node Mappings */

    Self::setIntExtMapping(SFNodeCorePtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFMaterialPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    // AMZ
#if 0
    Self::setIntExtMapping(SFGeoPTypesPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFGeoIndicesPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFGeoPLengthsPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFGeoColorsPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFGeoPositionsPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFGeoNormalsPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);

    Self::setIntExtMapping(SFGeoTexCoordsPtr::getClassType().getId(),
                           ScanParseSkel::OSGsfNode);
#endif
    Self::setIntExtMapping(MFStateChunkPtr::getClassType().getId(),
                           ScanParseSkel::OSGmfNode);

    //SFAttachmentMap
    Self::setIntExtMapping(SFFieldContainerAttachmentPtrMap::getClassType().getId(),
                           ScanParseSkel::OSGmfNode);

    /* extended types */

    Self::setIntExtMapping(SFMatrix::getClassType().getId(),
                           ScanParseSkel::OSGsfMatrix);

    Self::setIntExtMapping(SFPnt3f::getClassType().getId(),
                           ScanParseSkel::OSGsfPnt3f);

    Self::setIntExtMapping(MFPnt3f::getClassType().getId(),
                           ScanParseSkel::OSGmfPnt3f);
}


void VRMLFile::initExtIntFieldTypeMapper(void)
{
    Self::setExtIntMapping(ScanParseSkel::OSGsfBool,
                           SFBool::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfColor,
                           SFColor3f::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfFloat,
                           SFReal32::getClassType().getId());

/*
    Self::setExtIntMapping(SFImage::getClassType().getId(),
                     ScanParseSkel::OSGsfInt32);
                     */

    Self::setExtIntMapping(ScanParseSkel::OSGsfImage,
                           SFImagePtr::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfInt32,
                           SFInt32::getClassType().getId());


    Self::setExtIntMapping(ScanParseSkel::OSGsfRotation,
                           SFQuaternion::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfString,
                           SFString::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfTime,
                           SFTime::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfVec2f,
                           SFVec2f::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfVec3f,
                           SFVec3f::getClassType().getId());



    Self::setExtIntMapping(ScanParseSkel::OSGmfColor,
                           MFColor3f::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfFloat,
                           MFReal32::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfInt32,
                           MFInt32::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfRotation,
                           MFQuaternion::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfString,
                           MFString::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfTime,
                           MFTime::getClassType().getId());


    Self::setExtIntMapping(ScanParseSkel::OSGmfVec3f,
                           MFVec3f::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfVec2f,
                           MFVec2f::getClassType().getId());


    Self::setExtIntMapping(ScanParseSkel::OSGsfNode,
                           SFFieldContainerPtr::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfNode,
                           MFFieldContainerPtr::getClassType().getId());


    /* extended types */

    Self::setExtIntMapping(ScanParseSkel::OSGsfMatrix,
                           SFMatrix::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGsfPnt3f,
                           SFPnt3f::getClassType().getId());

    Self::setExtIntMapping(ScanParseSkel::OSGmfPnt3f,
                           MFPnt3f::getClassType().getId());
}

/* remove this, if there is a general methode to find containers */
FieldContainerPtr VRMLFile::findFCByName(const Char8  *szName,
                                               NodePtr pNode)
{
    MFNodePtr::const_iterator i;

    NamePtr           pNodename = NullFC;
    NodeCorePtr       pCore     = NullFC;
    FieldContainerPtr pFC       = NullFC;

#if 0
    // check if name matches nodename

    pNodename =
        cast_dynamic<NamePtr>(
            pNode->findAttachment(Name::getClassType().getGroupId()));

    if(pNodename != NullFC)
    {
        if(strcmp(szName, pNodename->getFieldPtr()->getValue().c_str())==0)
            return pNode;
    }
    // check if name matches corename

    pCore = pNode->getCore();

    if(pCore != NullFC)
    {
        pNodename = cast_dynamic<NamePtr>(
            pCore->findAttachment(Name::getClassType().getGroupId()));

        if(pNodename != NullFC)
        {
            if(strcmp(szName, pNodename->getFieldPtr()->getValue().c_str())==0)
                return pCore;
        }
    }

    // matching for children
    for(i  = pNode->getMFChildren()->begin();
        i != pNode->getMFChildren()->end();
        i++)
    {
        pFC = findFCByName(szName, *i);

        if(pFC != NullFC)
        {
            return pFC;
        }
    }
#endif

    return pFC;
}

FieldContainerPtr VRMLFile::findReference(const Char8 *szName)
{
    // search reference in this file
    FieldContainerPtr          returnValue = NullFC;

#if 0
    NameContainerMap::iterator mIt         =
        _nameFCMap.find(IDStringLink(szName));

    if(mIt != _nameFCMap.end())
    {
        returnValue = mIt->second;
    }
    else
    {
        returnValue = findFCByName(szName, _pSceneRootNode);

        if(returnValue == NullFC && _pLightRoot != NullFC)
        {
            returnValue = findFCByName(szName, _pLightRoot);
        }
    }
#endif

    return returnValue;
}

void VRMLFile::setContainerFieldValue(const FieldContainerPtr &pFC)
{
    if(_pCurrNodeHelper != NULL)
    {
        _pCurrNodeHelper->setContainerFieldValue( pFC,
                                                 _pCurrentFieldDesc,
                                                 _pCurrentFieldFC);
    }
}

#include "OSGVRMLProtos.inl"
