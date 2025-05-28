set(TARGET_NAME GPIO)

add_library(${TARGET_NAME} STATIC
    src/gpio.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include/arduino-hal/gpio>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
)

install(
    DIRECTORY inc/
    DESTINATION include/arduino-hal/gpio
)

install(
    TARGETS ${TARGET_NAME}
    EXPORT arduino-hal-targets
    ARCHIVE DESTINATION lib/arduino-hal
)