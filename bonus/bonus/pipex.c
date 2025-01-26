/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:16:01 by aromani           #+#    #+#             */
/*   Updated: 2025/01/26 18:11:09 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int infile_check(int *pfd, int fd, char **av)
{
	if (ft_strcmp(av[1],"here_doc") == 0)
		{
			fd = pfd[3];
			if (pfd[2] == 3 && fd > 0)
			{
				dup2(fd, 0);
				close(fd);
			}
		}	
		else
		{
			if (pfd[2] == 2)
			{
				fd = open(av[1], O_RDONLY);
				if (fd == -1)
					return (1);
				dup2(fd, 0);
				close(fd);
			}
		}
	return (0);
}

int	child_proc(int *pfd, char **arg, char **env, char **av)
{
	int		id;
	char	*str;
	int		fd;
	int		inch;

	fd = 0;
	str = last_path(env, arg);
	if (!str)
		return (0);
	id = fork();
	if (id == 0)
	{
		inch = infile_check(pfd,fd,av);
		if (inch == 1)
			return (close(pfd[0]),close(pfd[1]),free(str),0);
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		if (execve(str, arg, env) < 0)
			perror("execve : ");
		exit(0);
	}
	return (free(str), id);
}

void	child_proc2(char *str, char **arg, char **env, char *av)
{
	int		id;
	char	*tmp;
	int		fd;

	id = fork();
	if (id == 0)
	{
		fd = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd, 1);
		close(fd);
		tmp = str;
		if (!str)
			return (free(tmp));
		if (execve(tmp, arg, env) == -1)
			perror("execve : ");
		free(tmp);
		exit(0);
	}
}

int files_main_handling(int ac,char **av,int f,int *fd)
{
	if (ft_strcmp(av[1],"here_doc") == 0)
	{
		if (ac >= 6)
			f = here_doc(av);
		else
			return (ft_printf("here_doc need atlist 6 argements"),close(fd[0]),close(fd[1]),-10);
	}
	else
	{
		f = open(av[1], O_RDONLY);
		if (f < 0)
			ft_printf("No such file or directory : %s \n", av[1]);
	}
	return (f);
}
