
import logging;

from FCDElement import FCDElement;

class FieldContainer(FCDElement):
    """Represents a <Field/> element from a .fcd file.
    """

    def __init__(self):
        super(FieldContainer, self).__init__();
        self.m_log    = logging.getLogger("FieldContainer");
        self.m_fields = [];
        
        self.initFCDDict();
    
    def initFCDDict(self):
        """Sets the fcd dictionary to default values.
        """
        self.setFCD("name",                  "");
        self.setFCD("parent",                "");
        self.setFCD("library",               "");
        self.setFCD("pointerfieldtypes",     "");
        self.setFCD("structure",             "");
        self.setFCD("systemcomponent",       "true");
        self.setFCD("parentsystemcomponent", "true");
        self.setFCD("decoratable",           "false");
        self.setFCD("useLocalIncludes",      "false");
        self.setFCD("isNodeCore",            "false");
        self.setFCD("description",           "");
        self.setFCD("group",                 "NULL");
        self.setFCD("namespace",             "");
        self.setFCD("decorateeFieldFlags",   "");
        self.setFCD("additionalIncludes",    "");
        self.setFCD("fcdFileLines",          []);
    
    #
    # Access fields
    
    def addField(self, field):
        idx = len(self.m_fields);
        field.setFieldContainer(self);
        self.m_fields.append(field);
        return idx;
    
    #
    # Common tests
    
    def isSystemComponent(self):
        return self["isSystemComponent"];
    
    def isDecoratable(self):
        return self["isDecoratable"];
    
    def setupFieldContainer(self):
        self["Classname"]   = self.getFCD("name");
        self["CLASSNAME"]   = self.getFCD("name").upper();
        self["Parent"]      = self.getFCD("parent");
        self["isDecorator"] = False;
    
    def setupDecorator(self):
        self["Classname"]   = self.getFCD("name") + "Decorator";
        self["CLASSNAME"]   = self.getFCD("name").upper() + "DECORATOR";
        self["Parent"]      = self.getFCD("name");
        self["isDecorator"] = True;
    
    def finalize(self):
        if len(self.m_fields) > 0:
            self["hasFields"] = True;
        else:
            self["hasFields"] = False;
        
        if self.getFCD("library") != "":
            self["isInLibrary"] = True;
            self["Libname"]     = self.getFCD("library");
            self["LIBNAME"]     = self.getFCD("library").upper();
        else:
            if self.getFCD("systemcomponent") == "true":
                self.m_log.error("finalize: \"library\" not set for a systemcomponent.");
                self["isInLibrary"] = True;
                self["Libname"]     = "<UNDEF>";
                self["LIBNAME"]     = "<UNDEF>";
            else:
                self["isInLibrary"] = False;
                self["Libname"]     = None;
                self["LIBNAME"]     = None;
        
        if self.getFCD("name") != "":
            self["Classname"] = self.getFCD("name");
            self["CLASSNAME"] = self.getFCD("name").upper();
        else:
            self.m_log.error("finalize: \"name\" has no valid value.");
            self["Classname"] = "<UNDEF>";
            self["CLASSNAME"] = "<UNDEF>";
        
        if self.getFCD("parent") != "":
            self["Parent"] = self.getFCD("parent");
        else:
            self.m_log.error("finalize: \"parent\" has no valid value.");
            self["Parent"] = "<UNDEF>";
        
        if self.getFCD("decoratable") == "true":
            self["isDecoratable"] = True;
        else:
            self["isDecoratable"] = False;
        
        if self.getFCD("systemcomponent") == "true":
            self["isSystemComponent"] = True;
        else:
            self["isSystemComponent"] = False;
        
        if self.getFCD("structure") == "concrete":
            self["isAbstract"] = False;
        elif self.getFCD("structure") == "abstract":
            self["isAbstract"] = True;
        else:
            self.m_log.warning("finalize: \"structure\" has no valid value.");
        
        if ((self.getFCD("parentsystemcomponent") == "true") and
            (self.getFCD("systemcomponent")       == "false")   ):
            self["ParentHeaderPrefix"] = "OpenSG/";
        else:
            self["ParentHeaderPrefix"] = "";
        
        if self.getFCD("systemcomponent") == "false":
            self["HeaderPrefix"] = "OpenSG/";
        else:
            self["HeaderPrefix"] = "";
        
        if self.getFCD("description").strip() == "":
            self["Description"]     = "";
            self["SafeDescription"] = "\"\"";
        else:
            self["Description"]     = self._formatString    (self.getFCD("description"), 4)
            self["SafeDescription"] = self._formatSafeString(self.getFCD("description"), 4)
        
        self["hasPrivateFields"]   = False;
        self["hasProtectedFields"] = False;
        self["hasPublicFields"]    = False;
        self["hasPtrFields"]       = False;
        
        self["Fields"]  = [];
        self["SFields"] = [];
        self["MFields"] = [];
        
        for i, field in enumerate(self.m_fields):
            
            field.finalize();
            
            if i == 0:
                field["prevField"]    = None;
                field["isFirstField"] = True;
            else:
                field["prevField"]    = self.m_fields[i - 1];
                field["isFirstField"] = False;
            
            if i == len(self.m_fields) - 1:
                field["Separator"]   = "";
                field["nextField"]   = None;
                field["isLastField"] = True;
            else:
                field["Separator"]   = ",";
                field["nextField"]   = self.m_fields[i + 1];
                field["isLastField"] = False;
            
            self["Fields"].append(field);
            
            if field.isPrivate():
                self["hasPrivateFields"] = True;
                
            if field.isProtected():
                self["hasProtectedFields"] = True;
            
            if field.isPublic():
                self["hasPublicFields"] = True;
            
            if field.isPtrField():
                self["hasPtrFields"] = True;
            
            if field.isSField():
                self["SFields"].append(field);
            
            if field.isMField():
                self["MFields"].append(field);
        
        self["PointerField"]   = False;
        self["SFPointerField"] = False;
        self["MFPointerField"] = False;
        
        if self.getFCD("pointerfieldtypes") == "both":
            self["PointerField"]   = True;
            self["SFPointerField"] = True;
            self["MFPointerField"] = True;
        elif self.getFCD("pointerfieldtypes") == "single":
            self["PointerField"]   = True;
            self["SFPointerField"] = True;
        elif self.getFCD("pointerfieldtypes") == "multi":
            self["PointerField"]   = True;
            self["MFPointerField"] = True;
        
        self["MethodType"]  = "";
        
        if self.getFCD("decoratable") == "true":
            self["MethodType"] = "virtual";
        
        if self.getFCD("group") != "":
            self["Group"] = self.getFCD("group");
        else:
            self["Group"] = "NULL";
        
        if self.getFCD("namespace") != "":
            self["Namespace"] = self.getFCD("namespace");
        else:
            self["Namespace"] = "0";
        
        decorateeFieldFlags = self.getFCD("decorateeFieldFlags");
        if decorateeFieldFlags == "":
            self["DecorateeFieldFlags"] = "Field::SFDefaultFlags";
        else:
            dffList  = decorateeFieldFlags.split(",");
            numFlags = len(dffList);
            decorateeFieldFlags = "(";
            
            for i, flag in enumerate(dffList):
                flag = flag.strip();
                
                if (i == 0) and (i != numFlags - 1):
                    decorateeFieldFlags = decorateeFieldFlags + "Field::" + flag + " |";
                    continue;
                
                if i == numFlags - 1:
                    if i == 0:
                        decorateeFieldFlags = decorateeFieldFlags + "Field::" + flag;
                    else:
                        decorateeFieldFlags = decorateeFieldFlags + " Field::" + flag;
                    continue;
                
                decorateeFieldFlags = decorateeFieldFlags + " Field::" + flag + " |";
            decorateeFieldFlags = decorateeFieldFlags + ")";
            self["DecorateeFieldFlags"] = decorateeFieldFlags;
        
        includesList = self.getFCD("additionalIncludes").split(",");
        self["AdditionalIncludes"] = [];
        for include in includesList:
            include = include.strip();
            if include != "":
                self["AdditionalIncludes"].append(include);
    
    def setFCDContents(self, fcdContents):
        self.setFCD("fcdFileLines", fcdContents);
        if fcdContents == []:
            self["Fcdxml"] = "\"\"";
        else:
            self["Fcdxml"] = self._formatXML(fcdContents, 4);
    
    def _dumpValues(self):
        self.m_log.info("FieldContainer dumpValues:");
        super(FieldContainer, self)._dumpValues(self.m_log);
        
        for field in self.m_fields:
            field._dumpValues();
    
