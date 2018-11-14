NAME = fillit

SRCS = srcs/main.c srcs/valid_file.c srcs/check_valid.c srcs/fill_lst.c\
	   srcs/solve.c srcs/lst_modif.c srcs/check_valid_logic.c\
	   srcs/solve_final_board.c

OBJS = main.o valid_file.o check_valid.o fill_lst.o solve.o lst_modif.o\
	   check_valid_logic.o solve_final_board.o

HEADER = fillit.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

all: $(NAME)

$(NAME):
	@make re -C $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS) -I $(LIBFT) -I ./includes
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(LIBFT) -L$(LIBFT) -lft

clean:
	@make clean -C $(LIBFT)
	/bin/rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
