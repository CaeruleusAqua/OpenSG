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
 **     class Viewarea!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"



#include "OSGRenderOptions.h"           // RenderOptions Class

#include "OSGViewareaBase.h"
#include "OSGViewarea.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Viewarea
    A Viewport is a part of the Window it is attached to used for rendering. See
    \ref PageSystemWindowViewports for a description.

    The size of the viewport is defined by the _sfLeft, _sfRight, _sfBottom and
    _sfTop Fields. The Window this Viewport is attached is stored in _sfWindow.
    _sfBackground defines the background clearing method, the
    _sfRoot and _sfCamera Fields the scene being rendered and the camera used to
    view it. The optional _mfForegrounds define which information are added or
    actions are executed after the Viewport has been rendered.

    \ext

    To create a new Viewport the draw and render methods should be overridden. 

    \endext

    \dev

    When adding fields to the Viewport, make sure to add the code to copy them to
    all the different ClusterWindows!

    \enddev
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Real32          ViewareaBase::_sfLeft
    The left edge of the viewport. Values between 0 and 1 are relative to the 
    size of the Window, values >1 are absolute pixel coordinates.
    All other values are illegal.
*/

/*! \var Real32          ViewareaBase::_sfRight
    The right edge of the viewport. Values between 0 and 1 are relative to the 
    size of   the Window, values >1 are absolute pixel coordinates.
    All other values are illegal.
*/

/*! \var Real32          ViewareaBase::_sfBottom
    The bottom edge of the viewport. Values between 0 and 1 are relative to 
    the size of the Window, values >1 are absolute pixel coordinates.
    All other values are illegal.
*/

/*! \var Real32          ViewareaBase::_sfTop
    The top edge of the viewport. Values between 0 and 1 are relative to the 
    size of the Window, values >1 are absolute pixel coordinates.
    All other values are illegal.
*/

/*! \var UInt32          ViewareaBase::_sfTravMask
    The foreground additions to the rendered image.
*/

/*! \var bool            ViewareaBase::_sfEnabled
    Enabled is used to turn drawing on and off of a viewport.
*/

/*! \var Real32          ViewareaBase::_sfDrawTime
    Drawtime of the last frame using this viewport.
*/

/*! \var Int32           ViewareaBase::_sfDrawableId
    DrawableId to select viewport dependent elements (e.g. Distortion filter).
*/

