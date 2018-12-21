cmake_minimum_required(VERSION 2.8.8)
project(cmake-vc-bug)

if(MSVC)
	set(CompilerFlags CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
	foreach(CompilerFlag ${CompilerFlags})
	  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()

	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_subdirectory(tests)

