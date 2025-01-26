/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:07:00 by aromani           #+#    #+#             */
/*   Updated: 2025/01/25 21:35:50 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*access_path(char *cmd, char *path)
{
	char	*p;
	
	p = pathchecker(cmd, path);
	if (!p)
		return (free(p), NULL);
	else
		return (p);
}

char	*path_geter(char *str, char **ev)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (ev[i])
	{
		while (ev[i][j] == str[j])
		{
			j++;
			if (ev[i][j] == str[j])
				j++;
		}
		if (j == ft_strlen(str))
			return (ev[i]);
		i++;
	}
	return (NULL);
}

char	*pathchecker(char *c, char *paths)
{
	char	**pth;
	char	*tmp2;
	size_t	i;

	i = 0;
	pth = ft_split(paths, ':');
	if (!pth)
		return (NULL);
	while (pth[i])
	{
		if (ft_searchh(c,'/') != -1)
			tmp2 = ft_strdup(c);
		else
			tmp2 = ft_strjoin(pth[i], c);
		if (access(tmp2, X_OK) != -1)
		{
			ft_free (pth, count_words(paths, ':'));
			return (tmp2);
		}
		else
			free (tmp2);
		i++;
	}
	return (ft_free(pth, count_words(paths, ':')), NULL);
}

char	*last_path(char **env, char **arg)
{
	char	*path;
	char	*str;
	char	*tmp;

	path = path_geter("PATH", env);
	str = ft_substr(path, (ft_search(path, '=') + 1), ft_strlen(path));	
	tmp = access_path(arg[0], str);
	free (str);
	if (!tmp)
		return (NULL);
	return (tmp);
}

int firstfcheck(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	return (close(fd),1);
}