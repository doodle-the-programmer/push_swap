/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:17:54 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:40:43 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	if ((nmemb != 0 && size > SIZE_MAX / nmemb) || nmemb == 0 || size == 0)
		return (malloc(0));
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)res)[i] = 0;
		i++;
	}
	return (res);
}
