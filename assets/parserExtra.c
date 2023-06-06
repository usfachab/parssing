/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserExtra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:25:58 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/06 15:18:34 by yachaab          ###   ########.fr       */
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

static char	which_quote(char *value)
{
	while (value && *value)
	{
		if (*value == '\'' || *value == '\"')
			return (*value);
		value++;
	}
	return (0);
}

char	*skip_quote(char *value)
{
	char	*tmp;
	char	*string;
	int		len;
	char	quote;

	string = NULL;
	len = 0;
	quote = which_quote(value);
	while (value && *value)
	{
		while (*value == quote)
			value++;
		tmp = malloc(len + 2);
		if (string != NULL)
		{
			memcpy(tmp, string, len);
			free(string);
		}
		string = tmp;
		string[len] = *value;
		string[len + 1] = '\0';
		len++;
		value++;
	}
	return (string);
}
