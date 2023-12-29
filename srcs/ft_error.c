/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:43:47 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:43:49 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(const char *error_message)
{
	int	err;

	err = ft_strlen(error_message);
	write(2, "ERROR\n", 6);
	write(2, error_message, err);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
