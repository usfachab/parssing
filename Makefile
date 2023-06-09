NAME	=	lexer

CC		=	cc

CFALGS	=	-Wextra -Werror -Wall

LDFLAG	=	-lreadline

SRC		=	main.c reset.c assets/exitStat.c assets/lexer.c assets/parser.c assets/parserExtra.c assets/syntax.c assets/__syntax.c \
			assets/expand.c assets/extra.c assets/token.c helper/find_and_replace.c helper/ft_split.c \
			helper/ft_strjoin.c helper/node_list.c helper/nodeListExtra.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFALGS) -o $@ $(SRC) $(LDFLAG)

%.o		:	%.c
			@$(CC) $(CFALGS) -o $@ $(SRC) $(LDFLAG)

git		:
			make fclean && git add . && git commit -m "update: handle free but still problem in expand more than one variable" && git push
clean	:
			@rm -fr $(OBJ)

fclean	:	clean
			@rm -fr $(OBJ) $(NAME)

re		:	fclean all