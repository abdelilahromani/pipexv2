/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:16:01 by aromani           #+#    #+#             */
/*   Updated: 2025/01/26 20:54:25 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	child_proc(int *pfd, char **arg, char **env, char **av)
{
	int		id;
	char	*str;
	int		fd;

	str = last_path(env, arg);
	if (!str)
		return (0);
	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (0);
		dup2(fd, 0);
		close(fd);
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (execve(str, arg, env) == -1)
			perror("execve failed ");
		exit(0);
	}
	return (free(str), id);
}

void	child_proc2(char *str, char **arg, char **env, char **av)
{
	int		id;
	char	*tmp;
	int		fd;

	id = fork();
	if (id == -1)
		exit(1);
	if (id == 0)
	{
		fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd < 0)
			return ;
		dup2(fd, 1);
		close(fd);
		tmp = str;
		if (!str)
			return (free(tmp));
		if (execve(tmp, arg, env) == -1)
			perror("execve failed ");
		free(tmp);
		exit(0);
	}
}

int	parent(char **av, char **env)
{
	char	*str;
	char	**arg;
	int		pfd[2];
	int		child_id;

	if (pipe(pfd) == -1)
		exit(1);
	arg = ft_split(av[2], ' ');
	if (!arg)
		return (0);
	str = last_path(env, arg);
	if (!str)
		return (ft_free(arg, count_words(av[2], ' ')),
			free(str), ft_printf("command not found \n"), 0);
	child_id = child_proc(pfd, arg, env, av);
	if (child_id == 0)
		return (1);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
	return (ft_free(arg, count_words(av[2], ' ')), free(str), 0);
}

int	parent2(char **av, char **env)
{
	char	*str;
	char	**arg;

	arg = ft_split(av[3], ' ');
	if (!arg)
		return (0);
	str = last_path(env, arg);
	if (!str)
		ft_printf("command not found \n");
	child_proc2(str, arg, env, av);
	return (ft_free(arg, count_words(av[3], ' ')), free(str), 0);
}
