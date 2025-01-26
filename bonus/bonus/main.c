/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:54:16 by aromani           #+#    #+#             */
/*   Updated: 2025/01/26 18:11:00 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void ff()
// {
// 	system("lsof -c pipex_bonus");
// }
// void ff()
// {
// 	system("leaks  pipex_bonus");
// 	system("lsof -c  pipex_bonus");
// }

int duplication(int child_id,int *pfd)
{
	if (child_id == 0 && pfd[4] != 4)
	 	return (close(pfd[1]),close(pfd[0]),1);
	else
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
	}
	return (0);
}
int	parent(char **av, char **env,int j,int f)
{
	char	*str;
	char	**arg;
	int		pfd[5];
	int		child_id;
	int 	dup;

	if (pipe(pfd) == -1)
		exit(0);
	arg = ft_split(av[j], ' ');
	if (!arg)
		return (close(pfd[0]),close(pfd[1]),0);
	str = last_path(env, arg);
	if (!str)
	{
		pfd[4] = 4;
		ft_printf("command not found \n");
	}
	pfd[2] = j;
	pfd[3] = f;
	child_id = child_proc(pfd, arg, env, av);
	dup = duplication(child_id,pfd);
	if (dup == 1)
		return (1);
	return (ft_free(arg, count_words(av[j], ' ')), free(str), 0);
}

int	parent2(char **av, char **env,int i)
{
	char	*str;
	char	**arg;

	arg = ft_split(av[i], ' ');
	if (!arg)
		return (0);
	str = last_path(env, arg);
	if (!str)
		ft_printf("command not found \n");
	child_proc2(str, arg, env, av[i + 1]);
	return (ft_free(arg, count_words(av[i], ' ')), free(str), 0);
}

int looping(int ac,char **av,char **env,int fd)
{
    int j;
    int i;
    int id;

    i = 0;
    j = 0;
	if (ft_strcmp(av[1],"here_doc") == 0)
		i++;
	while (i < ac - 4)
	{
		j = i + 2;
		id = parent(av, env,j,fd);
		if (id == 1)
			return (1);
		if (id == 2)
			i++;

		i++;
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int f;
	int	lop;

	//atexit(ff);
	f = 0;
	if (ac < 5)
		return (ft_printf("bad representation of args"),0);
	fd[0] = dup(0);
	fd[1] = dup(1);
	f = files_main_handling(ac,av,f,fd);
	if (f == -10)
		return (0);
	lop = looping(ac,av,env,f);
	if (lop == 1)
		return (close(f),close(fd[0]),close(fd[1]),0);
	parent2(av, env, ac - 2);
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	close(f);
	close(fd[0]);
	close(fd[1]);
	while (wait(0) != -1)
		;
	return (0);
}
