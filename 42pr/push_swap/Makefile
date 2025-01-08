# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasnawww <hasnawww@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 14:33:52 by ilhasnao          #+#    #+#              #
#    Updated: 2025/01/08 03:49:31 by hasnawww         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT = libft/
RM = rm -f

SRC_1 = src/main.c

SRC_2 = src/list.c \
		src/utils.c \
		src/utils_2.c \
		src/print.c \
		src/parsing.c \
		src/sort.c \
		src/algo.c \
		instructions/swap_p.c \
		instructions/swap_r.c \
		instructions/swap_rr.c \
		instructions/swap_s.c \

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
	
$(NAME): $(OBJ_1) ${OBJ_2}
		@make -C $(LIBFT)
		@${CC} ${CFLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}
		@echo "$(GREEN)Its compiled hbibi!$(DEF_COLOR)"

all: ${NAME}

clean:
		@${RM} ${OBJ_1} ${OBJ_2} ${NAME}
		@cd ${LIBFT} && $(MAKE) clean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

fclean: clean
		@${RM} ${NAME}
		@cd ${LIBFT} && $(MAKE) fclean
		@echo "$(CYAN)I'm cleaning hbibi!$< $(DEF_COLOR)"

re: clean all

.PHONY: all clean fclean re bonus
