# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:18:22 by jwilliam          #+#    #+#              #
#    Updated: 2022/06/05 16:11:03 by jwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INCL = includes

CC = gcc

FLAGS = -Wall -Werror -Wextra
P_T = -pthread

RM = rm -rf

FILES = main.c \
		actions.c \
		error.c \
		init.c \
		print_action.c \
		process.c \
		utils.c \
		validate_args.c \

OBJS_NAME = $(FILES:.c=.o)

OBJS = $(addprefix $(OBJS_DIR), $(OBJS_NAME))
SRCS = $(addprefix $(SRC_DIR), $(FILES))
SRC_DIR = srcs/
OBJS_DIR = objs/

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(P_T) $(OBJS) -o $@
		@echo "\033[32m████████████████████████████████"
		@echo "\033[32m█████ \033[39mphilosophers created \033[32m█████"
		@echo "\033[32m████████████████████████████████ \033[39m"

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
		@mkdir -p $(OBJS_DIR)
		@$(CC) $(FLAGS) -o $@ -c $< -I $(INCL)

clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJS_DIR)
		@echo "\033[33m████████████████████████████████"
		@echo "\033[33m█████ \033[39mcleaned philosophers \033[33m█████"
		@echo "\033[33m█████     \033[39mobject files     \033[33m█████"		
		@echo "\033[33m████████████████████████████████ \033[39m"

fclean:	clean	
		@$(RM) $(NAME)
		@$(RM) $(NAME).a
		@echo "\033[33m████████████████████████████████"
		@echo "\033[33m█████ \033[39mcleaned philosophers \033[33m█████"
		@echo "\033[33m█████    \033[39mprogram files     \033[33m█████"		
		@echo "\033[33m████████████████████████████████ \033[39m"

re: fclean all

.PHONY: clean fclean all re