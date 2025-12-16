/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:10:53 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:41 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(int err_code, int should_exit)
{
	write(2, "Error\n", 7);
	if (should_exit)
		exit(err_code);
	return (err_code);
}

int	main(int argc, char **argv)
{
	t_parse_data	*data;
	t_stack			*stack;
	t_snode			*node;
	int				i;

	if (argc < 2)
		return (error(1, 0));
	data = parse_args(argc, argv);
	ft_printf("Size: %i.\n", data->size);
	i = -1;
	while (++i < data->size)
		ft_printf("Data: %i at %i\n", data->values[i], i);
	stack = init_stack_a(data->values, data->size);
	node = stack->head;
	i = 0;
	while (node)
	{
		ft_printf("\nContent: %i, at index: %i (%i)\n", node->value,
			node->index, i++);
		node = node->next;
	}
	return (0);
}
