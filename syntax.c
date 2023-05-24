/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:38:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/24 19:56:48 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

void	*unclosed_quote(char *input)
{
	int	i;
	char quote;

	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			quote = input[i];
			i++;
			while (input[i] != quote || !input[i])
			{
				if (input[i] == quote)
					break;
				else if (!input[i])
				{
					printf("Syntax error near to %c\n", quote);
					return (NULL);
				}
				i++;
			}
		}
		i++;
	}
	return ("OK");
}

char 	*skip_white_space(char *input)
{
	while ((*input >= 9 && *input <= 13) || *input == 32)
		input++;
	return (input);
}

void	*search_for_identifier_form_front(char *input, char id)
{
	input = skip_white_space(input);
	if (*input == id)
	{
		printf("syntax error near to token %c\n", id);
		return (NULL);
	}
	return ("OK");
}

void	*search_for_identifier_form_back(char *input, char id)
{
	int len;
	
	len = strlen(input) - 1;
	while (((input[len] >= 9 && input[len] <= 13) || input[len] == 32)  && len >= 0)
		len--;
	if (input[len] == id)
	{
		printf("syntax error near to token %c\n", id);
		return (NULL);
	}
	return ("OK");
}

void	*double_identifier(char *input, char id)
{
	while (*input)
	{
		if (*input == id)
		{
			input++;
			if (!search_for_identifier_form_front(input, id))
				return (NULL);
		}
		input++;
	}
	return ("OK");
}

void *pipe_err(char *input)
{
	if (!search_for_identifier_form_front(input, '|'))
		return (NULL);
	if (!search_for_identifier_form_back(input, '|'))
		return (NULL);
	if (!double_identifier(input, '|'))
		return (NULL);
	return ("OK");
}

int redirection(char *input)
{
    if (*input == '>')
       input++;
    else if ( *input == '<')
        input++;
    else
        return 0;
    return 1;
}

void	*redirection_error(char *input)
{
	while (*input)
    {
		if (*input == '<')
		{
			input++;
			if (*input == '<')
				input++;
			input = skip_white_space(input);
			if (!(*input) || *input == '|' || (*input == '<' || *input == '>'))
			{
				printf("syntax error on redirections\n");
				return (NULL);
			}
		}
		else if (*input == '>')
		{
			input++;
			if (*input == '>')
				input++;
			input = skip_white_space(input);
			if (!(*input) || *input == '|' || (*input == '>' || *input == '<'))
			{
				printf("syntax error on redirections\n");
				return (NULL);
			}
		}
		input++;
	}
    return ("OK");
}

void *syntax_err(char *input)
{	

	if (!unclosed_quote(input))
		return (NULL);
	if (!pipe_err(input))
		return (NULL);
	if (!redirection_error(input))
		return (NULL);
	return ("OK");
}