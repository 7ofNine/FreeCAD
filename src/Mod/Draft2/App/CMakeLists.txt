# set project name. Temporary to be able to easily change it
# SET(GUT_DRAFT_APP "Draft2")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# define source files
set(Draft2_SOURCES    
    empty.cpp
)
SOURCE_GROUP("Application" FILES ${Draft2_SOURCES})

set(Draft2_HEADERS
    empty.h
    )
SOURCE_GROUP("Headers" FILES ${Draft2_HEADERS})    
 
set(Draft2_INIT init.py)
set(Draft2_SCRIPTS
    ../${Draft2_init})
SOURCE_GROUP("Scripts" FILES ${Draft2_SCRIPTS})

## define needed libraries
set(Draft2_LIBS
    FreeCADApp    
)


# define the project
add_library(Draft2 SHARED ${Draft2_SOURCES})
target_link_libraries(Draft2 ${Draft2_LIBS})
target_sources(Draft2  PRIVATE ${Draft2_HEADERS} PRIVATE ${Draft2_SCRIPTS}) 

fc_target_copy_resource(Draft2 ${CMAKE_SOURCE_DIR}/src/Mod/Draft2 ${CMAKE_BINARY_DIR}/Mod/Draft2 ${Draft2_INIT})

# set up the target directory for the binaries (dll)
SET_BIN_DIR(Draft2 Draft2 /Mod/Draft2)