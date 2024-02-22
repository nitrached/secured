##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME         = libhashtable.a

OBJS     = $(SRCS:.c=.o)

CFLAGS   = -Wall -Wextra -I include -I lib/include

	GREEN=\033[1;32m
	YELLOW=\033[1;93m
	GREY=\033[2;49m
	ITALIC=\033[3m
	NC=\033[0m

all: $(NAME)

$(NAME): build_lib

build_lib:
	make -C ./lib

clean:
	make fclean -C ./lib
	$(RM) $(OBJS) $(NAME)
	find . -name "#*#" -delete -o -name "*~" -delete
	$(RM) coding-style-reports.log
	$(RM) vgcore*
	clear

fclean: clean
	$(RM) a.out
	$(RM) lib/libmy.a
	clear

re: fclean all

debug: fclean
debug: CFLAGS += -g
debug: all

.c.o:
	@ $(CC) -o $(subst .c,.o,$<) -c $< $(CFLAGS) \
		&& echo -e "[ ${GREEN}OK${NC} ] ${GREY}$<${NC}" \
		|| echo -e "[ ${YELLOW}KO${NC} ] ${ITALIC}$<${NC}"

.PHONY: re fclean clean all .c.o
