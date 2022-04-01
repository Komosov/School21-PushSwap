NAME	=	push_swap

SRCS	=	push_swap.c \
			ft_array.c \
			ft_atoi_push_swap.c \
			ft_nodes.c \
			ft_op_push.c \
			ft_op_rotate.c \
			ft_op_rrotate.c \
			ft_op_swap.c \
			ft_ps_utils.c \
			ft_sort_stack_2_5.c \
			ft_sort_stack_6_more.c \

HEADER	=	push_swap.h

LIBFT	=	./libft/libft.a

OBJS	=	${SRCS:%.c=%.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.PHONY	:	all clean fclean re

all		:	${NAME}

${NAME}	:	${LIBFT} ${OBJS}
			${CC} ${CFLAGS} ${OBJS} -L ./libft -lft -o ${NAME}

$(LIBFT):
			make -C ./libft all

%.o 	:	%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean	:
			${RM} ${OBJS}
			make -C ./libft clean

fclean	:	clean
			${RM} ${NAME}
			make -C ./libft fclean

re		:	fclean all
