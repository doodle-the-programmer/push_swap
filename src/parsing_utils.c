/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:40:11 by gpatrici          #+#    #+#             */
/*   Updated: 2025/12/16 14:56:13 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if a string is a valid integer
int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

// Check for duplicate values
int	has_duplicates(int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_parse_data(t_parse_data *data)
{
	if (!data)
		return ;
	if (data->values)
		free(data->values);
	free(data);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

int	get_split_size(char **split)
{
	int	size;

	size = 0;
	while (split[size])
		size++;
	return (size);
}
