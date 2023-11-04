NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
LDFLAGS = -lreadline
SRC = minishell.c utils.c ./lexer/*.c utils1.c ./execve/*.c ./parsing_system/*.c  ./builtins/*.c  syntax_error.c env.c env_utils.c redirections.c fork.c signals.c ft_malloc.c misc_functions.c misc_functions2.c redirections_utils.c utils2.c utils3.c free.c

.SILENT:
all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	printf "\033[32mcompiling...\033[\n"
	$(CC) $(CFLAGS) -L/Users/mboudrio/.brew/opt/readline/lib $(SRC) ./libft/libft.a -o $@ $(LDFLAGS)
	printf "\033[32mDONE\033[\n"

clean:
	make clean -C libft
	rm -f $(NAME)

fclean: clean
	printf "\033[31mcleaning...\033[\n"
	make fclean -C libft
	rm -f $(NAME)

re: fclean all


