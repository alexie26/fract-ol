/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:02:58 by roalexan          #+#    #+#             */
/*   Updated: 2024/11/18 16:17:59 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	s_len;

	if (s == NULL)
	{
		return (NULL);
	}
	s_len = ft_strlen(s);
	if ((size_t)start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > (s_len - start))
	{
		len = s_len - start;
	}
	s1 = (char *)malloc(len + 1);
	if (!s1)
	{
		return (NULL);
	}
	ft_strlcpy(s1, s + start, len + 1);
	return (s1);
}
