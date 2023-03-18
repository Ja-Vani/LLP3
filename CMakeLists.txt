cmake_minimum_required(VERSION 3.16)
project(LLP3 C)

set(CMAKE_C_STANDARD 11)

find_package(json-c CONFIG)

set(SRC_DIR "./Lab2")
set(PARSER_DIR "${CMAKE_CURRENT_BINARY_DIR}")

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 2.3 REQUIRED)

set(LEXER_OUT "${PARSER_DIR}/lexer.c")
set(PARSER_OUT "${PARSER_DIR}/parser.c")

flex_target(LEXER "${SRC_DIR}/lex.l" "${LEXER_OUT}" DEFINES_FILE "${PARSER_DIR}/lexer.h")
bison_target(PARSER "${SRC_DIR}/bison.y" "${PARSER_OUT}" DEFINES_FILE "${PARSER_DIR}/parser.h" COMPILE_FLAGS "-d -v")
add_flex_bison_dependency(LEXER PARSER)

file(GLOB source_files
        ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/*.c
        )

add_executable(CLIENT client.c "${source_files}" "${LEXER_OUT}" "${PARSER_OUT}" "Lab2/request_tree.h" "Lab2/request_tree.c" "Lab2/array_list.c" "Lab2/array_list.h" json_tree.c json_tree.h)
target_include_directories(CLIENT PRIVATE ${PARSER_DIR} ${SRC_DIR})



add_executable(SERVER server.c json_execute.c Lab1/data.c Lab1/database.c Lab1/idata.c)


target_link_libraries(CLIENT PRIVATE json-c m)
target_link_libraries(SERVER PRIVATE json-c)