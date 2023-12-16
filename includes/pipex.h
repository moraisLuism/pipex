/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:41:22 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:42:56 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"

void	ft_process_1(char **argv, char **envp, int *fd);
void	ft_process_2(char **argv, char **envp, int *fd);
void	ft_exec(char *argv, char **envp);
char	*ft_path(char *command, char **envp);
void	ft_error(void);

#endif
