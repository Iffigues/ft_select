# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bordenoy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/28 19:39:36 by bordenoy          #+#    #+#              #
#    Updated: 2019/04/25 13:19:18 by bordenoy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
SRC=main.c ft_libere.c ft_begin.c ft_col.c ft_signal.c ft_charz.c ft_count.c ft_aff.c ft_background.c ft_mode.c ft_type.c ft_setip.c ft_enter.c ft_choose.c ft_static.c
OBJ=$(SRC:.c=.o)
CC=gcc -Wall -Wextra -Werror
INCLUDE= -I ./
all:$(NAME)
$(NAME):$(OBJ)
	@make -C libft/ 
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME) -L libft/ -lft -ltermcap 
%.o:%.c
	$(CC) $(INCLUDE) -c $< 
clean:
	rm -f *.o
	@make clean -C  libft/
fclean:clean
	rm -f $(NAME)
	make fclean -C libft/
re:fclean all
.PHONY:all clean fclean re
