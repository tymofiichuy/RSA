cmake_minimum_required(VERSION 3.10)
project(client_model)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/client_model/src)
# set(RSA_DIR ${CMAKE_SOURCE_DIR}/RSA/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/client_model/main)

set(SOURCES
    # ${RSA_DIR}/bbs_generator.cpp
    # ${RSA_DIR}/primality_test.cpp
    # ${RSA_DIR}/RSA_keygen.cpp
    # ${RSA_DIR}/RSA_encryption.cpp
    # ${RSA_DIR}/RSA_signature.cpp
)

add_executable(client_model ${MAIN_DIR}/main.cpp ${SOURCES})

target_link_libraries(client_model PRIVATE RSA)
target_include_directories(client_model PRIVATE ${SOURCE_DIR})