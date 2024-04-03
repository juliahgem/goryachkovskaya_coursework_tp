cmake_minimum_required(VERSION 3.17)
project(coursework)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

set(CMAKE_CXX_STANDARD 14)

find_package(Doxygen REQUIRED)

add_subdirectory(mylib)

add_executable(test_coursework main.cpp)
target_link_libraries(test_coursework lib)

install(TARGETS test_coursework RUNTIME
  DESTINATION bin
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/test_files/
  DESTINATION test_files
)

if(DOXYGEN_FOUND)
       set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/mylib/Doxyfile)
       set(DOXYGEN_CONFIGURED_INPUT ${DOXYGEN_IN})

       add_custom_target(doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_CONFIGURED_INPUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
       )

endif()

if(DOXYGEN_FOUND)
       install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxygen_docs/rtf
               DESTINATION docs)
   endif()