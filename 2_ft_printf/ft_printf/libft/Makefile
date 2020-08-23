NAME	= libft.a

SRCS	= ./ft_putchar.c \
		  ./ft_putchar_n.c \
		  ./ft_putstr.c \
		  ./ft_putstr_n.c \
		  ./ft_putnbr_base.c \
		  ./ft_atoi.c \
		  ./ft_atouni.c \
		  ./ft_itoa.c \
		  ./ft_lltoa.c \
		  ./ft_itoa_base.c \
		  ./ft_lltoa_base.c \
		  ./ft_uitoa.c \
		  ./ft_ulltoa.c \
		  ./get_atouni_width.c \
		  ./get_itoa_width.c \
		  ./get_itoa_base_width.c \
		  ./is_set.c \
		  ./ft_strlen.c \
		  ./ft_strcpy.c \
		  ./ft_strncpy.c \
		  ./ft_strchr.c \
		  ./ft_strstrhr.c \
		  ./ft_strndup.c \
		  ./ft_strjoin.c \
		  ./ft_memset.c \
		  ./ft_memcpy.c \
		  ./max.c \
		  ./min.c

OBJS	= $(SRCS:.c=.o)
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(bonus)

re : fclean all
