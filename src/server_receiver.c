/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_receiver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:43 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:23:48 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#define COMPLETE_BYTE 8
#define END_OF_MSG 0
#define ERROR 1

static int	append_char_to_msg(struct s_lst **msg, char c, int pid)
{
	struct s_lst	*new;

	if (!msg)
	{
		error_manager(MEM_ERR, pid);
		return (1);
	}
	new = init_new_lst(c);
	if (!new)
	{
		error_manager(MEM_ERR, pid);
		return (1);
	}
	ft_lstadd_back(msg, new);
	return (0);
}

static void	reset_server(size_t *i, char *c, struct s_lst **msg_head)
{
	ft_lstclear(msg_head);
	*i = 0;
	*c = 0;
}

static int	confirmation_of_reception(int client_pid)
{
	if (kill(client_pid, SIGUSR1))
	{
		if (kill(client_pid, SIGUSR1))
		{
			error_manager(SIG_FAIL, client_pid);
			return (1);
		}
	}
	return (0);
}

void	receive_msg(int sig, siginfo_t *siginfo, void *context)
{
	static size_t		i = 0;
	static char			received_c = 0;
	static struct s_lst	*msg_head = NULL;
	static int			client_pid = 0;

	(void)context;
	if (siginfo->si_pid && siginfo->si_pid != client_pid)
		client_pid = siginfo->si_pid;
	if (sig == SIGUSR1)
		received_c = received_c | (1 << i);
	if (++i == COMPLETE_BYTE)
	{
		if (append_char_to_msg(&msg_head, received_c, client_pid) == ERROR)
			return (reset_server(&i, &received_c, &msg_head));
		if (received_c == END_OF_MSG)
		{
			print_lst(msg_head);
			reset_server(&i, &received_c, &msg_head);
		}
		i = 0;
		received_c = 0;
	}
	if (confirmation_of_reception(client_pid) == ERROR)
		reset_server(&i, &received_c, &msg_head);
}
