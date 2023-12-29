/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:45:14 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:45:16 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process_2(char **argv, char **envp, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (file2 == -1)
		ft_error("OPEN FILE2 FAIL");
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	ft_exec(argv[3], envp);
}
