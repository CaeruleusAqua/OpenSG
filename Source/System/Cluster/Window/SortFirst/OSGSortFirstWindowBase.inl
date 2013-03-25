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
 **     class SortFirstWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &SortFirstWindowBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 SortFirstWindowBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 SortFirstWindowBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the SortFirstWindow::_sfCompression field.

inline
std::string &SortFirstWindowBase::editCompression(void)
{
    editSField(CompressionFieldMask);

    return _sfCompression.getValue();
}

//! Get the value of the SortFirstWindow::_sfCompression field.
inline
const std::string &SortFirstWindowBase::getCompression(void) const
{
    return _sfCompression.getValue();
}

//! Set the value of the SortFirstWindow::_sfCompression field.
inline
void SortFirstWindowBase::setCompression(const std::string &value)
{
    editSField(CompressionFieldMask);

    _sfCompression.setValue(value);
}
//! Get the value of the SortFirstWindow::_sfSubtileSize field.

inline
UInt32 &SortFirstWindowBase::editSubtileSize(void)
{
    editSField(SubtileSizeFieldMask);

    return _sfSubtileSize.getValue();
}

//! Get the value of the SortFirstWindow::_sfSubtileSize field.
inline
      UInt32  SortFirstWindowBase::getSubtileSize(void) const
{
    return _sfSubtileSize.getValue();
}

//! Set the value of the SortFirstWindow::_sfSubtileSize field.
inline
void SortFirstWindowBase::setSubtileSize(const UInt32 value)
{
    editSField(SubtileSizeFieldMask);

    _sfSubtileSize.setValue(value);
}
//! Get the value of the SortFirstWindow::_sfCompose field.

inline
bool &SortFirstWindowBase::editCompose(void)
{
    editSField(ComposeFieldMask);

    return _sfCompose.getValue();
}

//! Get the value of the SortFirstWindow::_sfCompose field.
inline
      bool  SortFirstWindowBase::getCompose(void) const
{
    return _sfCompose.getValue();
}

//! Set the value of the SortFirstWindow::_sfCompose field.
inline
void SortFirstWindowBase::setCompose(const bool value)
{
    editSField(ComposeFieldMask);

    _sfCompose.setValue(value);
}
//! Get the value of the SortFirstWindow::_sfUseFaceDistribution field.

inline
bool &SortFirstWindowBase::editUseFaceDistribution(void)
{
    editSField(UseFaceDistributionFieldMask);

    return _sfUseFaceDistribution.getValue();
}

//! Get the value of the SortFirstWindow::_sfUseFaceDistribution field.
inline
      bool  SortFirstWindowBase::getUseFaceDistribution(void) const
{
    return _sfUseFaceDistribution.getValue();
}

//! Set the value of the SortFirstWindow::_sfUseFaceDistribution field.
inline
void SortFirstWindowBase::setUseFaceDistribution(const bool value)
{
    editSField(UseFaceDistributionFieldMask);

    _sfUseFaceDistribution.setValue(value);
}

//! Get the value of the \a index element the SortFirstWindow::_mfRegion field.
inline
      UInt32  SortFirstWindowBase::getRegion(const UInt32 index) const
{
    return _mfRegion[index];
}

inline
UInt32 &SortFirstWindowBase::editRegion(const UInt32 index)
{
    editMField(RegionFieldMask, _mfRegion);

    return _mfRegion[index];
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void SortFirstWindowBase::execSync (      SortFirstWindowBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (CompressionFieldMask & whichField))
        _sfCompression.syncWith(pFrom->_sfCompression);

    if(FieldBits::NoField != (SubtileSizeFieldMask & whichField))
        _sfSubtileSize.syncWith(pFrom->_sfSubtileSize);

    if(FieldBits::NoField != (ComposeFieldMask & whichField))
        _sfCompose.syncWith(pFrom->_sfCompose);

    if(FieldBits::NoField != (RegionFieldMask & whichField))
        _mfRegion.syncWith(pFrom->_mfRegion,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (UseFaceDistributionFieldMask & whichField))
        _sfUseFaceDistribution.syncWith(pFrom->_sfUseFaceDistribution);
}
#endif


inline
const Char8 *SortFirstWindowBase::getClassname(void)
{
    return "SortFirstWindow";
}
OSG_GEN_CONTAINERPTR(SortFirstWindow);

OSG_END_NAMESPACE

