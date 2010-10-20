IF( COMMAND CMAKE_MINIMUM_REQUIRED )
        CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENDIF( COMMAND CMAKE_MINIMUM_REQUIRED )

####################################################################################
# The name of the project
####################################################################################
PROJECT(Pluxx)

####################################################################################
# Target OS specific flags.
####################################################################################
IF(APPLE)
    # Flags for universal build.
    SET(CMAKE_OSX_ARCHITECTURES ppc;i386)

    # Determine the SDK the source has to build for.
    SET(OSX_SDK 10.5)

    SET(CMAKE_OSX_SYSROOT "/Developer/SDKs/MacOSX${OSX_SDK}.sdk")
ENDIF (APPLE)

####################################################################################
# Make sure the compiler can find include files from our project.
####################################################################################
INCLUDE_DIRECTORIES (${PROJECT_SOURCE_DIR}/include) 

####################################################################################
# The executeable(s) to build to.
####################################################################################
ADD_LIBRARY(pluxx STATIC
    src/PluginExceptions.cpp
    src/PluginLoader.cpp
    src/stringUtil.h

    include//pluxx/Plugin.h
    include//pluxx/PluginExceptions.h
    include//pluxx/PluginLoader.h

)

#TARGET_LINK_LIBRARIES(pluxx pthread)

####################################################################################
# Target specific flags.
####################################################################################
IF(APPLE)
    SET_TARGET_PROPERTIES(pluxx PROPERTIES LINK_FLAGS -mmacosx-version-min=${OSX_SDK})
ENDIF(APPLE)

####################################################################################
# Additional Directories to deal with...
####################################################################################
# ADD_SUBDIRECTORY(lib)

# INSTALL(TARGETS projectExe DESTINATION /usr/bin)
