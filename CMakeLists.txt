cmake_minimum_required(VERSION 3.27)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled2 main.cpp
        TrieNode.cpp
        TrieNode.h
        Trie.cpp
        Trie.h)
configure_file(dictionary.txt dictionary.txt COPYONLY)
configure_file(input.txt input.txt COPYONLY)
