NAME	= libft.a

SRCS	= ./ft_memset.c \
		  ./ft_bzero.c \
		  ./ft_memcpy.c \
		  ./ft_memccpy.c \
		  ./ft_memmove.c \
		  ./ft_memchr.c \
		  ./ft_memcmp.c \
		  ./ft_strlen.c \
		  ./ft_strcpy.c \
		  ./ft_strlcpy.c \
		  ./ft_strlcat.c \
		  ./ft_strchr.c \
		  ./ft_strrchr.c \
		  ./ft_strnstr.c \
		  ./ft_strcmp.c \
		  ./ft_strncmp.c \
		  ./ft_atoi.c \
		  ./ft_isalpha.c \
		  ./ft_isdigit.c \
		  ./ft_only_digit.c \
		  ./ft_isalnum.c \
		  ./ft_isascii.c \
		  ./ft_isprint.c \
		  ./ft_isset.c \
		  ./ft_isformat.c \
		  ./ft_tolower.c \
		  ./ft_toupper.c \
		  ./ft_calloc.c \
		  ./ft_free_2d.c \
		  ./ft_strdup.c \
		  ./ft_strndup.c \
		  ./ft_substr.c \
		  ./ft_strjoin.c \
		  ./ft_strtrim.c \
		  ./ft_split.c \
		  ./ft_itoa.c \
		  ./ft_strmapi.c \
		  ./ft_putchar_fd.c \
		  ./ft_putstr_fd.c \
		  ./ft_putstr.c \
		  ./ft_putendl_fd.c \
		  ./ft_putnbr_fd.c \
		 ./ft_lstnew.c \
		 ./ft_lstadd_front.c \
		 ./ft_lstsize.c \
		 ./ft_lstlast.c \
		 ./ft_lstadd_back.c \
		 ./ft_lstdelone.c \
		 ./ft_lstclear.c \
		 ./ft_lstiter.c \
		 ./ft_lstmap.c \
		 ./ft_longest_node_len.c \
		 ./ft_strexit.c \
		 ./get_next_line.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INCS	= .
OBJS	= $(SRCS:.c=.o)
LIBC	= ar rc

RM		= rm -f

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
