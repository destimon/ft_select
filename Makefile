# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcherend <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/17 15:19:05 by dcherend          #+#    #+#              #
#    Updated: 2018/07/29 15:15:05 by dcherend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= ft_select

LIBFT 			= $(LIBFT_DIR)libft.a
LIBFT_DIR 		= $(LIB_DIR)libft/
LIBFT_INC 		= $(LIBFT_DIR)$(INC_DIR)
LIBFT_FLAGS 	= -lft -L $(LIBFT_DIR)
LIBFT_DIR 		= ./lib/libft/
LIBFT_HDR_DIR 	= ./lib/libft/
OBJ_DIR 		= ./obj/
SRC_DIR 		= ./src/
HDR_DIR 		= ./include/

CC 				= gcc
CFLAGS 			= -I$(HDR_DIR) -I$(LIBFT_HDR_DIR) # -Wall -Werror -Wextra \

SRC 			= main.c core.c term.c list.c utils.c ui.c input.c input2.c \
                    signals.c extend.c pagination.c

OBJ 			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIB_BIN 		= $(LIBFT_DIR)libft.a
LIB_FLAGS 		= -lft -L$(LIBFT_DIR)
LIB 			= $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_FLAGS) -o $(NAME) -ltermcap

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(HEADERS_FLAGS) $(CFLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