/*! \var RenderOptions * ViewareaBase::_sfRenderOptions
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<Viewarea *, nsOSG>::_type(
    "ViewareaPtr", 
    "AttachmentContainerPtr", 
    Viewarea::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(Viewarea *, nsOSG)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           Viewarea *,
                           nsOSG);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           Viewarea *,
                           nsOSG);

DataType &FieldTraits< Viewarea *, nsOSG + 1 >::getType(void)
{
    return FieldTraits<Viewarea *, nsOSG>::getType();
}


OSG_EXPORT_PTR_MFIELD(ChildPointerMField,
                      Viewarea *,
                      UnrecordedRefCountPolicy,
                      nsOSG + 1);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void ViewareaBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "left",
        "The left edge of the viewport. Values between 0 and 1 are relative to the \n"
        "size of the Window, values >1 are absolute pixel coordinates.\n"
        "All other values are illegal.\n",
        LeftFieldId, LeftFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleLeft),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleLeft));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "right",
        "The right edge of the viewport. Values between 0 and 1 are relative to the \n"
        "size of   the Window, values >1 are absolute pixel coordinates.\n"
        "All other values are illegal.\n",
        RightFieldId, RightFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleRight),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleRight));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "bottom",
        "The bottom edge of the viewport. Values between 0 and 1 are relative to \n"
        "the size of the Window, values >1 are absolute pixel coordinates.\n"
        "All other values are illegal.\n",
        BottomFieldId, BottomFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleBottom),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleBottom));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "top",
        "The top edge of the viewport. Values between 0 and 1 are relative to the \n"
        "size of the Window, values >1 are absolute pixel coordinates.\n"
        "All other values are illegal.\n",
        TopFieldId, TopFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleTop),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleTop));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "travMask",
        "The foreground additions to the rendered image.\n",
        TravMaskFieldId, TravMaskFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleTravMask),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleTravMask));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "enabled",
        "Enabled is used to turn drawing on and off of a viewport.\n",
        EnabledFieldId, EnabledFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleEnabled),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleEnabled));

    oType.addInitialDesc(pDesc);

    pDesc = new SFReal32::Description(
        SFReal32::getClassType(),
        "drawTime",
        "Drawtime of the last frame using this viewport.\n",
        DrawTimeFieldId, DrawTimeFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleDrawTime),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleDrawTime));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "drawableId",
        "DrawableId to select viewport dependent elements (e.g. Distortion filter).\n",
        DrawableIdFieldId, DrawableIdFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleDrawableId),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleDrawableId));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecRenderOptionsPtr::Description(
        SFUnrecRenderOptionsPtr::getClassType(),
        "renderOptions",
        "",
        RenderOptionsFieldId, RenderOptionsFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Viewarea::editHandleRenderOptions),
        static_cast<FieldGetMethodSig >(&Viewarea::getHandleRenderOptions));

    oType.addInitialDesc(pDesc);
}


ViewareaBase::TypeObject ViewareaBase::_type(
    ViewareaBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&ViewareaBase::createEmptyLocal),
    Viewarea::initMethod,
    Viewarea::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&Viewarea::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"Viewarea\"\n"
    "   parent=\"AttachmentContainer\"\n"
    "   library=\"System\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   childFields=\"multi\"\n"
    "   docGroupBase=\"GrpSystemWindow\"\n"
    "   >\n"
    "\n"
    "  A Viewport is a part of the Window it is attached to used for rendering. See\n"
    "  \\ref PageSystemWindowViewports for a description.\n"
    "  \n"
    "  The size of the viewport is defined by the _sfLeft, _sfRight, _sfBottom and\n"
    "  _sfTop Fields. The Window this Viewport is attached is stored in _sfWindow.\n"
    "  _sfBackground defines the background clearing method, the\n"
    "  _sfRoot and _sfCamera Fields the scene being rendered and the camera used to\n"
    "  view it. The optional _mfForegrounds define which information are added or\n"
    "  actions are executed after the Viewport has been rendered.\n"
    "  \n"
    "  \\ext\n"
    "  \n"
    "  To create a new Viewport the draw and render methods should be overridden. \n"
    "  \n"
    "  \\endext\n"
    "\n"
    "  \\dev\n"
    "  \n"
    "  When adding fields to the Viewport, make sure to add the code to copy them to\n"
    "  all the different ClusterWindows!\n"
    "  \n"
    "  \\enddev\n"
    "  <Field\n"
    "      name=\"left\"\n"
    "      type=\"Real32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"0.f\"\n"
    "      >\n"
    "    The left edge of the viewport. Values between 0 and 1 are relative to the \n"
    "    size of the Window, values &gt; 1 are absolute pixel coordinates.\n"
    "    All other values are illegal.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"right\"\n"
    "      type=\"Real32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"1.f\"\n"
    "      >\n"
    "    The right edge of the viewport. Values between 0 and 1 are relative to the \n"
    "    size of   the Window, values &gt; 1 are absolute pixel coordinates.\n"
    "    All other values are illegal.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"bottom\"\n"
    "      type=\"Real32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"0.f\"\n"
    "      >\n"
    "    The bottom edge of the viewport. Values between 0 and 1 are relative to \n"
    "    the size of the Window, values &gt; 1 are absolute pixel coordinates.\n"
    "    All other values are illegal.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"top\"\n"
    "      type=\"Real32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"1.f\"\n"
    "      >\n"
    "    The top edge of the viewport. Values between 0 and 1 are relative to the \n"
    "    size of the Window, values &gt; 1 are absolute pixel coordinates.\n"
    "    All other values are illegal.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"travMask\"\n"
    "      type=\"UInt32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"TypeTraits&lt;UInt32&gt;::getMax()\"\n"
    "      >\n"
    "    The foreground additions to the rendered image.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"enabled\"\n"
    "      type=\"bool\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"true\"\n"
    "      >\n"
    "    Enabled is used to turn drawing on and off of a viewport.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"drawTime\"\n"
    "      type=\"Real32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"internal\"\n"
    "      defaultValue=\"0.0f\"\n"
    "      access=\"public\"\n"
    "      >\n"
    "    Drawtime of the last frame using this viewport.\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"drawableId\"\n"
    "      type=\"Int32\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"internal\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"-1\"\n"
    "      >\n"
    "    DrawableId to select viewport dependent elements (e.g. Distortion filter).\n"
    "  </Field>\n"
    "  <Field\n"
    "      name=\"renderOptions\"\n"
    "      type=\"RenderOptionsPtr\"\n"
    "      cardinality=\"single\"\n"
    "      visibility=\"external\"\n"
    "      access=\"public\"\n"
    "      defaultValue=\"NULL\"\n"
    "      >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    "A Viewport is a part of the Window it is attached to used for rendering. See\n"
    "\\ref PageSystemWindowViewports for a description.\n"
    "\n"
    "The size of the viewport is defined by the _sfLeft, _sfRight, _sfBottom and\n"
    "_sfTop Fields. The Window this Viewport is attached is stored in _sfWindow.\n"
    "_sfBackground defines the background clearing method, the\n"
    "_sfRoot and _sfCamera Fields the scene being rendered and the camera used to\n"
    "view it. The optional _mfForegrounds define which information are added or\n"
    "actions are executed after the Viewport has been rendered.\n"
    "\n"
    "\\ext\n"
    "\n"
    "To create a new Viewport the draw and render methods should be overridden. \n"
    "\n"
    "\\endext\n"
    "\n"
    "\\dev\n"
    "\n"
    "When adding fields to the Viewport, make sure to add the code to copy them to\n"
    "all the different ClusterWindows!\n"
    "\n"
    "\\enddev\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ViewareaBase::getType(void)
{
    return _type;
}

const FieldContainerType &ViewareaBase::getType(void) const
{
    return _type;
}

UInt32 ViewareaBase::getContainerSize(void) const
{
    return sizeof(Viewarea);
}

/*------------------------- decorator get ------------------------------*/


