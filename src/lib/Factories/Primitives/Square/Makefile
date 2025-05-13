##
## EPITECH PROJECT, 2025
## GrayTracer
## File description:
## Makefile
##

## DEFS - Set your project infos and compilation preferences

NAME		=	libspherefactory.so
CXX			=	g++
CXXFLAGS	=	-Wall -Wextra -std=c++20
DFLAGS		=	-MMD -MF $(@:.o=.d)

## SRC - Put your sources files here

FILE_EXTENSION	=	.cpp
INCLUDE_PATH	=	../../../../../include

SRCS		=	src/SphereFactory.cpp

## OBJS

OBJS		=	$(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.o})
DEPS		=	$(addprefix objs/, ${SRCS:$(FILE_EXTENSION)=.d})

## RULES

all: $(NAME)

-include $(DEPS)

$(NAME):	$(OBJS)
	$(CXX) -shared $(CXXFLAGS) $(DFLAGS) $(OBJS) -o $@ -I $(INCLUDE_PATH)

objs/%.o:	%$(FILE_EXTENSION)
	mkdir -p $(dir $@)
	$(CXX) -fPIC $(CXXFLAGS) $(DFLAGS) -c $< -o $@ -I $(INCLUDE_PATH)

clean:
	rm -rf objs *.gcda *.gcno

fclean:		clean
	rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
