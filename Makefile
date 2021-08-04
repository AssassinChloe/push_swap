NAME	= push_swap
SRCS	= main.c ft_atoll.c ft_isdigit.c ft_sort.c push.c reverse_rotate.c rotate.c swap.c utils.c
OBJSD	= .obj/
OBJS	= $(addprefix $(OBJSD), $(SRCS:%.c=%.o))
INC		= -I push_swap.h
CC		= clang
FLAGS 	= -Wall -Wextra -Werror

all : 		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)
clean :
			rm -rf $(OBJSD) 

fclean : 	clean
			rm -f $(NAME)

re : 		fclean all

$(OBJSD)%.o:%.c
		@mkdir -p $(OBJSD) 
		$(CC) $(FLAGS) $(INC) -o $@ -c $<