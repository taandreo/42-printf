.PHONY: libft.a all clean fclean re log bonus

CC = clang-12
INCLUDE = include
NAME = libftprintf.a
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

SOURCES = mandatory/ft_printf.c \
		mandatory/ft_utoa.c \
		mandatory/utils.c \

BONUS_SOURCES = bonus/append_flag_00_bonus.c \
		bonus/append_flag_01_bonus.c \
		bonus/arg_parse_bonus.c \
		bonus/ft_printf_bonus.c \
		bonus/get_str_bonus.c \
		bonus/linked_list_bonus.c \
		bonus/utils_00_bonus.c \
		bonus/utils_01_bonus.c \

OBJS = $(SOURCES:.c=.o)
BONUS_OBJS = $(BONUS_SOURCES:.c=.o)
ALL_OBJS = $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)
	cp -p $(LIBFT) $(NAME)

bonus: $(BONUS_OBJS) $(LIBFT)
	ar rcs $(NAME) $(BONUS_OBJS)

all: $(NAME)

clean:
	rm -f $(ALL_OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -f a.out

main:
	$(CC) -Wall -Wextra -I $(INCLUDE) main.c -L . -lftprintf  && ./a.out

test:
	$(CC) -I $(INCLUDE) test.c -L . -lftprintf && ./a.out 

flags:
	$(CC) $(CFLAGS) flags.c -L . -lftprintf && ./a.out

linked:
	$(CC) $(CFLAGS) linked.c -L . -lftprintf && ./a.out

re: fclean all

log:
	echo $(ALL_OBJS)
	# @echo $(OBJS)
	# @echo $(BONUS_OBJS)
	# @echo $(CFLAGS)