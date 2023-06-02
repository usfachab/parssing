/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:41:46 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 23:44:47 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_special_character(char ch)
{
	char	*special_char;

	special_char = " \t\n\"\'$.-+|,!@#$%^&*(){}:;\\/?><~";
	if (strchr(special_char, ch))
		return (1);
	return (0);
}

char	*add_quote_to_variable(char *value)
{
	int		i;
	int		valen;
	char	*new_val;

	i = 0;
	valen = strlen(value);
	new_val = malloc(sizeof(char) * (valen + 3));
	new_val[i] = '\"';
	while (value[i])
	{
		if (value[i] == 32)
			new_val[i + 1] = -42;
		else
			new_val[i + 1] = value[i];
		i++;
	}
	new_val[i + 1] = '\"';
	new_val[i + 2] = '\0';
	//free(value);
	return (new_val);
}

int	variable_contain_white_space(char *variable)
{
	int	i;

	i = 0;
	while (_white_space(variable[i]))
		i++;
	while (variable[i])
	{
		if (_white_space(variable[i])
			&& !_white_space(variable[i + 1]) && variable[i + 1] != 0)
			return (1);
		i++;
	}
	return (0);
}
