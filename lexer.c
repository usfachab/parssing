/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:28:44 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/15 23:41:25 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *new_line_after_identifier(char *input)
{
	while (*input != '0')
	{
		if (*input == '|' && *(input++) == '\n')
		{
			exit_status = 258;
			return (NULL);
		}
		if (*input == '<' && *(input++) == '\n')
		{
			exit_status = 258;
			return (NULL);
		}
		if (*input == '>' && *(input++) == '\n')
		{
			exit_status = 258;
			return (NULL);
		}
	}
	return ("OK");
}

void *lexer(char *input)
{
	if (!new_line_after_identifier)
		return (NULL);
}