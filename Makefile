# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-quer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/03 19:06:56 by jle-quer          #+#    #+#              #
#    Updated: 2016/06/09 15:06:17 by jle-quer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	main.c \
			error.c \
			check_parse_acquisition.c \
			check_path.c \
			parse.c \
			parse_2.c \
			path_finding.c \
			parse_opt.c \
			set_moves.c \
			tools.c \
			tools_2.c \
			tools_3.c

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
