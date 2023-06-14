/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skipQuote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:51:39 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/14 15:41:31 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

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

t_skip_quote	*init_skip_quote(char *value)
{
	t_skip_quote	*skip;

	skip = malloc(sizeof(t_skip_quote));
	skip->num_of_quote = 0;
	skip->string = NULL;
	skip->len = 0;
	skip->quote = which_quote(value);
	return (skip);
}

static char	*fn(char *value, t_skip_quote *skip)
{
	while (*value == skip->quote && skip->quote != '\0')
	{
		skip->num_of_quote += 1;
		if (skip->num_of_quote % 2 == 0 && skip->num_of_quote > 0)
		{
			skip->quote = which_quote(value + 1);
			skip->num_of_quote = 1;
		}
		value++;
	}
	return (value);
}

char	*skip_quote(char *value, t_skip_quote *skip)
{
	while (value && *value)
	{
		value = fn(value, skip);
		skip->tmp = malloc(skip->len + 2);
		if (skip->string != NULL)
		{
			memcpy(skip->tmp, skip->string, skip->len);
			free(skip->string);
		}
		skip->string = skip->tmp;
		skip->string[skip->len] = *value;
		skip->string[skip->len + 1] = '\0';
		skip->len++;
		if (*value == '\0')
			return (skip->string);
		value++;
	}
	return (skip->string);
}

char	*remove_quote(t_parser_var *var)
{
	char	*hold;

	if (strchr(var->token->value, '\'') || strchr(var->token->value, '\"'))
	{	
		hold = skip_quote(var->token->value, var->skip);
		free(var->token->value);
		var->token->value = hold;
	}
	return (var->token->value);
}
