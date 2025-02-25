/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:10:39 by roalexan          #+#    #+#             */
/*   Updated: 2024/10/13 17:35:30 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*i;

	i = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			i = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		i = (char *)s;
	}
	return (i);
}
