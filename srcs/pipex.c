/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-bar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 23:30:43 by cben-bar          #+#    #+#             */
/*   Updated: 2022/04/19 16:11:50 by cben-bar         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char **av, char **envp, int *fd)
{
	int		infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		error(NULL);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp);
}

void	parent(char **av, char **envp, int *fd)
{
	int		outfile;

	outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile == -1)
		error(NULL);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	execute(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid_p;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error(NULL);
		pid1 = fork();
		if (pid1 == -1)
			error(NULL);
		if (pid1 == 0)
			child(av, envp, fd);
		pid_p = fork();
		close(fd[1]);
		if (pid_p == 0)
			parent(av, envp, fd);
		waitpid(pid1, NULL, 0);
		waitpid(pid_p, NULL, 0);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
	}
	return (0);
}
