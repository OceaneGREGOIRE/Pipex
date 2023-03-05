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

int child_process(int *fd, char **argv, char **env)
{
	int		infile;
	char	**arg;
	char	*path;

	infile = open(argv[2], O_RDONLY);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	arg = ft_split(argv[2], ' ');
	path = get_path(arg[0], env);
	execve(path, arg, env);
	return(0);
}

int	parent_process(int *fd, char **argv, char **env)
{
	int		outfile;
	char	**arg;
	char	*path;

	wait(0);
	outfile = open(argv[3], O_WRONLY, O_CREAT);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	arg = ft_split(argv[3], ' ');
	path = get_path(arg[0], env);
	execve(path, arg, env);
	return(0);
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
    char    **gpath;
    char    *tpath;
	int		i;
	int		j;
	
	i = 0;
	if (!env)
		return (cmd);
	
	while (env[i] && (ft_strncmp(env[i], "PATH=", 5))) 
		i++;
	printf("%d\n", i);
	gpath = ft_split(&(env[i][5]), ':');
	i = 0;
	
	while  (gpath[i])
	{
        tpath = ft_strjoin(gpath[i], "/");
		free(gpath[i]);
        gpath[i] = ft_strjoin(tpath, cmd);
		free(tpath);
		if (access(gpath[i], F_OK) == 0)
    	{
			path = ft_strdup(gpath[i]);
			j = 0;
			while (gpath[j])
			{
				free(gpath[j]);
				j++;
			}
        	free(gpath);
        	return(path);
    	}
		i++;
	}
	perror("error");
	exit(127);
}

int main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	pipe(fd);
	if (pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		child_process(fd, argv, env);
	}
	else
		parent_process(fd, argv, env);
	return(0);
}