/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:11:11 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/03 17:11:11 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include "parser.h"
/* ----------------------------- parser  --------------------------------*/
t_parser_var	*parser(char *command, char **env);
/* ----------------------------- parserExtra  ---------------------------*/
int				variable_contain_42(char *value);
void			variable_reverce_42(char *value);
char			*skip_white_space(char *input);
char			*skip_quote(char *value, t_skip_quote *skip);
char			*get_env_variable(char *buffer, char **env);
void			save_file(t_parser_var	*var);
void			save_heredoc(t_parser_var *var);
void			expand_in_save_file(t_parser_var *var);
/* ----------------------------- src folder -----------------------------*/
void			find_char_and_replace_with_unprintable(char *str);
void			find_unprintable_and_replace_with_char(char *str);
void			find_unprintable_replace_space(char **str);
t_data			*ft_lstnew_node(char **command, t_file *files);
t_file			*ft_lstnew_subnode(char *content, int type);
void			ft_lstadd_back_node(t_data **lst, t_data *new);
void			ft_lstadd_back_subnode(t_file **lst, t_file *new);
char			*_join(char *path, char *cmd);
char			**split(char *str, char del);
/* ---------------------------- lexer -----------------------------------*/
t_lexer			*init_lexer(char *content);
char			*lexer_collect_string(t_lexer *lexer);
char			*lexer_collect_file_name(t_lexer *lexer);
void			lexer_advence(t_lexer *lexer);
void			lexer_skip_white_space(t_lexer *lexer);
/* ---------------------------- token -----------------------------------*/
t_token			*lexer_get_next_token(t_lexer *lexer);
t_token			*lexer_collect_identifier(t_lexer *lexer);
t_token			*lexer_advence_with_token(t_lexer *lexer, t_token *token);
t_token			*init_token(int type, char *value);
/* ---------------------------- expand ----------------------------------*/
char			*expand_env_variables(char *command, char **env);
int				variable_contain_white_space(char *variable);
char			*read_buffer(t_exp_var *exp, char *value, char **env);
/* ---------------------------- syntax ----------------------------------*/
void			*syntax_err(char *input);
void			*redirection_error(char *input);
void			*unclosed_quote(char *input);
char			*skip_white_space(char *input);
void			*white_space_only(char *input);
/* ---------------------------- extra -----------------------------------*/
int				_white_space(char c);
int				is_special_character(char ch);
int				variable_contain_white_space(char *variable);
char			*add_quote_to_variable(char *value);
void			lexer_skip_white_space(t_lexer *lexer);
/* ---------------------------- nodeListExtra ---------------------------*/
void			*ft_lstlast_subnode(t_file *lst);
void			*ft_lstlast_node(t_data *lst);
/* ---------------------------- ExitStat --------------------------------*/
void			reset(t_parser_var *var);
/* ---------------------------- SkipQuote --------------------------------*/
char			which_quote(char *value);
char			*remove_quote(t_parser_var *var);
t_skip_quote	*init_skip_quote(char *value);
#endif