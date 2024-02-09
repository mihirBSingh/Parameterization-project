
add_executable( project4_exe EXCLUDE_FROM_ALL main.cpp )
target_link_libraries( project4_exe flux_shared )

target_compile_definitions( project4_exe PUBLIC -DFLUX_FULL_UNIT_TEST=false )

add_custom_target( project4 command $<TARGET_FILE:project4_exe> 1 WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/projects/project4 )

ADD_DEBUG_TARGETS( project4 ${CMAKE_SOURCE_DIR}/projects/project4/ )
