NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS = 	pipex.c\
		libft/ft_split.c\
		libft/ft_strjoin.c\
		libft/ft_strlen.c

$(NAME) :
	gcc $(SRCS) -o $(NAME)

re :
	$(RM) $(NAME)	
	gcc $(SRCS) -o $(NAME)