cmake_minimum_required(VERSION 3.16.3)

project(FSM)

set(FSM_SOURCES 
	${CMAKE_CURRENT_LIST_DIR}/main.cpp )

set(FSM_INCLUDES 
    ${CMAKE_CURRENT_LIST_DIR}/../)

add_executable ( FSM ${FSM_SOURCES})
target_include_directories(FSM PRIVATE ${FSM_INCLUDES})