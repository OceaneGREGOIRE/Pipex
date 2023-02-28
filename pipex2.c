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

int child_process(int *fd, char *path, char **argv, char **env)
{
	int		infile;


	infile = open(argv[2], O_RDONLY);
	close(fd[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exceve("PATH", argv[2], env);
	return(0);
}

int	parent_process(int *fd, char *path, char **argv, char **env)
{
	int		outfile;


	wait("PID");
	outfile = open(argv[3], O_WRONLY, O_CREAT);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	execve(path, argv[3], env);
	return(0);
}

char	*get_path(char *cmd ,char **env)
{
	char	*path;
    char    **gpath;
    char    *tpath;
	int		i;
	int		j;
	
	j = 0;
	i = 0;
	if (!env)
		/*fct test bin et commande*/;
	else
	{
		while (env[i] && (!ft_strnstr(env[i], "PATH=", 5)))
			i++;
		if (!env[i]) 
		{
			/*si y a pas d'environnement faire un cas "construire" un environneemnt*/;
		}
		else
			gpath = ft_split(env[i] + 5, ':');
	}
	
	while  (gpath[i])
	{
        tpath = ft_strjoin(gpath[i], "/");
		free(gpath[i]);
        gpath[i] = ft_strjoin (tpath, cmd);
		free(tpath[i]);
		if (access(gpath[i], F_OK))
    	{
			path = ft_strdupcpy(gpath[i]);
			while (gpath[j])
			{
				free(gpath[j]);
				j++;
			}
        	free(gpath);
        	return(path);
    	}
	}
	perror("error");
	exit(127);
}

int main (int argc, char **argv, int **env)
{
	pid_t	pid;
	int		fd[2];

	pid = fork();
	pipe(fd[2]);
	if (pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		child_process(pid, fd, get_path(argv[2], env), argv[2], env);
	}
	else
	pipe (fd[2]);
	if (pipe(fd) == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	
	return();
}

