set(TARGET_NAME arduino-hal)

add_library(${TARGET_NAME} INTERFACE)

add_subdirectory(GPIO)
add_subdirectory(interrupt)
add_subdirectory(timer)
add_subdirectory(UART)
add_subdirectory(util)

target_link_libraries(${TARGET_NAME} INTERFACE
    GPIO
    INTERRUPT
    TIMER
    UART
    UTIL
)

install(
    EXPORT arduino-hal-targets
    NAMESPACE arduino-hal::
    FILE arduino-hal-config.cmake
    DESTINATION lib/cmake/arduino-hal
)