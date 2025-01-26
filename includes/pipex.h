/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:17:56 by aromani           #+#    #+#             */
/*   Updated: 2025/01/26 18:00:09 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <strings.h>
# include "ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>
# include <libc.h>

int		ft_searchh(char *str, int c);
size_t	count_words(char const *str, int sep);
size_t	ft_strcpy(char *dst, char const *src, size_t index, char c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char*s2);
size_t	ft_strlen(const char *s);
int		ft_search(char *str, char c);
char	*ft_substr(char *s, int start, int end);
char	*ft_strdup(char *str);
void	ft_free(char **p, size_t index);
char	*access_path(char *cmd, char *path);
char	*path_geter(char *str, char **ev);
char	*pathchecker(char *c, char *paths);
char	*last_path(char **env, char **arg);
int     firstfcheck(char *av);
int     parent(char **av, char **env);
int     parent2(char **av, char **env);

#endif