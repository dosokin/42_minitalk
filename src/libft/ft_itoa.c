/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:18:47 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:24:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#define MY_INT_MIN -2147483648

static size_t	get_literal_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		i;

	if (n == MY_INT_MIN)
		return (ft_strdup("-2147483648"));
	len = get_literal_len(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = 0;
	result[0] = 0;
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	i = (int)len - 1;
	while (i >= (int)(result[0] == '-'))
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (result);
}
