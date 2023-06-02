/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:57:34 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 11:54:19 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"


size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*_join(char *path, char *cmd)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	i = 0;
	ptr = malloc(ft_strlen(path) + ft_strlen(cmd) + 3);
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(path))
	{
		ptr[i] = path[i];
		i++;
	}
	ptr[i] = ' ';
	i++;
	ptr[i] = 0;
	j = 0;
	while (j < ft_strlen(cmd))
	{
		ptr[i + j] = cmd[j];
		j++;
	}
	ptr[i + j] = 0;
	return (ptr);
}