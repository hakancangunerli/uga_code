cmake_minimum_required(VERSION 3.20)
project(assignment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment2
        empty.txt
        input.txt
        ItemType.cpp
        ItemType.h
        ListNode.h
        main.cpp
        SortedLinkedList.cpp
        SortedLinkedList.h)
