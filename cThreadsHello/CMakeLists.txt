cmake_minimum_required(VERSION 2.8.9)
project (TestLibrary)
 
#For the shared library:
#set ( PROJECT_LINK_LIBS libtestStudent.so )
#link_directories( ~/exploringBB/extras/cmake/studentlib_shared/build )
 
#For the static library:
#set ( PROJECT_LINK_LIBS libtestStudent.a )
#link_directories( ~/exploringBB/extras/cmake/studentlib_static/build )
 
#include_directories(~/exploringBB/extras/cmake/studentlib_shared/include)
 
add_executable(thread thread.c)
target_link_libraries(thread pthread)
#target_link_libraries(server ${PROJECT_LINK_LIBS})
