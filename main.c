/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/07 15:41:01 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"
void	signal_handler(int num)
{
	exit(num);
}
// int	g_status = 0;
int	main(void)
{
	char			*input;
	t_parser_var	*var;

	var = NULL;
	signal(SIGINT, signal_handler);
	while (SIGQUIT)
	{
		input = readline("minishell -> ");
		if (!input || !strcmp(input, "exit"))
			exit(EXIT_FAILURE);
		add_history(input);
		find_char_and_replace_with_unprintable(input);
		if (syntax_err(input))
		{
			find_unprintable_and_replace_with_char(input);
			var = parser(input);
			while (var->data)
			{
				int i = 0;
				while (var->data->cmd_args && var->data->cmd_args[i])
				{
					printf("command and args:%s\n", var->data->cmd_args[i]);
					i++;
				}
				while (var->data && var->data->file)
				{
					printf("file_name: %s | file_type: %d\n",
					var->data->file->file_name, var->data->file->type);
					var->data->file = var->data->file->next;
				}
				printf("------------ next command ----------\n");
				var->data = var->data->next;
			}
		}
		free(input);
	}
	return (0);
}