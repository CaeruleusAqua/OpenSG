/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *                     Copyright 2000-2002 by OpenSG Forum                   *
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


OSG_BEGIN_NAMESPACE

inline
const StateChunkClass *TextureBaseChunk::getStaticClass(void)
{
    return &TextureBaseChunk::_class;
}

inline
UInt32 TextureBaseChunk::getStaticClassId(void)
{
    return getStaticClass()->getId();
}

inline
UInt16 TextureBaseChunk::getChunkId(void)
{
    return _uiChunkId;
}

inline 
bool TextureBaseChunk::hasMultiTexture(Window *win)
{
    return win->hasExtOrVersion(_arbMultiTex, 0x0103, 0x0200);
}

//! call glActiveTexture via the extension mechanism
inline 
void TextureBaseChunk::activeTexture(Window *win, UInt16 texture)
{
    OSGGETGLFUNCBYID_GL3_ES( glActiveTexture,
                             osgGlActiveTexture,
                            _funcActiveTexture,
                             win);

    osgGlActiveTexture(GL_TEXTURE0 + texture);
}

//! call glActiveTexture via the extension mechanism, if MultiTextures
//! are supported. Return false if successful, true if not.
inline 
bool TextureBaseChunk::activateTexture(Window *win, UInt16 texture)
{
    if(hasMultiTexture(win))
    {
        activeTexture(win, texture);
    }
#ifdef OSG_DEBUG
    else
    {
        if(texture != 0)
        {
            FWARNING(("TextureChunk::activateTexture: trying to activate "
                      "texture %d, but Window %p doesn't support "
                      "multi-textures!\n", 
                      texture, 
                      static_cast<void *>(win)));
            return true;
        }
    }
#endif
    return false;
}


OSG_END_NAMESPACE

