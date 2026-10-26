# Název výsledného programu
NAME = poly

# Překladač a příznaky
CC = cc
CFLAGS = -Wall -Wextra -Werror  -I fPie -g
DEBUG_FLAGS = -fsanitize=address  


# Seznam všech .c souborů
SRC =   main.c          \
		parsing/checker.c		\
		parsing/get_next_line.c	\
		parsing/line_to_lst.c	\
		parsing/linked_list.c	\
		parsing/read_args.c		\
        parsing/utils.c       	\
		polygon/polygon.c		\


# Změna koncovek .c na .o pro objekty
OBJ = $(SRC:.c=.o)

# Hlavní pravidlo
all: $(NAME)

# Jak vytvořit výsledný program z objektů
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Pravidlo pro kompilaci jednotlivých .c souborů na .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pravidlo pro promazání objektových souborů
clean:
	rm -f $(OBJ)

# Pravidlo pro kompletní smazání (včetně programu)
fclean: clean
	rm -f $(NAME)

# Pravidlo pro "přestavbu" od nuly
re: fclean all


debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re debug 