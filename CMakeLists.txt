cmake_minimum_required (VERSION 3.23)

project (oop1_project)
set (MY_AUTHORS "Odelia_Shemesh-Hadas_Maimon")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME} WIN32)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

include (cmake/Zip.cmake)

set (SFML_LOCATION "C:/SFML/SFML-2.5.1")
set (SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS graphics audio REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (${CMAKE_PROJECT_NAME} sfml-graphics sfml-audio sfml-main)

include (cmake/SFML.cmake)

configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)
