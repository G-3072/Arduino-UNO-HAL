set(TARGET_NAME UART)

add_library(${TARGET_NAME} STATIC
    src/uart.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include/arduino-hal/uart>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
)

install(
    DIRECTORY inc/
    DESTINATION include/arduino-hal/uart
)

install(
    TARGETS ${TARGET_NAME}
    EXPORT arduino-hal-targets
    ARCHIVE DESTINATION lib/arduino-hal
)