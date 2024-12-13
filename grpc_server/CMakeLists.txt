cmake_minimum_required(VERSION 3.16)

set(BASE_NAME "DoctorConsole")
set(SERVER_NAME "${BASE_NAME}Server")
set(GRPC_LIBRARY "${BASE_NAME}Grpc")
set(SERVER_APP "${SERVER_NAME}App")

project(${SERVER_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6::Grpc module is not used directly in this project. But this allows to find Qt6::Grpc's
# dependencies without setting extra cmake module paths.
find_package(Qt6 COMPONENTS Grpc)
find_package(WrapgRPCPlugin)
find_package(WrapgRPC)

if(MINGW)
    message(WARNING "${PROJECT_NAME} uses reference grpc++ library that doesn't officially support"
        " MinGW. Please use the MSVC compiler to build this example. The correct work is not"
        " guaranteed otherwise.")
endif()

set(proto_files "${CMAKE_CURRENT_LIST_DIR}/../proto/DoctorConsoleService.proto")
set(out_dir ${CMAKE_CURRENT_SOURCE_DIR})

set(generated_files
    "${out_dir}/DoctorConsoleService.pb.h" "${out_dir}/DoctorConsoleService.pb.cc"
    "${out_dir}/DoctorConsoleService.grpc.pb.h" "${out_dir}/DoctorConsoleService.grpc.pb.cc")

add_custom_command(
    OUTPUT ${generated_files}
    COMMAND
    $<TARGET_FILE:WrapProtoc::WrapProtoc>
    ARGS
    --grpc_out "${out_dir}"
    --cpp_out "${out_dir}"
    -I "${CMAKE_CURRENT_LIST_DIR}/../proto/"
    --plugin=protoc-gen-grpc=$<TARGET_FILE:WrapgRPC::WrapgRPCPlugin>
    "${proto_files}"
    WORKING_DIRECTORY ${out_dir}
    DEPENDS "${proto_files}"
    COMMENT "Generating gRPC ${target} sources..."
    COMMAND_EXPAND_LISTS
    VERBATIM
)

set_source_files_properties(${generated_files} PROPERTIES GENERATED TRUE)
add_library(${GRPC_LIBRARY} STATIC ${generated_files})
target_include_directories(${GRPC_LIBRARY}
    PRIVATE
    ${out_dir}
)

target_link_libraries(${GRPC_LIBRARY}
    PRIVATE
    WrapgRPC::WrapLibgRPC
)

file(GLOB_RECURSE PROJECT_SOURCES "*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "*.hpp")

add_library(${SERVER_NAME}
    STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS}
)

target_include_directories(${SERVER_NAME} PRIVATE ${out_dir})

target_link_libraries(${SERVER_NAME}
    PRIVATE
    ${GRPC_LIBRARY}
    WrapgRPC::WrapLibgRPC
    Qt6::Core
)

qt_add_executable(${SERVER_APP}
    main.cpp
)

target_link_libraries(${SERVER_APP} PRIVATE
    Qt6::Core
    ${SERVER_NAME}
)