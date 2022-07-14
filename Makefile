.PHONY: libft.a all clean fclean re log bonus

CC = clang
INCLUDE = include
NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)
SOURCES_DIR = sources/
SOURCES = $(wildcard $(SOURCES_DIR)*.c)
OBJS = $(SOURCES:.c=.o)

# BONUS_OBJS = $(BONUS:.c=.o)
# ALL_OBJS = $(OBJS) $(BONUS_OBJS)

sources/%.o: sources/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)
	cp -p $(LIBFT) $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -f a.out

all: $(NAME)

main: all
	$(CC) $(CFLAGS) main.c -L . -lftprintf -I $(INCLUDE) && ./a.out

test: all
	$(CC) $(CFLAGS) test.c -L . -lftprintf -I $(INCLUDE) && ./a.out 

# bonus: $(ALL_OBJS)
# ar rcs $(NAME) $(ALL_OBJS)

re: fclean all

log:
	@echo $(OBJS)
	# @echo $(BONUS_OBJS)
	@echo $(CFLAGS)