/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:10:00 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:14 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_split_to_values(char **split, int size)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		if (!is_valid_number(split[i]))
		{
			free(values);
			free_split(split);
			error(1, 1);
		}
		values[i] = ft_atoi(split[i]);
	}
	return (values);
}

t_parse_data	*parse_single_arg(char *arg)
{
	char			**split;
	int				size;
	t_parse_data	*data;

	split = ft_split(arg, ' ');
	if (!split)
		return (NULL);
	size = get_split_size(split);
	if (size == 0)
		return (free_split(split), NULL);
	data = malloc(sizeof(t_parse_data));
	if (!data)
		return (free_split(split), NULL);
	data->values = convert_split_to_values(split, size);
	if (!data->values)
		return (free(data), NULL);
	free_split(split);
	data->size = size;
	return (data);
}

t_parse_data	*parse_multi_args(int argc, char **argv)
{
	int				*values;
	int				i;
	t_parse_data	*data;

	values = malloc(sizeof(int) * (argc - 1));
	if (!values)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
	{
		if (!is_valid_number(argv[i + 1]))
			return (free(values), error(1, 1), NULL);
		values[i] = ft_atoi(argv[i + 1]);
	}
	data = malloc(sizeof(t_parse_data));
	if (!data)
		return (free(values), NULL);
	data->values = values;
	data->size = argc - 1;
	return (data);
}
