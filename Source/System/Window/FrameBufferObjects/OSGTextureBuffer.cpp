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

#include <OSGConfig.h>
#include <OSGGL.h>
#include <OSGGLEXT.h>

#include "OSGTextureBuffer.h"
#include "OSGWindow.h"
#include "OSGDrawEnv.h"
#include "OSGTextureObjChunk.h"

OSG_USING_NAMESPACE


UInt32 TextureBuffer::_uiFramebuffer_object_extension = 
    Window::invalidExtensionID;

UInt32 TextureBuffer::_uiFuncFramebufferTexture1D =  Window::invalidFunctionID;
UInt32 TextureBuffer::_uiFuncFramebufferTexture2D =  Window::invalidFunctionID;
UInt32 TextureBuffer::_uiFuncFramebufferTexture3D =  Window::invalidFunctionID;
UInt32 TextureBuffer::_uiFuncGenerateMipmap       =  Window::invalidFunctionID;


typedef void (OSG_APIENTRY *GLFramebufferTexture1DEXTProcT)(
    GLenum target, 
    GLenum attachment, 
    GLenum textarget, 
    GLuint texture, 
    GLint level);

typedef void (OSG_APIENTRY *GLFramebufferTexture2DEXTProcT)(
    GLenum target, 
    GLenum attachment, 
    GLenum textarget, 
    GLuint texture, 
    GLint level);

typedef void (OSG_APIENTRY *GLFramebufferTexture3DEXTProcT)(
    GLenum target, 
    GLenum attachment, 
    GLenum textarget, 
    GLuint texture, 
    GLint level, 
    GLint zoffset);

typedef void   (OSG_APIENTRY *GLGenerateMipmapEXTProcT)(GLenum target);

// Documentation for this class is emited in the
// OSGTextureBufferBase.cpp file.
// To modify it, please change the .fcd file (OSGTextureBuffer.fcd) and
// regenerate the base file.

void TextureBuffer::bind(DrawEnv *pEnv, UInt32 index)
{
    Window *pWindow = pEnv->getWindow();

    if(_sfTexture.getValue() != NULL)
    {
        pWindow->validateGLObject(_sfTexture.getValue()->getGLId(), pEnv);

        GLenum target;

        if(getTexTarget() != GL_NONE)
        {
            target = getTexTarget();
        }
        else
        {
            target = _sfTexture.getValue()->determineTextureTarget(pWindow);
        }
            
        switch(target)
        {
            case GL_TEXTURE_1D:
            {
                GLFramebufferTexture1DEXTProcT 
                    glFramebufferTexture1DEXTProc =

                    reinterpret_cast<GLFramebufferTexture1DEXTProcT>(
                        pWindow->getFunction(_uiFuncFramebufferTexture1D));

                glFramebufferTexture1DEXTProc(
                    GL_FRAMEBUFFER_EXT, 
                    index,
                    target,
                    pWindow->getGLObjectId(
                        _sfTexture.getValue()->getGLId()),
                    getLevel());
             }
            break;
                
            case GL_TEXTURE_2D:
            case GL_TEXTURE_RECTANGLE_ARB:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB:
            {
                GLFramebufferTexture2DEXTProcT 
                    glFramebufferTexture2DEXTProc =

                    reinterpret_cast<GLFramebufferTexture2DEXTProcT>(
                        pWindow->getFunction(_uiFuncFramebufferTexture2D));

                glFramebufferTexture2DEXTProc(
                    GL_FRAMEBUFFER_EXT, 
                    index,
                    target,
                    pWindow->getGLObjectId(
                        _sfTexture.getValue()->getGLId()),
                    getLevel());
            }
            break;
                
            case GL_TEXTURE_3D:
                break;
        }
    }
}

void TextureBuffer::validate(DrawEnv *pEnv)
{
    Window *pWindow = pEnv->getWindow();

    if(_sfTexture.getValue() != NULL)
    {
        pWindow->validateGLObject(_sfTexture.getValue()->getGLId(), pEnv);
    }
}

