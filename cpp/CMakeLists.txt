cmake_minimum_required(VERSION 3.2)
project(mathlibraJ)
include(ExternalProject)
link_directories(${CMAKE_CURRENT_BINARY_DIR}/lib/)
        SET(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}" CACHE PATH "Install prefix" FORCE)

include_directories( "$(JAVA_HOME)/include" "$(JAVA_HOME)/include/linux")
include_directories("./" "../mathlibra_include/"  "/usr/lib/jvm/java-8-openjdk-amd64/include/linux" "/usr/lib/jvm/java-8-openjdk-amd64/include" )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set_property(DIRECTORY PROPERTY EP_BASE ${CMAKE_CURRENT_BINARY_DIR}/mathlibra)
ExternalProject_Add(mathlibra
  GIT_REPOSITORY git@github.com:VirtualRaven/mathlibra.git

        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}
            -DCMAKE_BUILD_TYPE:STRING=Release
  GIT_TAG new_typesystem
  UPDATE_COMMAND ""

)


set(SOURCE_FILES    NativeType.cpp
                    mathlibra_Mathlibra.h
                    mathlibra_NativeType.h
                    Mathlibra.cpp
                    NativeComponents.cpp )

ExternalProject_Get_Property(mathlibra install_dir)
add_library(mathlibraJ SHARED ${SOURCE_FILES})
add_dependencies(mathlibraJ mathlibra)
target_link_libraries(mathlibraJ mathlibra_CXX)
install(TARGETS mathlibraJ LIBRARY DESTINATION lib)
