set(TARGET_NAME TIMER)

add_library(${TARGET_NAME} STATIC
    src/timer_base.c
    src/timer_outputCompare.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
)