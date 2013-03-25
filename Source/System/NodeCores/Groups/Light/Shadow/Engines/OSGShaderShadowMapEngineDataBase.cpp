/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: dirk@opensg.org, gerrit.voss@vossg.org, carsten_neumann@gmx.net  *
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
 **     class ShaderShadowMapEngineData!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"



#include "OSGFrameBufferObject.h"       // RenderTargets Class
#include "OSGTextureBuffer.h"           // ShadowTexBuffers Class
#include "OSGTextureObjChunk.h"         // ShadowTexChunk Class
#include "OSGImage.h"                   // ShadowTexImage Class
#include "OSGChunkMaterial.h"           // LightPassMaterials Class
#include "OSGBackground.h"              // Background Class

#include "OSGShaderShadowMapEngineDataBase.h"
#include "OSGShaderShadowMapEngineData.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ShaderShadowMapEngineData
    Data use for rendering by the DSShadowMapEngine
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var FrameBufferObject * ShaderShadowMapEngineDataBase::_mfRenderTargets
    FBOs for rendering the depth texture, can be multiple for point lights.
*/

/*! \var TextureBuffer * ShaderShadowMapEngineDataBase::_mfShadowTexBuffers
    FBO Attachments holding the depth texture, can be multiple for point lights.
*/

/*! \var TextureObjChunk * ShaderShadowMapEngineDataBase::_sfShadowTexChunk
    The depth texture.
*/

/*! \var Image *         ShaderShadowMapEngineDataBase::_sfShadowTexImage
    The depth texture image.
*/

/*! \var ChunkMaterial * ShaderShadowMapEngineDataBase::_mfLightPassMaterials
    Material used to render the scene from the lights point of view.
*/

