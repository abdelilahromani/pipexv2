/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:00:15 by aromani           #+#    #+#             */
/*   Updated: 2025/01/26 18:00:45 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	id;
	
	if (ac == 5)
	{
		if (firstfcheck(av[1]) == 0)
			ft_printf("No such file or directory : %s \n", av[1]);
		fd[0] = dup(0);
		fd[1] = dup(1);
		id = parent(av, env);
		if (id == 1)
			return (0);
		parent2(av, env);
		dup2(fd[0], 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		while (wait(0) != -1)
			;
	}
	else
		ft_printf("bad representation of args");
	return (0);
}
