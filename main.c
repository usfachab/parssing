/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 23:35:46 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

// int	g_status = 0;
int	main(void)
{
	char			*input;
	t_data			*data;

	while (1)
	{
		input = readline("minishell -> ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		if (syntax_err(input))
		{
			input = expand_env_variables(input);
			data = parser(input);
			while (data)
			{
				int i = 0;
				while (data->cmd_args && data->cmd_args[i])
				{
					printf("command and args: %s\n", data->cmd_args[i]);
					i++;
				}
				while (data && data->file)
				{
					printf("file_name: %s | file_type: %d\n", data->file->file_name, data->file->type);
					data->file = data->file->next;
				}
				data = data->next;
			}
		}
		free(input);
	}
	return (0);
}
