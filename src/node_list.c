/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachaab <yachaab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:52:42 by yachaab           #+#    #+#             */
/*   Updated: 2023/05/24 21:06:58 by yachaab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

// t_list	*ft_lstnew(void *content, int type)
// {
// 	t_list	*node;

// 	node = NULL;
// 	node = (t_list *)malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->content = content;
// 	node->type = type;
// 	node->next = NULL;
// 	return (node);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_data	*last;

	last = NULL;
	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}

t_infile *init_infile()
{
	
}
t_data	*ft_lstnew(char *input)
{
	t_data	*node;

	node = NULL;
	node = (t_data *)malloc(sizeof(t_data));
	if (!node)
		return (NULL);
	node->infile = init_infile(input);
	node->outfile = init_outfile(input);
	node->cmd_args = NULL;
	node->next = NULL;
	return (node);
}