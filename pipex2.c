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

int child_pipex(pid_t pid, int *fd, char *path, char **argv)
{
	int		infile;


	if (pid == 0) /* processus fils */
	{
		infile = open(argv[2], O_RDONLY);
		close(fd[0]); /*ferme l'entree lire*/
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(infile);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exceve(/*path*/, argv[2], env);

	}
	return(0);
}

int	parent_pipex(pid_t pid, int *fd, char *path, char **argv)
{
	int		outfile;

	if (pid > 0)
	{
		wait();
		outfile = open(argv[3], O_WRONLY, /*O_CREAT*/)
		close(fd[1]); /*ferme la sortie ecrire */
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exceve(/*path*/, argv[3], env);
	}
	return(0);
}

char	*get_path(int env**);
{
	
}


