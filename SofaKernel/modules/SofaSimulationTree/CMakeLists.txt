cmake_minimum_required(VERSION 3.12)
project(SofaSimulationTree)

set(HEADER_FILES
    config.h.in
    ExportDotVisitor.h
    GNode.h
    GNodeMultiMappingElement.h
    GNodeVisitor.h
    TreeSimulation.h
    init.h
)

set(SOURCE_FILES
    ExportDotVisitor.cpp
    GNode.cpp
    GNodeMultiMappingElement.cpp
    GNodeVisitor.cpp
    TreeSimulation.cpp
    init.cpp
)


add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC SofaSimulationCommon)

sofa_install_targets(SofaSimulation ${PROJECT_NAME} "SofaSimulation/${PROJECT_NAME}")
