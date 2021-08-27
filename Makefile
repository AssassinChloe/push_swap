# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cassassi <cassassi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 16:23:30 by cassassi          #+#    #+#              #
#    Updated: 2021/08/27 12:42:22 by cassassi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

SRCS	= main.c ft_sort.c push.c reverse_rotate.c\
	  rotate.c swap.c utils_push.c quick_sort.c sort_5.c sort_3.c median.c\
	  checksorting.c free.c parse.c utils_qs.c sortsub_3.c

OBJSD	= .obj/

OBJS	= $(addprefix $(OBJSD), $(SRCS:%.c=%.o))

INC	= -I push_swap.h

LIB	= libft/libft.a

CC	= clang

FLAGS 	= -Wall -Wextra -Werror

all : 		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C libft
			$(CC) -o $(NAME) $(OBJS) $(LIB)
clean :
			$(MAKE) clean -C libft
			rm -rf $(OBJSD) 

fclean : 	clean
			$(MAKE) fclean -C libft
			rm -f $(NAME)

re : 		fclean all

$(OBJSD)%.o:%.c
		@mkdir -p $(OBJSD) 
		$(CC) $(FLAGS) $(INC) -o $@ -c $<
