set(TARGET_NAME INTERRUPT)

add_library(${TARGET_NAME} STATIC
    src/interrupt.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include/arduino-hal/interrupt>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
    GPIO
)

install(
    DIRECTORY inc/
    DESTINATION include/arduino-hal/interrupt
)

install(
    TARGETS ${TARGET_NAME}
    EXPORT arduino-hal-targets
    ARCHIVE DESTINATION lib/arduino-hal
)