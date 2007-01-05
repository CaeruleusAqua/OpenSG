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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include <OSGGL.h>
#include "OSGMaterial.h"
#include "OSGSimpleMaterial.h"

OSG_USING_NAMESPACE

// Documentation for this class is emited in the
// OSGMaterialBase.cpp file.
// To modify it, please change the .fcd file (OSGMaterial.fcd) and
// regenerate the base file.

/*! \fn OSG::Material::makeState()
  
  Creates an instance of a OSG::State that is used to represent the material.
  This is used by the OSG::DrawAction.  
 */

/*! \fn OSG::Material::rebuildState()
  
  Update the internal OSG::State. 
 */

/*! \fn OSG::Material::getState()
  
  Access the internal OSG::State, used by the OSG::RenderAction.
 */

/*! \fn OSG::Material::isTransparent()
  
  Check if the Material is transparent and thus has to be rendered afte the
  opaque ones.
 */

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

OSG_BEGIN_NAMESPACE
OSG_SYSTEM_DLLMAPPING MaterialPtr NullMaterial;
OSG_END_NAMESPACE

const Int32 Material::NoStateSorting = 0x7fffffff;

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                -
\*-------------------------------------------------------------------------*/

void Material::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  public                                                                 -
\*-------------------------------------------------------------------------*/


/*------------- constructors & destructors --------------------------------*/

Material::Material(void) :
     Inherited(),
    _pState   ()
{
}

Material::Material(const Material &source) :
     Inherited(source),
    _pState   (      )
{
// Doing this kills using prototypes with preset states. 
// What's the point of this anyway? Sharing _pState between Materials never
// makes sense
//    setRefdCP(_pState, source._pState); 
}

Material::~Material(void)
{
    subRef(_pState);
}


StatePtr Material::getState(UInt32)
{
    return _pState;
}

UInt32 Material::getNPasses(void)
{
    return 1;
}

void Material::changed(ConstFieldMaskArg whichField, UInt32 origin)
{
    Inherited::changed(whichField, origin);

    rebuildState();
}

/*------------------------------- dump ----------------------------------*/

void Material::dump(      UInt32    ,
                    const BitVector ) const
{
    SLOG << "Material::dump called: NIY!" << std::endl;
//   Inherited::dump(uiIndent, bvFlags);
}

ActionBase::ResultE Material::renderEnter(const NodeCorePtr &pCore,
                                                Action      *pAction)
{
    return Action::Continue;
}

ActionBase::ResultE Material::renderLeave(const NodeCorePtr &pCore,
                                                  Action      *pAction)
{
    return Action::Continue;
}

/*-------------------------- comparison -----------------------------------*/

bool Material::operator < (const Material &other) const
{
    return this < &other;
}

bool Material::operator == (const Material &other) const
{   
    return _pState == other._pState;
}

bool Material::operator != (const Material &other) const
{
    return ! (*this == other);
}



/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

#if defined(OSG_WIN32_ICL) && !defined(OSG_CHECK_FIELDSETARG)
#pragma warning (disable : 383)
#endif

OSG_BEGIN_NAMESPACE

static bool subRefDefaultMaterial     (void);
static bool subRefDefaultUnlitMaterial(void);


/*! \ingroup GrpSystemDrawablesGeometrySimpleGeometry
    Stores the default material used by the Simple Geometry.
*/
static SimpleMaterialPtr _defaultMaterial;

/*! \ingroup GrpSystemDrawablesGeometrySimpleGeometry
    Access the default Material for Simple Geometry. Also useful whenever 
    an arbitrary material is needed.
*/

MaterialPtr getDefaultMaterial(void)
{
    if(_defaultMaterial == NullFC)
    {
        _defaultMaterial = SimpleMaterial::create();

		_defaultMaterial->setDiffuse  (Color3r(.7f,.7f,.5f));
		_defaultMaterial->setAmbient  (Color3r(0.1f,0.1f,0.1f));
		_defaultMaterial->setSpecular (Color3r(1.f,1.f,1.f));
        _defaultMaterial->setShininess(20.f);

        addRef(_defaultMaterial);

        addPostFactoryExitFunction(subRefDefaultMaterial);

        _defaultMaterial->rebuildState();
    }
    
    return _defaultMaterial;
}

/*! \ingroup GrpSystemDrawablesGeometrySimpleGeometry
    Stores the default unlit material.
*/
static SimpleMaterialPtr _defaultUnlitMaterial;

/*! \ingroup GrpSystemDrawablesGeometrySimpleGeometry
    Access the default unlit Material. Useful whenever 
    an arbitrary unlit material is needed.
*/

MaterialPtr getDefaultUnlitMaterial(void)
{
    if(_defaultUnlitMaterial == NullFC)
    {
        _defaultUnlitMaterial = SimpleMaterial::create();

		_defaultUnlitMaterial->setDiffuse(Color3r(1.f,1.f,.5f));
        _defaultUnlitMaterial->setLit(false);

        addRef(_defaultUnlitMaterial);

        addPostFactoryExitFunction(subRefDefaultUnlitMaterial);

        _defaultUnlitMaterial->rebuildState();
	}
    
    return _defaultUnlitMaterial;
}

bool subRefDefaultMaterial     (void)
{
    subRef(_defaultMaterial);

    return true;
}

bool subRefDefaultUnlitMaterial(void)
{
    subRef(_defaultUnlitMaterial);

    return true;
}

OSG_END_NAMESPACE

/*------------------------------------------------------------------------*/
/*                              cvs id's                                  */

#ifdef OSG_SGI_CC
#pragma set woff 1174
#endif

#ifdef OSG_LINUX_ICC
#pragma warning( disable : 177 )
#endif

namespace
{
    static Char8 cvsid_cpp       [] = "@(#)$Id$";
    static Char8 cvsid_hpp       [] = OSGMATERIAL_HEADER_CVSID;
    static Char8 cvsid_inl       [] = OSGMATERIAL_INLINE_CVSID;

    static Char8 cvsid_fields_hpp[] = OSGMATERIALFIELDS_HEADER_CVSID;
}

#ifdef __sgi
#pragma reset woff 1174
#endif