/*! \var Background *    ShaderShadowMapEngineDataBase::_sfBackground
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<ShaderShadowMapEngineData *, nsOSG>::_type(
    "ShaderShadowMapEngineDataPtr", 
    "StageDataPtr", 
    ShaderShadowMapEngineData::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(ShaderShadowMapEngineData *, nsOSG)

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ShaderShadowMapEngineDataBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFUnrecFrameBufferObjectPtr::Description(
        MFUnrecFrameBufferObjectPtr::getClassType(),
        "renderTargets",
        "FBOs for rendering the depth texture, can be multiple for point lights.\n",
        RenderTargetsFieldId, RenderTargetsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderShadowMapEngineData::editHandleRenderTargets),
        static_cast<FieldGetMethodSig >(&ShaderShadowMapEngineData::getHandleRenderTargets));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecTextureBufferPtr::Description(
        MFUnrecTextureBufferPtr::getClassType(),
        "shadowTexBuffers",
        "FBO Attachments holding the depth texture, can be multiple for point lights.\n",
        ShadowTexBuffersFieldId, ShadowTexBuffersFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderShadowMapEngineData::editHandleShadowTexBuffers),
        static_cast<FieldGetMethodSig >(&ShaderShadowMapEngineData::getHandleShadowTexBuffers));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecTextureObjChunkPtr::Description(
        SFUnrecTextureObjChunkPtr::getClassType(),
        "shadowTexChunk",
        "The depth texture.\n",
        ShadowTexChunkFieldId, ShadowTexChunkFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderShadowMapEngineData::editHandleShadowTexChunk),
        static_cast<FieldGetMethodSig >(&ShaderShadowMapEngineData::getHandleShadowTexChunk));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecImagePtr::Description(
        SFUnrecImagePtr::getClassType(),
        "shadowTexImage",
        "The depth texture image.\n",
        ShadowTexImageFieldId, ShadowTexImageFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderShadowMapEngineData::editHandleShadowTexImage),
        static_cast<FieldGetMethodSig >(&ShaderShadowMapEngineData::getHandleShadowTexImage));

    oType.addInitialDesc(pDesc);

    pDesc = new MFUnrecChunkMaterialPtr::Description(
        MFUnrecChunkMaterialPtr::getClassType(),
        "lightPassMaterials",
        "Material used to render the scene from the lights point of view.\n",
        LightPassMaterialsFieldId, LightPassMaterialsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderShadowMapEngineData::editHandleLightPassMaterials),
        static_cast<FieldGetMethodSig >(&ShaderShadowMapEngineData::getHandleLightPassMaterials));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecBackgroundPtr::Description(
        SFUnrecBackgroundPtr::getClassType(),
        "background",
        "",
        BackgroundFieldId, BackgroundFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderShadowMapEngineData::editHandleBackground),
        static_cast<FieldGetMethodSig >(&ShaderShadowMapEngineData::getHandleBackground));

    oType.addInitialDesc(pDesc);
}


ShaderShadowMapEngineDataBase::TypeObject ShaderShadowMapEngineDataBase::_type(
    ShaderShadowMapEngineDataBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&ShaderShadowMapEngineDataBase::createEmptyLocal),
    ShaderShadowMapEngineData::initMethod,
    ShaderShadowMapEngineData::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ShaderShadowMapEngineData::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"ShaderShadowMapEngineData\"\n"
    "   parent=\"StageData\"\n"
    "   library=\"Group\"\n"
    "   pointerfieldtypes=\"none\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   decoratable=\"false\"\n"
    "   useLocalIncludes=\"false\"\n"
    "   isNodeCore=\"false\"\n"
    "   isBundle=\"true\"\n"
    "   docGroupBase=\"GrpGroupLightShadowEngines\"\n"
    "   >\n"
    "  Data use for rendering by the DSShadowMapEngine\n"
    "  <Field\n"
    "     name=\"renderTargets\"\n"
    "     category=\"pointer\"\n"
    "     type=\"FrameBufferObject\"\n"
    "     cardinality=\"multi\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    FBOs for rendering the depth texture, can be multiple for point lights.\n"
    "  </Field>\n"
    "  <Field\n"
    "     name=\"shadowTexBuffers\"\n"
    "     category=\"pointer\"\n"
    "     type=\"TextureBuffer\"\n"
    "     cardinality=\"multi\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    FBO Attachments holding the depth texture, can be multiple for point lights.\n"
    "  </Field>\n"
    "  <Field\n"
    "     name=\"shadowTexChunk\"\n"
    "     category=\"pointer\"\n"
    "     type=\"TextureObjChunk\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     defaultValue=\"NULL\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    The depth texture.\n"
    "  </Field>\n"
    "  <Field\n"
    "     name=\"shadowTexImage\"\n"
    "     category=\"pointer\"\n"
    "     type=\"Image\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    The depth texture image.\n"
    "  </Field>\n"
    "  <Field\n"
    "     name=\"lightPassMaterials\"\n"
    "     category=\"pointer\"\n"
    "     type=\"ChunkMaterial\"\n"
    "     cardinality=\"multi\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     > \n"
    "    Material used to render the scene from the lights point of view.\n"
    "  </Field>\n"
    "  <Field\n"
    "     name=\"background\"\n"
    "     category=\"pointer\"\n"
    "     type=\"Background\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     defaultValue=\"NULL\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    "Data use for rendering by the DSShadowMapEngine\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ShaderShadowMapEngineDataBase::getType(void)
{
    return _type;
}

const FieldContainerType &ShaderShadowMapEngineDataBase::getType(void) const
{
    return _type;
}

UInt32 ShaderShadowMapEngineDataBase::getContainerSize(void) const
{
    return sizeof(ShaderShadowMapEngineData);
}

/*------------------------- decorator get ------------------------------*/


//! Get the ShaderShadowMapEngineData::_mfRenderTargets field.
const MFUnrecFrameBufferObjectPtr *ShaderShadowMapEngineDataBase::getMFRenderTargets(void) const
{
    return &_mfRenderTargets;
}

MFUnrecFrameBufferObjectPtr *ShaderShadowMapEngineDataBase::editMFRenderTargets  (void)
{
    editMField(RenderTargetsFieldMask, _mfRenderTargets);

    return &_mfRenderTargets;
}
FrameBufferObject * ShaderShadowMapEngineDataBase::getRenderTargets(const UInt32 index) const
{
    return _mfRenderTargets[index];
}

//! Get the ShaderShadowMapEngineData::_mfShadowTexBuffers field.
const MFUnrecTextureBufferPtr *ShaderShadowMapEngineDataBase::getMFShadowTexBuffers(void) const
{
    return &_mfShadowTexBuffers;
}

MFUnrecTextureBufferPtr *ShaderShadowMapEngineDataBase::editMFShadowTexBuffers(void)
{
    editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);

    return &_mfShadowTexBuffers;
}
TextureBuffer * ShaderShadowMapEngineDataBase::getShadowTexBuffers(const UInt32 index) const
{
    return _mfShadowTexBuffers[index];
}

