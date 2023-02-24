# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 20:58:45 by ogregoir          #+#    #+#              #
#    Updated: 2023/02/06 21:19:41 by ogregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=

OBJS	=	$(SRCS:.c=.o)

NAME	=	pipex.a

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

#-----------------------------------------------#

all	:	$(NAME)

$(NAME)	: $(objs)
	ar -rcs $@ $^
clean	:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re	: fclean all

.PHONY : all $(NAME) clean fclean re
