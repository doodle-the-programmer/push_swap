/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:20:39 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:08 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push a node to the front (top) of the stack
void	push_front(t_stack *stack, t_snode *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->head;
	node->prev = NULL;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
	stack->size++;
}

// Push a node to the back (bottom) of the stack
void	push_back(t_stack *stack, t_snode *node)
{
	if (!stack || !node)
		return ;
	node->prev = stack->tail;
	node->next = NULL;
	if (stack->tail)
		stack->tail->next = node;
	else
		stack->head = node;
	stack->tail = node;
	stack->size++;
}

// Pop a node from the front (top) of the stack
t_snode	*pop_front(t_stack *stack)
{
	t_snode	*node;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

// Pop a node from the back (bottom) of the stack
t_snode	*pop_back(t_stack *stack)
{
	t_snode	*node;

	if (!stack || !stack->tail)
		return (NULL);
	node = stack->tail;
	stack->tail = node->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}
