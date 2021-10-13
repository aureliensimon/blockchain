cmake_minimum_required(VERSION 3.20)
project(blockchain)

set(CMAKE_CXX_STANDARD 11)

add_executable(blockchain main.cpp headers/Block.h headers/Blockchain.h lib/sha256.h lib/sha256.cpp src/Block.cpp src/Blockchain.cpp headers/Transaction.h src/Transaction.cpp)
