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

#ifndef _OSGWINDOW_H_
#define _OSGWINDOW_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"

#include <list>
#include <utility>
#include <boost/function.hpp>

#include "OSGDeprecatedCPP.h"

#include "OSGVector.h"

#include "OSGBackground.h"
#include "OSGCamera.h"
#include "OSGViewport.h"

#include "OSGWindowBase.h"

OSG_BEGIN_NAMESPACE

class DrawEnv;

class RenderActionBase;
class StageValidator;
class ShaderCache;

/*! \brief Window base class. See \ref PageSystemWindowWindow
for a description. */
class OSG_SYSTEM_DLLMAPPING Window : public WindowBase
{
    /*==========================  PUBLIC  =================================*/

  public:

    /**
     * Enumeration values for the status of the GL objects. This is primarily
     * used to signal the object's callback functions what to do. See \ref
     * PageSystemOGLObjects for a description.
     */
    enum GLObjectStatusE
    {
        notused      = 0x0001,  /**< Object is not used at all right now. */
        initialize   = 0x0002,  /**< Object is being initialized for the first time. */
        reinitialize = 0x0003,  /**< Object is being re-initialized (ie. significant change) */
        initialized  = 0x0004,  /**< Object is initialized and valid. */
        needrefresh  = 0x0005,  /**< Object is initialized but needs a refresh. */
        destroy      = 0x0006,  /**< Object is to be destroyed (removed from context) */
        finaldestroy = 0x0007   /**< Object has been removed from contexts, now release resources. */
    };

    enum
    {
        invalidExtensionID = 0x7fffffff,
        invalidFunctionID  = 0x7fffffff
    };

    static const Real32 unknownConstant;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Typedefs                               */
    /*! \{                                                                 */

    typedef boost::function<UInt32 (DrawEnv *, 
                                    UInt32, 
                                    GLObjectStatusE,
                                    UInt32         )> GLObjectFunctor;
    typedef boost::function<void   (DrawEnv *, 
                                    UInt32, 
                                    GLObjectStatusE)> GLObjectDestroyFunctor;

    typedef void (*GLExtensionFunction)(void);

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         detail);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Viewport handling                             */
    /*! \{                                                                 */

