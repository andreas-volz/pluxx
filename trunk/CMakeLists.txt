IF( COMMAND CMAKE_MINIMUM_REQUIRED )
        CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENDIF( COMMAND CMAKE_MINIMUM_REQUIRED )

####################################################################################
# The name of the project
####################################################################################
PROJECT(Pluxx)

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
# Additional Directories to deal with...
####################################################################################
# ADD_SUBDIRECTORY(lib)

# INSTALL(TARGETS projectExe DESTINATION /usr/bin)
