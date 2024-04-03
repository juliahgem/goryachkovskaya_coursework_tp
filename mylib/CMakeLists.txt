add_library(lib lib.cpp include/lib/lib.h)
set_property(TARGET lib PROPERTY CXX_STANDARD 14)
target_include_directories(lib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS lib)
