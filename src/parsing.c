/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:28:38 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:11 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_parse_data	*parse_args(int argc, char **argv)
{
	t_parse_data	*data;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		data = parse_single_arg(argv[1]);
	else
		data = parse_multi_args(argc, argv);
	if (!data)
		return (NULL);
	if (has_duplicates(data->values, data->size))
	{
		free_parse_data(data);
		error(1, 1);
	}
	return (data);
}
