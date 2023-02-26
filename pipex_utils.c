/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:43:42 by ogregoir          #+#    #+#             */
/*   Updated: 2023/02/26 11:43:44 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(char *hs, char *n, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!n[0])
		return ((char *)hs);
	while (hs[i] != '\0' && (i + j < len))
	{
		if (hs[i] != '\0' && hs[i] == n[0])
		{
			j = 0;
			while (n[j] && hs[i + j] == n[j] && (i + j < len))
				j++;
			if (n[j] == '\0')
				return ((char *)hs + i);
		}
		i++;
	}
	return("NULL");
}

static int	ft_number(const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	*ft_strdupcpy(char *src, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (src[i] != c && src[i])
		i++;
	if (!src)
		return (0);
	tab = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i] && src[i] != c)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		n;
	int		j;

	i = 0;
	j = 0;
	n = ft_number(s, c);
	tab = malloc(sizeof(char *) * (n + 1));
	if (!tab)
		return (0);
	while (s[i] && j < n)
	{
		if (s[i] != c)
		{
			tab[j] = ft_strdupcpy(s + i, c);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int 	lens2;
	int 	lens1;
	int    	i;

	i = 0;
    lens1 = ft_strlen(s1);
	lens2 = lens1 + ft_strlen(s2);
	str = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	while (s2[i])
    {
        str[lens1] = s2[i];
        lens1++;
    }
    str[lens1] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

