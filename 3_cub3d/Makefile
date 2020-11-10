NAME  = cub3D
BONUS = cub3D_bonus

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INCS = -I./srcs -I./libft -I./mlx
INCLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Llibft -lft

LIBFT_D = ./libft
LIBFT_A = ./libft/libft.a

ABBR = cub3d \
       f01_read_info \
       f02_read_map \
       f03_validate_info_map \
       f04_rearrange_all \
       f05_set_sprite \
       f06_run_program \
       f07_execute_raycasting_loop \
       f08_set_background \
       f09_raycast_background \
       f10_raycast_sprite \
       f11_take_screenshot

SRCS = $(addsuffix .c, $(addprefix srcs/, $(ABBR)))
OBJS = $(SRCS:.c=.o)

B_ABBR = f00

B_SRCS = $(addsuffix _bonus.c, $(addprefix bonus/, $(ABBR) $(B_ABBR)))
B_OBJS = $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_D)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(INCLIB)

bonus: fclean $(B_OBJS)
	make -C $(LIBFT_D)
	$(CC) $(CFLAGS) $(INCS) -o $(BONUS) $(B_OBJS) $(INCLIB)

clean:
	make -C $(LIBFT_D) clean
	rm -f $(OBJS) $(B_OBJS) *.bmp

fclean: clean
	rm -f $(NAME) $(BONUS) $(LIBFT_A)

re: fclean all

test: re
	./$(NAME) cubs/test.cub

save: re
	./$(NAME) cubs/test.cub --save

.PHONY: bonus all clean fclean bonus re test save
