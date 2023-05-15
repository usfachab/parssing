/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:29:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/15 21:41:47 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct INFILE_STRUCT
{
	char	*infile;
}	t_infile;

typedef struct OUTFILE_STRUCT
{
	char	*outfile;
}	t_outfile;

typedef struct COMMAND_STRUCT
{
	char					*command;
	t_infile				*infile;
	t_outfile				*outfile;
	struct COMMAND_STRUCT	*next;
} t_command;

typedef struct LEXER_STRUCT
{
	char			c;
	unsigned int	i;
	char			*content;
}	t_lexer;

#endif