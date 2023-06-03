/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodeListExtra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:11:26 by yachaab           #+#    #+#             */
/*   Updated: 2023/06/03 21:15:56 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

void	*ft_lstlast_subnode(t_file *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

void	*ft_lstlast_node(t_data *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}
