NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	pipex.c\
		main.c\
		libft/ft_split.c\
		libft/ft_strjoin.c\
		libft/ft_strlen.c

$(NAME) :
	make all -C libft
	#gcc $(SRCS) -o $(NAME) -fsanitize=address
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all
