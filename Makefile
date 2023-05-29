NAME = lexer

CC = cc

CFALGS = -Wextra -Werror -Wall

LDFLAG = -lreadline -I/Users/yachaab/.brew/Cellar/readline/8.2.1/lib/ -L/Users/yachaab/.brew/Cellar/readline/8.2.1/lib/

SRC = main.c lexer.c parser.c syntax.c expand.c src/find_and_replace.c src/ft_split.c src/ft_strjoin.c

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