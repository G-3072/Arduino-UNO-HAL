set(TARGET_NAME arduino-hal)

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
add_subdirectory(util)

target_link_libraries(${TARGET_NAME} INTERFACE
    GPIO
    INTERRUPT
    TIMER
    UART
    UTIL
)

install(TARGETS arduino-hal GPIO INTERRUPT TIMER UART UTIL EXPORT arduino-uno-hal-targets)
install(EXPORT arduino-uno-hal-targets
        FILE arduino-hal-Targets.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/arduino-hal        
)