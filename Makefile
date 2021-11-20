ROOT    := .
BIN     := bin
SRC     := src
INCLUDE := include
TESTS   := tests

CC             := gcc
CC_FLAGS       := -Wall -ansi -pedantic -ggdb -I${INCLUDE} -I${SRC} -lm
CC_TESTS_FLAGS := -I${INCLUDE} -lm -I${TESTS}/libtap -DTEST # I am not adding here the c90 standard, because it interferes with libtap.

SOURCES       := $(shell find ${SRC} -type f -name '*.c')
HEADERS       := $(shell find ${ROOT} -type f -name '*.h')
TESTS_SOURCES := $(shell find ${TESTS} -type f -name '*.c')

EXECUTABLE      := nubemetbase
TEST_EXECUTABLE := runtests

all: ${BIN}/${EXECUTABLE}

run: clean all
	@./${BIN}/${EXECUTABLE}

test: clean ${BIN}/${TEST_EXECUTABLE}
	@./${BIN}/${TEST_EXECUTABLE}

# We are compiling here the sources as well, because the tester code uses the c code.
${BIN}/${TEST_EXECUTABLE}: ${TESTS_SOURCES}
	mkdir bin -p
	${CC} ${TESTS_SOURCES} ${SOURCES} ${CC_TESTS_FLAGS} -o $@

${BIN}/${EXECUTABLE}: ${SOURCES} ${HEADERS}
	mkdir bin -p
	${CC} ${SOURCES} ${CC_FLAGS} -o $@ 

clean:
	rm -f ${BIN}/*