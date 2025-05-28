set(TARGET_NAME UTIL)

add_library(${TARGET_NAME} STATIC
    src/util.c
)

target_include_directories(${TARGET_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:include/arduino-hal/util>
)

target_link_libraries(${TARGET_NAME} PUBLIC

)

install(
    DIRECTORY inc/
    DESTINATION include/arduino-hal/util
)

install(
    TARGETS ${TARGET_NAME}
    EXPORT arduino-hal-targets
    ARCHIVE DESTINATION lib/arduino-hal
)