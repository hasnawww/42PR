# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:33:52 by ilhasnao          #+#    #+#              #
#    Updated: 2025/03/07 17:46:41 by ilhasnao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT = libft/
RM = rm -f
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

SRC_1 = srcs/mandatory/utils1.c srcs/mandatory/utils2.c \
		srcs/mandatory/utils3.c srcs/mandatory/utils4.c \
		pars/mandatory/parsing.c so_long.c pars/mandatory/parsing2.c \
		pars/mandatory/parsing3.c pars/mandatory/parsing4.c

SRC_2 = srcs/bonus/utils1_bonus.c srcs/bonus/utils2_bonus.c \
		srcs/bonus/utils3_bonus.c srcs/bonus/utils4_bonus.c \
		srcs/bonus/utils5_bonus.c \
		pars/bonus/parsing_bonus.c so_long_bonus.c pars/bonus/parsing_bonus4.c\
		pars/bonus/parsing_bonus2.c pars/bonus/parsing_bonus3.c \

OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

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

$(NAME_BONUS):  $(OBJ_2)
		@make -C $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_2} -o ${NAME_BONUS} ${INCLUDE} $(MLX_FLAGS)
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

mlx:
		git clone https://github.com/42Paris/minilibx-linux.git mlx || true
		make -C mlx

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
		@${RM} ${OBJ_1} $(OBJ_2)
		@cd ${LIBFT} && $(MAKE) clean
		@echo "$(CYAN)I'm cleaning hbibi!$(DEF_COLOR)"

fclean: clean
		@${RM} ${NAME} ${NAME_BONUS}
		@rm -rf mlx
		@cd ${LIBFT} && $(MAKE) fclean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

re: clean all

re_bonus: clean bonus

.PHONY: all clean fclean re bonus mlx re_bonus
