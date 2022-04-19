/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:13:48 by cben-bar          #+#    #+#             */
/*   Updated: 2022/04/07 23:42:42 by cben-bar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[len] = '\0';
	return (joined);
}
