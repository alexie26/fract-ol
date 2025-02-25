/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:07:04 by roalexan          #+#    #+#             */
/*   Updated: 2024/11/02 17:37:24 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*save;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	save = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!save)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		save[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		save[i++] = s2[j++];
	save[i] = '\0';
	return (save);
}
