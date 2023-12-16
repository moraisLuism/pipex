/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:44:20 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:44:21 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *command, char **envp)
{
	char	**mypaths;
	char	*onepath;
	char	*fullpath;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	mypaths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (mypaths[i])
	{
		onepath = ft_strjoin(mypaths[i], "/");
		fullpath = ft_strjoin(onepath, command);
		free(onepath);
		if (access(fullpath, F_OK) == 0)
			return (fullpath);
		i++;
	}
	return (0);
}
