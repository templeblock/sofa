cmake_minimum_required(VERSION 3.12)
project(VolumetricRendering VERSION 0.1)

find_package(SofaFramework REQUIRED)
find_package(SofaBase REQUIRED)
find_package(SofaGeneral REQUIRED)
find_package(SofaOpenglVisual REQUIRED)

set(HEADER_FILES
    src/VolumetricRendering/config.h.in
    src/VolumetricRendering/OglTetrahedralModel.h
    src/VolumetricRendering/OglTetrahedralModel.inl
    src/VolumetricRendering/OglVolumetricModel.h
)

set(SOURCE_FILES
    src/VolumetricRendering/initVolumetricRendering.cpp
    src/VolumetricRendering/OglTetrahedralModel.cpp
    src/VolumetricRendering/OglVolumetricModel.cpp
)

add_library(${PROJECT_NAME} SHARED  ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} SofaHelper SofaOpenglVisual )

# Add the include DIR from OpenHaptics to target
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${OPENHAPTICS_INCLUDE_DIR}>")

# Install rules for the library and the headers; CMake package configurations files
sofa_generate_package(
    NAME ${PROJECT_NAME}
    TARGETS ${PROJECT_NAME}
    VERSION ${PROJECT_VERSION}
    INCLUDE_SOURCE_DIR "src"
    INCLUDE_INSTALL_DIR "VolumetricRendering"
    RELOCATABLE "plugins"
    )