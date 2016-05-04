# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 19:06:56 by jle-quer          #+#    #+#              #
#    Updated: 2016/05/04 15:29:57 by jle-quer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LIB = ./Libft/libft.a

OBJET = $(SRC_NAME:.c=.o)

all: $(NAME)
	@echo "Make In Progress"
	@echo "Make Done."

$(NAME): $(LIB) $(OBJET)
	@gcc $(FLAGS) $(OBJET) -L./Libft/ -lft -o $(NAME)

$(LIB):
	make -C ./Libft/

%.o: %.c
	@gcc $(FLAGS) -I./Libft/INCLUDES -c $<

clean:
	@echo "Clean In Progress"
	@rm -f $(OBJET)
	@echo "Clean Done."

fclean: clean
	@rm -rf $(NAME)

re: fclean all

proper:
	@make
	@make clean -C ./Libft/
	@make clean

fcleanl:
	@make fclean -C ./Libft/
	@echo "./Libft/ Is Clean"
