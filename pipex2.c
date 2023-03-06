/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:00:59 by ogregoir          #+#    #+#             */
/*   Updated: 2023/03/06 21:01:03 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int *fd, char **argv, char **env)
{
	int		infile;
	char	**arg;
	char	*path;

	infile = open(argv[1], O_CREAT | O_RDONLY);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	arg = ft_split(argv[2], ' ');
	path = get_path(arg[0], env);
	execve(path, arg, env);
	return (0);
}

int	parent_process(int *fd, char **argv, char **env)
{
	int		outfile;
	char	**arg;
	char	*path;

	wait(0);
	outfile = open(argv[4], O_RDWR | O_CREAT, 0644);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	arg = ft_split(argv[3], ' ');
	path = get_path(arg[0], env);
	execve(path, arg, env);
	return (0);
}
