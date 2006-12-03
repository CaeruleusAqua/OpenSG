/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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
 **     class Particles!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &ParticlesBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 ParticlesBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 ParticlesBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the Particles::_sfMode field.

inline
UInt32 &ParticlesBase::editMode(void)
{
    editSField(ModeFieldMask);

    return _sfMode.getValue();
}

//! Get the value of the Particles::_sfMode field.
inline
const UInt32 &ParticlesBase::getMode(void) const
{
    return _sfMode.getValue();
}

#ifdef OSG_1_COMPAT
inline
UInt32              &ParticlesBase::getMode           (void)
{
    return this->editMode           ();
}
#endif

//! Set the value of the Particles::_sfMode field.
inline
void ParticlesBase::setMode(const UInt32 &value)
{
    editSField(ModeFieldMask);

    _sfMode.setValue(value);
}

//! Get the value of the Particles::_sfPositions field.
inline
GeoVectorPropertyPtrConst ParticlesBase::getPositions(void) const
{
    return _sfPositions.getValue();
}

//! Set the value of the Particles::_sfPositions field.
inline
void ParticlesBase::setPositions(GeoVectorPropertyPtrConstArg value)
{
    editSField(PositionsFieldMask);

    ParticlesPtr thisP = Inherited::constructPtr<Particles>(
        static_cast<Particles *>(this));

    if(_sfPositions.getValue() != NullFC)
    {
        _sfPositions.getValue()->subParent(thisP);
    }

    setRefd(_sfPositions.getValue(), value);

    if(_sfPositions.getValue() != NullFC)
    {
        _sfPositions.getValue()->addParent(thisP, PositionsFieldMask);
    }

}

//! Get the value of the Particles::_sfSecPositions field.
inline
GeoVectorPropertyPtrConst ParticlesBase::getSecPositions(void) const
{
    return _sfSecPositions.getValue();
}

//! Set the value of the Particles::_sfSecPositions field.
inline
void ParticlesBase::setSecPositions(GeoVectorPropertyPtrConstArg value)
{
    editSField(SecPositionsFieldMask);

    ParticlesPtr thisP = Inherited::constructPtr<Particles>(
        static_cast<Particles *>(this));

    if(_sfSecPositions.getValue() != NullFC)
    {
        _sfSecPositions.getValue()->subParent(thisP);
    }

    setRefd(_sfSecPositions.getValue(), value);

    if(_sfSecPositions.getValue() != NullFC)
    {
        _sfSecPositions.getValue()->addParent(thisP, SecPositionsFieldMask);
    }

}

//! Get the value of the Particles::_sfColors field.
inline
GeoVectorPropertyPtrConst ParticlesBase::getColors(void) const
{
    return _sfColors.getValue();
}

//! Set the value of the Particles::_sfColors field.
inline
void ParticlesBase::setColors(GeoVectorPropertyPtrConstArg value)
{
    editSField(ColorsFieldMask);

    ParticlesPtr thisP = Inherited::constructPtr<Particles>(
        static_cast<Particles *>(this));

    if(_sfColors.getValue() != NullFC)
    {
        _sfColors.getValue()->subParent(thisP);
    }

    setRefd(_sfColors.getValue(), value);

    if(_sfColors.getValue() != NullFC)
    {
        _sfColors.getValue()->addParent(thisP, ColorsFieldMask);
    }

}

//! Get the value of the Particles::_sfNormals field.
inline
GeoVectorPropertyPtrConst ParticlesBase::getNormals(void) const
{
    return _sfNormals.getValue();
}

//! Set the value of the Particles::_sfNormals field.
inline
void ParticlesBase::setNormals(GeoVectorPropertyPtrConstArg value)
{
    editSField(NormalsFieldMask);

    ParticlesPtr thisP = Inherited::constructPtr<Particles>(
        static_cast<Particles *>(this));

    if(_sfNormals.getValue() != NullFC)
    {
        _sfNormals.getValue()->subParent(thisP);
    }

    setRefd(_sfNormals.getValue(), value);

    if(_sfNormals.getValue() != NullFC)
    {
        _sfNormals.getValue()->addParent(thisP, NormalsFieldMask);
    }

}
//! Get the value of the Particles::_sfDrawOrder field.

inline
UInt32 &ParticlesBase::editDrawOrder(void)
{
    editSField(DrawOrderFieldMask);

    return _sfDrawOrder.getValue();
}

