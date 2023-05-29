/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/29 17:19:23 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

void *parser(char *input)
{
	//t_data	*data;
	t_lexer	*lexer;
	t_token *token;
	find_char_and_replace_with_unprintable(input);
	lexer = init_lexer(input);
	token = lexer_get_next_token(lexer);
	while (token)
	{
		find_unprintable_and_replace_with_char(token->value);
		//printf("TOKEN(%s, %d)\n", token->value, token->type);
		if (token->type == 0)
			printf("there is a command here\n");
		if (token->type != 0 && token->type != 1)
			printf("there is a file here\n");
		if (token->type == 1)
			ft_lstadd_back(&data, ft_lstnew_node(command, files));
		token = lexer_get_next_token(lexer);
	}

	return (ft_lstadd_back(&data, ft_lstnew_node(command, files)));
}

//ft_lstadd_back(&data, ft_lstnew_node(command, file));