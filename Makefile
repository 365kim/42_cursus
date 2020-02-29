SRCS	= ./ft_memset.c \
		  ./ft_bzero.c \
		  ./ft_memcpy.c \
		  ./ft_memccpy.c \
		  ./ft_memmove.c \
		  ./ft_memchr.c \
		  ./ft_memcmp.c \
		  ./ft_strlen.c \
		  ./ft_strlcpy.c \
		  ./ft_strlcat.c \
		  ./ft_strchr.c \
		  ./ft_strrchr.c \
		  ./ft_strnstr.c \
		  ./ft_strncmp.c \
		  ./ft_atoi.c \
		  ./ft_isalpha.c \
		  ./ft_isdigit.c \
		  ./ft_isalnum.c \
		  ./ft_isascii.c \
		  ./ft_isprint.c \
		  ./ft_tolower.c \
		  ./ft_toupper.c \
		  ./ft_calloc.c \
		  ./ft_strdup.c \
		  ./ft_substr.c \
		  ./ft_strjoin.c \
		  ./ft_strtrim.c \
		  ./ft_split.c \
		  ./ft_itoa.c \
		  ./ft_strmapi.c \
		  ./ft_putchar_fd.c \
		  ./ft_putstr_fd.c \
		  ./ft_putendl_fd.c \
		  ./ft_putnbr_fd.c

NAME	= libft.a
OBJS	= ${SRCS:.c=.o}
INCS	= .
RM		= rm -f
LIBC	= ar rc
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}


$(NAME) : ${OBJS}
	${LIBC} $@ $(OBJS)

all : ${NAME}

fclean : clean
	${RM} ${NAME}

clean :
	${RM} ${OBJS}

re : fclean all
