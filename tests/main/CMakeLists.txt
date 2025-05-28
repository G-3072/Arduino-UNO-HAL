set(TARGET_NAME arduino-hal-testing)

add_executable(${TARGET_NAME} src/main.c)

target_link_libraries(${TARGET_NAME} PRIVATE
    arduino-hal-tests
    arduino-hal
)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND avr-objcopy -O ihex $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.hex
    COMMENT "Generating HEX file"
)