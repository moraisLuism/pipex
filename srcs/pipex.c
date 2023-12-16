/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:45:54 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:45:56 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	secondary1;
	pid_t	secondary2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error();
		secondary1 = fork();
		if (secondary1 == -1)
			ft_error();
		if (secondary1 == 0)
			ft_process_1(argv, envp, fd);
		secondary2 = fork();
		if (secondary2 == -1)
			ft_error();
		if (secondary2 == 0)
			ft_process_2(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(secondary1, NULL, 0);
		waitpid(secondary2, NULL, 0);
	}
	else
		ft_error();
}
