# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aserrano <aserrano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/07 16:32:01 by aserrano          #+#    #+#              #
#    Updated: 2019/12/05 18:13:47 by aserrano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a


SRC =	./*.c

SRCO		= $(SRC:.c=.o)
		


all:	$(NAME)

$(NAME):
		-@gcc -Werror -Wall -Wextra -c $(SRC)
		-@ar rc $(NAME) $(SRCO)
		-@ranlib $(NAME)

clean:	
		-@rm -f $(SRCO) $(SRCBO)

fclean:	clean
		-@rm -f $(NAME)

re: 	fclean all
