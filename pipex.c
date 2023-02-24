/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:21:55 by ogregoir          #+#    #+#             */
/*   Updated: 2023/02/22 16:34:46 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv, char **env)
{
	int 	fd[2];
	pid_t	pid;

	pipe(fd[2]);
	if (argc > 1)
	{

		if (execve(argv[1],argv + 1, env) == -1)
			perror("error");
	}
	return (0);
	if ((pid = fork()) == -1)
	{
		perror("erreur");
		

	return (0);
}
