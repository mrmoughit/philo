# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abechcha <abechcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 09:19:32 by abechcha          #+#    #+#              #
#    Updated: 2024/03/09 13:17:03 by abechcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

SRC = creat_threads.c\
	  ft_atoi.c\
	  free_function.c\
	  ft_set_mutex.c\
	  ft_error.c\
	  extra_functions.c\
	  init_philo.c\
	  main.c\
	  ft_lstnew.c\
	  parsing.c\
	  ft_is_die.c\

OBJ = ${SRC:.c=.o}

all : ${NAME} 

%.o : %.c philo.h
	cc ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ}
	cc ${CFLAGS} ${OBJ} -o ${NAME}

clean :
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}

re : fclean all

PHONY : clean
