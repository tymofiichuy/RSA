cmake_minimum_required(VERSION 3.10)
project(RSA_encryption)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/RSA_encryption/src)
set(MAIN_DIR ${CMAKE_SOURCE_DIR}/RSA_encryption/main)

set(SOURCES

)

find_package(CryptoPP CONFIG REQUIRED)

add_executable(RSA_enc ${MAIN_DIR}/driver.cpp ${SOURCES})

target_include_directories(RSA_enc PUBLIC ${SOURCE_DIR})

target_link_libraries(RSA_enc PUBLIC CryptoPP)