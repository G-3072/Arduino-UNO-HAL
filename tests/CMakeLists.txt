set(TARGET_NAME HAL-TEST)

add_library(${TARGET_NAME} INTERFACE)

target_compile_options(${TARGET_NAME} INTERFACE
    "-mmcu=${MCU}"
    "-Os"
    "-DF_CPU=${F_CPU}"
    "-ffunction-sections"
    "-fdata-sections"
)

target_link_options(${TARGET_NAME} INTERFACE
    "-Wl,--gc-sections"
)

add_subdirectory(GPIO)
add_subdirectory(interrupt)
add_subdirectory(timer)
add_subdirectory(UART)

target_link_libraries(${TARGET_NAME} INTERFACE
    GPIO_TEST
    INTERRUPT_TEST
    TIMER_TEST
    UART_TEST
)