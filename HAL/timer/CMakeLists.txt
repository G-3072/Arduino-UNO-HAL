set(TARGET_NAME TIMER)

add_library(${TARGET_NAME} STATIC
    src/timer.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include/arduino-hal/timer>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
)

install(
    DIRECTORY inc/
    DESTINATION include/arduino-hal/timer
)

install(
    TARGETS ${TARGET_NAME}
    EXPORT arduino-hal-targets
    ARCHIVE DESTINATION lib/arduino-hal
)