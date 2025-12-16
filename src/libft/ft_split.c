/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpatrici <gpatrici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:00:32 by gpatrici          #+#    #+#             */
/*   Updated: 2025/10/22 17:01:07 by gpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*dup_word(char const *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	split_words(char **result, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			result[i] = dup_word(s, c);
			if (!result[i])
			{
				j = 0;
				while (j < i)
					free(result[j++]);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**res;
	int		i;

	// Test 1: Normal split
	res = ft_split("Hello World Test", ' ');
	if (res)
	{
		i = 0;
		while (res[i])
		{
			printf("Word %d: '%s'\n", i, res[i]);
			free(res[i]);
			i++;
		}
		free(res);
	}
	// Test 2: Multiple delimiters
	res = ft_split("...Hello...World...", '.');
	if (res)
	{
		i = 0;
		while (res[i])
		{
			printf("Word %d: '%s'\n", i, res[i]);
			free(res[i]);
			i++;
		}
		free(res);
	}
	// Test 3: No delimiter found
	res = ft_split("Hello", ' ');
	if (res)
	{
		i = 0;
		while (res[i])
		{
			printf("Word %d: '%s'\n", i, res[i]);
			free(res[i]);
			i++;
		}
		free(res);
	}
	return (0);
}
*/
// 	}
// 	return (0);
// }