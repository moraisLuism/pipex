/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:48:19 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/15 08:48:20 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (needle[i] && haystack[i] == needle[i] && len > 0)
		{
			len--;
			i++;
		}
		if (needle[i] == '\0')
			return ((char *)haystack);
		len += i;
		len--;
		haystack++;
	}
	return (NULL);
}