SFReal32 *ViewareaBase::editSFLeft(void)
{
    editSField(LeftFieldMask);

    return &_sfLeft;
}

const SFReal32 *ViewareaBase::getSFLeft(void) const
{
    return &_sfLeft;
}


SFReal32 *ViewareaBase::editSFRight(void)
{
    editSField(RightFieldMask);

    return &_sfRight;
}

const SFReal32 *ViewareaBase::getSFRight(void) const
{
    return &_sfRight;
}


SFReal32 *ViewareaBase::editSFBottom(void)
{
    editSField(BottomFieldMask);

    return &_sfBottom;
}

const SFReal32 *ViewareaBase::getSFBottom(void) const
{
    return &_sfBottom;
}


SFReal32 *ViewareaBase::editSFTop(void)
{
    editSField(TopFieldMask);

    return &_sfTop;
}

const SFReal32 *ViewareaBase::getSFTop(void) const
{
    return &_sfTop;
}


SFUInt32 *ViewareaBase::editSFTravMask(void)
{
    editSField(TravMaskFieldMask);

    return &_sfTravMask;
}

const SFUInt32 *ViewareaBase::getSFTravMask(void) const
{
    return &_sfTravMask;
}


SFBool *ViewareaBase::editSFEnabled(void)
{
    editSField(EnabledFieldMask);

    return &_sfEnabled;
}

const SFBool *ViewareaBase::getSFEnabled(void) const
{
    return &_sfEnabled;
}


SFReal32 *ViewareaBase::editSFDrawTime(void)
{
    editSField(DrawTimeFieldMask);

    return &_sfDrawTime;
}

const SFReal32 *ViewareaBase::getSFDrawTime(void) const
{
    return &_sfDrawTime;
}


SFInt32 *ViewareaBase::editSFDrawableId(void)
{
    editSField(DrawableIdFieldMask);

    return &_sfDrawableId;
}

const SFInt32 *ViewareaBase::getSFDrawableId(void) const
{
    return &_sfDrawableId;
}


//! Get the Viewarea::_sfRenderOptions field.
const SFUnrecRenderOptionsPtr *ViewareaBase::getSFRenderOptions(void) const
{
    return &_sfRenderOptions;
}

SFUnrecRenderOptionsPtr *ViewareaBase::editSFRenderOptions  (void)
{
    editSField(RenderOptionsFieldMask);

    return &_sfRenderOptions;
}

//! Get the value of the Viewarea::_sfRenderOptions field.
RenderOptions * ViewareaBase::getRenderOptions(void) const
{
    return _sfRenderOptions.getValue();
}

//! Set the value of the Viewarea::_sfRenderOptions field.
void ViewareaBase::setRenderOptions(RenderOptions * const value)
{
    editSField(RenderOptionsFieldMask);

    _sfRenderOptions.setValue(value);
}






/*------------------------------ access -----------------------------------*/

