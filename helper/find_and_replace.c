/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:02:59 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/03 21:04:20 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	find_char_and_replace_with_unprintable(char *str)
{
	int	double_quote;
	int	single_quote;

	double_quote = 0;
	single_quote = 0;
	while (str && *str)
	{
		if (*str == '"')
			double_quote = !double_quote;
		if (*str == '\'')
			single_quote = !single_quote;
		if ((*str != '"' || *str != '\'') && (double_quote || single_quote))
		{
			if (*str == '|')
				*str = -1;
			if (*str == '<')
				*str = -2;
			if (*str == '>')
				*str = -3;
			if (*str == ' ')
				*str = -4;
		}
		str++;
	}
}

void	find_unprintable_and_replace_with_char(char *str)
{
	while (str && *str)
	{
		if (*str == -1)
			*str = '|';
		if (*str == -2)
			*str = '<';
		if (*str == -3)
			*str = '>';
		if (*str == -4)
			*str = ' ';
		str++;
	}
}

void	find_unprintable_replace_space(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{	
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == -1)
				str[i][j] = '|';
			if (str[i][j] == -2)
				str[i][j] = '<';
			if (str[i][j] == -3)
				str[i][j] = '>';
			if (str[i][j] == -4)
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
}