/*
    void addPort      (const ViewportPtr &portP);
    void insertPort   (      UInt32       portIndex,
                       const ViewportPtr &portP);

    void replacePort  (      UInt32       portIndex,
                       const ViewportPtr &portP);
    void replacePortBy(const ViewportPtr &portP,
                       const ViewportPtr &newPortP);

    void subPort      (const ViewportPtr &portP);
    void subPort      (      UInt32       portIndex);
 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name             Extension registration                           
    * See \ref */
    /*! \{                                                                 */

    static UInt32 registerExtension(const Char8 *s               );
    static void   ignoreExtensions (const Char8 *s               );

    static UInt32 registerFunction (const Char8 *s,
                                          Int32  ext     = -1,
                                          UInt32 version = 0xffff);

    static void   registerConstant (      GLenum val             );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name               Extension handling                             */
    /*! \{                                                                 */

    static void                 setGLLibraryName  (const Char8  *s     );

           UInt32               getGLVersion      (      void          );

    static Int32                getExtensionId    (const Char8  *s     );
           bool                 hasExtension      (      UInt32  extId );
           bool                 hasExtension      (const Char8  *s     );
    static bool                 hasCommonExtension(      UInt32  extId );
           GLExtensionFunction  getFunction       (      UInt32  funcId);
           GLExtensionFunction  getFunctionNoCheck(      UInt32  funcId);
           void                 dumpExtensions    (      void          );
           GLExtensionFunction  getFunctionByName (const Char8  *s     );
           Real32               getConstantValue  (      GLenum  val   );
    const  Vec2f               &getConstantValuev (      GLenum  val   );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name            Extension string handling                         */
    /*! \{                                                                 */

    static const std::vector<std::string> &getRegisteredExtensions(void);
           const std::vector<std::string> &getRegisteredFunctions (void);
           const std::vector<std::string> &getExtensions          (void);
           const std::vector<std::string> &getIgnoredExtensions   (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name             GL object registration                           */
    /*! \{                                                                 */

    static UInt32 registerGLObject(GLObjectFunctor        functor,
                                   GLObjectDestroyFunctor destroyFunctor,
                                   UInt32                 num = 1);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name               GL object handling                             */
    /*! \{                                                                 */

           UInt32          validateGLObject    (UInt32          osgId,
                                                DrawEnv        *pEnv,
                                                UInt32          uiOptions = 0);
           void            validateAllGLObjects(void);

           //GLObjectStatusE getGLObjectStatus   (UInt32           osgId   );
           void            setGLObjectId       (UInt32           osgId,
                                                UInt32           id2     );
           UInt32          getGLObjectId       (UInt32           osgId   );


    static UInt32          getGLObjectsSize    (void                     );

    static void            refreshGLObject         (UInt32           osgId   );
    static void            refreshAllGLObjects     (void                     );

    static void            reinitializeGLObject    (UInt32           osgId   );
    static void            reinitializeAllGLObjects(void                     );

    static void            destroyGLObject         (UInt32           osgId,
                                                    UInt32           num = 1 );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                 Size handling                                */
    /*! \{                                                                 */

            bool isResizePending(void         );

    virtual void resize         (int width,
                                 int height   );
    virtual void resizeGL       (void         );

            void setSize        (UInt16 width,
                                 UInt16 height);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Drawing                                   */
    /*! \{                                                                 */

    virtual void    frameInit         (void);
    virtual void    frameExit         (void);

#ifdef OSG_OLD_RENDER_ACTION
    virtual void    render            (DrawActionBase   *action = NULL);
    virtual void    renderAllViewports(DrawActionBase   *action = NULL);
#endif

    virtual void    render            (RenderActionBase *action);
    virtual void    renderAllViewports(RenderActionBase *action);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name      Window system implementation functions                  */
    /*! \{                                                                 */

    virtual void init      (void) = 0;
    virtual void activate  (void) = 0;
    virtual void deactivate(void) = 0;
    virtual bool swap      (void) = 0;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

           ShaderCache    *getShaderCache   (void          );
           StageValidator *getStageValidator(void          );
    
    static void            requestStageRun  (Int32 iStageId);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Output                                  */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Output                                  */
    /*! \{                                                                 */

    virtual void dump(      UInt32    uiIndent = 0,
                      const BitVector bvFlags  = 0) const;

    /*! \}                                                                 */

    /*=========================  PROTECTED  ===============================*/

  protected:

    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    Window(void);
    Window(const Window &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~Window(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                GL setup handling                             */
    /*! \{                                                                 */

    virtual void setupGL(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Init                                   */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);
    static bool terminate (void            );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                GL object handling                            */
    /*! \{                                                                 */

    static void   initRegisterGLObject  (UInt32          osgId,
                                         UInt32          num   );

           void   doInitRegisterGLObject(UInt32          osgId,
                                         UInt32          num   );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name           GL object handling helper class                    */
    /*! \{                                                                 */

    class GLObject;

    friend class GLObject;

    /** Used to keep track of the OpenGL objects registered with the system.
     * See \ref PageSystemOGLObjects for a description.
     */
    class GLObject
    {
      public:

        GLObject(GLObjectFunctor funct, GLObjectDestroyFunctor destroy);

        GLObjectFunctor& getFunctor(void                 );
        void             setFunctor(GLObjectFunctor funct);

        GLObjectDestroyFunctor& getDestroyFunctor(void                        );
        void                    setDestroyFunctor(GLObjectDestroyFunctor funct);

        UInt32 getLastValidate(void      );
        void   setLastValidate(UInt32 val);

        UInt32 getRefCounter(void);
        UInt32 incRefCounter(void);
        UInt32 decRefCounter(void);

      protected:

                 GLObjectFunctor        _functor;
                 GLObjectDestroyFunctor _destroy;
        volatile UInt32                 _refCounter;
                 UInt32                 _lastValidate;
    };

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                MT Construction                               */
    /*! \{                                                                 */

           void onCreate       (const Window *source = NULL);

           void onCreateAspect (const Window *createAspect,
                                const Window *source = NULL);

           void onDestroy      (      UInt32  uiContainerId);

           void onDestroyAspect(      UInt32  uiContainerId,
                                      UInt32  uiAspect     );

    static void staticAcquire (void                       );
    static void staticRelease (void                       );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name            Map for GL cvonstant handling                     */
    /*! \{                                                                 */

    typedef OSG_HASH_MAP(GLenum, Vec2f) ConstHash;

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    typedef WindowBase Inherited;

    friend class FieldContainer;
    friend class WindowBase;

    static std::vector<Window *> _allWindows;
    static Int32                 _currentWindowId;

    /*---------------------------------------------------------------------*/
    /*! \name   Static GL Object / Extension variables                     */
    /*! \{                                                                 */

#ifndef OSG_EMBEDDED
    static  Lock                     *_GLObjectLock;
    static  Lock                     *_staticWindowLock;
#endif

    static std::vector<GLObject  *>   _glObjects;
    static const Char8               *_glLibraryName;

    /**
     * List of registered extension names. The index of the entry is the
     * id/handle of the extention.
     */
    static  std::vector<std::string>  _registeredExtensions;
    /** List of names of extensions to ignore. */
    static  std::vector<std::string>  _ignoredExtensions;
    static  std::vector<bool       >  _commonExtensions;       /**< ??? */
    static  std::vector<std::string>  _registeredFunctions;
    static  std::vector<Int32      >  _registeredFunctionExts;
    static  std::vector<UInt32     >  _registeredFunctionVersions;

    static  std::vector<GLenum     >  _registeredConstants;

    typedef std::pair<UInt32,UInt32>   DestroyEntry;

            std::list<DestroyEntry >  _glObjectDestroyList;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name        GL Object / Extension variables                       */
    /*! \{                                                                 */

    std::vector<UInt32             >  _lastValidate;
    std::vector<UInt32             >  _ids;

    UInt32                            _glVersion;
    std::vector<std::string        >  _extensions;
    /**
     * List of whether extension can be used in current context. Indexed by
     * extension id (registeredExtensions).
     */
    std::vector<bool               >  _availExtensions;
    std::vector<GLExtensionFunction>  _extFunctions;

    ConstHash                         _availConstants;
    UInt32                            _numAvailConstants;

    Int32                             _windowId;
    StageValidator                   *_pStageValidator;
    ShaderCache                      *_pShaderCache;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/

    // prohibit default functions (move to 'public' if you need one)
    Window &operator =(const Window &source);
};

//---------------------------------------------------------------------------
//   Exported Types
//---------------------------------------------------------------------------

typedef Window *WindowP;

OSG_END_NAMESPACE

#include "OSGWindowBase.inl"
#include "OSGWindow.inl"

#endif /* _OSGWINDOW_H_ */
