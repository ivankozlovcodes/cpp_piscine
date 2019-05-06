# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arherrer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 15:17:56 by arherrer          #+#    #+#              #
#    Updated: 2019/05/04 13:39:17 by arherrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX := clang++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -Wpedantic
LDFLAGS := -lncurses

name := ft_retro
src := $(wildcard *.cpp)
obj := $(src:.cpp=.o)

.PHONY: all
all: $(name)

$(name): $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj)

.PHONY: fclean
fclean: clean
	rm -f $(name)

.PHONY: all
re: fclean all
