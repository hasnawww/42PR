# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:33:52 by ilhasnao          #+#    #+#              #
#    Updated: 2025/02/28 00:30:05 by ilhasnao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
LIBFT = libft/
RM = rm -f
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC_1 = parsing.c map_init.c mlx.c

OBJ_1 = $(SRC_1:.c=.o)

INCLUDE = -L ./libft -lft

DEF_COLOR = \033[0m
PINK = \033[5;95m
GREEN = \033[1;92m
CYAN = \033[1;96m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(PINK)I'm compiling hbibi!$(DEF_COLOR)"
	
$(NAME): $(OBJ_1)
		@make -C $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE} $(MLX_FLAGS)
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

mlx:
		git clone https://github.com/42Paris/minilibx-linux.git mlx || true
		make -C mlx

all: ${NAME}

clean:
		@${RM} ${OBJ_1} ${NAME}
		@cd ${LIBFT} && $(MAKE) clean
		@echo "$(CYAN)I'm cleaning hbibi!$(DEF_COLOR)"

fclean: clean
		@${RM} ${NAME}
		@cd ${LIBFT} && $(MAKE) fclean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

re: clean all

.PHONY: all clean fclean re bonus mlx
