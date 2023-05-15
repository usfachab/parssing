/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/15 23:34:13 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"
#include "include/parser.h"


int exit_status = 0;

int main(int argc, char *argv[], char *env[])
{
	(void)argc;(void)argv;
	while (1)
	{
		char	*input;
		input = readline("minishell -> ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		if (lexer(input))
		{
			t_data	*data = parser(input, env);
			execution(data);
		}
		free(input);
	}
	return (0);
}