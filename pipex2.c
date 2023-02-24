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
	pipe (fd[2]);
	if (pipe(fd) == -1)
	{
		perror();
		exit(EXIT_FAILURE);
	}

}

int child_pipex(char *path, char **argv)
{
	pid_t	pid;
	int		fd[2];

	pid = fork();
	if (pid == -1)
	{
		perror();
		exit(EXIT_FAILURE);
	}
	if (pid == 0) /* processus fils */
	{
		close(fd[1]); /*ferme l'entree lire*/
		exceve(/*path*/, argv[2], env);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
	}
	else /* processus pere*/
	{
		wait();
		close(fd[0]); /*ferme la sortie ecrire */
	//	fork();
		
		exceve(/*path*/, argv[3], env);

	}
	return(0);
}
int 


