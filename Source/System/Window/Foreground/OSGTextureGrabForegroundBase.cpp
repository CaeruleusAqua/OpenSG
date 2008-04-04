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
 **     class TextureGrabForeground!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#define OSG_COMPILETEXTUREGRABFOREGROUNDINST

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>



#include <OSGTextureObjChunk.h> // Texture Class

#include "OSGTextureGrabForegroundBase.h"
#include "OSGTextureGrabForeground.h"

#include "boost/bind.hpp"

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::TextureGrabForeground
    \ingroup GrpSystemWindowForegrounds

    The GrabForeground is used for grabbing a rendered viewport into a Texture.
    See \ref PageSystemWindowForegroundGrabTexture for a description.
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var TextureObjChunkPtr TextureGrabForegroundBase::_sfTexture
    The texture to grab into.
*/

/*! \var bool            TextureGrabForegroundBase::_sfAutoResize
    Automatically resize the texture when the viewport size changes.
*/

/*! \var GLenum          TextureGrabForegroundBase::_sfBindTarget
    Enum to use for glBindTexture, if GL_NONE chosen from texture dimensionality.
*/

/*! \var GLenum          TextureGrabForegroundBase::_sfCopyTarget
    Enum to use for glCopyTexture, if GL_NONE chosen from texture dimensionality.
    Mainly useful to grab into the different parts of a CubeTexture.
*/


void TextureGrabForegroundBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFTextureObjChunkPtr::Description(
        SFTextureObjChunkPtr::getClassType(),
        "texture",
        "The texture to grab into.\n",
        TextureFieldId, TextureFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&TextureGrabForegroundBase::editHandleTexture),
        static_cast<FieldGetMethodSig >(&TextureGrabForegroundBase::getHandleTexture));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "autoResize",
        "Automatically resize the texture when the viewport size changes.\n",
        AutoResizeFieldId, AutoResizeFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&TextureGrabForegroundBase::editHandleAutoResize),
        static_cast<FieldGetMethodSig >(&TextureGrabForegroundBase::getHandleAutoResize));

    oType.addInitialDesc(pDesc);

    pDesc = new SFGLenum::Description(
        SFGLenum::getClassType(),
        "bindTarget",
        "Enum to use for glBindTexture, if GL_NONE chosen from texture dimensionality.\n",
        BindTargetFieldId, BindTargetFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&TextureGrabForegroundBase::editHandleBindTarget),
        static_cast<FieldGetMethodSig >(&TextureGrabForegroundBase::getHandleBindTarget));

    oType.addInitialDesc(pDesc);

    pDesc = new SFGLenum::Description(
        SFGLenum::getClassType(),
        "copyTarget",
        "Enum to use for glCopyTexture, if GL_NONE chosen from texture dimensionality.\n"
        "Mainly useful to grab into the different parts of a CubeTexture.\n",
        CopyTargetFieldId, CopyTargetFieldMask,
        false,
        Field::SFDefaultFlags,
        static_cast<FieldEditMethodSig>(&TextureGrabForegroundBase::editHandleCopyTarget),
        static_cast<FieldGetMethodSig >(&TextureGrabForegroundBase::getHandleCopyTarget));

    oType.addInitialDesc(pDesc);
}


