# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jesuserr <jesuserr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 18:45:11 by jesuserr          #+#    #+#              #
#    Updated: 2023/10/27 18:45:11 by jesuserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fragtrap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

INCLUDE = -I ./
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
CC = c++

%.o: %.cpp
	$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)
		
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re