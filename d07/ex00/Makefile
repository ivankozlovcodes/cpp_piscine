# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/24 19:06:22 by ikozlov           #+#    #+#              #
#    Updated: 2019/05/08 13:30:30 by ivankozlov       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = template

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wconversion -std=c++98 -pedantic  -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re $(NAME)