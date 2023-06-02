NAME = lexer

CC = cc

CFALGS = -g #-Wextra -Werror -Wall -fsanitize=address

LDFLAG = -lreadline -I/Users/yachaab/.brew/Cellar/readline/8.2.1/lib/ -L/Users/yachaab/.brew/Cellar/readline/8.2.1/lib/

SRC = main.c assets/lexer.c assets/parser.c assets/syntax.c assets/__syntax.c assets/expand.c assets/extra.c assets/token.c src/find_and_replace.c src/ft_split.c src/ft_strjoin.c src/node_list.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFALGS) -o $@ $(SRC) $(LDFLAG)

%.o : %.c
	@$(CC) $(CFALGS) -o $@ $(SRC) $(LDFLAG)
clean :
	@rm -fr $(OBJ)

fclean : clean
	@rm -fr $(OBJ) $(NAME)

re : fclean all