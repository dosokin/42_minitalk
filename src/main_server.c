/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:27 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:34:36 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server_minitalk.h"
#include <stdlib.h>
#include <unistd.h>

void	display_pid(void)
{
	char	*process_id;

	process_id = ft_itoa(getpid());
	write(1, "SERVER PID [", 12);
	write(1, process_id, ft_strlen(process_id));
	write(1, "]\n", 2);
	free(process_id);
}

void	set_sig_handler(int sig, void (f)(int, siginfo_t *, void *))
{
	struct sigaction	new_action;

	new_action.sa_flags = SA_SIGINFO;
	new_action.sa_sigaction = f;
	sigaction(sig, &new_action, NULL);
}

int	main(void)
{
	display_pid();
	set_sig_handler(SIGUSR1, receive_msg);
	set_sig_handler(SIGUSR2, receive_msg);
	while (1)
		pause();
}
