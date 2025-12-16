/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:00:57 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:10 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free a single node
void	free_node(t_snode *node)
{
	if (node)
		free(node);
}

// Check if stack is empty
int	is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (stack->size == 0);
}

// Free the entire stack
void	free_stack(t_stack *stack)
{
	t_snode	*current;
	t_snode	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
	free(stack);
}

void	assign_indices(t_stack *stack)
{
	t_snode	*current;
	t_snode	*compare;
	int		rank;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		rank = 0;
		compare = stack->head;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}
