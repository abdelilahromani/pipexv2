/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpe_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:25:01 by aromani           #+#    #+#             */
/*   Updated: 2025/01/18 19:54:38 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strcpy(char *dst, char const *src, size_t index, char c)
{
	size_t	i;

	i = 0;
	while (src[index] && src[index] != c)
	{
		dst[i] = src[index];
		i++;
		index++;
	}
	dst[i] = '\0';
	return (index);
}

size_t	count_words(char const *str, int sep)
{
	size_t	i;
	size_t	cw;

	i = 0;
	cw = 0;
	while (str[i] == sep)
		i++;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == sep || str[i + 1] == '\0'))
			cw++;
		i++;
	}
	return (cw);
}
