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
 **     class SkinnedGeometry!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include "OSGConfig.h"



#include "OSGSkeleton.h"                // Skeleton Class
#include "OSGSkinningAlgorithm.h"       // SkinningAlgorithm Class

#include "OSGSkinnedGeometryBase.h"
#include "OSGSkinnedGeometry.h"

#include <boost/bind.hpp>

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::SkinnedGeometry
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var Skeleton *      SkinnedGeometryBase::_sfSkeleton
    The Skeleton that deforms this geometry.
*/

/*! \var Matrix          SkinnedGeometryBase::_sfBindShapeMatrix
    Matrix that is applied to the vertices of the mesh before deformation.
    It transforms the vertices into bind space.
*/

/*! \var Int16           SkinnedGeometryBase::_mfJointIds
    List of jointIds that are used by this SkinnedGeometry.
*/

/*! \var UInt16          SkinnedGeometryBase::_sfJointIndexProperty
    Index of the property that stores the joint indices that influence
    a vertex.
*/

/*! \var UInt16          SkinnedGeometryBase::_sfJointWeightProperty
    Index of the property that stores the joint weights that influence
    a vertex.
*/

/*! \var UInt32          SkinnedGeometryBase::_sfRenderMode
    
*/

/*! \var SkinningAlgorithm * SkinnedGeometryBase::_sfSkinningAlgorithm
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<SkinnedGeometry *>::_type("SkinnedGeometryPtr", "GeometryPtr");
#endif

OSG_FIELDTRAITS_GETTYPE(SkinnedGeometry *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           SkinnedGeometry *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           SkinnedGeometry *,
                           0);

DataType &FieldTraits<SkinnedGeometry *, 1 >::getType(void)
{
    return FieldTraits<SkinnedGeometry *, 0>::getType();
}


OSG_SFIELDTYPE_INST(ParentPointerSField,
                    SkinnedGeometry *,
                    NoRefCountPolicy,
                    1);

OSG_FIELD_DLLEXPORT_DEF3(ParentPointerSField,
                         SkinnedGeometry *,
                         NoRefCountPolicy,
                         1);


OSG_MFIELDTYPE_INST(ParentPointerMField,
                    SkinnedGeometry *,
                    NoRefCountPolicy,
                    1);

OSG_FIELD_DLLEXPORT_DEF3(ParentPointerMField,
                         SkinnedGeometry *,
                         NoRefCountPolicy,
                         1);


/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void SkinnedGeometryBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFUnrecSkeletonPtr::Description(
        SFUnrecSkeletonPtr::getClassType(),
        "skeleton",
        "The Skeleton that deforms this geometry.\n",
        SkeletonFieldId, SkeletonFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleSkeleton),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleSkeleton));

    oType.addInitialDesc(pDesc);

    pDesc = new SFMatrix::Description(
        SFMatrix::getClassType(),
        "bindShapeMatrix",
        "Matrix that is applied to the vertices of the mesh before deformation.\n"
        "It transforms the vertices into bind space.\n",
        BindShapeMatrixFieldId, BindShapeMatrixFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleBindShapeMatrix),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleBindShapeMatrix));

    oType.addInitialDesc(pDesc);

    pDesc = new MFInt16::Description(
        MFInt16::getClassType(),
        "jointIds",
        "List of jointIds that are used by this SkinnedGeometry.\n",
        JointIdsFieldId, JointIdsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleJointIds),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleJointIds));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt16::Description(
        SFUInt16::getClassType(),
        "jointIndexProperty",
        "Index of the property that stores the joint indices that influence\n"
        "a vertex.\n",
        JointIndexPropertyFieldId, JointIndexPropertyFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleJointIndexProperty),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleJointIndexProperty));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt16::Description(
        SFUInt16::getClassType(),
        "jointWeightProperty",
        "Index of the property that stores the joint weights that influence\n"
        "a vertex.\n",
        JointWeightPropertyFieldId, JointWeightPropertyFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleJointWeightProperty),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleJointWeightProperty));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "renderMode",
        "",
        RenderModeFieldId, RenderModeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleRenderMode),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleRenderMode));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecChildSkinningAlgorithmPtr::Description(
        SFUnrecChildSkinningAlgorithmPtr::getClassType(),
        "skinningAlgorithm",
        "",
        SkinningAlgorithmFieldId, SkinningAlgorithmFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&SkinnedGeometry::editHandleSkinningAlgorithm),
        static_cast<FieldGetMethodSig >(&SkinnedGeometry::getHandleSkinningAlgorithm));

    oType.addInitialDesc(pDesc);
}


SkinnedGeometryBase::TypeObject SkinnedGeometryBase::_type(
    SkinnedGeometryBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&SkinnedGeometryBase::createEmptyLocal),
    SkinnedGeometry::initMethod,
    SkinnedGeometry::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&SkinnedGeometry::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"SkinnedGeometry\"\n"
    "   parent=\"Geometry\"\n"
    "   library=\"Dynamics\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   decoratable=\"false\"\n"
    "   childFields=\"none\"\n"
    "   parentFields=\"both\"\n"
    ">\n"
    "\n"
    "  <Field\n"
    "     name=\"skeleton\"\n"
    "     type=\"Skeleton\"\n"
    "     category=\"pointer\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    The Skeleton that deforms this geometry.\n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"bindShapeMatrix\"\n"
    "     type=\"Matrix\"\n"
    "     category=\"data\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    Matrix that is applied to the vertices of the mesh before deformation.\n"
    "    It transforms the vertices into bind space.\n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"jointIds\"\n"
    "     type=\"Int16\"\n"
    "     category=\"data\"\n"
    "     cardinality=\"multi\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    List of jointIds that are used by this SkinnedGeometry.\n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"jointIndexProperty\"\n"
    "     type=\"UInt16\"\n"
    "     category=\"data\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    Index of the property that stores the joint indices that influence\n"
    "    a vertex.\n"
    "  </Field>\n"
    "  \n"
    "  <Field\n"
    "     name=\"jointWeightProperty\"\n"
    "     type=\"UInt16\"\n"
    "     category=\"data\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     >\n"
    "    Index of the property that stores the joint weights that influence\n"
    "    a vertex.\n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"renderMode\"\n"
    "     type=\"UInt32\"\n"
    "     category=\"data\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"public\"\n"
    "     defaultValue=\"0\"\n"
    "     >\n"
    "  </Field>\n"
    "\n"
    "  <Field\n"
    "     name=\"skinningAlgorithm\"\n"
    "     type=\"SkinningAlgorithm\"\n"
    "     category=\"childpointer\"\n"
    "     linkParentField=\"Skin\"\n"
    "     cardinality=\"single\"\n"
    "     visibility=\"external\"\n"
    "     access=\"protected\"\n"
    "     defaultValue=\"NULL\"\n"
    "     >\n"
    "  </Field>\n"
    "\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &SkinnedGeometryBase::getType(void)
{
    return _type;
}

const FieldContainerType &SkinnedGeometryBase::getType(void) const
{
    return _type;
}

UInt32 SkinnedGeometryBase::getContainerSize(void) const
{
    return sizeof(SkinnedGeometry);
}

/*------------------------- decorator get ------------------------------*/


