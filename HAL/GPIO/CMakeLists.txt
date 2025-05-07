set(TARGET_NAME GPIO)

add_library(${TARGET_NAME} STATIC
    src/gpio_base.c
    src/gpio_interrupts.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
)