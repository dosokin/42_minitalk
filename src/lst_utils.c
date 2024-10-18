/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:23:13 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:23:14 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "server_minitalk.h"
#include <stdlib.h>
#include <unistd.h>

struct s_lst	*init_new_lst(char c)
{
	struct s_lst	*new;

	new = malloc(sizeof(struct s_lst));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->c = c;
	return (new);
}

void	ft_lstadd_back(struct s_lst **lst, struct s_lst *new)
{
	struct s_lst	*tempo;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tempo = *lst;
	while (tempo->next)
		tempo = tempo->next;
	tempo->next = new;
}

static size_t	ft_lstsize(struct s_lst *lst)
{
	size_t	len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	ft_lstclear(struct s_lst **lst)
{
	struct s_lst	*prev;
	struct s_lst	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current->next)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
	free(current);
	*lst = NULL;
}

void	print_lst(struct s_lst *lst)
{
	char	*s;
	size_t	i;
	size_t	len;

	if (!lst)
		return ;
	len = ft_lstsize(lst);
	s = malloc((len) * sizeof(char));
	if (!s)
		return ;
	i = 0;
	while (lst->next)
	{
		s[i++] = lst->c;
		lst = lst->next;
	}
	s[i] = lst->c;
	write(1, s, ft_strlen(s));
	free(s);
}
