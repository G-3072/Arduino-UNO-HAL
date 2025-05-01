set(TARGET_NAME arduino-uno-hal)

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

add_subdirectory(ADC)
add_subdirectory(GPIO)
add_subdirectory(interrupt)
add_subdirectory(timer)
add_subdirectory(UART)
add_subdirectory(util)

target_link_libraries(${TARGET_NAME} INTERFACE
    ADC
    GPIO
    INTERRUPT
    TIMER
    UART
    UTIL
)

install(TARGETS arduino-uno-hal ADC GPIO INTERRUPT TIMER UART UTIL EXPORT arduino-uno-hal-targets)
install(EXPORT arduino-uno-hal-targets
        FILE arduino-hal-Targets.cmake
        NAMESPACE arduino::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/arduino-uno-hal        
)