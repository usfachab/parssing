/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/08 02:03:23 by yachaab          ###   ########.fr       */
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
	return (var);
}

void	collect_command(t_parser_var	*var)
{

	if (var->token->e_type == 0)
	{
		find_unprintable_and_replace_with_char(var->token->value);
		if (strchr(var->token->value, '$'))
			var->token->value = expand_env_variables(var->token->value, var->env);
		variable_reverce_42(var->token->value);
		var->command = _join(var->command, var->token->value);
		free(var->token->value);
	}
}

void	save_file(t_parser_var	*var)
{

	if (var->token->e_type != 0 && var->token->e_type != 1 && var->token->e_type != 5)
	{
		char	*hold = NULL;
		if (strchr(var->token->value, '$'))
		{
			var->token->value = expand_env_variables(var->token->value, var->env);
			if (variable_contain_42(var->token->value))
				var->token->e_type = -1;
		}
		if (strchr(var->token->value, '\'') || strchr(var->token->value, '\"'))
		{
			hold = skip_quote(var->token->value);
			free(var->token->value);
			var->token->value = hold;
		}
		find_unprintable_and_replace_with_char(var->token->value);
		ft_lstadd_back_subnode(&(var->file),
			ft_lstnew_subnode(var->token->value, var->token->e_type));
	}
}

t_parser_var	*parser(char *input, char **env)
{
	t_parser_var	*var;
	char			*skipped;

	find_char_and_replace_with_unprintable(input);
	var = init_var(input, env);
	while (var->token)
	{
		collect_command(var);
		save_file(var);
		if (var->token->e_type == 5)
		{
			find_unprintable_and_replace_with_char(var->token->value);
			ft_lstadd_back_subnode(&(var->file),
				ft_lstnew_subnode(var->token->value, var->token->e_type));
		}
		if (var->token->e_type == 1 ||!var->lexer->c)
		{
			if (var->lexer->c)
				free(var->token->value);
			find_char_and_replace_with_unprintable(var->command);
			skipped = skip_quote(var->command);
			var->_command = split(skipped, ' ');
			free(skipped);
			find_unprintable_replace_space(var->_command);
			ft_lstadd_back_node(&(var->data),
				ft_lstnew_node(var->_command, var->file));
			free(var->command);
			var->command = strdup("");
			var->file = NULL;
		}
		free(var->token);

		var->token = lexer_get_next_token(var->lexer);
	}
	return (var);
}
