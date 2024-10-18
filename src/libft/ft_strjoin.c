/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:28:08 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:28:10 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_joined_len(char **argv)
{
	size_t	i;
	size_t	len_joined;

	i = 0;
	len_joined = 0;
	while (argv[i])
	{
		len_joined += ft_strlen(argv[i]);
		i++;
	}
	return (len_joined);
}

char	*ft_strjoin(int argc, char **to_join)
{
	size_t	j;
	size_t	i_src;
	size_t	i_dst;
	char	*joined;

	joined = malloc((get_joined_len(to_join) + argc + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	j = 0;
	i_dst = 0;
	while (to_join[j])
	{
		i_src = 0;
		while (to_join[j][i_src])
			joined[i_dst++] = to_join[j][i_src++];
		joined[i_dst++] = ' ';
		j++;
	}
	joined[i_dst] = 0;
	return (joined);
}
