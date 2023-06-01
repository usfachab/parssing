/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:02:59 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 15:27:15 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	find_char_and_replace_with_unprintable(char *str)
{
	int	doubleQuote;
	int	singleQuote;

	doubleQuote = 0;
	singleQuote = 0;
	while (str && *str)
	{
		if (*str == '"')
			doubleQuote = !doubleQuote;
		if (*str == '\'')
			singleQuote = !singleQuote;
		if ((*str != '"' || *str != '\'') && (doubleQuote || singleQuote))
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
	// int	doubleQuote;
	// int	singleQuote;

	// doubleQuote = 0;
	// singleQuote = 0;
	while (str && *str)
	{
		// if (*str == '"')
		// 	doubleQuote = !doubleQuote;
		// if (*str == '\'')
		// 	singleQuote = !singleQuote;
		// if ((*str != '"' || *str != '\'') && (doubleQuote || singleQuote))
		// {
		if (*str == -1)
			*str = '|';
		if (*str == -2)
			*str = '<';
		if (*str == -3)
			*str = '>';
		if (*str == -4)
			*str = ' ';
		// }
		str++;
	}
}

// void	find_space_replace_unprintable(char *str)
// {
// 	int	doubleQuote;
// 	int	singleQuote;

// 	doubleQuote = 0;
// 	singleQuote = 0;
// 	while (str && *str)
// 	{
// 		if (*str == '"')
// 			doubleQuote = !doubleQuote;
// 		if (*str == '\'')
// 			singleQuote = !singleQuote;
// 		if (doubleQuote || singleQuote)
// 		{
// 			if (*str == 32)
// 				*str = -4;
// 			printf("xnxx\n");
// 		}
// 		str++;
// 	}
// }

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
			if (str[i][j] == -4)
				str[i][j] = ' ';
			j++;
		}
		i++;
	}
}