set(TARGET_NAME UART)

add_library(${TARGET_NAME} STATIC
    src/uart_base.c
    src/uart_advanced.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${TARGET_NAME} PUBLIC
    UTIL
)