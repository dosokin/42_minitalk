/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:34 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/19 13:26:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server_minitalk.h"
#include <stdbool.h>
#include <unistd.h>

void	*error_manager(enum e_errors e, int client_pid)
{
	static bool	broadcasted = false;
	static char	*errors[2] = {"allocation error\n",
		"failed to send signal to client\n"};

	if (broadcasted || e > 1)
		return (NULL);
	broadcasted = true;
	write(2, "Error\n", 6);
	write(2, errors[e], ft_strlen(errors[e]));
	kill(client_pid, SIGUSR2);
	return (NULL);
}
