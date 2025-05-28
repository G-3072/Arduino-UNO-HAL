set(TARGET_NAME arduino-hal-tests)

add_library(${TARGET_NAME} INTERFACE)

add_subdirectory(gpio)
add_subdirectory(interrupt)
add_subdirectory(timer)
add_subdirectory(uart)
add_subdirectory(main)


target_link_libraries(${TARGET_NAME} INTERFACE
    GPIO_TEST
    INTERRUPT_TEST
    TIMER_TEST
    UART_TEST
)

install(
    EXPORT arduino-hal-targets
    NAMESPACE arduino-hal::
    FILE arduino-hal-config.cmake
    DESTINATION lib/cmake/arduino-hal
)