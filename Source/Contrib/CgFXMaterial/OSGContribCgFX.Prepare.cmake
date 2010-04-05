MESSAGE(STATUS "Prepare OSGContribCgFX")

GET_FILENAME_COMPONENT(_CMAKE_CURRENT_LIST_DIR ${CMAKE_CURRENT_LIST_FILE} PATH)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${_CMAKE_CURRENT_LIST_DIR}/CMake")

INCLUDE(ConfigurePackages.OSGContribCgFX)


IF(NOT OSG_BUILD_DEPENDEND)
  OSG_CONFIGURE_CG()
ENDIF(NOT OSG_BUILD_DEPENDEND)

LIST(APPEND OSG_ADDITIONAL_CONFIGURE_LINES "#cmakedefine OSG_WITH_CG 1")

MESSAGE(STATUS "Cg Status: Cg: ${OSG_WITH_CG}")

INSTALL(FILES "${_CMAKE_CURRENT_LIST_DIR}/CMake/FindCg.cmake"
        DESTINATION share/OpenSG/cmake)

INSTALL(FILES "${_CMAKE_CURRENT_LIST_DIR}/CMake/ConfigurePackages.OSGContribCCgFX.cmake"
        DESTINATION share/OpenSG/cmake)

