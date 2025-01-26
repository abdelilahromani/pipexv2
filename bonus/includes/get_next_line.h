/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:02:51 by aromani           #+#    #+#             */
/*   Updated: 2025/01/23 22:23:17 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_substrr(char *s, unsigned int start, size_t len);
char	*ft_strjoinn(char *s1, char const *s2);
char	*ft_strdupp(const char *s1);
size_t	ft_strlenn(const char *s);
int		ft_searchh(char *str, int c);
char	*get_next_line(int fd);

#endif