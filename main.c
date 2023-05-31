/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/31 20:38:17 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

int exit_status = 0;

void	execution(t_data *data)
{
	(void)data;
	//printf("exec\n");
}
int main()
{
	while (1)
	{
		char	*input;
		input = readline("minishell -> ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		if (syntax_err(input))
		{
			input = expand_env_variables(input);
			t_data	*data = parser(input);
			while (data)
			{
				printf("command and args: %s\n", data->cmd_args);
				while (data->file)
				{
					printf("file_name: %s | file_type: %d\n", data->file->file_name, data->file->type);
					data->file = data->file->next;
				}
				data = data->next;
			}
			execution(data);
		}
		free(input);
	}
	return (0);
}
