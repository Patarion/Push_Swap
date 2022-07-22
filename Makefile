NAME = push_swap

SRCS = Small_tri.c\
	Parsing.c\
	Move_stack-b.c\
	Move_stack-a.c\
	Medium_tri.c\
	Main.c\
	Lst_utils3.c\
	Lst_utils2.c\
	Lst_utils.c\
	Lst_pointer.c\
	Single_arg_utils2.c\
	Single_arg_utils.c\
	Dispatch.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NORM = norminette
RM = rm -f


all: $(NAME)

$(NAME):

push_swap:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}
	@echo "____Push_swap créé avec succès____"

clean:
	@echo "_____Les objets ont été supprimés_____"

fclean: clean
	${RM} ${NAME}
	@echo "_____L'exécutable est touché coulé_____"

re: fclean all

.PHONY : all clean fclean re