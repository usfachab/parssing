/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/14 15:49:21 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

void	disable_echo_int(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (sig == SIGQUIT)
		rl_redisplay();
	else
		return ;
}

int	main(int argc, char *argv[], char *env[])
{
	char			*input;
	t_parser_var	*var;

	(void)argc;
	(void)argv;
	var = NULL;
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
	disable_echo_int();
	while (13)
	{
		input = readline("minishell -> ");
		if (!input || !strcmp(input, "exit"))
			exit(1);
		add_history(input);
		if (*input && syntax_err(input))
		{
			var = parser(input, env);
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
			reset(var);
		}
		free(input);
	}
	return (0);
}
