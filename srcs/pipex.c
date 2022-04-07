/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:59:51 by cben-bar          #+#    #+#             */
/*   Updated: 2022/04/07 17:45:54 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **av, char **env, int *fd)
{
	int		filein;

	filein = open(av[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], env);
}

void	parent(char **av, char **env, int *fd)
{
	int		fileout;
	pid_t	pidp;

	pidp = fork();
	if (pidp == 0)
	{
		fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fileout == -1)
			error();
		dup2(fd[0], STDIN_FILENO);
		dup2(fileout, STDOUT_FILENO);
		close(fd[1]);
		waitpid(pidp, NULL, 0);
		execute(av[3], env);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fds[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(fds) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child(av, env, fds);
		waitpid(pid, NULL, 0);
		parent(av, env, fds);
	}
	return (0);
}