SizeT ViewareaBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (LeftFieldMask & whichField))
    {
        returnValue += _sfLeft.getBinSize();
    }
    if(FieldBits::NoField != (RightFieldMask & whichField))
    {
        returnValue += _sfRight.getBinSize();
    }
    if(FieldBits::NoField != (BottomFieldMask & whichField))
    {
        returnValue += _sfBottom.getBinSize();
    }
    if(FieldBits::NoField != (TopFieldMask & whichField))
    {
        returnValue += _sfTop.getBinSize();
    }
    if(FieldBits::NoField != (TravMaskFieldMask & whichField))
    {
        returnValue += _sfTravMask.getBinSize();
    }
    if(FieldBits::NoField != (EnabledFieldMask & whichField))
    {
        returnValue += _sfEnabled.getBinSize();
    }
    if(FieldBits::NoField != (DrawTimeFieldMask & whichField))
    {
        returnValue += _sfDrawTime.getBinSize();
    }
    if(FieldBits::NoField != (DrawableIdFieldMask & whichField))
    {
        returnValue += _sfDrawableId.getBinSize();
    }
    if(FieldBits::NoField != (RenderOptionsFieldMask & whichField))
    {
        returnValue += _sfRenderOptions.getBinSize();
    }

    return returnValue;
}

void ViewareaBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (LeftFieldMask & whichField))
    {
        _sfLeft.copyToBin(pMem);
    }
    if(FieldBits::NoField != (RightFieldMask & whichField))
    {
        _sfRight.copyToBin(pMem);
    }
    if(FieldBits::NoField != (BottomFieldMask & whichField))
    {
        _sfBottom.copyToBin(pMem);
    }
    if(FieldBits::NoField != (TopFieldMask & whichField))
    {
        _sfTop.copyToBin(pMem);
    }
    if(FieldBits::NoField != (TravMaskFieldMask & whichField))
    {
        _sfTravMask.copyToBin(pMem);
    }
    if(FieldBits::NoField != (EnabledFieldMask & whichField))
    {
        _sfEnabled.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DrawTimeFieldMask & whichField))
    {
        _sfDrawTime.copyToBin(pMem);
    }
    if(FieldBits::NoField != (DrawableIdFieldMask & whichField))
    {
        _sfDrawableId.copyToBin(pMem);
    }
    if(FieldBits::NoField != (RenderOptionsFieldMask & whichField))
    {
        _sfRenderOptions.copyToBin(pMem);
    }
}

void ViewareaBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (LeftFieldMask & whichField))
    {
        editSField(LeftFieldMask);
        _sfLeft.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (RightFieldMask & whichField))
    {
        editSField(RightFieldMask);
        _sfRight.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (BottomFieldMask & whichField))
    {
        editSField(BottomFieldMask);
        _sfBottom.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (TopFieldMask & whichField))
    {
        editSField(TopFieldMask);
        _sfTop.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (TravMaskFieldMask & whichField))
    {
        editSField(TravMaskFieldMask);
        _sfTravMask.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (EnabledFieldMask & whichField))
    {
        editSField(EnabledFieldMask);
        _sfEnabled.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DrawTimeFieldMask & whichField))
    {
        editSField(DrawTimeFieldMask);
        _sfDrawTime.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (DrawableIdFieldMask & whichField))
    {
        editSField(DrawableIdFieldMask);
        _sfDrawableId.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (RenderOptionsFieldMask & whichField))
    {
        editSField(RenderOptionsFieldMask);
        _sfRenderOptions.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ViewareaTransitPtr ViewareaBase::createLocal(BitVector bFlags)
{
    ViewareaTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<Viewarea>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ViewareaTransitPtr ViewareaBase::createDependent(BitVector bFlags)
{
    ViewareaTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<Viewarea>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ViewareaTransitPtr ViewareaBase::create(void)
{
    ViewareaTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<Viewarea>(tmpPtr);
    }

    return fc;
}

Viewarea *ViewareaBase::createEmptyLocal(BitVector bFlags)
{
    Viewarea *returnValue;

    newPtr<Viewarea>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
Viewarea *ViewareaBase::createEmpty(void)
{
    Viewarea *returnValue;

    newPtr<Viewarea>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ViewareaBase::shallowCopyLocal(
    BitVector bFlags) const
{
    Viewarea *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Viewarea *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ViewareaBase::shallowCopyDependent(
    BitVector bFlags) const
{
    Viewarea *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Viewarea *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ViewareaBase::shallowCopy(void) const
{
    Viewarea *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const Viewarea *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ViewareaBase::ViewareaBase(void) :
    Inherited(),
    _sfLeft                   (Real32(0.f)),
    _sfRight                  (Real32(1.f)),
    _sfBottom                 (Real32(0.f)),
    _sfTop                    (Real32(1.f)),
    _sfTravMask               (UInt32(TypeTraits<UInt32>::getMax())),
    _sfEnabled                (bool(true)),
    _sfDrawTime               (Real32(0.0f)),
    _sfDrawableId             (Int32(-1)),
    _sfRenderOptions          (NULL)
{
}

ViewareaBase::ViewareaBase(const ViewareaBase &source) :
    Inherited(source),
    _sfLeft                   (source._sfLeft                   ),
    _sfRight                  (source._sfRight                  ),
    _sfBottom                 (source._sfBottom                 ),
    _sfTop                    (source._sfTop                    ),
    _sfTravMask               (source._sfTravMask               ),
    _sfEnabled                (source._sfEnabled                ),
    _sfDrawTime               (source._sfDrawTime               ),
    _sfDrawableId             (source._sfDrawableId             ),
    _sfRenderOptions          (NULL)
{
}


/*-------------------------- destructors ----------------------------------*/

ViewareaBase::~ViewareaBase(void)
{
}

void ViewareaBase::onCreate(const Viewarea *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        Viewarea *pThis = static_cast<Viewarea *>(this);

        pThis->setRenderOptions(source->getRenderOptions());
    }
}

GetFieldHandlePtr ViewareaBase::getHandleLeft            (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfLeft,
             this->getType().getFieldDesc(LeftFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleLeft           (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfLeft,
             this->getType().getFieldDesc(LeftFieldId),
             this));


    editSField(LeftFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleRight           (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfRight,
             this->getType().getFieldDesc(RightFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleRight          (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfRight,
             this->getType().getFieldDesc(RightFieldId),
             this));


    editSField(RightFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleBottom          (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfBottom,
             this->getType().getFieldDesc(BottomFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleBottom         (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfBottom,
             this->getType().getFieldDesc(BottomFieldId),
             this));


    editSField(BottomFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleTop             (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfTop,
             this->getType().getFieldDesc(TopFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleTop            (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfTop,
             this->getType().getFieldDesc(TopFieldId),
             this));


    editSField(TopFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleTravMask        (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfTravMask,
             this->getType().getFieldDesc(TravMaskFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleTravMask       (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfTravMask,
             this->getType().getFieldDesc(TravMaskFieldId),
             this));


    editSField(TravMaskFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleEnabled         (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfEnabled,
             this->getType().getFieldDesc(EnabledFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleEnabled        (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfEnabled,
             this->getType().getFieldDesc(EnabledFieldId),
             this));


    editSField(EnabledFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleDrawTime        (void) const
{
    SFReal32::GetHandlePtr returnValue(
        new  SFReal32::GetHandle(
             &_sfDrawTime,
             this->getType().getFieldDesc(DrawTimeFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleDrawTime       (void)
{
    SFReal32::EditHandlePtr returnValue(
        new  SFReal32::EditHandle(
             &_sfDrawTime,
             this->getType().getFieldDesc(DrawTimeFieldId),
             this));


    editSField(DrawTimeFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleDrawableId      (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfDrawableId,
             this->getType().getFieldDesc(DrawableIdFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleDrawableId     (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfDrawableId,
             this->getType().getFieldDesc(DrawableIdFieldId),
             this));


    editSField(DrawableIdFieldMask);

    return returnValue;
}

GetFieldHandlePtr ViewareaBase::getHandleRenderOptions   (void) const
{
    SFUnrecRenderOptionsPtr::GetHandlePtr returnValue(
        new  SFUnrecRenderOptionsPtr::GetHandle(
             &_sfRenderOptions,
             this->getType().getFieldDesc(RenderOptionsFieldId),
             const_cast<ViewareaBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr ViewareaBase::editHandleRenderOptions  (void)
{
    SFUnrecRenderOptionsPtr::EditHandlePtr returnValue(
        new  SFUnrecRenderOptionsPtr::EditHandle(
             &_sfRenderOptions,
             this->getType().getFieldDesc(RenderOptionsFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&Viewarea::setRenderOptions,
                    static_cast<Viewarea *>(this), _1));

    editSField(RenderOptionsFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ViewareaBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Viewarea *pThis = static_cast<Viewarea *>(this);

    pThis->execSync(static_cast<Viewarea *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ViewareaBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    Viewarea *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const Viewarea *>(pRefAspect),
                  dynamic_cast<const Viewarea *>(this));

    return returnValue;
}
#endif

void ViewareaBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<Viewarea *>(this)->setRenderOptions(NULL);


}


OSG_END_NAMESPACE
