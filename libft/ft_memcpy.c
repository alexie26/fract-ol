/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:09:20 by roalexan          #+#    #+#             */
/*   Updated: 2024/10/11 18:57:19 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t c)
{
	size_t	i;

	i = 0;
	if (!to && !from)
	{
		return (NULL);
	}
	if (from != to)
	{
		while (i < c)
		{
			((unsigned char *)to)[i] = ((unsigned char *)from)[i];
			i++;
		}
	}
	return (to);
}
