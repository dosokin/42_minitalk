/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_minitalk.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:35:10 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:35:12 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MINITALK_H
# define CLIENT_MINITALK_H

# include <signal.h>
# include <stdbool.h>

void	send_message(int pid, char *message);
void	server_available(int sig);

#endif
