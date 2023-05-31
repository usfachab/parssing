/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:08:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/31 21:00:25 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "include/lib.h"

int is_special_character(char ch) {
	char *specialChar;

	specialChar = " \t\n\"\'$.-+|,!@#$%^&*(){}:;\\/?><~";
	if (strchr(specialChar, ch))
		return (1);
	return (0);
}

char *get_env_variable(char *name) {
	extern char **environ;
	char **env = environ;
	size_t len = strlen(name);

	while (*env != NULL) {
		if (strncmp(name, *env, len) == 0 && (*env)[len] == '=') {
			return &(*env)[len + 1];
		}
		env++;
	}
	return NULL;
}

char	*expand_env_variables(char *value)
{
	size_t	length;
	char	*start = NULL;
	char	*end = NULL;
	char	*buffer = NULL;
	char	*variable = NULL;
	char	*head;
	char	*dollarsign;
	int		d__quote;
	int		s__quote;
	
	d__quote = 0;
	s__quote = 0;
	head = value;
	while (value && *value)
	{
		if (*value == '"')
			d__quote = !d__quote;
		if (*value == '\'')
			s__quote = !s__quote;
		if (*value == '$' && (d__quote || (!d__quote && !s__quote)))
		{
			start = value + 1;
			end = start;
			while (!is_special_character(*end))
				end++;
			length = end - start;
			buffer = malloc(length + 1);
			memcpy(buffer, start, length);
			buffer[length] = 0;
		}
		if (buffer)
		{
			variable = get_env_variable(buffer);
			free(buffer);
			buffer = NULL;
		}
		if (variable)
		{
			char	*neo_value;

			neo_value = malloc((strlen(head) - (length + 1)) + strlen(variable));
			memcpy(neo_value, head, start - head);
			memcpy(neo_value + (start - head - 1), variable, strlen(variable));
			memcpy(neo_value + ((start - head - 1) + strlen(variable)), end , strlen(end));
			neo_value[(strlen(head) - (length + 1)) + strlen(variable)] = 0;
			printf("neo_value: %s\n", neo_value);
			head = strdup(neo_value);
			dollarsign = strchr(head, '$');
			if (!dollarsign)
				return (head);
			value = dollarsign;
			free(neo_value);
			variable = NULL;
		}
	 	value++;
	}
	return (head);
}