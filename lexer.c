/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 23:28:44 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/29 15:06:56 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

t_token *init_token(int type, char *value)
{
	t_token *token;

	token = malloc(sizeof(struct TOKEN_STRUCT));
	if (!token)
		exit(EXIT_FAILURE);
	token->type = type;
	token->value = value;
	return (token);
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

int	identifier(t_lexer *lexer)
{
	if (lexer->c == '|' || lexer->c == '<'|| lexer->c == '>' || lexer->c == '\0' || lexer->c == '\n')
		return (1);
	return (0);
}

t_token	*lexer_advence_with_token(t_lexer *lexer, t_token *token)
{
	lexer_advence(lexer);
	return (token);
}

char	*lexer_char_as_string(t_lexer *lexer)
{
	char	*string;

	string = malloc(2 * sizeof(char));
	if (!string)
		exit(EXIT_FAILURE);
	string[0] = lexer->c;
	string[1] = '\0';
	return (string);
}

char	*lexer_collect_string(t_lexer *lexer)
{
	char	*string;
	int		len;

	string = NULL;
	len = 0;
	while (!identifier(lexer))
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

char *lexer_collect_file_name(t_lexer *lexer)
{
	char	*string;
	int		len;

	string = NULL;
	len = 0;
	lexer_skip_white_space(lexer);
	while (!identifier(lexer) && lexer->c != ' ')
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

t_token	*lexer_collect_identifier(t_lexer *lexer)
{
	if (lexer->c == '<')
	{
		lexer_advence(lexer);
		if (lexer->c == '<')
		{
			lexer_advence(lexer);
			return (init_token(TOKEN_HDC, lexer_collect_file_name(lexer)));
		}
		return(init_token(TOKEN_INFILE, lexer_collect_file_name(lexer)));
	}
	else if (lexer->c == '>')
	{
		lexer_advence(lexer);
		if (lexer->c == '>')
		{
			lexer_advence(lexer);
			return (init_token(TOKEN_APPAND, lexer_collect_file_name(lexer)));
		}
		return(init_token(TOKEN_OUTFILE, lexer_collect_file_name(lexer)));
	}
	return (NULL);
}


t_token	*lexer_get_next_token(t_lexer *lexer)
{
	while (lexer->c && lexer->i < strlen(lexer->content))
	{
		if ((lexer->c >= 9 && lexer->c <= 13) || lexer->c == 32)
			lexer_advence(lexer);
		if (lexer->c == '<' || lexer->c == '>')
			return (lexer_collect_identifier(lexer));
		if (lexer->c == '|')
			return (lexer_advence_with_token(lexer, init_token(TOKEN_PIPE, lexer_char_as_string(lexer))));
		else 
			return (init_token(TOKEN_STRING, lexer_collect_string(lexer)));
	}
	return (NULL);
}
