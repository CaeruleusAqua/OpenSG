import copy

class LibraryInfo(object):
   """ Helper class for capturing all the files that we are finding in source tree. """
   def __init__(self, name=""):
      self.name = name
      self.source_files = []         # List of source files for this library
      self.header_files = []         # List of header files for this library
      self.test_files = []           # list of source files for tests
      self.osg_dep_libs = []         # Names of OpenSG libraries we depend on
      self.libs = []                 # Names of other libraries we depend on
      self.libpath = []              # Paths to dependent libs
      self.cpppath = []              # List of extra paths we need to compile
      self.osg_test_libs = []        # Names of OSG libraries the tests depend on
      self.other_test_libs = []      # Names of non-OSG libraries the tests depend on
      self.test_cpppath = []         # Includedirs of libraries the tests depend on
      self.test_libpath = []         # Libpaths of libraries the tests depend on
      self.unittest_files = []       # list of source files for unit tests

   def dump(self):
      """ Dump contained date to a dictionary that could be pprinted. """
      ret_dict = {}
      for i in self.__dict__.keys():
         if i not in ["source_files","header_files","test_files"]:
            ret_dict[i] = self.__dict__[i]               
      return ret_dict

   def load(self, dumpDict):
      """ Load status from a dumped dictionary."""
      for i in self.__dict__.keys():
         if dumpDict.has_key(i):
            self.__dict__[i] = dumpDict[i]
            
   def merge(self, other):
      """ Merge our library information with another library info object. """
      # Merge the lists but only merge in new unique entries
      for a in ["source_files","header_files","test_files","osg_dep_libs",
                "libs","libpath","cpppath",
                "osg_test_libs","other_test_libs","test_cpppath","test_libpath","unittest_files"]:
         getattr(self,a).extend([i for i in getattr(other,a) if not i in getattr(self,a)])
 

   def getLibDepList(self, knownList, libMap):
      """ Get full list of dependent libraries base on libMap and existing known list. """
      dep_list = []
      dep_list.extend([l for l in self.osg_dep_libs if not l in knownList])
      for l in dep_list[:]:
         if libMap.has_key(l):
            dep_list.extend(libMap[l].getLibDepList(dep_list, libMap))
      return dep_list
   
   def createMergedDepLibrary(self, libMap):
      """ Return a new library object with all of the options
          merged for the dependencies of this library.
          This is used to combine all the options for a library and
          it's dependencies into a single object
      """      
      dep_list = [self.name] + self.getLibDepList([], libMap)
      #print "Deps for lib: %s  are: %s"%(self.name, dep_list)   
      
      dep_lib_list = [libMap[l] for l in dep_list]   
      merged_lib = LibraryInfo()
      merged_lib.libs = dep_list[:]               # Add on the OSG libraries      
      
      for lib in dep_lib_list:
         merged_lib.merge(lib)         
         
      return merged_lib

class ConfigInfoAdapter(object):
   """ Class to adapt a LibraryInfo object into something that returns config info
       type data.  (flags, paths, etc)
       
       libs: List or single library. (string name of class)
       libMap: Map from string library name to library object.
   """
   def __init__(self, libs, libMap, defaultMergedLib=None,
                incprefix="-I", libprefix="-l", libpathprefix="-L"):
      
      libraries = copy.copy(libs)    # Make a copy so we don't modify the original
      
      # Make sure we have a list of library objects
      if not type(libraries) == list:
         libraries = [libraries]
      for i in range(len(libraries)):
         if type(libraries[i]) == str:
            libraries[i] = libMap[libraries[i]]
      
      self.merged_lib = LibraryInfo()
      if defaultMergedLib:
         self.merged_lib = copy.copy(defaultMergedLib)   
   
      for lib in libraries:
         if not self.merged_lib:
            self.merged_lib = lib.createMergedDepLibrary(libMap)                              
         else:            
            self.merged_lib.merge(lib.createMergedDepLibrary(libMap))
      
      self.incprefix = incprefix
      self.libprefix = libprefix
      self.libpathprefix = libpathprefix

   def getIncPath(self):
      return self.merged_lib.cpppath
   def getIncPathStr(self):
      return " ".join(["%s%s"%(self.incprefix,p) for p in self.merged_lib.cpppath])
   def getLibs(self):
      return self.merged_lib.libs
   def getLibsStr(self):
      return " ".join(["%s%s"%(self.libprefix,l) for l in self.merged_lib.libs])
   def getLibPath(self):
      return self.merged_lib.libpath
   def getLibPathStr(self):
      return " ".join(["%s%s"%(self.libpathprefix,p) for p in self.merged_lib.libpath])
 

