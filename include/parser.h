/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:29:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/08 02:30:03 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

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

typedef struct exec_STRUCT
{
	t_list	*env;
}	t_exec;

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
		TOKEN_APPAND,
		TOKEN_HDC,
		TOKEN_AMBIGOUS
	} e_type;
	char	*value;
}	t_token;

typedef struct PARSER_VARIABLES
{
	char	**env;
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
}	t_exp_var;

#endif