/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:29:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/15 23:42:23 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct INFILE_STRUCT
{
	char					*infile;
	struct OUTFILE_STRUCT	*next;
}	t_infile;

typedef struct OUTFILE_STRUCT
{
	char					*outfile;
	struct OUTFILE_STRUCT	*next;
}	t_outfile;

typedef struct LEXER_STRUCT
{
	char			c;
	unsigned int	i;
	char			*content;
}	t_lexer;

typedef struct DATA_STRUCT
{
	char					*command;
	t_infile				*infile;
	t_outfile				*outfile;
	struct DATA_STRUCT		*next;
} t_data;

void	*lexer(char *input);
t_data	*parser(char *input, char **env);
void	execution(t_data *data);
#endif