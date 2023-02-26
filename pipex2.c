/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:22:57 by ogregoir          #+#    #+#             */
/*   Updated: 2023/02/24 08:03:19 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int child_pipex(pid_t pid, int *fd, char *path, char **argv, char **env)
{
	int		infile;


	if (pid == 0)
	{
		infile = open(argv[2], O_RDONLY);
		close(fd[0]);
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infile);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exceve("PATH", argv[2], env);

	}
	return(0);
}

int	parent_pipex(pid_t pid, int *fd, char *path, char **argv, char **env)
{
	int		outfile;

	if (pid > 0)
	{
		wait("PID");
		outfile = open(argv[3], O_WRONLY, O_CREAT);
		close(fd[1]); /*ferme la sortie ecrire */
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		execve('PATH', argv[3], env);
	}
	return(0);
}

char	*get_path(char *cmd ,char **env)
{
	char	*path;
    char    **gpath;
    char    *tpath;
	int		i;
	
	i = 0;
	while (env[i] && (!ft_strnstr(env[i], "PATH", 4)))
	{
		printf("env[%d] : %s", i, env[i]);
		i++;
	}
	gpath = ft_split(env[i] + 5, ':');
	i = 0;
	while  (path[i])
	{
        tpath = ft_strjoin(path[i], "/");
        path[i] = ft_strjoin (tpath, cmd);
		return (cmd[i]);
	}
	if (env[i] && !access(path, F_OK))
    {
        free(gpath);
        return(*path);
    }
	return (cmd[i]);
}

int main (int argc, char **argv, int env**)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror();
		exit(EXIT_FAILURE);
	}
	pipe (fd[2]);
	if (pipe(fd) == -1)
	{
		perror();
		exit(EXIT_FAILURE);
	}
	
	return();
}

