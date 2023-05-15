#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void	find_char_and_replace_with_unprintable(char *str);
void	find_unprintable_and_replace_with_char(char *str);
#endif