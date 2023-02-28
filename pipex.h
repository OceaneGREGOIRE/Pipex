/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:34:34 by ogregoir          #+#    #+#             */
/*   Updated: 2023/02/06 21:49:35 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int     child_process(int *fd, char *path, char **argv, char **env);
int	    parent_process(int *fd, char *path, char **argv, char **env);
char	*get_path(char *cmd ,char **env);
int     main (int argc, char **argv, int **env);
char	*ft_strnstr(char *hs, char *n, int len);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int	    ft_strlen(char *str);

#endif