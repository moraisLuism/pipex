/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:45:01 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:45:05 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process_1(char **argv, char **envp, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY, 0777);
	if (file1 == -1)
		ft_error("OPEN FILE1 FAIL");
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	ft_exec(argv[2], envp);
}
