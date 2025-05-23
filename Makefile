##
## EPITECH PROJECT, 2025
## day01-am
## File description:
## Makefile
##

## DEFS - Set your project infos and compilation preferences

NAME		=	raytracer
CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -std=c++20
DFLAGS		=	-MMD -MF $(@:.o=.d)
LDFLAGS		=	-lconfig++
CPPLINT_FLAGS		=														\
	--root=./include														\
	--repository=. 															\
	--filter=-legal/copyright,-build/c++17,+build/c++20,-runtime/references,$\
-build/include_subdir,-build/c++11,-whitespace/indent_namespace				\
	--recursive

## SRC - Put your sources files here

FILE_EXTENSION	=	.cpp
INCLUDE_PATH	=	./include

SRCS		=	src/APrimitive.cpp	\
				src/Face.cpp 		\
				src/parsing/SceneParser.cpp

MAIN		=	src/main.cpp

TEST_OUTPUT	=	unit_tests

SRCS_TEST	=

## Put the path of the factories Makefiles here from src/plugins/Factories/

FACTORIES	=	Primitives/Sphere		\
				Lights/DirectionalLight	\
				Material				\

FACTORIES_DIRS = $(addprefix src/plugins/Factories/, $(FACTORIES))

## OBJS

OBJS		=	$(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
OBJ_MAIN	=	$(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.o})
OBJS_TEST	=	$(addprefix objs/, ${SRCS_TEST:$(FILE_EXTENSION)=.o})
DEPS		=	$(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})
DEPS_MAIN	=	$(addprefix objs/, ${MAIN:$(FILE_EXTENSION)=.d})

## RULES

all: factories $(NAME)

-include $(DEPS) $(DEPS_MAIN)

$(NAME):	$(OBJS) $(OBJ_MAIN)
	$(CXX) $(CXXFLAGS) $(DFLAGS) $(OBJS) $(OBJ_MAIN)	\
	-o $@ -I $(INCLUDE_PATH) $(LDFLAGS)

objs/%.o:	%$(FILE_EXTENSION)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@ -I $(INCLUDE_PATH) $(LDFLAGS)

clean:
	rm -rf objs *.gcda *.gcno
	for dir in $(FACTORIES_DIRS); do \
		$(MAKE) -C $$dir clean;	\
	done

fclean:		clean
	rm -rf $(NAME) $(TEST_OUTPUT) plugins/
	for dir in $(FACTORIES_DIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re:		fclean all
	for dir in $(FACTORIES_DIRS); do \
		$(MAKE) -C $$dir re; \
	done

unit_tests: $(OBJS) $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) $(DFLAGS) -o $(TEST_OUTPUT) $(SRCS) $(OBJS_TEST)	\
	--coverage -lcriterion -I $(INCLUDE_PATH) $(LDFLAGS)

tests_run: unit_tests
	./$(TEST_OUTPUT)

tests_coverage:	tests_run
	gcovr

linter: clean
	cpplint $(CPPLINT_FLAGS) ./src/ ./include/

format: clean
	find . -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.tpp" \) ! \
	-path "./tests/*" -exec clang-format -i {} +

factories:
	mkdir -p plugins
	for dir in $(FACTORIES_DIRS); do \
		$(MAKE) -C $$dir; \
	done
	cp $$(find src/plugins/Factories -name '*.so') ./plugins/

.PHONY:	all clean fclean re tests_run tests_coverage linter format factories