TextureGrabForegroundBase::TypeObject TextureGrabForegroundBase::_type(
    TextureGrabForegroundBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    (PrototypeCreateF) &TextureGrabForegroundBase::createEmptyLocal,
    TextureGrabForeground::initMethod,
    TextureGrabForeground::exitMethod,
    (InitalInsertDescFunc) &TextureGrabForegroundBase::classDescInserter,
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"TextureGrabForeground\"\n"
    "\tparent=\"Foreground\"\n"
    "\tlibrary=\"Window\"\n"
    "\tpointerfieldtypes=\"none\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    ">\n"
    "\\ingroup GrpSystemWindowForegrounds\n"
    "\n"
    "The GrabForeground is used for grabbing a rendered viewport into a Texture.\n"
    "See \\ref PageSystemWindowForegroundGrabTexture for a description.\n"
    "\t<Field\n"
    "\t\tname=\"texture\"\n"
    "\t\ttype=\"TextureObjChunkPtr\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\tThe texture to grab into.\n"
    "\t</Field>\n"
    "\t<Field\n"
    "\t\tname=\"autoResize\"\n"
    "\t\ttype=\"bool\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"true\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "        Automatically resize the texture when the viewport size changes.\n"
    "\t</Field>\n"
    "       \t<Field\n"
    "\t\tname=\"bindTarget\"\n"
    "\t\ttype=\"GLenum\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"GL_NONE\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "        Enum to use for glBindTexture, if GL_NONE chosen from texture dimensionality.\n"
    "\t</Field>\n"
    "       \t<Field\n"
    "\t\tname=\"copyTarget\"\n"
    "\t\ttype=\"GLenum\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\tdefaultValue=\"GL_NONE\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "        Enum to use for glCopyTexture, if GL_NONE chosen from texture dimensionality.\n"
    "        Mainly useful to grab into the different parts of a CubeTexture.\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    "\\ingroup GrpSystemWindowForegrounds\n"
    "\n"
    "The GrabForeground is used for grabbing a rendered viewport into a Texture.\n"
    "See \\ref PageSystemWindowForegroundGrabTexture for a description.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &TextureGrabForegroundBase::getType(void)
{
    return _type;
}

const FieldContainerType &TextureGrabForegroundBase::getType(void) const
{
    return _type;
}

UInt32 TextureGrabForegroundBase::getContainerSize(void) const
{
    return sizeof(TextureGrabForeground);
}

/*------------------------- decorator get ------------------------------*/


//! Get the TextureGrabForeground::_sfTexture field.
const SFTextureObjChunkPtr *TextureGrabForegroundBase::getSFTexture(void) const
{
    return &_sfTexture;
}

SFBool *TextureGrabForegroundBase::editSFAutoResize(void)
{
    editSField(AutoResizeFieldMask);

    return &_sfAutoResize;
}

const SFBool *TextureGrabForegroundBase::getSFAutoResize(void) const
{
    return &_sfAutoResize;
}

#ifdef OSG_1_GET_COMPAT
SFBool              *TextureGrabForegroundBase::getSFAutoResize     (void)
{
    return this->editSFAutoResize     ();
}
#endif

SFGLenum *TextureGrabForegroundBase::editSFBindTarget(void)
{
    editSField(BindTargetFieldMask);

    return &_sfBindTarget;
}

const SFGLenum *TextureGrabForegroundBase::getSFBindTarget(void) const
{
    return &_sfBindTarget;
}

#ifdef OSG_1_GET_COMPAT
SFGLenum            *TextureGrabForegroundBase::getSFBindTarget     (void)
{
    return this->editSFBindTarget     ();
}
#endif

SFGLenum *TextureGrabForegroundBase::editSFCopyTarget(void)
{
    editSField(CopyTargetFieldMask);

    return &_sfCopyTarget;
}

const SFGLenum *TextureGrabForegroundBase::getSFCopyTarget(void) const
{
    return &_sfCopyTarget;
}

#ifdef OSG_1_GET_COMPAT
SFGLenum            *TextureGrabForegroundBase::getSFCopyTarget     (void)
{
    return this->editSFCopyTarget     ();
}
#endif





/*------------------------------ access -----------------------------------*/

UInt32 TextureGrabForegroundBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (TextureFieldMask & whichField))
    {
        returnValue += _sfTexture.getBinSize();
    }
    if(FieldBits::NoField != (AutoResizeFieldMask & whichField))
    {
        returnValue += _sfAutoResize.getBinSize();
    }
    if(FieldBits::NoField != (BindTargetFieldMask & whichField))
    {
        returnValue += _sfBindTarget.getBinSize();
    }
    if(FieldBits::NoField != (CopyTargetFieldMask & whichField))
    {
        returnValue += _sfCopyTarget.getBinSize();
    }

    return returnValue;
}

void TextureGrabForegroundBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (TextureFieldMask & whichField))
    {
        _sfTexture.copyToBin(pMem);
    }
    if(FieldBits::NoField != (AutoResizeFieldMask & whichField))
    {
        _sfAutoResize.copyToBin(pMem);
    }
    if(FieldBits::NoField != (BindTargetFieldMask & whichField))
    {
        _sfBindTarget.copyToBin(pMem);
    }
    if(FieldBits::NoField != (CopyTargetFieldMask & whichField))
    {
        _sfCopyTarget.copyToBin(pMem);
    }
}

void TextureGrabForegroundBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (TextureFieldMask & whichField))
    {
        _sfTexture.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (AutoResizeFieldMask & whichField))
    {
        _sfAutoResize.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (BindTargetFieldMask & whichField))
    {
        _sfBindTarget.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (CopyTargetFieldMask & whichField))
    {
        _sfCopyTarget.copyFromBin(pMem);
    }
}

//! create a new instance of the class
TextureGrabForegroundTransitPtr TextureGrabForegroundBase::create(void)
{
    TextureGrabForegroundTransitPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<TextureGrabForeground>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
TextureGrabForegroundTransitPtr TextureGrabForegroundBase::createLocal(BitVector bFlags)
{
    TextureGrabForegroundTransitPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<TextureGrabForeground>(tmpPtr);
    }

    return fc;
}

//! create an empty new instance of the class, do not copy the prototype
TextureGrabForegroundPtr TextureGrabForegroundBase::createEmpty(void)
{
    TextureGrabForegroundPtr returnValue;

    newPtr<TextureGrabForeground>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &= 
        ~Thread::getCurrentLocalFlags(); 

    return returnValue;
}

