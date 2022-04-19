/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:31:37 by cben-bar          #+#    #+#             */
/*   Updated: 2022/04/19 17:18:38 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char *cmd, char **envp, size_t j)
{
	char	**paths;
	char	*path;
	char	*part_path;

	while (ft_strnstr(envp[j], "PATH", 4) == 0)
		j++;
	if (j > line_count(envp))
		error(NULL);
	paths = ft_split(envp[j] + 5, ':');
	j = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (paths[j])
	{
		part_path = ft_strjoin(paths[j], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		j++;
	}
	cleaner(paths);
	return (0);
}

void	error(const char *msg)
{
	if (msg)
		perror(msg);
	else
		perror("Error");
	exit(EXIT_FAILURE);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;
	size_t	j;

	i = -1;
	j = 0;
	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp, j);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error("command not found");
	}
	if (execve(path, cmd, envp) == -1)
		error("command not found");
}
