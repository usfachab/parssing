/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:48:06 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/31 20:39:14 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lib.h"

// int is_special_character(char ch) {
// 	char *specialChar;

// 	specialChar = " \t\n\"\'$.-+|,!@#$%^&*(){}:;\\/?><~";
// 	if (strchr(specialChar, ch))
// 		return (1);
// 	return (0);
// }

// char *get_env_variable(char *name) {
// 	extern char **environ;
// 	char **env = environ;
// 	size_t len = strlen(name);

// 	while (*env != NULL) {
// 		if (strncmp(name, *env, len) == 0 && (*env)[len] == '=') {
// 			return &(*env)[len + 1];
// 		}
// 		env++;
// 	}
// 	return NULL;
// }

// char	*expand(char *value)
// {
// 	size_t	length;
// 	char	*start = NULL;
// 	char	*end = NULL;
// 	char	*buffer = NULL;
// 	char	*variable = NULL;
// 	char	*head;
// 	int		d__quote;
// 	int		s__quote;
	
// 	d__quote = 0;
// 	s__quote = 0;
// 	head = value;
// 	while (value && *value)
// 	{
// 		if (*value == '"')
// 			d__quote = !d__quote;
// 		if (*value == '\'')
// 			s__quote = !s__quote;
// 		if (*value == '$' && (d__quote || (!d__quote && !s__quote)))
// 		{
// 			start = value + 1;
// 			end = start;
// 			while (!is_special_character(*end))
// 				end++;
// 			length = end - start;
// 			buffer = malloc(length + 1);
// 			memcpy(buffer, start, length);
// 			buffer[length] = 0;
// 		}
// 		if (buffer)
// 		{
// 			variable = get_env_variable(buffer);
// 			free(buffer);
// 			buffer = NULL;
// 		}
// 		if (variable)
// 		{
// 			char	*neo_value;

// 			neo_value = malloc((strlen(head) - (length + 1)) + strlen(variable));
// 			memcpy(neo_value, head, start - head);
// 			memcpy(neo_value + (start - head - 1), variable, strlen(variable));
// 			memcpy(neo_value + ((start - head - 1) + strlen(variable)), end , strlen(end));
// 			neo_value[(strlen(head) - (length + 1)) + strlen(variable)] = 0;
// 			head = strdup(neo_value);
// 			value = head;
// 			free(neo_value);
// 			variable = NULL;
// 		}
// 	 	value++;
// 	}
// 	return (head);
// }

t_data *parser(char *input)
{
	t_data	*data;
	t_lexer	*lexer;
	t_token *token;
	t_file	*file;
	
	file = NULL;
	data = NULL;
	char *command = strdup("");
	//find_char_and_replace_with_unprintable(input);
	lexer = init_lexer(input);
	token = lexer_get_next_token(lexer);
	while (token)
	{
		//find_unprintable_and_replace_with_char(token->value);
		if (token->type == 0)
			command = _join(command, token->value);
		if (token->type != 0 && token->type != 1)
			ft_lstadd_back_subnode(&file, ft_lstnew_subnode(token->value, token->type));
		if (token->type == 1 ||!lexer->c)
		{
			ft_lstadd_back_node(&data, ft_lstnew_node(command, file));
			command = strdup("");
			file = NULL;
		}
		token = lexer_get_next_token(lexer);
	}
	return (data);
}



// 	if (dollarsign != NULL)
	// 	{
	// 		buffer = malloc((i - start) + 1);
	// 		strncpy(buffer, dollarsign + 1, i - start);
	// 		buffer[(i - start) + 1] = '\0';
	// 	}
	// 	printf("buffer : %s\n", buffer);
	// 	if (buffer != NULL)
	// 	{
	// 		variable = get_env_variable(buffer);
	// 		free(buffer);
	// 		buffer = NULL;
	// 	}
	// 	// if ()
	// 	// {
	// 	// 	printf("inside s_quote\n");
	// 	// 	dollarsign = NULL;
	// 	// }
	// 	// else
	// 	// {
	// 		expanded_value = malloc((strlen(value) - (i - start)) + strlen(variable));
	// 		printf("malloc ----------> %lu\n", (strlen(value) - (i - start)) + strlen(variable));
	// 		dollarsign = NULL;
	// 		printf("i : %c\n", value[i]);
	// 	// }