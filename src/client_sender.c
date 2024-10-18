/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_sender.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:06 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:23:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_minitalk.h"
#include <unistd.h>

bool		g_serv_available = true;

void	server_available(int sig)
{
	(void)sig;
	g_serv_available = true;
}

static void	await_server_availability(void)
{
	while (!(g_serv_available))
		usleep(10);
}

static void	send_char(int pid, char c)
{
	size_t	i;
	char	ref;

	i = 0;
	while (i < 8)
	{
		ref = 1 << i;
		g_serv_available = false;
		if (c & ref)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		await_server_availability();
		i++;
	}
}

void	send_message(int pid, char *message)
{
	size_t	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, 0);
}
