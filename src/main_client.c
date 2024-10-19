/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:20 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:32:23 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_minitalk.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#define MAIN_PROCESS 1

static void	panic_server(int sig)
{
	(void)sig;
	write(2, "Error\nunknown error occurred\n", 29);
	exit(1);
}

static void	set_sig_handler(int sig, void (f)(int))
{
	struct sigaction	new_action;

	new_action.sa_handler = f;
	new_action.sa_flags = SA_NODEFER;
	sigaction(sig, &new_action, NULL);
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;
	bool	error;

	if (argc != 3)
	{
		write(2, "Error\nInvalid syntax => ./client [SERVER PID] [MESSAGE]\n",
			56);
		return (1);
	}
	error = false;
	pid = ft_safe_atoi(argv[1], &error);
	if (error || pid <= MAIN_PROCESS)
		return (1);
	set_sig_handler(SIGUSR1, server_available);
	set_sig_handler(SIGUSR2, panic_server);
	message = argv[2];
	send_message(pid, message);
	return (0);
}
