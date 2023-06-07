NAME	=	lexer

CC		=	gcc

CFALGS	=	-Wextra -Werror -Wall

LDFLAG	=	-lreadline -I/Users/yachaab/.brew/Cellar/readline/8.2.1/lib/ -L/Users/yachaab/.brew/Cellar/readline/8.2.1/lib/

SRC		=	main.c assets/lexer.c assets/parser.c assets/parserExtra.c assets/syntax.c assets/__syntax.c \
			assets/expand.c assets/extra.c assets/token.c helper/find_and_replace.c helper/ft_split.c \
			helper/ft_strjoin.c helper/node_list.c helper/nodeListExtra.c

OBJ		=	$(SRC:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			@$(CC) $(CFALGS) -o $@ $(SRC) $(LDFLAG)

%.o		:	%.c
			@$(CC) $(CFALGS) -o $@ $(SRC) $(LDFLAG)

git		:
			make fclean && git add . && git commit -m "update: handle skipping quotes" && git push
clean	:
			@rm -fr $(OBJ)

fclean	:	clean
			@rm -fr $(OBJ) $(NAME)

re		:	fclean all