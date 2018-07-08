# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 19:06:22 by ikozlov           #+#    #+#              #
#    Updated: 2018/07/07 23:40:20 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC_DIR = srcs/
OBJ_DIR = objs/

SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.cpp))
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIB = -lncurses
INC = -I includes/

CXX = clang++
# FLAGS = -Wconversion -std=c++98 -pedantic  -Wall -Werror -Wextra
FLAGS = -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) $(INC) $(LIB) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re $(NAME)