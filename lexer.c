/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:28:44 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/18 17:24:04 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

void	*unclosed_quote(char *input)
{
	int number_of_single_quotes;
	int number_of_double_quotes; 

	number_of_single_quotes = 0;
	number_of_double_quotes = 0;
	
	while (*input != '\0')
	{
		if (*input == '\'')
			number_of_single_quotes++;
		if (*input == '\"')
			number_of_double_quotes++;
		input++;	
	}
	if (number_of_single_quotes % 2 == 0 &&
		number_of_double_quotes % 2 == 0)
		return ("OK");
	return (NULL);
}

t_lexer *init_lexer(char *content)
{
	t_lexer	*lexer;

	lexer = malloc(sizeof(struct LEXER_STRUCT));
	if (!lexer)
		exit(EXIT_FAILURE);
	lexer->content = content;
	lexer->i = 0;
	lexer->c = content[lexer->i];
	return (lexer);
}

void	lexer_advence(t_lexer *lexer)
{
	if (lexer->c && lexer->i < strlen(lexer->content))
	{
		lexer->i += 1;
		lexer->c = lexer->content[lexer->i];
	}
}

void	lexer_skip_white_space(t_lexer *lexer)
{
	while ((lexer->c >= 9 && lexer->c <= 13) || lexer->c == 32)
		lexer_advence(lexer);
}

char	*lexer_collect_string(t_lexer *lexer)
{
	char	*string;
	int		len;

	string = NULL;
	len = 0;
	while ()
	{
		char	*tmp = malloc(len + 2);
		if (!tmp)
			exit(EXIT_FAILURE);
		if (string != NULL)
		{
			memcpy(tmp, string, len);
			free(string);
		}
		string = tmp;
		string[len] = lexer->c;
		string[len + 1] = '\0';
		len++;
		lexer_advence(lexer);
	}
	return (string);
}

void *lexer(char *input)
{
	if (!unclosed_quote(input))
		return (NULL);
	return ("OK");
}