//! Get the value of the Particles::_sfDrawOrder field.
inline
const UInt32 &ParticlesBase::getDrawOrder(void) const
{
    return _sfDrawOrder.getValue();
}

#ifdef OSG_1_COMPAT
inline
UInt32              &ParticlesBase::getDrawOrder      (void)
{
    return this->editDrawOrder      ();
}
#endif

//! Set the value of the Particles::_sfDrawOrder field.
inline
void ParticlesBase::setDrawOrder(const UInt32 &value)
{
    editSField(DrawOrderFieldMask);

    _sfDrawOrder.setValue(value);
}
//! Get the value of the Particles::_sfDynamic field.

inline
bool &ParticlesBase::editDynamic(void)
{
    editSField(DynamicFieldMask);

    return _sfDynamic.getValue();
}

//! Get the value of the Particles::_sfDynamic field.
inline
const bool &ParticlesBase::getDynamic(void) const
{
    return _sfDynamic.getValue();
}

#ifdef OSG_1_COMPAT
inline
bool                &ParticlesBase::getDynamic        (void)
{
    return this->editDynamic        ();
}
#endif

//! Set the value of the Particles::_sfDynamic field.
inline
void ParticlesBase::setDynamic(const bool &value)
{
    editSField(DynamicFieldMask);

    _sfDynamic.setValue(value);
}
//! Get the value of the Particles::_sfPump field.

inline
UInt32 &ParticlesBase::editPump(void)
{
    editSField(PumpFieldMask);

    return _sfPump.getValue();
}

//! Get the value of the Particles::_sfPump field.
inline
const UInt32 &ParticlesBase::getPump(void) const
{
    return _sfPump.getValue();
}

#ifdef OSG_1_COMPAT
inline
UInt32              &ParticlesBase::getPump           (void)
{
    return this->editPump           ();
}
#endif

//! Set the value of the Particles::_sfPump field.
inline
void ParticlesBase::setPump(const UInt32 &value)
{
    editSField(PumpFieldMask);

    _sfPump.setValue(value);
}
//! Get the value of the Particles::_sfBsp field.

inline
ParticleBSPTree &ParticlesBase::editBsp(void)
{
    editSField(BspFieldMask);

    return _sfBsp.getValue();
}

//! Get the value of the Particles::_sfBsp field.
inline
const ParticleBSPTree &ParticlesBase::getBsp(void) const
{
    return _sfBsp.getValue();
}

#ifdef OSG_1_COMPAT
inline
ParticleBSPTree     &ParticlesBase::getBsp            (void)
{
    return this->editBsp            ();
}
#endif

//! Set the value of the Particles::_sfBsp field.
inline
void ParticlesBase::setBsp(const ParticleBSPTree &value)
{
    editSField(BspFieldMask);

    _sfBsp.setValue(value);
}
//! Get the value of the Particles::_sfNumParticles field.

inline
Int32 &ParticlesBase::editNumParticles(void)
{
    editSField(NumParticlesFieldMask);

    return _sfNumParticles.getValue();
}

//! Get the value of the Particles::_sfNumParticles field.
inline
const Int32 &ParticlesBase::getNumParticles(void) const
{
    return _sfNumParticles.getValue();
}

#ifdef OSG_1_COMPAT
inline
Int32               &ParticlesBase::getNumParticles   (void)
{
    return this->editNumParticles   ();
}
#endif

//! Set the value of the Particles::_sfNumParticles field.
inline
void ParticlesBase::setNumParticles(const Int32 &value)
{
    editSField(NumParticlesFieldMask);

    _sfNumParticles.setValue(value);
}

//! Get the value of the \a index element the Particles::_mfSizes field.
inline
const Vec3f &ParticlesBase::getSizes(const UInt32 index) const
{
    return _mfSizes[index];
}

inline
Vec3f &ParticlesBase::editSizes(const UInt32 index)
{
    editMField(SizesFieldMask, _mfSizes);

    return _mfSizes[index];
}

//! Get the Particles::_mfSizes field.
inline
MFVec3f &ParticlesBase::editSizes(void)
{
    editMField(SizesFieldMask, _mfSizes);

    return _mfSizes;
}

#ifdef OSG_1_COMPAT
inline
Vec3f               &ParticlesBase::getSizes          (const UInt32 index)
{
    return this->editSizes          (index);
}

