# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/04 11:30:46 by ashea             #+#    #+#              #
#    Updated: 2021/07/04 11:30:48 by ashea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I .

FRACTAL = fractal
FRACTAL_SRCS = main.o complex_utility.o complex_utility2.o drow.o hook.o init.o utility.o


%.o : %.c
	@$(CC) $(FLAGS) $< -c

all : $(FRACTAL) 

$(FRACTAL) : $(FRACTAL_SRCS)
	@$(CC) $(FRACTAL_SRCS) libmlx.dylib -o $(FRACTAL)
	@printf "\e[32m$@ built\e[0m\n"

clean :
	@rm -f $(FRACTAL_SRCS)
	@printf "\e[31mclean done\e[0m\n"

fclean : clean
	@rm -f $(FRACTAL) 
	@printf "\e[31mfclean done\e[0m\n"

re : fclean all

.PHONY: all clean fclean re
