/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 23:46:45 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

char	*skip_white_space(char *input)
{
	while ((*input >= 9 && *input <= 13) || *input == 32)
		input++;
	return (input);
}

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

t_data	*parser(char *input)
{
	t_parser_var	*var;

	var = init_var(input);
	find_char_and_replace_with_unprintable(input);
	while (var->token)
	{
		find_unprintable_and_replace_with_char(var->token->value);
		if (var->token->type == 0)
			var->command = _join(var->command, var->token->value);
		if (var->token->type != 0 && var->token->type != 1)
			ft_lstadd_back_subnode(&(var->file),
				ft_lstnew_subnode(var->token->value, var->token->type));
		if (var->token->type == 1 ||!var->lexer->c)
		{
			find_char_and_replace_with_unprintable(var->command);
			var->_command = split(var->command, ' ');
			find_unprintable_replace_space(var->_command);
			ft_lstadd_back_node(&(var->data),
				ft_lstnew_node(var->_command, var->file));
			var->file = NULL;
			var->command = strdup("");
		}
		var->token = lexer_get_next_token(var->lexer);
	}
	return (var->data);
}
