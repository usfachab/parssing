#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "global.h"
/* --------------- current folder -----------------*/
void	*lexer(char *command);
void	*parser(char *command);
char    *expand_env_variables(char *command);
void	execution(t_data *data);
/* ----------------- src folder -------------------*/
void	find_char_and_replace_with_unprintable(char *str);
void	find_unprintable_and_replace_with_char(char *str);
void	ft_lstadd_back(void **lst, void *new);
t_data *ft_lstnew_node(char *command, t_file *files);
t_file	*ft_lstnew_subnode(char *content, int type);
char	**split(char *str, char del);
char	*_join(char *path, char *cmd);
/* ---------------- lexer.c file ------------------*/
t_lexer	*init_lexer(char *content);
t_token	*lexer_get_next_token(t_lexer *lexer);
/* ---------------- main.c file -------------------*/
void	execution(t_data *data);
void	*syntax_err(char *input);
#endif