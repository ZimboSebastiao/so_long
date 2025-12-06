/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:14:01 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 20:32:22 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr_gnl(char *s, int c)
{
	while (c > 255)
		c = c - 256;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)(s));
		s++;
	}
	if (*s == c)
		return ((char *)(s));
	return (0);
}

static char	*ft_init_s1(char *s1)
{
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	return (s1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	s1 = ft_init_s1(s1);
	if (!s1 || !s2)
		return (s1);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}
