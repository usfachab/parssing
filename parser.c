/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/24 20:59:39 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

// t_data	*init_data(t_lexer *lexer)
// {
// 	infile->infile = init_infile(lexer);
// 	outfile->outfile = init_outfile(lexer);
	
// }

int	count_pipe(char *input)
{
	int	i;
	int count;
	
	i = 0;
	count = 0;
	find_char_and_replace_with_unprintable(input);
	printf("input 1: %s\n", input);
	while (input[i])
	{
		if (input[i] == '|')
			count++;
		i++;
	}
	find_unprintable_and_replace_with_char(input);
	return (count);
}

t_data *parser(char *input, char **env)
{
	(void)env;
	t_data	*data;
	int number_of_pipe;
	
	number_of_pipe = count_pipe(input);
	while (number_of_pipe > 0)
	{
		ft_lstadd_back(&data, ft_lstnew(input));
		number_of_pipe--;
	}
	return (NULL);
}