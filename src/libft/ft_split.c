/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:27:34 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:27:36 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*clean_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	get_parts_number(char *s, char c)
{
	size_t	i;
	size_t	parts_count;

	i = 0;
	parts_count = 1;
	while (s[i])
	{
		if (s[i] == c)
			parts_count++;
		i++;
	}
	return (parts_count);
}

static char	*crope(char *s, size_t start, size_t end)
{
	char	*result;
	size_t	i;

	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	**splitted;

	splitted = malloc((get_parts_number(s, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (s[start])
	{
		while (s[end] && s[end] != c)
			end++;
		splitted[i] = crope(s, start, end);
		if (!splitted[i])
			return (clean_array((void **)splitted));
		i++;
		if (!s[end])
			break ;
		start = ++end;
	}
	splitted[i] = NULL;
	return (splitted);
}
