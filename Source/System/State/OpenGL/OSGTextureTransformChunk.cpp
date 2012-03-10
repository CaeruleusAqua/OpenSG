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

#include "OSGGL.h"

#include "OSGTextureTransformChunk.h"
#include "OSGWindow.h"
#include "OSGCamera.h"
#include "OSGViewport.h"
#include "OSGTextureBaseChunk.h"
#include "OSGDrawEnv.h"

OSG_USING_NAMESPACE

// Documentation for this class is emited in the
// OSGTextureTransformChunkBase.cpp file.
// To modify it, please change the .fcd file (OSGTextureTransformChunk.fcd) and
// regenerate the base file.

/***************************************************************************\
 *                           Class variables                               *
\***************************************************************************/

StateChunkClass TextureTransformChunk::_class("TextureTransform",
                                              osgMaxTexCoords, 
                                              130);

/***************************************************************************\
 *                           Class methods                                 *
\***************************************************************************/

void TextureTransformChunk::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);
}

/***************************************************************************\
 *                           Instance methods                              *
\***************************************************************************/

/*-------------------------------------------------------------------------*\
 -  private                                                                 -
\*-------------------------------------------------------------------------*/

TextureTransformChunk::TextureTransformChunk(void) :
    Inherited()
{
}

TextureTransformChunk::TextureTransformChunk(
    const TextureTransformChunk &source) :

    Inherited(source)
{
}

TextureTransformChunk::~TextureTransformChunk(void)
{
}

/*------------------------- Chunk Class Access ---------------------------*/

const StateChunkClass *TextureTransformChunk::getClass(void) const
{
    return &_class;
}

/*------------------------------- Sync -----------------------------------*/

void TextureTransformChunk::changed(ConstFieldMaskArg whichField, 
                                    UInt32            origin,
                                    BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

/*------------------------------ Output ----------------------------------*/

void TextureTransformChunk::dump(      UInt32    , 
                                 const BitVector ) const
{
    SLOG << "Dump TextureTransformChunk NI" << std::endl;
}

/*------------------------------ State ------------------------------------*/

void TextureTransformChunk::activate(DrawEnv *pEnv, UInt32 idx)
{
#if !defined(OSG_OGL_COREONLY) || defined(OSG_CHECK_COREONLY)
    Window *win = pEnv->getWindow();
    
    Real32 ntexcoords;
    if((ntexcoords = win->getConstantValue(GL_MAX_TEXTURE_COORDS_ARB)) ==
       Window::unknownConstant
      )
    {
        ntexcoords = win->getConstantValue(GL_MAX_TEXTURE_UNITS_ARB);
        // sgi doesn't support GL_MAX_TEXTURE_UNITS_ARB!
        if(ntexcoords == Window::unknownConstant)
            ntexcoords = 1.0f;
    }

    if(idx >= static_cast<UInt32>(ntexcoords))
    {
#ifdef OSG_DEBUG
        FWARNING(("TextureTransformChunk::deactivate: Trying to bind "
                  "texcoord unit %d, but Window %p only supports %lf!\n",
                  idx, win, ntexcoords));
#endif
        return;        
    }

    TextureBaseChunk::activateTexture(win, idx);
  
    glMatrixMode(GL_TEXTURE);

    if(getUseCameraBeacon())
    {
        Matrix m = pEnv->getCameraToWorld();
        
        m[3].setValues(0, 0, 0, 1);
        glLoadMatrixf(m.getValues());
    }
    else
    {
        glLoadMatrixf(getMatrix().getValues());
    }
    glMatrixMode(GL_MODELVIEW);
#else
    OSG_ASSERT(false);
#endif
}

void TextureTransformChunk::changeFrom(DrawEnv    *pEnv, 
                                       StateChunk *old, 
                                       UInt32      idx )
{
#if !defined(OSG_OGL_COREONLY) || defined(OSG_CHECK_COREONLY)
    // change from me to me?
    // this assumes I haven't changed in the meantime. is that a valid
    // assumption? 

    if ( old == this )
        return;

    Window *win = pEnv->getWindow();
    
    Real32 ntexcoords;
    if((ntexcoords = win->getConstantValue(GL_MAX_TEXTURE_COORDS_ARB)) ==
       Window::unknownConstant
      )
    {
        ntexcoords = win->getConstantValue(GL_MAX_TEXTURE_UNITS_ARB);
        // sgi doesn't support GL_MAX_TEXTURE_UNITS_ARB!
        if(ntexcoords == Window::unknownConstant)
            ntexcoords = 1.0f;
    }

    if(idx >= static_cast<UInt32>(ntexcoords))
    {
#ifdef OSG_DEBUG
        FWARNING(("TextureTransformChunk::deactivate: Trying to bind "
                  "texcoord unit %d, but Window %p only supports %lf!\n",
                  idx, win, ntexcoords));
#endif
        return;        
    }

    TextureBaseChunk::activateTexture(win, idx);

    glMatrixMode(GL_TEXTURE);
    if(getUseCameraBeacon())
    {
        Matrix m = pEnv->getCameraToWorld();

        m[3].setValues(0, 0, 0, 1);
        glLoadMatrixf(m.getValues());
    }
    else
    {
        glLoadMatrixf(getMatrix().getValues());
    }
    glMatrixMode(GL_MODELVIEW);
#else
    OSG_ASSERT(false);
#endif
}

void TextureTransformChunk::deactivate(DrawEnv *pEnv, UInt32 idx)
{
#if !defined(OSG_OGL_COREONLY) || defined(OSG_CHECK_COREONLY)
    Window *win = pEnv->getWindow();   

    Real32 ntexcoords;
    if((ntexcoords = win->getConstantValue(GL_MAX_TEXTURE_COORDS_ARB)) ==
       Window::unknownConstant
      )
    {
        ntexcoords = win->getConstantValue(GL_MAX_TEXTURE_UNITS_ARB);
        // sgi doesn't support GL_MAX_TEXTURE_UNITS_ARB!
        if(ntexcoords == Window::unknownConstant)
            ntexcoords = 1.0f;
    }

    if(idx >= static_cast<UInt32>(ntexcoords))
    {
#ifdef OSG_DEBUG
        FWARNING(("TextureTransformChunk::deactivate: Trying to bind"
                  " texcoord unit %d, but Window %p only supports %lf!\n",
                  idx, win, ntexcoords));
#endif
        return;        
    }

    TextureBaseChunk::activateTexture(win, idx);

    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
#else
    OSG_ASSERT(false);
#endif
}


/*-------------------------- Comparison -----------------------------------*/

Real32 TextureTransformChunk::switchCost(StateChunk *OSG_CHECK_ARG(chunk))
{
    return 0;
}

bool TextureTransformChunk::operator <(const StateChunk &other) const
{
    return this < &other;
}

bool TextureTransformChunk::operator ==(const StateChunk &other) const
{
    TextureTransformChunk const *tother = 
        dynamic_cast<TextureTransformChunk const*>(&other);

    if(!tother)
        return false;

    if(tother == this)
        return true;

    if(getMatrix() != tother->getMatrix())
        return false;

    return true;
}

bool TextureTransformChunk::operator !=(const StateChunk &other) const
{
    return !(*this == other);
}
