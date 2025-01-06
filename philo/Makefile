# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babischa <babischa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 17:01:22 by babischa          #+#    #+#              #
#    Updated: 2025/01/06 12:16:21 by babischa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO	:=	philo

CC 			:=	cc
FLAGS 		:=	-Werror -Wextra -Wall -g3

HEADERS 	:=	-I ./include

SRC_PHILO	:=	main \
				routine \
				print_actions \
				utils

OBJ_PHILO	:=	$(addprefix objects/, $(addsuffix .o, $(SRC_PHILO)))

all: $(PHILO)

objects/%.o: source/%.c | objects
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS) ; \
	echo "Compiling: $(notdir $<)"

$(PHILO): $(OBJ_PHILO)
	$(CC) $(OBJ_PHILO) $(HEADERS) -o $(PHILO) -lpthread $(HEADERS)

objects:
	mkdir -p objects

bonus: all

clean:
	rm -rf objects

fclean: clean
	rm -rf $(PHILO)

re: fclean all

.PHONY: all clean fclean re objects

.SILENT:
