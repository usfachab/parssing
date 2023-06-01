/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:29:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 19:31:52 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct FILE_STRUCT
{
	char					*file_name;
	int						type;
	struct FILE_STRUCT		*next;
}	t_file;

typedef struct DATA_STRUCT
{
	char					**cmd_args;
	t_file					*file;
	struct DATA_STRUCT		*next;
}	t_data;

typedef struct LEXER_STRUCT
{
	char			c;
	unsigned int	i;
	char			*content;
}	t_lexer;

typedef struct TOKEN_STRUCT
{
	enum
	{
		TOKEN_STRING,
		TOKEN_PIPE,
		TOKEN_INFILE,
		TOKEN_OUTFILE,
		TOKEN_HDC,
		TOKEN_APPAND,
		TOKEN_AMBIGOUS
	} type;
	char *value;
}	t_token;

typedef struct PARSER_VARIABLES
{
	t_data	*data;
	t_lexer	*lexer;
	t_token	*token;
	t_file	*file;
	char	*command;
	char	**_command;
}	t_parser_var;

typedef struct EXPAND_VARIABLES
{
	char	*neo_value;
	char	*start;
	char	*end;
	char	*buffer;
	char	*variable;
	char	*head;
	char	*dollarsign;
	size_t	length;
	int		d__quote;
	int		s__quote;
} t_exp_var;

#endif