/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expandExtra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:03:32 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/14 00:24:20 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

char	*read_buffer(t_exp_var *exp, char *value, char **env)
{
	if (exp->buffer)
	{
		exp->variable = get_env_variable(exp->buffer, env);
		free(exp->buffer);
		exp->buffer = NULL;
	}
	if ((*value == '$' && (*(value + 1) == '?')))
	{
		value = value + 1;
		exp->start = value;
		exp->variable = "xxxx";
		exp->end = value + 1;
		exp->length = 1;
	}
	return (value);
}