inline
MFVec3f             &ParticlesBase::getSizes          (void)
{
    return this->editSizes          ();
}

#endif


//! Get the Particles::_mfSizes field.
inline
const MFVec3f &ParticlesBase::getSizes(void) const
{
    return _mfSizes;
}

//! Get the value of the \a index element the Particles::_mfIndices field.
inline
const Int32 &ParticlesBase::getIndices(const UInt32 index) const
{
    return _mfIndices[index];
}

inline
Int32 &ParticlesBase::editIndices(const UInt32 index)
{
    editMField(IndicesFieldMask, _mfIndices);

    return _mfIndices[index];
}

//! Get the Particles::_mfIndices field.
inline
MFInt32 &ParticlesBase::editIndices(void)
{
    editMField(IndicesFieldMask, _mfIndices);

    return _mfIndices;
}

#ifdef OSG_1_COMPAT
inline
Int32               &ParticlesBase::getIndices        (const UInt32 index)
{
    return this->editIndices        (index);
}

inline
MFInt32             &ParticlesBase::getIndices        (void)
{
    return this->editIndices        ();
}

#endif


//! Get the Particles::_mfIndices field.
inline
const MFInt32 &ParticlesBase::getIndices(void) const
{
    return _mfIndices;
}

//! Get the value of the \a index element the Particles::_mfTextureZs field.
inline
const Real32 &ParticlesBase::getTextureZs(const UInt32 index) const
{
    return _mfTextureZs[index];
}

inline
Real32 &ParticlesBase::editTextureZs(const UInt32 index)
{
    editMField(TextureZsFieldMask, _mfTextureZs);

    return _mfTextureZs[index];
}

//! Get the Particles::_mfTextureZs field.
inline
MFReal32 &ParticlesBase::editTextureZs(void)
{
    editMField(TextureZsFieldMask, _mfTextureZs);

    return _mfTextureZs;
}

#ifdef OSG_1_COMPAT
inline
Real32              &ParticlesBase::getTextureZs      (const UInt32 index)
{
    return this->editTextureZs      (index);
}

inline
MFReal32            &ParticlesBase::getTextureZs      (void)
{
    return this->editTextureZs      ();
}

#endif


//! Get the Particles::_mfTextureZs field.
inline
const MFReal32 &ParticlesBase::getTextureZs(void) const
{
    return _mfTextureZs;
}

//! create a new instance of the class
inline
ParticlesPtr ParticlesBase::create(void)
{
    ParticlesPtr fc;

    if(getClassType().getPrototype() != NullFC)
    {
        fc = OSG::cast_dynamic<Particles::ObjPtr>(
            getClassType().getPrototype()-> shallowCopy());
    }

    return fc;
}

#ifdef OSG_MT_FIELDCONTAINERPTR
inline
void ParticlesBase::execSync(      ParticlesBase *pOther,
                                       ConstFieldMaskArg  whichField,
                                       ConstFieldMaskArg  syncMode,
                                 const UInt32             uiSyncInfo,
                                       UInt32             uiCopyOffset)
{
    Inherited::execSync(pOther, whichField, syncMode, uiSyncInfo, uiCopyOffset);

    if(FieldBits::NoField != (ModeFieldMask & whichField))
        _sfMode.syncWith(pOther->_sfMode);

    if(FieldBits::NoField != (PositionsFieldMask & whichField))
        _sfPositions.syncWith(pOther->_sfPositions);

    if(FieldBits::NoField != (SizesFieldMask & whichField))
        _mfSizes.syncWith(pOther->_mfSizes,
                                syncMode,
                                uiSyncInfo,
                                uiCopyOffset);

    if(FieldBits::NoField != (SecPositionsFieldMask & whichField))
        _sfSecPositions.syncWith(pOther->_sfSecPositions);

    if(FieldBits::NoField != (ColorsFieldMask & whichField))
        _sfColors.syncWith(pOther->_sfColors);

    if(FieldBits::NoField != (NormalsFieldMask & whichField))
        _sfNormals.syncWith(pOther->_sfNormals);

    if(FieldBits::NoField != (IndicesFieldMask & whichField))
        _mfIndices.syncWith(pOther->_mfIndices,
                                syncMode,
                                uiSyncInfo,
                                uiCopyOffset);

    if(FieldBits::NoField != (TextureZsFieldMask & whichField))
        _mfTextureZs.syncWith(pOther->_mfTextureZs,
                                syncMode,
                                uiSyncInfo,
                                uiCopyOffset);

    if(FieldBits::NoField != (DrawOrderFieldMask & whichField))
        _sfDrawOrder.syncWith(pOther->_sfDrawOrder);

    if(FieldBits::NoField != (DynamicFieldMask & whichField))
        _sfDynamic.syncWith(pOther->_sfDynamic);

    if(FieldBits::NoField != (PumpFieldMask & whichField))
        _sfPump.syncWith(pOther->_sfPump);

    if(FieldBits::NoField != (BspFieldMask & whichField))
        _sfBsp.syncWith(pOther->_sfBsp);

    if(FieldBits::NoField != (NumParticlesFieldMask & whichField))
        _sfNumParticles.syncWith(pOther->_sfNumParticles);
}
#endif