//! Get the SkinnedGeometry::_sfSkeleton field.
const SFUnrecSkeletonPtr *SkinnedGeometryBase::getSFSkeleton(void) const
{
    return &_sfSkeleton;
}

SFUnrecSkeletonPtr  *SkinnedGeometryBase::editSFSkeleton       (void)
{
    editSField(SkeletonFieldMask);

    return &_sfSkeleton;
}

SFMatrix *SkinnedGeometryBase::editSFBindShapeMatrix(void)
{
    editSField(BindShapeMatrixFieldMask);

    return &_sfBindShapeMatrix;
}

const SFMatrix *SkinnedGeometryBase::getSFBindShapeMatrix(void) const
{
    return &_sfBindShapeMatrix;
}


MFInt16 *SkinnedGeometryBase::editMFJointIds(void)
{
    editMField(JointIdsFieldMask, _mfJointIds);

    return &_mfJointIds;
}

const MFInt16 *SkinnedGeometryBase::getMFJointIds(void) const
{
    return &_mfJointIds;
}


SFUInt16 *SkinnedGeometryBase::editSFJointIndexProperty(void)
{
    editSField(JointIndexPropertyFieldMask);

    return &_sfJointIndexProperty;
}

const SFUInt16 *SkinnedGeometryBase::getSFJointIndexProperty(void) const
{
    return &_sfJointIndexProperty;
}


