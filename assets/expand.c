/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:08:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/01 23:43:39 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/lib.h"

char	*get_env_variable(char *name)
{
	extern char	**environ;
	char		**env;
	size_t		len;

	env = environ;
	len = strlen(name);
	while (*env != NULL)
	{
		if (strncmp(name, *env, len) == 0 && (*env)[len] == '=')
			return (&(*env)[len + 1]);
		env++;
	}
	return (NULL);
}

t_exp_var	*init_exp_var(char *value)
{
	t_exp_var	*exp;

	exp = malloc(sizeof(t_exp_var));
	if (!exp)
		exit(1);
	exp->neo_value = NULL;
	exp->start = NULL;
	exp->end = NULL;
	exp->buffer = NULL;
	exp->variable = NULL;
	exp->head = value;
	exp->dollarsign = NULL;
	exp->length = 0;
	exp->d__quote = 0;
	exp->s__quote = 0;
	return (exp);
}

void	fill_buffer(char *value, t_exp_var *exp)
{
	if (*value == '$' && (exp->d__quote
			|| (!exp->d__quote && !exp->s__quote)))
	{
		exp->start = value + 1;
		exp->end = exp->start;
		while (!is_special_character(*exp->end))
			exp->end++;
		exp->length = exp->end - exp->start;
		exp->buffer = malloc(exp->length + 1);
		memcpy(exp->buffer, exp->start, exp->length);
		exp->buffer[exp->length] = 0;
	}
}

void	start_expanding(t_exp_var *exp, char *value)
{
	if (exp->variable)
	{
		exp->neo_value = malloc(sizeof(char *) * ((strlen(exp->head)
						- (exp->length + 1)) + strlen(exp->variable)));
		memcpy(exp->neo_value, exp->head, exp->start - exp->head);
		memcpy(exp->neo_value + (exp->start - exp->head - 1),
			exp->variable, strlen(exp->variable));
		memcpy(exp->neo_value + ((exp->start - exp->head - 1)
				+ strlen(exp->variable)), exp->end, strlen(exp->end));
		exp->neo_value[(strlen(exp->head) - (exp->length + 1))
			+ strlen(exp->variable)] = 0;
		exp->head = strdup(exp->neo_value);
		exp->dollarsign = strchr(exp->head, '$');
		value = exp->dollarsign;
		free(exp->neo_value);
		exp->variable = NULL;
	}
}

char	*expand_env_variables(char *value)
{
	t_exp_var	*exp;

	exp = init_exp_var(value);
	while (value && *value)
	{
		if (*value == '"')
			exp->d__quote = !exp->d__quote;
		if (*value == '\'')
			exp->s__quote = !exp->s__quote;
		fill_buffer(value, exp);
		if (exp->buffer)
		{
			exp->variable = get_env_variable(exp->buffer);
			free(exp->buffer);
			exp->buffer = NULL;
		}
		if (exp->variable && variable_contain_white_space(exp->variable))
			exp->variable = add_quote_to_variable(exp->variable);
		start_expanding(exp, value);
		value++;
	}
	return (exp->head);
}
