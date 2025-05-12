##
## EPITECH PROJECT, 2025
## day01-am
## File description:
## Makefile
##

## DEFS - Set your project infos and compilation preferences

NAME		=	raytracer
CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -std=c++20 -lsfml-graphics -lsfml-window -lsfml-system
DFLAGS		=	-MMD -MF $(@:.o=.d)
LDFLAGS		=
CPPLINT_FLAGS		=														\
	--root=./include														\
	--repository=. 															\
	--filter=-legal/copyright,-build/c++17,+build/c++20,-runtime/references,$\
-build/include_subdir,-build/c++11											\
	--recursive

## SRC - Put your sources files here

FILE_EXTENSION	=	.cpp
INCLUDE_PATH	=	./include

SRCS		=	src/Render.cpp

MAIN		=	src/main.cpp

TEST_OUTPUT	=	unit_tests

SRCS_TEST	=
## OBJS

OBJS		=	$(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN	=	$(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
OBJS_TEST	=	$(addprefix objs/, ${SRCS_TEST:$(FILE_EXTENSION)=.o})
DEPS		=	$(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})
DEPS_MAIN	=	$(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.d})

## RULES

all: $(NAME)

-include $(DEPS) $(DEPS_MAIN)

$(NAME):	$(OBJS) $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(OBJS) $(OBJ_MAIN) -o $@ -I $(INCLUDE_PATH)

objs/%.o:	%$(FILE_EXTENSION)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)

clean:
	rm -rf objs *.gcda *.gcno

fclean:		clean
	rm -rf $(NAME) $(TEST_OUTPUT)

re:		fclean all

unit_tests: $(OBJS) $(OBJS_TEST)
	$(CXX) -o $(TEST_OUTPUT) $(SRCS) $(OBJS_TEST) --coverage -lcriterion

tests_run: unit_tests
	./$(TEST_OUTPUT)

tests_coverage:	tests_run
	gcovr

linter: clean
	cpplint $(CPPLINT_FLAGS) ./src/ ./include/

format: clean
	find . -type f \( -name "*.cpp" -o -name "*.hpp" \) ! -path "./tests/*"	\
	-exec clang-format -i {} +

.PHONY:	all clean fclean re tests_run tests_coverage linter format
