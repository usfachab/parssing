/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserExtra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:25:58 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/03 17:34:30 by yachaab          ###   ########.fr       */
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
