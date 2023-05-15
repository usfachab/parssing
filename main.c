/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:26:45 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/15 21:28:21 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	while (1)
	{
		char	*input;
		input = readline("minishell -> ");
		if (!input)
			exit(EXIT_FAILURE);
		add_history(input);
		find_char_and_replace(input);
		free(input);
	}
	return (0);
}