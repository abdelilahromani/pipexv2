/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aromani <aromani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:35:42 by aromani           #+#    #+#             */
/*   Updated: 2025/01/26 16:18:33 by aromani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/pipex.h"
#include "../includes/pipex.h"
#include <stdio.h>

int ft_strcmp(char *s1,char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char *withoutnewline(char *line)
{
	char *str;
	size_t		i;
	size_t		j;

	j = ft_strlen(line);
	i = 0;
	str = malloc (j);
	while (line[i] && i < j)
	{
		str[i] = line[i];
		i++;
	}
	str[i - 1] = '\0';
	return (str);
}

void writer(char *line,int fd)
{
	int i;

	i = 0;
	while (line[i])
		write (fd,&line[i++],1);
	return ;
}

char * here_doc_reader(char **av,int fd)
{
	char *line;
	char *tmp;
	char *tmp2;

	write (1,"heredoc>",9);
	line = get_next_line(0);
	if (!line)
		return (NULL);
	tmp = withoutnewline(line);
	if (ft_strcmp(tmp,av[2]) == 0)
		return (free(tmp),free(line),NULL);
	free(tmp);
	if (line != NULL && ft_strcmp(line,av[2]) != 0)
	{
		tmp2 = line;
		writer(tmp2, fd);
		free(tmp2);
	}
	return (line);
}

int here_doc(char **av)
{
	char *str;
	int		flag;
	int		fd[2];

	flag = 0;
	unlink(av[1]);
	fd[0] = open(av[1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	fd[1] = open(av[1], O_RDONLY, 0777);
	unlink(av[1]);
	if (ft_strcmp(av[1],"here_doc") == 0)
	{
		while (1)
		{
			str = here_doc_reader(av,fd[0]);
			if (str == NULL)
			{
				close(fd[0]);
				break ;
			}
		}
	}
	else
		return (close(fd[0]),0);
	return (fd[1]);
}

// int main(int ac,char **av)
// {
// 	//void(ac);
// 	ac = 2;
// 	here_doc(av);
// 	return (0);
// }