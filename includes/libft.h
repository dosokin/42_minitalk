/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:35:23 by dosokin           #+#    #+#             */
/*   Updated: 2024/10/18 23:35:25 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

char	**ft_split(char *s, char c);
char	*ft_strjoin(int argc, char **argv);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *a, char *b);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_safe_atoi(char *s, bool *error);