SFUInt16 *SkinnedGeometryBase::editSFJointWeightProperty(void)
{
    editSField(JointWeightPropertyFieldMask);

    return &_sfJointWeightProperty;
}

const SFUInt16 *SkinnedGeometryBase::getSFJointWeightProperty(void) const
{
    return &_sfJointWeightProperty;
}


SFUInt32 *SkinnedGeometryBase::editSFRenderMode(void)
{
    editSField(RenderModeFieldMask);

    return &_sfRenderMode;
}

const SFUInt32 *SkinnedGeometryBase::getSFRenderMode(void) const
{
    return &_sfRenderMode;
}


//! Get the SkinnedGeometry::_sfSkinningAlgorithm field.
const SFUnrecChildSkinningAlgorithmPtr *SkinnedGeometryBase::getSFSkinningAlgorithm(void) const
{
    return &_sfSkinningAlgorithm;
}

SFUnrecChildSkinningAlgorithmPtr *SkinnedGeometryBase::editSFSkinningAlgorithm(void)
{
    editSField(SkinningAlgorithmFieldMask);

    return &_sfSkinningAlgorithm;
}





/*------------------------------ access -----------------------------------*/

UInt32 SkinnedGeometryBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
    {
        returnValue += _sfSkeleton.getBinSize();
    }
    if(FieldBits::NoField != (BindShapeMatrixFieldMask & whichField))
    {
        returnValue += _sfBindShapeMatrix.getBinSize();
    }
    if(FieldBits::NoField != (JointIdsFieldMask & whichField))
    {
        returnValue += _mfJointIds.getBinSize();
    }
    if(FieldBits::NoField != (JointIndexPropertyFieldMask & whichField))
    {
        returnValue += _sfJointIndexProperty.getBinSize();
    }
    if(FieldBits::NoField != (JointWeightPropertyFieldMask & whichField))
    {
        returnValue += _sfJointWeightProperty.getBinSize();
    }
    if(FieldBits::NoField != (RenderModeFieldMask & whichField))
    {
        returnValue += _sfRenderMode.getBinSize();
    }
    if(FieldBits::NoField != (SkinningAlgorithmFieldMask & whichField))
    {
        returnValue += _sfSkinningAlgorithm.getBinSize();
    }

    return returnValue;
}

void SkinnedGeometryBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
    {
        _sfSkeleton.copyToBin(pMem);
    }
    if(FieldBits::NoField != (BindShapeMatrixFieldMask & whichField))
    {
        _sfBindShapeMatrix.copyToBin(pMem);
    }
    if(FieldBits::NoField != (JointIdsFieldMask & whichField))
    {
        _mfJointIds.copyToBin(pMem);
    }
    if(FieldBits::NoField != (JointIndexPropertyFieldMask & whichField))
    {
        _sfJointIndexProperty.copyToBin(pMem);
    }
    if(FieldBits::NoField != (JointWeightPropertyFieldMask & whichField))
    {
        _sfJointWeightProperty.copyToBin(pMem);
    }
    if(FieldBits::NoField != (RenderModeFieldMask & whichField))
    {
        _sfRenderMode.copyToBin(pMem);
    }
    if(FieldBits::NoField != (SkinningAlgorithmFieldMask & whichField))
    {
        _sfSkinningAlgorithm.copyToBin(pMem);
    }
}

void SkinnedGeometryBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (SkeletonFieldMask & whichField))
    {
        _sfSkeleton.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (BindShapeMatrixFieldMask & whichField))
    {
        _sfBindShapeMatrix.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (JointIdsFieldMask & whichField))
    {
        _mfJointIds.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (JointIndexPropertyFieldMask & whichField))
    {
        _sfJointIndexProperty.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (JointWeightPropertyFieldMask & whichField))
    {
        _sfJointWeightProperty.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (RenderModeFieldMask & whichField))
    {
        _sfRenderMode.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (SkinningAlgorithmFieldMask & whichField))
    {
        _sfSkinningAlgorithm.copyFromBin(pMem);
    }
}

