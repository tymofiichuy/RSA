cmake_minimum_required(VERSION 3.10)
project(RSA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/RSA/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/RSA/main)

set(SOURCES
    ${SOURCE_DIR}/bbs_generator.cpp
    ${SOURCE_DIR}/primality_test.cpp
    ${SOURCE_DIR}/RSA_keygen.cpp
    ${SOURCE_DIR}/RSA_encryption.cpp
    ${SOURCE_DIR}/RSA_signature.cpp
)

find_package(cryptopp CONFIG REQUIRED)

add_library(RSA STATIC ${SOURCES})
add_executable(RSA_enc ${MAIN_DIR}/driver.cpp ${SOURCES})

target_include_directories(RSA PUBLIC ${SOURCE_DIR})
target_link_libraries(RSA PUBLIC cryptopp::cryptopp)

target_link_libraries(RSA_enc PRIVATE RSA)