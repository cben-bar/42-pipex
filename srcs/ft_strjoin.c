/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:56:23 by cben-bar          #+#    #+#             */
/*   Updated: 2022/04/06 15:32:14 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final_s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	final_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!final_s)
		return (NULL);
	while (s1[j] != '\0')
	{
		final_s[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		final_s[i] = s2[j];
		i++;
		j++;
	}
	final_s[i] = '\0';
	return (final_s);
}