//! create a new instance of the class
SkinnedGeometryTransitPtr SkinnedGeometryBase::createLocal(BitVector bFlags)
{
    SkinnedGeometryTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<SkinnedGeometry>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
SkinnedGeometryTransitPtr SkinnedGeometryBase::createDependent(BitVector bFlags)
{
    SkinnedGeometryTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<SkinnedGeometry>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
SkinnedGeometryTransitPtr SkinnedGeometryBase::create(void)
{
    SkinnedGeometryTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<SkinnedGeometry>(tmpPtr);
    }

    return fc;
}

SkinnedGeometry *SkinnedGeometryBase::createEmptyLocal(BitVector bFlags)
{
    SkinnedGeometry *returnValue;

    newPtr<SkinnedGeometry>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
SkinnedGeometry *SkinnedGeometryBase::createEmpty(void)
{
    SkinnedGeometry *returnValue;

    newPtr<SkinnedGeometry>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr SkinnedGeometryBase::shallowCopyLocal(
    BitVector bFlags) const
{
    SkinnedGeometry *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SkinnedGeometry *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr SkinnedGeometryBase::shallowCopyDependent(
    BitVector bFlags) const
{
    SkinnedGeometry *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const SkinnedGeometry *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr SkinnedGeometryBase::shallowCopy(void) const
{
    SkinnedGeometry *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const SkinnedGeometry *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

SkinnedGeometryBase::SkinnedGeometryBase(void) :
    Inherited(),
    _sfSkeleton               (NULL),
    _sfBindShapeMatrix        (),
    _mfJointIds               (),
    _sfJointIndexProperty     (),
    _sfJointWeightProperty    (),
    _sfRenderMode             (UInt32(0)),
    _sfSkinningAlgorithm      (this,
                          SkinningAlgorithmFieldId,
                          SkinningAlgorithm::SkinFieldId)
{
}

SkinnedGeometryBase::SkinnedGeometryBase(const SkinnedGeometryBase &source) :
    Inherited(source),
    _sfSkeleton               (NULL),
    _sfBindShapeMatrix        (source._sfBindShapeMatrix        ),
    _mfJointIds               (source._mfJointIds               ),
    _sfJointIndexProperty     (source._sfJointIndexProperty     ),
    _sfJointWeightProperty    (source._sfJointWeightProperty    ),
    _sfRenderMode             (source._sfRenderMode             ),
    _sfSkinningAlgorithm      (this,
                          SkinningAlgorithmFieldId,
                          SkinningAlgorithm::SkinFieldId)
{
}


/*-------------------------- destructors ----------------------------------*/

SkinnedGeometryBase::~SkinnedGeometryBase(void)
{
}

/*-------------------------------------------------------------------------*/
/* Child linking                                                           */

bool SkinnedGeometryBase::unlinkChild(
    FieldContainer * const pChild,
    UInt16           const childFieldId)
{
    if(childFieldId == SkinningAlgorithmFieldId)
    {
        SkinningAlgorithm * pTypedChild =
            dynamic_cast<SkinningAlgorithm *>(pChild);

        if(pTypedChild != NULL)
        {
            if(pTypedChild == _sfSkinningAlgorithm.getValue())
            {
                editSField(SkinningAlgorithmFieldMask);

                _sfSkinningAlgorithm.setValue(NULL);

                return true;
            }

            FWARNING(("SkinnedGeometryBase::unlinkParent: Child <-> "
                      "Parent link inconsistent.\n"));

            return false;
        }

        return false;
    }


    return Inherited::unlinkChild(pChild, childFieldId);
}

void SkinnedGeometryBase::onCreate(const SkinnedGeometry *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        SkinnedGeometry *pThis = static_cast<SkinnedGeometry *>(this);

        pThis->setSkeleton(source->getSkeleton());

        pThis->setSkinningAlgorithm(source->getSkinningAlgorithm());
    }
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleSkeleton        (void) const
{
    SFUnrecSkeletonPtr::GetHandlePtr returnValue(
        new  SFUnrecSkeletonPtr::GetHandle(
             &_sfSkeleton,
             this->getType().getFieldDesc(SkeletonFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleSkeleton       (void)
{
    SFUnrecSkeletonPtr::EditHandlePtr returnValue(
        new  SFUnrecSkeletonPtr::EditHandle(
             &_sfSkeleton,
             this->getType().getFieldDesc(SkeletonFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SkinnedGeometry::setSkeleton,
                    static_cast<SkinnedGeometry *>(this), _1));

    editSField(SkeletonFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleBindShapeMatrix (void) const
{
    SFMatrix::GetHandlePtr returnValue(
        new  SFMatrix::GetHandle(
             &_sfBindShapeMatrix,
             this->getType().getFieldDesc(BindShapeMatrixFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleBindShapeMatrix(void)
{
    SFMatrix::EditHandlePtr returnValue(
        new  SFMatrix::EditHandle(
             &_sfBindShapeMatrix,
             this->getType().getFieldDesc(BindShapeMatrixFieldId),
             this));


    editSField(BindShapeMatrixFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleJointIds        (void) const
{
    MFInt16::GetHandlePtr returnValue(
        new  MFInt16::GetHandle(
             &_mfJointIds,
             this->getType().getFieldDesc(JointIdsFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleJointIds       (void)
{
    MFInt16::EditHandlePtr returnValue(
        new  MFInt16::EditHandle(
             &_mfJointIds,
             this->getType().getFieldDesc(JointIdsFieldId),
             this));


    editMField(JointIdsFieldMask, _mfJointIds);

    return returnValue;
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleJointIndexProperty (void) const
{
    SFUInt16::GetHandlePtr returnValue(
        new  SFUInt16::GetHandle(
             &_sfJointIndexProperty,
             this->getType().getFieldDesc(JointIndexPropertyFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleJointIndexProperty(void)
{
    SFUInt16::EditHandlePtr returnValue(
        new  SFUInt16::EditHandle(
             &_sfJointIndexProperty,
             this->getType().getFieldDesc(JointIndexPropertyFieldId),
             this));


    editSField(JointIndexPropertyFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleJointWeightProperty (void) const
{
    SFUInt16::GetHandlePtr returnValue(
        new  SFUInt16::GetHandle(
             &_sfJointWeightProperty,
             this->getType().getFieldDesc(JointWeightPropertyFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleJointWeightProperty(void)
{
    SFUInt16::EditHandlePtr returnValue(
        new  SFUInt16::EditHandle(
             &_sfJointWeightProperty,
             this->getType().getFieldDesc(JointWeightPropertyFieldId),
             this));


    editSField(JointWeightPropertyFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleRenderMode      (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfRenderMode,
             this->getType().getFieldDesc(RenderModeFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleRenderMode     (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfRenderMode,
             this->getType().getFieldDesc(RenderModeFieldId),
             this));


    editSField(RenderModeFieldMask);

    return returnValue;
}

GetFieldHandlePtr SkinnedGeometryBase::getHandleSkinningAlgorithm (void) const
{
    SFUnrecChildSkinningAlgorithmPtr::GetHandlePtr returnValue(
        new  SFUnrecChildSkinningAlgorithmPtr::GetHandle(
             &_sfSkinningAlgorithm,
             this->getType().getFieldDesc(SkinningAlgorithmFieldId),
             const_cast<SkinnedGeometryBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr SkinnedGeometryBase::editHandleSkinningAlgorithm(void)
{
    SFUnrecChildSkinningAlgorithmPtr::EditHandlePtr returnValue(
        new  SFUnrecChildSkinningAlgorithmPtr::EditHandle(
             &_sfSkinningAlgorithm,
             this->getType().getFieldDesc(SkinningAlgorithmFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&SkinnedGeometry::setSkinningAlgorithm,
                    static_cast<SkinnedGeometry *>(this), _1));

    editSField(SkinningAlgorithmFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void SkinnedGeometryBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    SkinnedGeometry *pThis = static_cast<SkinnedGeometry *>(this);

    pThis->execSync(static_cast<SkinnedGeometry *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *SkinnedGeometryBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    SkinnedGeometry *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const SkinnedGeometry *>(pRefAspect),
                  dynamic_cast<const SkinnedGeometry *>(this));

    return returnValue;
}
#endif

void SkinnedGeometryBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<SkinnedGeometry *>(this)->setSkeleton(NULL);

    static_cast<SkinnedGeometry *>(this)->setSkinningAlgorithm(NULL);

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfJointIds.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
