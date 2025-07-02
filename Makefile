NAME			= get_next_line.a
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -D BUFFER_SIZE=42

SRCS			= get_next_line.c  get_next_line_utils.c
OBJS			= $(SRCS:.c=.o)
HEADER			= get_next_line.h

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re