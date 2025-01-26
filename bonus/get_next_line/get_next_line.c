/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:01:44 by aromani           #+#    #+#             */
/*   Updated: 2025/01/23 22:23:09 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*static_filler(char *res, char *str, int fd)
{
	ssize_t	pos;
	char	*tmp;

	pos = 1;
	while (pos)
	{
		pos = read(fd, str, BUFFER_SIZE);
		if (pos < 0)
			return (free(str), NULL);
		if (pos == 0)
			break ;
		str[pos] = '\0';
		if (!res)
			res = ft_strdupp ("");
		tmp = res;
		res = ft_strjoinn(tmp, str);
		free(tmp);
		tmp = NULL;
		if (res && ft_searchh(res, '\n') != -1)
			break ;
	}
	return (res);
}

static char	*get_line(char *res)
{
	char	*line;
	int		i;

	i = 0;
	if (!res)
		return (NULL);
	while (res[i] != '\n' && res[i] != '\0')
		i++;
	if (res[i] == '\n')
		i++;
	if (!res[0])
		return (NULL);
	line = ft_substrr(res, 0, i);
	if (line == NULL || line[0] == '\0')
		return (free(line), line = NULL, NULL);
	return (line);
}

static char	*new_res(char *res)
{
	char	*new_res;
	int		i;

	i = 0;
	if (!res)
		return (NULL);
	if (ft_searchh(res, '\n') != -1)
		i = ft_searchh(res, '\n');
	if (res[i] == '\n')
		i++;
	if (i == 0)
		return (NULL);
	new_res = ft_substrr(res, i, ft_strlenn(res) - i);
	return (new_res);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	char		*tmp;
	static char	*res;

	if (BUFFER_SIZE > INT_MAX || fd < 0 || fd > OPEN_MAX
		|| read (fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	str = malloc((size_t)BUFFER_SIZE + 1);
	if (!str)
		return (free(res), res = NULL, NULL);
	res = static_filler(res, str, fd);
	free(str);
	str = NULL;
	line = get_line(res);
	tmp = res;
	res = new_res(res);
	free(tmp);
	return (line);
}
