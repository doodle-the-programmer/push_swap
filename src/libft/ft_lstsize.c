/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:39:55 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:07 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Test 1: Empty list
	printf("Size of empty list: %d\n", ft_lstsize(list));

	// Test 2: List with 3 nodes
	node1 = ft_lstnew("First");
	node2 = ft_lstnew("Second");
	node3 = ft_lstnew("Third");
	node1->next = node2;
	node2->next = node3;
	list = node1;
	printf("Size of list: %d\n", ft_lstsize(list));

	// Cleanup
	while (list)
	{
		t_list *temp = list;
		list = list->next;
		free(temp);
	}

	return (0);
}
*/
