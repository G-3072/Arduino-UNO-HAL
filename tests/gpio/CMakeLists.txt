set(TARGET_NAME GPIO_TEST)

add_library(${TARGET_NAME} STATIC
    src/test_gpio.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/inc
)

target_link_libraries(${TARGET_NAME} PUBLIC
    GPIO
)
