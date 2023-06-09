/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:33:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/03 22:33:13 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

void reset(t_parser_var *var)
{
	int i;
	if (var)
	{
		while (var->data)
		{
			i = 0;
			while (var->data->cmd_args && var->data->cmd_args[i])
			{
				free(var->data->cmd_args[i]);
				i++;
			}
			while (var->data && var->data->file)
			{
				t_file	*file_next = var->data->file->next;
				free(var->data->file->file_name);
				free(var->data->file);
				var->data->file = file_next;
			}
			t_data *data_next = var->data->next;
			free(var->data->cmd_args);
			free(var->data);
			var->data = data_next;
		}
		free(var->command);
		free(var->file);
		free(var->lexer);
		free(var->token);
		free(var->data);
		free(var);
	}
}