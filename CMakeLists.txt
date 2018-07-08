project( DX11Collections )
cmake_minimum_required( VERSION 2.8 )

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

# include directories
include_directories("common")

# source files
set(srcs Source/TestSample.h
         Source/main.cpp	 
		 Common/Sample.h
         Common/Sample.cpp 
         Common/Application.h
		 Common/Application.cpp)	
	 	 
add_executable(DX11Collections WIN32 ${srcs})



