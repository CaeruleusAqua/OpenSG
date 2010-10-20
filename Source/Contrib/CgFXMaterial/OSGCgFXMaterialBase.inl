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
 **     class CgFXMaterial!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &CgFXMaterialBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 CgFXMaterialBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 CgFXMaterialBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the CgFXMaterial::_sfTreatTechniquesAsVariants field.

inline
bool &CgFXMaterialBase::editTreatTechniquesAsVariants(void)
{
    editSField(TreatTechniquesAsVariantsFieldMask);

    return _sfTreatTechniquesAsVariants.getValue();
}

//! Get the value of the CgFXMaterial::_sfTreatTechniquesAsVariants field.
inline
      bool  CgFXMaterialBase::getTreatTechniquesAsVariants(void) const
{
    return _sfTreatTechniquesAsVariants.getValue();
}

//! Set the value of the CgFXMaterial::_sfTreatTechniquesAsVariants field.
inline
void CgFXMaterialBase::setTreatTechniquesAsVariants(const bool value)
{
    editSField(TreatTechniquesAsVariantsFieldMask);

    _sfTreatTechniquesAsVariants.setValue(value);
}
//! Get the value of the CgFXMaterial::_sfParameterValueSource field.

inline
UInt8 &CgFXMaterialBase::editParameterValueSource(void)
{
    editSField(ParameterValueSourceFieldMask);

    return _sfParameterValueSource.getValue();
}

//! Get the value of the CgFXMaterial::_sfParameterValueSource field.
inline
      UInt8  CgFXMaterialBase::getParameterValueSource(void) const
{
    return _sfParameterValueSource.getValue();
}

//! Set the value of the CgFXMaterial::_sfParameterValueSource field.
inline
void CgFXMaterialBase::setParameterValueSource(const UInt8 value)
{
    editSField(ParameterValueSourceFieldMask);

    _sfParameterValueSource.setValue(value);
}
//! Get the value of the CgFXMaterial::_sfEffectFile field.

inline
std::string &CgFXMaterialBase::editEffectFile(void)
{
    editSField(EffectFileFieldMask);

    return _sfEffectFile.getValue();
}

//! Get the value of the CgFXMaterial::_sfEffectFile field.
inline
const std::string &CgFXMaterialBase::getEffectFile(void) const
{
    return _sfEffectFile.getValue();
}

//! Set the value of the CgFXMaterial::_sfEffectFile field.
inline
void CgFXMaterialBase::setEffectFile(const std::string &value)
{
    editSField(EffectFileFieldMask);

    _sfEffectFile.setValue(value);
}
//! Get the value of the CgFXMaterial::_sfEffectString field.

inline
std::string &CgFXMaterialBase::editEffectString(void)
{
    editSField(EffectStringFieldMask);

    return _sfEffectString.getValue();
}

//! Get the value of the CgFXMaterial::_sfEffectString field.
inline
const std::string &CgFXMaterialBase::getEffectString(void) const
{
    return _sfEffectString.getValue();
}

//! Set the value of the CgFXMaterial::_sfEffectString field.
inline
void CgFXMaterialBase::setEffectString(const std::string &value)
{
    editSField(EffectStringFieldMask);

    _sfEffectString.setValue(value);
}

//! Get the value of the CgFXMaterial::_sfVariables field.
inline
ShaderProgramVariables * CgFXMaterialBase::getVariables(void) const
{
    return _sfVariables.getValue();
}

//! Set the value of the CgFXMaterial::_sfVariables field.
inline
void CgFXMaterialBase::setVariables(ShaderProgramVariables * const value)
{
    editSField(VariablesFieldMask);

    _sfVariables.setValue(value);
}
//! Get the value of the CgFXMaterial::_sfSelectedTechnique field.

inline
std::string &CgFXMaterialBase::editSelectedTechnique(void)
{
    editSField(SelectedTechniqueFieldMask);

    return _sfSelectedTechnique.getValue();
}

//! Get the value of the CgFXMaterial::_sfSelectedTechnique field.
inline
const std::string &CgFXMaterialBase::getSelectedTechnique(void) const
{
    return _sfSelectedTechnique.getValue();
}

