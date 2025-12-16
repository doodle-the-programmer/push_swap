/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:59:58 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:57:15 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialize an empty stack
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

// Create a new node with given value and index
t_snode	*create_node(int value, int index)
{
	t_snode	*node;

	node = (t_snode *)malloc(sizeof(t_snode));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

// Initialize stack A with values
t_stack	*init_stack_a(int *values, int size)
{
	int		i;
	t_snode	*node;
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 0;
	while (i < size)
	{
		node = create_node(values[i], i);
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		push_back(stack, node);
		i++;
	}
	assign_indices(stack);
	return (stack);
}