void TextureBuffer::processPreDeactivate(DrawEnv *pEnv, UInt32 index)
{
    if(_sfReadBack.getValue() == true)
    {
        TextureObjChunk *pTexObj = this->getTexture();
        
        if(pTexObj == NULL)
            return;
        
        Image *pTexImg = pTexObj->getImage();
                    
        if(pTexImg->getData() == NULL)
        {
            SINFO << "TextureBuffer::render: (Re)Allocating image "
                  << "for read-back."
                  << endLog;
            
            pTexImg->set(pTexImg->getPixelFormat(),
                         pTexImg->getWidth      (),
                         pTexImg->getHeight     ());
        }
        
        // select GL_COLORATTACHMENTn and read data into image
        glReadBuffer(index);
        glReadPixels(0, 0, 
                     pTexImg->getWidth      (), 
                     pTexImg->getHeight     (),
                     pTexImg->getPixelFormat(), 
                     pTexImg->getDataType   (),
                     pTexImg->editData      ());

        glReadBuffer(GL_NONE);
    }
}

void TextureBuffer::processPostDeactivate(DrawEnv *pEnv)
{
    Window *win = pEnv->getWindow();

    // If there are TextureBuffers with mipmap filters attached,
    // the mipmaps need to be regenerated
    GLGenerateMipmapEXTProcT glGenerateMipmapExtProc =
        reinterpret_cast<GLGenerateMipmapEXTProcT>(
            win->getFunction(_uiFuncGenerateMipmap));

    TextureObjChunk *pTexObj = this->getTexture();
        
    if(pTexObj == NULL)
        return;
        
    GLenum target = pTexObj->determineTextureTarget(win);
    
    if(target                  == GL_TEXTURE_2D                 &&
       (pTexObj->getMinFilter() == GL_NEAREST_MIPMAP_NEAREST ||
        pTexObj->getMinFilter() == GL_LINEAR_MIPMAP_NEAREST  ||
        pTexObj->getMinFilter() == GL_NEAREST_MIPMAP_LINEAR  ||
        pTexObj->getMinFilter() == GL_LINEAR_MIPMAP_LINEAR     )   )
    {
        glBindTexture(target, win->getGLObjectId(pTexObj->getGLId()));
        glGenerateMipmapExtProc(target);
    }
}

/*----------------------- constructors & destructors ----------------------*/

TextureBuffer::TextureBuffer(void) :
    Inherited()
{
}

TextureBuffer::TextureBuffer(const TextureBuffer &source) :
    Inherited(source)
{
}

TextureBuffer::~TextureBuffer(void)
{
}

/*----------------------------- class specific ----------------------------*/

void TextureBuffer::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        _uiFramebuffer_object_extension = 
            Window::registerExtension("GL_EXT_framebuffer_object");

        _uiFuncFramebufferTexture1D =
            Window::registerFunction (
                OSG_DLSYM_UNDERSCORE"glFramebufferTexture1DEXT", 
                _uiFramebuffer_object_extension);

        _uiFuncFramebufferTexture2D =
            Window::registerFunction (
                OSG_DLSYM_UNDERSCORE"glFramebufferTexture2DEXT", 
                _uiFramebuffer_object_extension);

        _uiFuncFramebufferTexture3D =
            Window::registerFunction (
                OSG_DLSYM_UNDERSCORE"glFramebufferTexture3DEXT", 
                _uiFramebuffer_object_extension);

        _uiFuncGenerateMipmap =
            Window::registerFunction (
                OSG_DLSYM_UNDERSCORE"glGenerateMipmapEXT",
                _uiFramebuffer_object_extension);
    }

}

void TextureBuffer::changed(ConstFieldMaskArg whichField, 
                            UInt32            origin,
                            BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void TextureBuffer::dump(      UInt32    , 
                         const BitVector ) const
{
    SLOG << "Dump TextureBuffer NI" << std::endl;
}