//! Set the value of the CgFXMaterial::_sfSelectedTechnique field.
inline
void CgFXMaterialBase::setSelectedTechnique(const std::string &value)
{
    editSField(SelectedTechniqueFieldMask);

    _sfSelectedTechnique.setValue(value);
}
//! Get the value of the CgFXMaterial::_sfStateVariables field.

inline
UInt32 &CgFXMaterialBase::editStateVariables(void)
{
    editSField(StateVariablesFieldMask);

    return _sfStateVariables.getValue();
}

//! Get the value of the CgFXMaterial::_sfStateVariables field.
inline
      UInt32  CgFXMaterialBase::getStateVariables(void) const
{
    return _sfStateVariables.getValue();
}

//! Set the value of the CgFXMaterial::_sfStateVariables field.
inline
void CgFXMaterialBase::setStateVariables(const UInt32 value)
{
    editSField(StateVariablesFieldMask);

    _sfStateVariables.setValue(value);
}
//! Get the value of the CgFXMaterial::_sfGLId field.

inline
GLenum &CgFXMaterialBase::editGLId(void)
{
    editSField(GLIdFieldMask);

    return _sfGLId.getValue();
}

//! Get the value of the CgFXMaterial::_sfGLId field.
inline
const GLenum &CgFXMaterialBase::getGLId(void) const
{
    return _sfGLId.getValue();
}

//! Set the value of the CgFXMaterial::_sfGLId field.
inline
void CgFXMaterialBase::setGLId(const GLenum &value)
{
    editSField(GLIdFieldMask);

    _sfGLId.setValue(value);
}

//! Get the value of the \a index element the CgFXMaterial::_mfCompilerOptions field.
inline
const std::string &CgFXMaterialBase::getCompilerOptions(const UInt32 index) const
{
    return _mfCompilerOptions[index];
}

inline
std::string &CgFXMaterialBase::editCompilerOptions(const UInt32 index)
{
    editMField(CompilerOptionsFieldMask, _mfCompilerOptions);

    return _mfCompilerOptions[index];
}


//! Get the value of the \a index element the CgFXMaterial::_mfTechniques field.
inline
CgFXTechnique * CgFXMaterialBase::getTechniques(const UInt32 index) const
{
    return _mfTechniques[index];
}

//! Get the value of the \a index element the CgFXMaterial::_mfTextures field.
inline
TextureObjChunk * CgFXMaterialBase::getTextures(const UInt32 index) const
{
    return _mfTextures[index];
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void CgFXMaterialBase::execSync (      CgFXMaterialBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (TreatTechniquesAsVariantsFieldMask & whichField))
        _sfTreatTechniquesAsVariants.syncWith(pFrom->_sfTreatTechniquesAsVariants);

    if(FieldBits::NoField != (ParameterValueSourceFieldMask & whichField))
        _sfParameterValueSource.syncWith(pFrom->_sfParameterValueSource);

    if(FieldBits::NoField != (EffectFileFieldMask & whichField))
        _sfEffectFile.syncWith(pFrom->_sfEffectFile);

    if(FieldBits::NoField != (EffectStringFieldMask & whichField))
        _sfEffectString.syncWith(pFrom->_sfEffectString);

    if(FieldBits::NoField != (CompilerOptionsFieldMask & whichField))
        _mfCompilerOptions.syncWith(pFrom->_mfCompilerOptions,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (VariablesFieldMask & whichField))
        _sfVariables.syncWith(pFrom->_sfVariables);

    if(FieldBits::NoField != (SelectedTechniqueFieldMask & whichField))
        _sfSelectedTechnique.syncWith(pFrom->_sfSelectedTechnique);

    if(FieldBits::NoField != (StateVariablesFieldMask & whichField))
        _sfStateVariables.syncWith(pFrom->_sfStateVariables);

    if(FieldBits::NoField != (TechniquesFieldMask & whichField))
        _mfTechniques.syncWith(pFrom->_mfTechniques,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (TexturesFieldMask & whichField))
        _mfTextures.syncWith(pFrom->_mfTextures,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (GLIdFieldMask & whichField))
        _sfGLId.syncWith(pFrom->_sfGLId);
}
#endif


inline
const Char8 *CgFXMaterialBase::getClassname(void)
{
    return "CgFXMaterial";
}
OSG_GEN_CONTAINERPTR(CgFXMaterial);

OSG_END_NAMESPACE

