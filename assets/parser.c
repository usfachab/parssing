/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/06 15:15:11 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

t_parser_var	*init_var(char *input)
{
	t_parser_var	*var;

	var = malloc(sizeof(t_parser_var));
	if (!var)
		exit(1);
	var->data = NULL;
	var->lexer = init_lexer(input);
	var->token = lexer_get_next_token(var->lexer);
	var->file = NULL;
	var->command = strdup("");
	var->_command = NULL;
	return (var);
}

char	which_quote(char *value)
{
	while (value && *value)
	{
		if (*value == '\'' || *value == '\"')
			return (*value);
		value++;
	}
	return (0);
}

void	collect_command(t_parser_var	*var)
{
	if (var->token->e_type == 0)
	{
		if (strchr(var->token->value, '$'))
			var->token->value = expand_env_variables(var->token->value);
		variable_reverce_42(var->token->value);
		var->command = _join(var->command, var->token->value);
	}
}

void	save_file(t_parser_var	*var)
{
	char	*hold;

	if (var->token->e_type != 0 && var->token->e_type != 1)
	{
		if (var->token->e_type != 5 && strchr(var->token->value, '$'))
		{
			var->token->value = expand_env_variables(var->token->value);
			if (variable_contain_42(var->token->value))
				var->token->e_type = -1;
		}
		hold = skip_quote(var->token->value);
		free(var->token->value);
		find_unprintable_and_replace_with_char(hold);
		ft_lstadd_back_subnode(&(var->file),
			ft_lstnew_subnode(hold, var->token->e_type));
	}
}

t_parser_var	*parser(char *input)
{
	t_parser_var	*var;

	find_char_and_replace_with_unprintable(input);
	var = init_var(input);
	while (var->token)
	{
		collect_command(var);
		save_file(var);
		if (var->token->e_type == 1 ||!var->lexer->c)
		{
			var->_command = split(skip_quote(var->command), ' ');
			find_unprintable_replace_space(var->_command);
			ft_lstadd_back_node(&(var->data),
				ft_lstnew_node(var->_command, var->file));
			free(var->command);
			var->command = strdup("");
			var->file = NULL;
		}
		var->token = lexer_get_next_token(var->lexer);
	}
	return (var);
}
