##
## EPITECH PROJECT, 2021
## The Marvelous Libmy
## File description:
## Makefile
##

#library name
LIB	=	libmy.a

#copy path
HDRDIR	=	../includes

#library sources
SRC	=	sources/chained_list/c_list_index.c	\
		sources/chained_list/c_list.c		\
		sources/my_queue/my_queue.c			\
		sources/my_stack/my_stack.c			\
		sources/sources/qcs_utility.c
HDR	=	includes/c_list.h	\
		includes/my_queue.h	\
		includes/my_stack.h	\
		includes/qcs_utility.h

#Compiler and Linker
CC	= cc
OBJ	=	$(SRC:.c=.o)

#obj file path
BUILDDIR=	obj
SRCDIR	=	my

#flags
CFLAGS	=	-Wall -Werror
IFLAGS	=	-Iincludes

#------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#------------------------------------------------------------------------------

%.o: %.c
	@$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $^\
	&& printf "[\033[1;35mcompiled\033[0m]% 50s\n" $< |  tr ' ' '.'\
	|| printf "[\033[1;31merror\033[0m]% 50s\n" $< |  tr ' ' '.'

all: $(LIB)

$(LIB): $(OBJ)
	@cp $(HDR) $(HDRDIR)
	@ar rc $(LIB) $(OBJ)
	@printf "\e[1;36mFinished compiling library\e[0m\n"

clean:
	@rm -f *~
	@rm -f *#
	@rm -f $(OBJ)
	@printf "\e[0;33mDeleted all .o in lib\e[0m\n"

fclean: clean
	@rm -f $(LIB)
	@printf "\e[0;33mDeleted libmy.a\e[0m\n"
	@cd $(HDRDIR) && rm -f $(notdir $(HDR))
	@printf "\e[1;32mDeleted all .o in lib and all libmy.a\e[0m\n"

re: fclean all

.PHONY: all clean fclean re
