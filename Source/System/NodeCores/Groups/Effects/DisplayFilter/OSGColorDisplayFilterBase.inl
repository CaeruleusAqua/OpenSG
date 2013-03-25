/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
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
 **     class ColorDisplayFilter!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &ColorDisplayFilterBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 ColorDisplayFilterBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 ColorDisplayFilterBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the ColorDisplayFilter::_sfGamma field.

inline
Real32 &ColorDisplayFilterBase::editGamma(void)
{
    editSField(GammaFieldMask);

    return _sfGamma.getValue();
}

//! Get the value of the ColorDisplayFilter::_sfGamma field.
inline
      Real32  ColorDisplayFilterBase::getGamma(void) const
{
    return _sfGamma.getValue();
}

//! Set the value of the ColorDisplayFilter::_sfGamma field.
inline
void ColorDisplayFilterBase::setGamma(const Real32 value)
{
    editSField(GammaFieldMask);

    _sfGamma.setValue(value);
}
//! Get the value of the ColorDisplayFilter::_sfMatrix field.

inline
Matrix &ColorDisplayFilterBase::editMatrix(void)
{
    editSField(MatrixFieldMask);

    return _sfMatrix.getValue();
}

//! Get the value of the ColorDisplayFilter::_sfMatrix field.
inline
const Matrix &ColorDisplayFilterBase::getMatrix(void) const
{
    return _sfMatrix.getValue();
}

//! Set the value of the ColorDisplayFilter::_sfMatrix field.
inline
void ColorDisplayFilterBase::setMatrix(const Matrix &value)
{
    editSField(MatrixFieldMask);

    _sfMatrix.setValue(value);
}
//! Get the value of the ColorDisplayFilter::_sfColorTableWidth field.

inline
UInt32 &ColorDisplayFilterBase::editColorTableWidth(void)
{
    editSField(ColorTableWidthFieldMask);

    return _sfColorTableWidth.getValue();
}

//! Get the value of the ColorDisplayFilter::_sfColorTableWidth field.
inline
      UInt32  ColorDisplayFilterBase::getColorTableWidth(void) const
{
    return _sfColorTableWidth.getValue();
}

//! Set the value of the ColorDisplayFilter::_sfColorTableWidth field.
inline
void ColorDisplayFilterBase::setColorTableWidth(const UInt32 value)
{
    editSField(ColorTableWidthFieldMask);

    _sfColorTableWidth.setValue(value);
}
//! Get the value of the ColorDisplayFilter::_sfColorTableHeight field.

inline
UInt32 &ColorDisplayFilterBase::editColorTableHeight(void)
{
    editSField(ColorTableHeightFieldMask);

    return _sfColorTableHeight.getValue();
}

//! Get the value of the ColorDisplayFilter::_sfColorTableHeight field.
inline
      UInt32  ColorDisplayFilterBase::getColorTableHeight(void) const
{
    return _sfColorTableHeight.getValue();
}

//! Set the value of the ColorDisplayFilter::_sfColorTableHeight field.
inline
void ColorDisplayFilterBase::setColorTableHeight(const UInt32 value)
{
    editSField(ColorTableHeightFieldMask);

    _sfColorTableHeight.setValue(value);
}
//! Get the value of the ColorDisplayFilter::_sfColorTableDepth field.

inline
UInt32 &ColorDisplayFilterBase::editColorTableDepth(void)
{
    editSField(ColorTableDepthFieldMask);

    return _sfColorTableDepth.getValue();
}

//! Get the value of the ColorDisplayFilter::_sfColorTableDepth field.
inline
      UInt32  ColorDisplayFilterBase::getColorTableDepth(void) const
{
    return _sfColorTableDepth.getValue();
}

//! Set the value of the ColorDisplayFilter::_sfColorTableDepth field.
inline
void ColorDisplayFilterBase::setColorTableDepth(const UInt32 value)
{
    editSField(ColorTableDepthFieldMask);

    _sfColorTableDepth.setValue(value);
}

//! Get the value of the \a index element the ColorDisplayFilter::_mfColorTable field.
inline
const Color3f &ColorDisplayFilterBase::getColorTable(const UInt32 index) const
{
    return _mfColorTable[index];
}

inline
Color3f &ColorDisplayFilterBase::editColorTable(const UInt32 index)
{
    editMField(ColorTableFieldMask, _mfColorTable);

    return _mfColorTable[index];
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void ColorDisplayFilterBase::execSync (      ColorDisplayFilterBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (GammaFieldMask & whichField))
        _sfGamma.syncWith(pFrom->_sfGamma);

    if(FieldBits::NoField != (MatrixFieldMask & whichField))
        _sfMatrix.syncWith(pFrom->_sfMatrix);

    if(FieldBits::NoField != (ColorTableWidthFieldMask & whichField))
        _sfColorTableWidth.syncWith(pFrom->_sfColorTableWidth);

    if(FieldBits::NoField != (ColorTableHeightFieldMask & whichField))
        _sfColorTableHeight.syncWith(pFrom->_sfColorTableHeight);

    if(FieldBits::NoField != (ColorTableDepthFieldMask & whichField))
        _sfColorTableDepth.syncWith(pFrom->_sfColorTableDepth);

    if(FieldBits::NoField != (ColorTableFieldMask & whichField))
        _mfColorTable.syncWith(pFrom->_mfColorTable,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (TableImageFieldMask & whichField))
        _sfTableImage.syncWith(pFrom->_sfTableImage);

    if(FieldBits::NoField != (FilterShaderFieldMask & whichField))
        _sfFilterShader.syncWith(pFrom->_sfFilterShader);
}
#endif


inline
const Char8 *ColorDisplayFilterBase::getClassname(void)
{
    return "ColorDisplayFilter";
}
OSG_GEN_CONTAINERPTR(ColorDisplayFilter);

OSG_END_NAMESPACE

