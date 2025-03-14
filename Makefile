##
## EPITECH PROJECT, 2025
## B-PDG-300-TLS-3-1-PDGD06-guillaume1.blondel
## File description:
## Makefile
##

SRC	:=	$(wildcard src/*.cpp)

TESTS_SRC := $(filter-out src/main.cpp, $(SRC))

OBJ_DIR	:=	build

OBJ	:=	$(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.cpp=.o}))

BINARY	:=	nanotekspice

CFLAGS	:=	-std=c++20 -Wall -Werror -Wextra -g3

UNIT_TESTS = unit_tests

CF = tests/test.cpp 

all:	$(OBJ_DIR) ${BINARY} 

${OBJ_DIR}:
	@(mkdir -p ${OBJ_DIR})

${OBJ_DIR}/%.o:	src/%.cpp
	@echo "$<..."
	@(g++ ${CFLAGS} -c $< -o $@)

${BINARY}:	${OBJ}
	@echo "Linking ${BINARY}"
	@(g++ ${OBJ} -o ${BINARY})
	@(echo Compilation Finished ✅​)

tests_run:
	g++ $(TESTS_SRC) $(CF) -o unit_tests --coverage -lcriterion 
	./unit_tests

clean:
	@rm -f ${OBJ}
	@rm -rf ${OBJ_DIR}
	@rm -rf *.gcno

fclean:	clean
	@rm -f ${BINARY}
	@rm -rf *.gcno
	@rm -rf *.gcda
	@rm -rf unit_tests

re:	fclean
	@(${MAKE} --no-print-directory all)
