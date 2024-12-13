cmake_minimum_required(VERSION 3.16)

set(APPLICATION_NAME "GrpcUi")

project(${APPLICATION_NAME} LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Protobuf
    ProtobufQuick
    Grpc
    GrpcQuick
    GrpcTools
    Quick
)

qt_standard_project_setup()

add_subdirectory(grpc_server)

file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE PROTO_FILES "proto/*.proto")

qt_add_executable(${APPLICATION_NAME}
    main.cpp 
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
)

qt_add_protobuf(${APPLICATION_NAME}_plugin
PROTO_FILES ${PROTO_FILES}
    QML
)

qt_add_grpc(${APPLICATION_NAME}_plugin CLIENT
    PROTO_FILES ${PROTO_FILES}
    QML
)

set_target_properties(${APPLICATION_NAME} PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# Subfolders must be grouped seperately
file(GLOB PROJECT_QMLS RELATIVE ${CMAKE_SOURCE_DIR} qml/*.qml)
source_group("Qml Files" FILES ${PROJECT_QMLS})

qt_add_qml_module(${APPLICATION_NAME}
    URI ${APPLICATION_NAME}
    QML_FILES ${PROJECT_QMLS}
)

target_link_libraries(${APPLICATION_NAME} PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Protobuf
    Qt6::Grpc
    Qt6::GrpcQuick
    ${APPLICATION_NAME}_plugin
)