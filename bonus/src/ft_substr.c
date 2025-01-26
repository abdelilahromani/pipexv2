/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:29:24 by aromani           #+#    #+#             */
/*   Updated: 2025/01/18 19:52:22 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char *s, int start, int end)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	while (s[i] && i < end)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_search(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	s = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
