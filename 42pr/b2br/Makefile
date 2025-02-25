# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilhasnao <ilhasnao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:33:52 by ilhasnao          #+#    #+#              #
#    Updated: 2025/02/24 21:46:33 by ilhasnao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
LIBFT = libft/
RM = rm -f

SRC_1 = pipex.c process.c path.c

SRC_2 = pipex_bonus.c path_bonus.c process_bonus.c pipex_bonus_utils.c \
		free_bonus.c

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
		@${CC} ${CFLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

bonus : $(OBJ_2)
		@make -C $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_2} -o ${NAME} ${INCLUDE}
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

all: ${NAME}

clean:
		@${RM} ${OBJ_1} ${OBJ_2}
		@cd ${LIBFT} && $(MAKE) clean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

fclean: clean
		@${RM} ${NAME}
		@cd ${LIBFT} && $(MAKE) fclean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
