/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:08:07 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/28 13:48:34 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "include/lib.h"

void *ft_memmove(void *dst, const void *src, size_t len) {
    size_t i;
    unsigned char *d;
    unsigned char *s;

    i = 0;
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    if (!d && !s)
        return (0);
    if (d < s) {
        while (i < len) {
            d[i] = s[i];
            i++;
        }
    }
    if (d > s) {
        i = len;
        while (i--)
            d[i] = s[i];
    }
    return ((void *)d);
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

int is_special_character(char ch) {
    char *specialChar;

    specialChar = " \t\n\"\'$.-+|,!@#$%^&*(){}:;\\/?><~";
    if (strchr(specialChar, ch))
        return (1);
    return (0);
}

int inside_single_quote(char *cmd, char *start, char *end)
{
    if (start != cmd && *(start - 2) == '\'')
    {
        if (*(end) == '\'')
            return 1;
    }
    return 0;
}

int inside_double_quote(char *cmd, char *start, char *end)
{
    if (start != cmd && *(start - 2) == '\"')
    {
        if (*(end) == '\"')
            return 1;
    }
    return 0;
}

char    *expand_env_variables(char *command)
{
    char    *dollarSign;
    char    *start;
    char    *end;
    char    *variable;
    char    *buffer;

    dollarSign = strchr(command, '$');
    while (dollarSign != NULL) {
        start = dollarSign + 1;
        end = start;
        while (!is_special_character(*end))
            end++;
        size_t length = end - start;
        buffer = malloc(length + 1);
        if (!buffer)
            exit(1);
        strncpy(buffer, start, length);
        buffer[length] = '\0';
        variable = get_env_variable(buffer);
        free(buffer);
        if ((variable != NULL && length > 0) && (inside_double_quote(command, start, end)
          || (!inside_double_quote(command, start, end) && !inside_single_quote(command, start, end))))
        {
            size_t valueLen = strlen(variable);
            char *new_input = malloc((strlen(command) - length + 1) + valueLen);
            if (!new_input)
                exit(1);
            ft_memmove(new_input, command, dollarSign - command);
            ft_memmove(new_input + (dollarSign - command), variable, valueLen);
            ft_memmove(new_input + (dollarSign - command) + valueLen,
            dollarSign + length + 1, strlen(dollarSign + length + 1));
            free(command);
            command = new_input;//printf("command %s\n", command);
            dollarSign = strchr(command, '$');
        }
        else
            dollarSign= strchr(dollarSign + 1, '$');
        
    }
    return (command);
}