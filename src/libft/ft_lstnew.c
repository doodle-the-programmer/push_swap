/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:24:01 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:03:44 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	*node;
	char	*content;

	content = "Hello World";
	// Test 1: Create new node
	node = ft_lstnew(content);
	printf("Content: %s\n", (char *)node->content);
	printf("Next: %p\n", (void *)node->next);
	free(node);
	// Test 2: Create with NULL content
	node = ft_lstnew(NULL);
	printf("Content: %p\n", node->content);
	free(node);
	return (0);
}
*/
