/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_minitalk.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:34:52 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:34:54 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MINITALK_H
# define SERVER_MINITALK_H

# include <signal.h>
# include <stdbool.h>

enum				e_errors
{
	MEM_ERR,
	SIG_FAIL,
};

struct				s_lst
{
	char			c;
	struct s_lst	*next;
};

struct s_lst		*init_new_lst(char c);
void				ft_lstclear(struct s_lst **lst);
void				ft_lstadd_back(struct s_lst **lst, struct s_lst *new);
void				print_lst(struct s_lst *lst);

void				receive_msg(int sig, siginfo_t *siginfo, void *context);

void				*error_manager(enum e_errors e, int client_pid);

#endif
