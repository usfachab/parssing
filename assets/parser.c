/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/14 15:40:54 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

static t_parser_var	*init_var(char *input, char **env)
{
	t_parser_var	*var;

	var = malloc(sizeof(t_parser_var));
	if (!var)
		exit(1);
	var->env = env;
	var->data = NULL;
	var->lexer = init_lexer(input);
	var->token = lexer_get_next_token(var->lexer);
	var->file = NULL;
	var->command = strdup("");
	var->_command = NULL;
	var->skip = init_skip_quote(input);
	return (var);
}

void	expand_in_save_file(t_parser_var *var)
{
	char	*exp;

	exp = NULL;
	find_unprintable_and_replace_with_char(var->token->value);
	exp = expand_env_variables(var->token->value, var->env);
	if (exp != var->token->value)
	{
		free(var->token->value);
		var->token->value = strdup(exp);
		free(exp);
	}
	find_char_and_replace_with_unprintable(var->token->value);
	if (variable_contain_42(var->token->value))
		var->token->e_type = -1;
}

void	collect_command(t_parser_var *var)
{
	char	*exp;

	if (var->token->e_type == 0)
	{
		exp = NULL;
		if (strchr(var->token->value, '$'))
			expand_in_save_file(var);
		variable_reverce_42(var->token->value);
		if (strchr(var->token->value, '\'') || strchr(var->token->value, '\"'))
			var->token->value = remove_quote(var);
		var->command = _join(var->command, var->token->value);
		free(var->token->value);
	}
}

void	create_node(t_parser_var *var)
{
	if (var->token->e_type == 1 ||!var->lexer->c)
	{
		if (var->lexer->c)
			free(var->token->value);
		find_char_and_replace_with_unprintable(var->command);
		var->_command = split(var->command, ' ');
		find_unprintable_replace_space(var->_command);
		ft_lstadd_back_node(&(var->data),
			ft_lstnew_node(var->_command, var->file));
		free(var->command);
		var->command = strdup("");
		var->file = NULL;
	}
}

t_parser_var	*parser(char *input, char **env)
{
	t_parser_var	*var;

	var = NULL;
	find_char_and_replace_with_unprintable(input);
	var = init_var(input, env);
	while (var->token)
	{
		collect_command(var);
		save_file(var);
		save_heredoc(var);
		create_node(var);
		free(var->token);
		var->token = lexer_get_next_token(var->lexer);
	}
	return (var);
}