#ifdef OSG_MT_CPTR_ASPECT
inline
void ParticlesBase::execSync (      ParticlesBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (ModeFieldMask & whichField))
        _sfMode.syncWith(pFrom->_sfMode);

    if(FieldBits::NoField != (PositionsFieldMask & whichField))
        _sfPositions.syncWith(pFrom->_sfPositions);

    if(FieldBits::NoField != (SizesFieldMask & whichField))
        _mfSizes.syncWith(pFrom->_mfSizes,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (SecPositionsFieldMask & whichField))
        _sfSecPositions.syncWith(pFrom->_sfSecPositions);

    if(FieldBits::NoField != (ColorsFieldMask & whichField))
        _sfColors.syncWith(pFrom->_sfColors);

    if(FieldBits::NoField != (NormalsFieldMask & whichField))
        _sfNormals.syncWith(pFrom->_sfNormals);

    if(FieldBits::NoField != (IndicesFieldMask & whichField))
        _mfIndices.syncWith(pFrom->_mfIndices,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (TextureZsFieldMask & whichField))
        _mfTextureZs.syncWith(pFrom->_mfTextureZs,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (DrawOrderFieldMask & whichField))
        _sfDrawOrder.syncWith(pFrom->_sfDrawOrder);

    if(FieldBits::NoField != (DynamicFieldMask & whichField))
        _sfDynamic.syncWith(pFrom->_sfDynamic);

    if(FieldBits::NoField != (PumpFieldMask & whichField))
        _sfPump.syncWith(pFrom->_sfPump);

    if(FieldBits::NoField != (BspFieldMask & whichField))
        _sfBsp.syncWith(pFrom->_sfBsp);

    if(FieldBits::NoField != (NumParticlesFieldMask & whichField))
        _sfNumParticles.syncWith(pFrom->_sfNumParticles);
}
#endif

#if 0
inline
void ParticlesBase::execBeginEdit(ConstFieldMaskArg whichField,
                                      UInt32            uiAspect,
                                      UInt32            uiContainerSize)
{
    Inherited::execBeginEdit(whichField, uiAspect, uiContainerSize);

    if(FieldBits::NoField != (SizesFieldMask & whichField))
    {
        _mfSizes.beginEdit(uiAspect, uiContainerSize);
    }

    if(FieldBits::NoField != (IndicesFieldMask & whichField))
    {
        _mfIndices.beginEdit(uiAspect, uiContainerSize);
    }

    if(FieldBits::NoField != (TextureZsFieldMask & whichField))
    {
        _mfTextureZs.beginEdit(uiAspect, uiContainerSize);
    }
}
#endif


inline
Char8 *ParticlesBase::getClassname(void)
{
    return "Particles";
}

typedef PointerBuilder<Particles>::ObjPtr          ParticlesPtr;
typedef PointerBuilder<Particles>::ObjPtrConst     ParticlesPtrConst;
typedef PointerBuilder<Particles>::ObjConstPtr     ParticlesConstPtr;

typedef PointerBuilder<Particles>::ObjPtrArg       ParticlesPtrArg;
typedef PointerBuilder<Particles>::ObjConstPtrArg  ParticlesConstPtrArg;
typedef PointerBuilder<Particles>::ObjPtrConstArg  ParticlesPtrConstArg;

OSG_END_NAMESPACE

#define OSGPARTICLESBASE_INLINE_CVSID "@(#)$Id$"
