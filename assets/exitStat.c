/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitStat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:59:24 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/07 23:11:31 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	exxit(char *str, int num)
{
	printf("%s\n", str);
	exit(num);
}