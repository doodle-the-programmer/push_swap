/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:33:26 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:07 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*temp;

	list = NULL;
	// Create nodes
	node1 = ft_lstnew("First");
	node2 = ft_lstnew("Second");
	node3 = ft_lstnew("Third");
	// Add to front
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	ft_lstadd_front(&list, node3);
	// Print list (should be: Third -> Second -> First)
	while (list)
	{
		printf("%s\n", (char *)list->content);
		temp = list;
		list = list->next;
		free(temp);
	}
	return (0);
}
*/
