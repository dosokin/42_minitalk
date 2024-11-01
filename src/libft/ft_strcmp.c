/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:29:01 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:29:08 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(char *a, char *b)
{
	size_t	i;

	if (!a || !b)
		return (0);
	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			break ;
		i++;
	}
	return (a[i] - b[i]);
}
