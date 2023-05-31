/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:02:59 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/31 15:52:31 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		}
		str++;
	}
}

void	find_unprintable_and_replace_with_char(char *str)
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
			if (*str == -1)
				*str = '|';
			if (*str == -2)
				*str = '<';
			if (*str == -3)
				*str = '>';
		}
		str++;
	}
}