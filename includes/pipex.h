/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:33:11 by cben-bar          #+#    #+#             */
/*   Updated: 2022/04/19 17:01:11 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ****************************************************************************
-----------------------------------INCLUDES-----------------------------------
* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

/* ****************************************************************************
-----------------------------PROTOTYPES FUNCTIONS-----------------------------
* ************************************************************************** */

void	error(const char *msg);
size_t	line_count(char **tab);
char	*find_path(char *cmd, char **envp);
void	execute(char *av, char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	cleaner(char **tab);

#endif