//! Get the ShaderShadowMapEngineData::_sfShadowTexChunk field.
const SFUnrecTextureObjChunkPtr *ShaderShadowMapEngineDataBase::getSFShadowTexChunk(void) const
{
    return &_sfShadowTexChunk;
}

SFUnrecTextureObjChunkPtr *ShaderShadowMapEngineDataBase::editSFShadowTexChunk (void)
{
    editSField(ShadowTexChunkFieldMask);

    return &_sfShadowTexChunk;
}

//! Get the value of the ShaderShadowMapEngineData::_sfShadowTexChunk field.
TextureObjChunk * ShaderShadowMapEngineDataBase::getShadowTexChunk(void) const
{
    return _sfShadowTexChunk.getValue();
}

//! Set the value of the ShaderShadowMapEngineData::_sfShadowTexChunk field.
void ShaderShadowMapEngineDataBase::setShadowTexChunk(TextureObjChunk * const value)
{
    editSField(ShadowTexChunkFieldMask);

    _sfShadowTexChunk.setValue(value);
}


//! Get the ShaderShadowMapEngineData::_sfShadowTexImage field.
const SFUnrecImagePtr *ShaderShadowMapEngineDataBase::getSFShadowTexImage(void) const
{
    return &_sfShadowTexImage;
}

SFUnrecImagePtr     *ShaderShadowMapEngineDataBase::editSFShadowTexImage (void)
{
    editSField(ShadowTexImageFieldMask);

    return &_sfShadowTexImage;
}

//! Get the value of the ShaderShadowMapEngineData::_sfShadowTexImage field.
Image * ShaderShadowMapEngineDataBase::getShadowTexImage(void) const
{
    return _sfShadowTexImage.getValue();
}

//! Set the value of the ShaderShadowMapEngineData::_sfShadowTexImage field.
void ShaderShadowMapEngineDataBase::setShadowTexImage(Image * const value)
{
    editSField(ShadowTexImageFieldMask);

    _sfShadowTexImage.setValue(value);
}


//! Get the ShaderShadowMapEngineData::_mfLightPassMaterials field.
const MFUnrecChunkMaterialPtr *ShaderShadowMapEngineDataBase::getMFLightPassMaterials(void) const
{
    return &_mfLightPassMaterials;
}

MFUnrecChunkMaterialPtr *ShaderShadowMapEngineDataBase::editMFLightPassMaterials(void)
{
    editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);

    return &_mfLightPassMaterials;
}
ChunkMaterial * ShaderShadowMapEngineDataBase::getLightPassMaterials(const UInt32 index) const
{
    return _mfLightPassMaterials[index];
}

//! Get the ShaderShadowMapEngineData::_sfBackground field.
const SFUnrecBackgroundPtr *ShaderShadowMapEngineDataBase::getSFBackground(void) const
{
    return &_sfBackground;
}

SFUnrecBackgroundPtr *ShaderShadowMapEngineDataBase::editSFBackground     (void)
{
    editSField(BackgroundFieldMask);

    return &_sfBackground;
}

//! Get the value of the ShaderShadowMapEngineData::_sfBackground field.
Background * ShaderShadowMapEngineDataBase::getBackground(void) const
{
    return _sfBackground.getValue();
}

//! Set the value of the ShaderShadowMapEngineData::_sfBackground field.
void ShaderShadowMapEngineDataBase::setBackground(Background * const value)
{
    editSField(BackgroundFieldMask);

    _sfBackground.setValue(value);
}




void ShaderShadowMapEngineDataBase::pushToRenderTargets(FrameBufferObject * const value)
{
    editMField(RenderTargetsFieldMask, _mfRenderTargets);

    _mfRenderTargets.push_back(value);
}

void ShaderShadowMapEngineDataBase::assignRenderTargets(const MFUnrecFrameBufferObjectPtr &value)
{
    MFUnrecFrameBufferObjectPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecFrameBufferObjectPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<ShaderShadowMapEngineData *>(this)->clearRenderTargets();

    while(elemIt != elemEnd)
    {
        this->pushToRenderTargets(*elemIt);

        ++elemIt;
    }
}

void ShaderShadowMapEngineDataBase::removeFromRenderTargets(UInt32 uiIndex)
{
    if(uiIndex < _mfRenderTargets.size())
    {
        editMField(RenderTargetsFieldMask, _mfRenderTargets);

        _mfRenderTargets.erase(uiIndex);
    }
}

