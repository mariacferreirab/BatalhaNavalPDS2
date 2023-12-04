CC=g++
CFLAGS=-std=c++11 -Wall --coverage
TARGET=program
TARGET_TESTS=program_tests

BUILD_DIR    = ./build
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
TEST_DIR = ./tests
COVERAGE_DIR = ./coverage
THIRD_DIR = ./third_party

all: ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/Jogo.o ${BUILD_DIR}/Jogador.o ${BUILD_DIR}/Navio.o ${BUILD_DIR}/Tabuleiro.o ${BUILD_DIR}/Contratorpedeiro.o ${BUILD_DIR}/Cruzador.o ${BUILD_DIR}/Encouracado.o ${BUILD_DIR}/Submarino.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${TARGET} ${BUILD_DIR}/*.o

${BUILD_DIR}/Jogo.o: ${INCLUDE_DIR}/Jogo/Jogo.hpp ${SRC_DIR}/Jogo/Jogo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Jogo/ -I ${INCLUDE_DIR}/Tabuleiro/ -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Jogo/Jogo.cpp -o ${BUILD_DIR}/Jogo.o

${BUILD_DIR}/Jogador.o: ${INCLUDE_DIR}/Jogador/Jogador.hpp ${SRC_DIR}/Jogador/Jogador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Jogador/ -c ${SRC_DIR}/Jogador/Jogador.cpp -o ${BUILD_DIR}/Jogador.o

${BUILD_DIR}/Navio.o: ${INCLUDE_DIR}/Navio/Navio.hpp ${INCLUDE_DIR}/Navio/Navio.hpp ${SRC_DIR}/Navio/Navio.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Navio/Navio.cpp -o ${BUILD_DIR}/Navio.o
	
${BUILD_DIR}/Tabuleiro.o: ${INCLUDE_DIR}/Tabuleiro/Tabuleiro.hpp ${SRC_DIR}/Tabuleiro/Tabuleiro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Tabuleiro/ -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Tabuleiro/Tabuleiro.cpp -o ${BUILD_DIR}/Tabuleiro.o

${BUILD_DIR}/Cruzador.o: ${INCLUDE_DIR}/Navio/Cruzador.hpp  ${SRC_DIR}/Navio/Cruzador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Navio/Cruzador.cpp -o ${BUILD_DIR}/Cruzador.o

${BUILD_DIR}/Contratorpedeiro.o: ${INCLUDE_DIR}/Navio/Contratorpedeiro.hpp  ${SRC_DIR}/Navio/Contratorpedeiro.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Navio/Contratorpedeiro.cpp -o ${BUILD_DIR}/Contratorpedeiro.o

${BUILD_DIR}/Encouracado.o: ${INCLUDE_DIR}/Navio/Encouracado.hpp  ${SRC_DIR}/Navio/Encouracado.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Navio/Encouracado.cpp -o ${BUILD_DIR}/Encouracado.o

${BUILD_DIR}/Submarino.o: ${INCLUDE_DIR}/Navio/Submarino.hpp  ${SRC_DIR}/Navio/Submarino.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/Navio/Submarino.cpp -o ${BUILD_DIR}/Submarino.o
	
${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Tabuleiro/ -I ${INCLUDE_DIR}/Jogo/  -I ${INCLUDE_DIR}/Navio/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${TEST_DIR}/TesteNavio.o: ${TEST_DIR}/Navio/TesteNavio.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/Navio/ -c ${TEST_DIR}/Navio/TesteNavio.cpp -o ${TEST_DIR}/TesteNavio.o

${TEST_DIR}/TesteTabuleiro.o: ${TEST_DIR}/Tabuleiro/TesteTabuleiro.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/Navio/ -I ${INCLUDE_DIR}/Tabuleiro/ -c ${TEST_DIR}/Tabuleiro/TesteTabuleiro.cpp -o ${TEST_DIR}/TesteTabuleiro.o

${TEST_DIR}/main_testes.o: ${TEST_DIR}/main_testes.cpp
	${CC} ${CFLAGS} -I ${THIRD_DIR} -I ${INCLUDE_DIR}/Navio/ -I ${INCLUDE_DIR}/Tabuleiro/ -c ${TEST_DIR}/main_testes.cpp -o ${TEST_DIR}/main_testes.o

tests: all ${TEST_DIR}/TesteTabuleiro.o ${TEST_DIR}/TesteNavio.o ${TEST_DIR}/main_testes.o
	${CC} ${CFLAGS} -o ${TEST_DIR}/${TARGET_TESTS} ${BUILD_DIR}/Tabuleiro.o ${BUILD_DIR}/Navio.o ${BUILD_DIR}/Contratorpedeiro.o ${BUILD_DIR}/Encouracado.o ${BUILD_DIR}/Cruzador.o ${BUILD_DIR}/Submarino.o ${TEST_DIR}/*.o

run_tests: tests
	./${TEST_DIR}/${TARGET_TESTS}

run: all
	./${BUILD_DIR}/${TARGET}

coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h"
	gcovr -r . --exclude="third_party/doctest.h" -b	

html_coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h" --html --html-details -o ${COVERAGE_DIR}/relatorio.html

documentation:
	doxygen Doxyfile

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/*
	rm -f ${TEST_DIR}/*.o ${TEST_DIR}/*.gcda ${TEST_DIR}/*.gcno ${TEST_DIR}/${TARGET_TESTS}
	rm -f ${COVERAGE_DIR}/*
	rm -rf ./doc/*