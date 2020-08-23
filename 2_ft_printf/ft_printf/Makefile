C = clang

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ./ft_printf.c \
			  ./parse_all.c \
			  ./pre_process.c \
			  ./print_1_char.c \
			  ./print_2_string.c \
			  ./print_3_int.c \
			  ./print_4_unsigned_int.c \
			  ./print_5_hexa.c \
			  ./print_6_pointer.c \
			  ./print_7_percent.c \
			  ./store_8_nbyte.c \
			  ./manage_box.c \
			  ./manage_int_sign.c

OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o
