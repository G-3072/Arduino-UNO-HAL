set(TARGET_NAME GPIO_TEST)

add_library(${TARGET_NAME} STATIC
    src/gpio_test.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    GPIO
    UTIL
)