void ShaderShadowMapEngineDataBase::removeObjFromRenderTargets(FrameBufferObject * const value)
{
    Int32 iElemIdx = _mfRenderTargets.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(RenderTargetsFieldMask, _mfRenderTargets);

        _mfRenderTargets.erase(iElemIdx);
    }
}
void ShaderShadowMapEngineDataBase::clearRenderTargets(void)
{
    editMField(RenderTargetsFieldMask, _mfRenderTargets);


    _mfRenderTargets.clear();
}

void ShaderShadowMapEngineDataBase::pushToShadowTexBuffers(TextureBuffer * const value)
{
    editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);

    _mfShadowTexBuffers.push_back(value);
}

void ShaderShadowMapEngineDataBase::assignShadowTexBuffers(const MFUnrecTextureBufferPtr &value)
{
    MFUnrecTextureBufferPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecTextureBufferPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<ShaderShadowMapEngineData *>(this)->clearShadowTexBuffers();

    while(elemIt != elemEnd)
    {
        this->pushToShadowTexBuffers(*elemIt);

        ++elemIt;
    }
}

void ShaderShadowMapEngineDataBase::removeFromShadowTexBuffers(UInt32 uiIndex)
{
    if(uiIndex < _mfShadowTexBuffers.size())
    {
        editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);

        _mfShadowTexBuffers.erase(uiIndex);
    }
}

void ShaderShadowMapEngineDataBase::removeObjFromShadowTexBuffers(TextureBuffer * const value)
{
    Int32 iElemIdx = _mfShadowTexBuffers.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);

        _mfShadowTexBuffers.erase(iElemIdx);
    }
}
void ShaderShadowMapEngineDataBase::clearShadowTexBuffers(void)
{
    editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);


    _mfShadowTexBuffers.clear();
}

void ShaderShadowMapEngineDataBase::pushToLightPassMaterials(ChunkMaterial * const value)
{
    editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);

    _mfLightPassMaterials.push_back(value);
}

void ShaderShadowMapEngineDataBase::assignLightPassMaterials(const MFUnrecChunkMaterialPtr &value)
{
    MFUnrecChunkMaterialPtr::const_iterator elemIt  =
        value.begin();
    MFUnrecChunkMaterialPtr::const_iterator elemEnd =
        value.end  ();

    static_cast<ShaderShadowMapEngineData *>(this)->clearLightPassMaterials();

    while(elemIt != elemEnd)
    {
        this->pushToLightPassMaterials(*elemIt);

        ++elemIt;
    }
}

void ShaderShadowMapEngineDataBase::removeFromLightPassMaterials(UInt32 uiIndex)
{
    if(uiIndex < _mfLightPassMaterials.size())
    {
        editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);

        _mfLightPassMaterials.erase(uiIndex);
    }
}

void ShaderShadowMapEngineDataBase::removeObjFromLightPassMaterials(ChunkMaterial * const value)
{
    Int32 iElemIdx = _mfLightPassMaterials.findIndex(value);

    if(iElemIdx != -1)
    {
        editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);

        _mfLightPassMaterials.erase(iElemIdx);
    }
}
void ShaderShadowMapEngineDataBase::clearLightPassMaterials(void)
{
    editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);


    _mfLightPassMaterials.clear();
}



/*------------------------------ access -----------------------------------*/

SizeT ShaderShadowMapEngineDataBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (RenderTargetsFieldMask & whichField))
    {
        returnValue += _mfRenderTargets.getBinSize();
    }
    if(FieldBits::NoField != (ShadowTexBuffersFieldMask & whichField))
    {
        returnValue += _mfShadowTexBuffers.getBinSize();
    }
    if(FieldBits::NoField != (ShadowTexChunkFieldMask & whichField))
    {
        returnValue += _sfShadowTexChunk.getBinSize();
    }
    if(FieldBits::NoField != (ShadowTexImageFieldMask & whichField))
    {
        returnValue += _sfShadowTexImage.getBinSize();
    }
    if(FieldBits::NoField != (LightPassMaterialsFieldMask & whichField))
    {
        returnValue += _mfLightPassMaterials.getBinSize();
    }
    if(FieldBits::NoField != (BackgroundFieldMask & whichField))
    {
        returnValue += _sfBackground.getBinSize();
    }

    return returnValue;
}

void ShaderShadowMapEngineDataBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (RenderTargetsFieldMask & whichField))
    {
        _mfRenderTargets.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShadowTexBuffersFieldMask & whichField))
    {
        _mfShadowTexBuffers.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShadowTexChunkFieldMask & whichField))
    {
        _sfShadowTexChunk.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShadowTexImageFieldMask & whichField))
    {
        _sfShadowTexImage.copyToBin(pMem);
    }
    if(FieldBits::NoField != (LightPassMaterialsFieldMask & whichField))
    {
        _mfLightPassMaterials.copyToBin(pMem);
    }
    if(FieldBits::NoField != (BackgroundFieldMask & whichField))
    {
        _sfBackground.copyToBin(pMem);
    }
}

void ShaderShadowMapEngineDataBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (RenderTargetsFieldMask & whichField))
    {
        editMField(RenderTargetsFieldMask, _mfRenderTargets);
        _mfRenderTargets.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShadowTexBuffersFieldMask & whichField))
    {
        editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);
        _mfShadowTexBuffers.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShadowTexChunkFieldMask & whichField))
    {
        editSField(ShadowTexChunkFieldMask);
        _sfShadowTexChunk.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShadowTexImageFieldMask & whichField))
    {
        editSField(ShadowTexImageFieldMask);
        _sfShadowTexImage.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (LightPassMaterialsFieldMask & whichField))
    {
        editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);
        _mfLightPassMaterials.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (BackgroundFieldMask & whichField))
    {
        editSField(BackgroundFieldMask);
        _sfBackground.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ShaderShadowMapEngineDataTransitPtr ShaderShadowMapEngineDataBase::createLocal(BitVector bFlags)
{
    ShaderShadowMapEngineDataTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ShaderShadowMapEngineData>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ShaderShadowMapEngineDataTransitPtr ShaderShadowMapEngineDataBase::createDependent(BitVector bFlags)
{
    ShaderShadowMapEngineDataTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ShaderShadowMapEngineData>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ShaderShadowMapEngineDataTransitPtr ShaderShadowMapEngineDataBase::create(void)
{
    return createLocal();
}

ShaderShadowMapEngineData *ShaderShadowMapEngineDataBase::createEmptyLocal(BitVector bFlags)
{
    ShaderShadowMapEngineData *returnValue;

    newPtr<ShaderShadowMapEngineData>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ShaderShadowMapEngineData *ShaderShadowMapEngineDataBase::createEmpty(void)
{
    return createEmptyLocal();
}


FieldContainerTransitPtr ShaderShadowMapEngineDataBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ShaderShadowMapEngineData *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderShadowMapEngineData *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderShadowMapEngineDataBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ShaderShadowMapEngineData *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderShadowMapEngineData *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderShadowMapEngineDataBase::shallowCopy(void) const
{
    return shallowCopyLocal();
}




/*------------------------- constructors ----------------------------------*/

ShaderShadowMapEngineDataBase::ShaderShadowMapEngineDataBase(void) :
    Inherited(),
    _mfRenderTargets          (),
    _mfShadowTexBuffers       (),
    _sfShadowTexChunk         (NULL),
    _sfShadowTexImage         (NULL),
    _mfLightPassMaterials     (),
    _sfBackground             (NULL)
{
}

ShaderShadowMapEngineDataBase::ShaderShadowMapEngineDataBase(const ShaderShadowMapEngineDataBase &source) :
    Inherited(source),
    _mfRenderTargets          (),
    _mfShadowTexBuffers       (),
    _sfShadowTexChunk         (NULL),
    _sfShadowTexImage         (NULL),
    _mfLightPassMaterials     (),
    _sfBackground             (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

ShaderShadowMapEngineDataBase::~ShaderShadowMapEngineDataBase(void)
{
}

void ShaderShadowMapEngineDataBase::onCreate(const ShaderShadowMapEngineData *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        ShaderShadowMapEngineData *pThis = static_cast<ShaderShadowMapEngineData *>(this);

        MFUnrecFrameBufferObjectPtr::const_iterator RenderTargetsIt  =
            source->_mfRenderTargets.begin();
        MFUnrecFrameBufferObjectPtr::const_iterator RenderTargetsEnd =
            source->_mfRenderTargets.end  ();

        while(RenderTargetsIt != RenderTargetsEnd)
        {
            pThis->pushToRenderTargets(*RenderTargetsIt);

            ++RenderTargetsIt;
        }

        MFUnrecTextureBufferPtr::const_iterator ShadowTexBuffersIt  =
            source->_mfShadowTexBuffers.begin();
        MFUnrecTextureBufferPtr::const_iterator ShadowTexBuffersEnd =
            source->_mfShadowTexBuffers.end  ();

        while(ShadowTexBuffersIt != ShadowTexBuffersEnd)
        {
            pThis->pushToShadowTexBuffers(*ShadowTexBuffersIt);

            ++ShadowTexBuffersIt;
        }

        pThis->setShadowTexChunk(source->getShadowTexChunk());

        pThis->setShadowTexImage(source->getShadowTexImage());

        MFUnrecChunkMaterialPtr::const_iterator LightPassMaterialsIt  =
            source->_mfLightPassMaterials.begin();
        MFUnrecChunkMaterialPtr::const_iterator LightPassMaterialsEnd =
            source->_mfLightPassMaterials.end  ();

        while(LightPassMaterialsIt != LightPassMaterialsEnd)
        {
            pThis->pushToLightPassMaterials(*LightPassMaterialsIt);

            ++LightPassMaterialsIt;
        }

        pThis->setBackground(source->getBackground());
    }
}

GetFieldHandlePtr ShaderShadowMapEngineDataBase::getHandleRenderTargets   (void) const
{
    MFUnrecFrameBufferObjectPtr::GetHandlePtr returnValue(
        new  MFUnrecFrameBufferObjectPtr::GetHandle(
             &_mfRenderTargets,
             this->getType().getFieldDesc(RenderTargetsFieldId),
             const_cast<ShaderShadowMapEngineDataBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderShadowMapEngineDataBase::editHandleRenderTargets  (void)
{
    MFUnrecFrameBufferObjectPtr::EditHandlePtr returnValue(
        new  MFUnrecFrameBufferObjectPtr::EditHandle(
             &_mfRenderTargets,
             this->getType().getFieldDesc(RenderTargetsFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&ShaderShadowMapEngineData::pushToRenderTargets,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&ShaderShadowMapEngineData::removeFromRenderTargets,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&ShaderShadowMapEngineData::removeObjFromRenderTargets,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&ShaderShadowMapEngineData::clearRenderTargets,
                    static_cast<ShaderShadowMapEngineData *>(this)));

    editMField(RenderTargetsFieldMask, _mfRenderTargets);

    return returnValue;
}

GetFieldHandlePtr ShaderShadowMapEngineDataBase::getHandleShadowTexBuffers (void) const
{
    MFUnrecTextureBufferPtr::GetHandlePtr returnValue(
        new  MFUnrecTextureBufferPtr::GetHandle(
             &_mfShadowTexBuffers,
             this->getType().getFieldDesc(ShadowTexBuffersFieldId),
             const_cast<ShaderShadowMapEngineDataBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderShadowMapEngineDataBase::editHandleShadowTexBuffers(void)
{
    MFUnrecTextureBufferPtr::EditHandlePtr returnValue(
        new  MFUnrecTextureBufferPtr::EditHandle(
             &_mfShadowTexBuffers,
             this->getType().getFieldDesc(ShadowTexBuffersFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&ShaderShadowMapEngineData::pushToShadowTexBuffers,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&ShaderShadowMapEngineData::removeFromShadowTexBuffers,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&ShaderShadowMapEngineData::removeObjFromShadowTexBuffers,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&ShaderShadowMapEngineData::clearShadowTexBuffers,
                    static_cast<ShaderShadowMapEngineData *>(this)));

    editMField(ShadowTexBuffersFieldMask, _mfShadowTexBuffers);

    return returnValue;
}

GetFieldHandlePtr ShaderShadowMapEngineDataBase::getHandleShadowTexChunk  (void) const
{
    SFUnrecTextureObjChunkPtr::GetHandlePtr returnValue(
        new  SFUnrecTextureObjChunkPtr::GetHandle(
             &_sfShadowTexChunk,
             this->getType().getFieldDesc(ShadowTexChunkFieldId),
             const_cast<ShaderShadowMapEngineDataBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderShadowMapEngineDataBase::editHandleShadowTexChunk (void)
{
    SFUnrecTextureObjChunkPtr::EditHandlePtr returnValue(
        new  SFUnrecTextureObjChunkPtr::EditHandle(
             &_sfShadowTexChunk,
             this->getType().getFieldDesc(ShadowTexChunkFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&ShaderShadowMapEngineData::setShadowTexChunk,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));

    editSField(ShadowTexChunkFieldMask);

    return returnValue;
}

GetFieldHandlePtr ShaderShadowMapEngineDataBase::getHandleShadowTexImage  (void) const
{
    SFUnrecImagePtr::GetHandlePtr returnValue(
        new  SFUnrecImagePtr::GetHandle(
             &_sfShadowTexImage,
             this->getType().getFieldDesc(ShadowTexImageFieldId),
             const_cast<ShaderShadowMapEngineDataBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderShadowMapEngineDataBase::editHandleShadowTexImage (void)
{
    SFUnrecImagePtr::EditHandlePtr returnValue(
        new  SFUnrecImagePtr::EditHandle(
             &_sfShadowTexImage,
             this->getType().getFieldDesc(ShadowTexImageFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&ShaderShadowMapEngineData::setShadowTexImage,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));

    editSField(ShadowTexImageFieldMask);

    return returnValue;
}

GetFieldHandlePtr ShaderShadowMapEngineDataBase::getHandleLightPassMaterials (void) const
{
    MFUnrecChunkMaterialPtr::GetHandlePtr returnValue(
        new  MFUnrecChunkMaterialPtr::GetHandle(
             &_mfLightPassMaterials,
             this->getType().getFieldDesc(LightPassMaterialsFieldId),
             const_cast<ShaderShadowMapEngineDataBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderShadowMapEngineDataBase::editHandleLightPassMaterials(void)
{
    MFUnrecChunkMaterialPtr::EditHandlePtr returnValue(
        new  MFUnrecChunkMaterialPtr::EditHandle(
             &_mfLightPassMaterials,
             this->getType().getFieldDesc(LightPassMaterialsFieldId),
             this));

    returnValue->setAddMethod(
        boost::bind(&ShaderShadowMapEngineData::pushToLightPassMaterials,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setRemoveMethod(
        boost::bind(&ShaderShadowMapEngineData::removeFromLightPassMaterials,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setRemoveObjMethod(
        boost::bind(&ShaderShadowMapEngineData::removeObjFromLightPassMaterials,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));
    returnValue->setClearMethod(
        boost::bind(&ShaderShadowMapEngineData::clearLightPassMaterials,
                    static_cast<ShaderShadowMapEngineData *>(this)));

    editMField(LightPassMaterialsFieldMask, _mfLightPassMaterials);

    return returnValue;
}

GetFieldHandlePtr ShaderShadowMapEngineDataBase::getHandleBackground      (void) const
{
    SFUnrecBackgroundPtr::GetHandlePtr returnValue(
        new  SFUnrecBackgroundPtr::GetHandle(
             &_sfBackground,
             this->getType().getFieldDesc(BackgroundFieldId),
             const_cast<ShaderShadowMapEngineDataBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ShaderShadowMapEngineDataBase::editHandleBackground     (void)
{
    SFUnrecBackgroundPtr::EditHandlePtr returnValue(
        new  SFUnrecBackgroundPtr::EditHandle(
             &_sfBackground,
             this->getType().getFieldDesc(BackgroundFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&ShaderShadowMapEngineData::setBackground,
                    static_cast<ShaderShadowMapEngineData *>(this), _1));

    editSField(BackgroundFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ShaderShadowMapEngineDataBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ShaderShadowMapEngineData *pThis = static_cast<ShaderShadowMapEngineData *>(this);

    pThis->execSync(static_cast<ShaderShadowMapEngineData *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ShaderShadowMapEngineDataBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ShaderShadowMapEngineData *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ShaderShadowMapEngineData *>(pRefAspect),
                  dynamic_cast<const ShaderShadowMapEngineData *>(this));

    return returnValue;
}
#endif

void ShaderShadowMapEngineDataBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<ShaderShadowMapEngineData *>(this)->clearRenderTargets();

    static_cast<ShaderShadowMapEngineData *>(this)->clearShadowTexBuffers();

    static_cast<ShaderShadowMapEngineData *>(this)->setShadowTexChunk(NULL);

    static_cast<ShaderShadowMapEngineData *>(this)->setShadowTexImage(NULL);

    static_cast<ShaderShadowMapEngineData *>(this)->clearLightPassMaterials();

    static_cast<ShaderShadowMapEngineData *>(this)->setBackground(NULL);


}


OSG_END_NAMESPACE
