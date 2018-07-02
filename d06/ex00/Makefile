# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 19:06:22 by ikozlov           #+#    #+#              #
#    Updated: 2018/07/02 16:40:24 by ivankozlov       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
FLAGS = -Wconversion -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.c
	$(CXX) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re $(NAME)