TextureGrabForegroundPtr TextureGrabForegroundBase::createEmptyLocal(BitVector bFlags)
{
    TextureGrabForegroundPtr returnValue;

    newPtr<TextureGrabForeground>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr TextureGrabForegroundBase::shallowCopy(void) const
{
    TextureGrabForegroundPtr tmpPtr;

    newPtr(tmpPtr, 
           dynamic_cast<const TextureGrabForeground *>(this), 
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}

FieldContainerTransitPtr TextureGrabForegroundBase::shallowCopyLocal(
    BitVector bFlags) const
{
    TextureGrabForegroundPtr tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const TextureGrabForeground *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}



/*------------------------- constructors ----------------------------------*/

TextureGrabForegroundBase::TextureGrabForegroundBase(void) :
    Inherited(),
    _sfTexture                (NullFC),
    _sfAutoResize             (bool(true)),
    _sfBindTarget             (GLenum(GL_NONE)),
    _sfCopyTarget             (GLenum(GL_NONE))
{
}

TextureGrabForegroundBase::TextureGrabForegroundBase(const TextureGrabForegroundBase &source) :
    Inherited(source),
    _sfTexture                (NullFC),
    _sfAutoResize             (source._sfAutoResize             ),
    _sfBindTarget             (source._sfBindTarget             ),
    _sfCopyTarget             (source._sfCopyTarget             )
{
}


/*-------------------------- destructors ----------------------------------*/

TextureGrabForegroundBase::~TextureGrabForegroundBase(void)
{
}

void TextureGrabForegroundBase::onCreate(const TextureGrabForeground *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {

        this->setTexture(source->getTexture());
    }
}

GetFieldHandlePtr TextureGrabForegroundBase::getHandleTexture         (void) const
{
    SFTextureObjChunkPtr::GetHandlePtr returnValue(
        new  SFTextureObjChunkPtr::GetHandle(
             &_sfTexture, 
             this->getType().getFieldDesc(TextureFieldId)));

    return returnValue;
}

EditFieldHandlePtr TextureGrabForegroundBase::editHandleTexture        (void)
{
    SFTextureObjChunkPtr::EditHandlePtr returnValue(
        new  SFTextureObjChunkPtr::EditHandle(
             &_sfTexture, 
             this->getType().getFieldDesc(TextureFieldId)));

    returnValue->setSetMethod(boost::bind(&TextureGrabForeground::setTexture, 
                                          static_cast<TextureGrabForeground *>(this), _1));

    editSField(TextureFieldMask);

    return returnValue;
}

GetFieldHandlePtr TextureGrabForegroundBase::getHandleAutoResize      (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfAutoResize, 
             this->getType().getFieldDesc(AutoResizeFieldId)));

    return returnValue;
}

EditFieldHandlePtr TextureGrabForegroundBase::editHandleAutoResize     (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfAutoResize, 
             this->getType().getFieldDesc(AutoResizeFieldId)));

    editSField(AutoResizeFieldMask);

    return returnValue;
}

GetFieldHandlePtr TextureGrabForegroundBase::getHandleBindTarget      (void) const
{
    SFGLenum::GetHandlePtr returnValue(
        new  SFGLenum::GetHandle(
             &_sfBindTarget, 
             this->getType().getFieldDesc(BindTargetFieldId)));

    return returnValue;
}

EditFieldHandlePtr TextureGrabForegroundBase::editHandleBindTarget     (void)
{
    SFGLenum::EditHandlePtr returnValue(
        new  SFGLenum::EditHandle(
             &_sfBindTarget, 
             this->getType().getFieldDesc(BindTargetFieldId)));

    editSField(BindTargetFieldMask);

    return returnValue;
}

GetFieldHandlePtr TextureGrabForegroundBase::getHandleCopyTarget      (void) const
{
    SFGLenum::GetHandlePtr returnValue(
        new  SFGLenum::GetHandle(
             &_sfCopyTarget, 
             this->getType().getFieldDesc(CopyTargetFieldId)));

    return returnValue;
}

EditFieldHandlePtr TextureGrabForegroundBase::editHandleCopyTarget     (void)
{
    SFGLenum::EditHandlePtr returnValue(
        new  SFGLenum::EditHandle(
             &_sfCopyTarget, 
             this->getType().getFieldDesc(CopyTargetFieldId)));

    editSField(CopyTargetFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void TextureGrabForegroundBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    this->execSync(static_cast<TextureGrabForegroundBase *>(&oFrom),
                   whichField,
                   oOffsets,
                   syncMode,
                   uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainerPtr TextureGrabForegroundBase::createAspectCopy(void) const
{
    TextureGrabForegroundPtr returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const TextureGrabForeground *>(this));

    return returnValue;
}
#endif

void TextureGrabForegroundBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<TextureGrabForeground *>(this)->setTexture(NullFC);


}


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<TextureGrabForegroundPtr>::_type("TextureGrabForegroundPtr", "ForegroundPtr");
#endif


OSG_END_NAMESPACE
