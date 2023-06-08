/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/08 02:43:10 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"
int	main(void)
{
	int				exit_stat;
	char			*input;
	t_parser_var	*var;
	t_glob			*glob;

	var = NULL;
	exit_stat = 0;
	while (SIGQUIT)
	{
		input = readline("minishell -> ");
		if (!input || !strcmp(input, "exit"))
			exxit("exit", 0);
		add_history(input);
		find_char_and_replace_with_unprintable(input);
		if (syntax_err(input))
		{
			find_unprintable_and_replace_with_char(input);
			var = parser(input, glob->env);
			execution(var->data);
		}
		free(input);
	}
	return (0);
}
			// while (var->data)
			// {
			// 	int i = 0;
			// 	while (var->data->cmd_args && var->data->cmd_args[i])
			// 	{
			// 		printf("command and args:%s\n", var->data->cmd_args[i]);
			// 		i++;
			// 	}
			// 	while (var->data && var->data->file)
			// 	{
			// 		printf("file_name: %s | file_type: %d\n",
			// 		var->data->file->file_name, var->data->file->type);
			// 		var->data->file = var->data->file->next;
			// 	}
			// 	printf("------------ next command ----------\n");
			// 	var->data = var->data->next;
			// }