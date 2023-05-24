/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:18:38 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/22 21:17:55 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	count_word(const char *string, char delim)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] != delim
			&& (string[i + 1] == delim || string[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char *collect_string(char *str, char del)
{
	static int	i;
	int len;
	char *string;
	
	len = 0;
	string = NULL;
	while (str[i] == del)
		i++;
	while (str[i] != del && str[i] != '\0')
	{
		char	*tmp = malloc(len + 2);
		if (!tmp)
			return (NULL);
		if (string != NULL)
		{
			memcpy(tmp, string, len);
			free(string);
		}
		string = tmp;
		string[len] = str[i];
		string[len + 1] = '\0';
		len++;
		i++;
	}
	return (string);
}
char **split(char *str, char del)
{
	int			index;
	char 		**word;
	char		*string;

	index = 0;
	word = malloc(sizeof(char *) * count_word(str, del) + 1);
	if (!word)
		return (NULL);
	while (index < count_word(str, del))
	{
		string = collect_string(str, del);
		word[index] = string;
		index++;
	}
	word[index] = NULL;
	return (word);
}