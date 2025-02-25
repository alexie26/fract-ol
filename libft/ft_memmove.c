/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:13:23 by roalexan          #+#    #+#             */
/*   Updated: 2024/10/12 19:52:11 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *to, const void *from, size_t n)
{
	size_t			i;
	char			c;
	unsigned char	*j;
	unsigned char	*d;

	i = 0;
	c = 1;
	j = (unsigned char *)to;
	d = (unsigned char *)from;
	if (!to && !from)
		return (NULL);
	if (to > from)
	{
		c = -1;
		j += n - 1;
		d += n - 1;
	}
	while (i < n)
	{
		*j = *d;
		j += c;
		d += c;
		i++;
	}
	return (to);
}
