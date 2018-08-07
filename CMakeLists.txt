project( DXCollections )
cmake_minimum_required( VERSION 2.8 )

# Test branch


include( CheckCXXCompilerFlag )
check_cxx_compiler_flag( "-std=c++11"   COMPILER_SUPPORTS_CXX11 )
check_cxx_compiler_flag( "-std=c++0x"   COMPILER_SUPPORTS_CXX0X )
if( COMPILER_SUPPORTS_CXX11 )
    if( CMAKE_COMPILER_IS_GNUCXX )
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11" )
    else()
        set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
    endif()
elseif( COMPILER_SUPPORTS_CXX0X)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )
else()
    # MSVC, On by default (if available)
endif()

# use unicode in projects		
add_definitions(-DUNICODE -D_UNICODE)

set(thirdPartyPath "${CMAKE_SOURCE_DIR}/ThirdParty")

# include directories
include_directories("common")
include_directories("ThirdParty/fbxsdk/include")
include_directories("$ENV{DXSDK_DIR}Include")

# source files
set(srcs Source/TestDemo.h
         Source/TestDemo.cpp
         Source/main.cpp 
		 Common/Demo.h
         Common/Demo.cpp
         Common/FBXHelper.h
         Common/FBXHelper.cpp
         Common/Shader.h
         Common/Shader.cpp
         Common/Sphere.h
         Common/Sphere.cpp		 
         Common/Application.h
		 Common/Application.cpp
		 Common/Globals.h
		 Common/Meshes.h		 
		 Common/Meshes.cpp
		 )	
	 	 
# add referenced library		 
set(libs d3d11
         d3dx11
		 libfbxsdk)

if(CMAKE_SIZEOF_VOID_P)
    set(platform x64)
else(CMAKE_SIZEOF_VOID_P)
    set(platform x86)
endif(CMAKE_SIZEOF_VOID_P)	 

link_directories("$ENV{DXSDK_DIR}Lib/${platform}/")
link_directories("${thirdPartyPath}/fbxsdk/lib/vs2015/${platform}/")

add_executable(DXCollections "${srcs}")
target_link_libraries(DXCollections "${libs}")

# working directories
set_target_properties(DXCollections PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/Assets")
set_target_properties(DXCollections PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")




