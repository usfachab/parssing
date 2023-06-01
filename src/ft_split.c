/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:18:38 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 12:38:44 by yachaab          ###   ########.fr       */
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

char *collect_string(char *str, char del, int *i)
{
	int 		len;
	char		*string;
	
	len = 0;
	string = NULL;
	while (str[*i] == del)
		*i += 1;
	while (str[*i] != del && str[*i] != '\0')
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
		string[len] = str[*i];
		string[len + 1] = '\0';
		len++;
		*i += 1;
	}
	return (string);
}
char	**split(char *str, char del)
{
	int			i;
	int			index;
	char 		**word;
	char		*string;

	index = 0;
	i = 0;
	word = malloc(sizeof(char *) * (count_word(str, del) + 1));
	if (!word)
		return (NULL);
	while (index < count_word(str, del))
	{
		string = collect_string(str, del, &i);
		word[index] = string;
		index++;
	}
	word[index] = NULL;
	return (word);
}


// char	**ft_free(char **word)
// {
// 	int	i;

// 	i = 0;
// 	while (word[i])
// 	{
// 		free(word[i]);
// 		i++;
// 	}	
// 	free(word);
// 	return (NULL);
// }

// int	count_word(const char *string, char delim)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	if (!string)
// 		return (0);
// 	while (string[i])
// 	{
// 		if (string[i] != delim
// 			&& (string[i + 1] == delim || string[i + 1] == '\0'))
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// char	**word_alloc(const char *s, char d)
// {
// 	char	**word;
	
// 	word = (char **)malloc(sizeof(char *) * count_word(s, d) + 1);
// 	return (word);
// }

// char	*str_cpy(const char *string, int size)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = malloc(sizeof(char) * size + 1);
// 	if (!ptr)
// 		return (0);
// 	while (i < size)
// 	{
// 		ptr[i] = *string;
// 		i++;
// 		string++;
// 	}
// 	return (ptr);
// }

// char	**split(const char *string, char delim)
// {
// 	int		i;
// 	int		index;
// 	int		size;
// 	int		char_index;
// 	char	**word;

// 	i = 0;
// 	index = -1;
// 	word = word_alloc(string, delim);
// 	if (!word)
// 		return (NULL);
// 	while (++index < count_word(string, delim))
// 	{
// 		while (string[i] == delim)
// 			i++;
// 		char_index = i;
// 		size = 0;
// 		i--;
// 		while (string[++i] != delim && string[i])
// 			size++;
// 		word[index] = str_cpy(string + char_index, size);
// 		if (word[index] == NULL)
// 			return (ft_free(word));
// 	}
// 	return (word);
// }