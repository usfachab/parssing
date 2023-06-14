/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserExtra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:25:58 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/14 15:38:47 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	variable_contain_42(char *value)
{
	while (value && *value)
	{
		if (*value == -42)
			return (1);
		value++;
	}
	return (0);
}

void	variable_reverce_42(char *value)
{
	while (value && *value)
	{
		if (*value == -42)
			*value = 32;
		value++;
	}
}

char	*skip_white_space(char *input)
{
	while (input && ((*input >= 9 && *input <= 13) || *input == 32))
		input++;
	return (input);
}

void	save_file(t_parser_var	*var)
{
	char	*hold;

	hold = NULL;
	if (var->token->e_type != 0 && var->token->e_type != 1
		&& var->token->e_type != 5)
	{
		if (strchr(var->token->value, '$'))
			expand_in_save_file(var);
		if (strchr(var->token->value, '\'') || strchr(var->token->value, '\"'))
			var->token->value = remove_quote(var);
		find_unprintable_and_replace_with_char(var->token->value);
		ft_lstadd_back_subnode(&(var->file),
			ft_lstnew_subnode(var->token->value, var->token->e_type));
	}
}

void	save_heredoc(t_parser_var *var)
{
	if (var->token->e_type == 5)
	{
		if (strchr(var->token->value, '\'') || strchr(var->token->value, '\"'))
			var->token->value = remove_quote(var);
		find_unprintable_and_replace_with_char(var->token->value);
		ft_lstadd_back_subnode(&(var->file),
			ft_lstnew_subnode(var->token->value, var->token->e_type));
	}
}
