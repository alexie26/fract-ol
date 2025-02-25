/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:42:10 by roalexan          #+#    #+#             */
/*   Updated: 2024/11/05 13:11:18 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_checkset(char const *set, char const c)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(set);
	while (i < len)
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	while (ft_checkset(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	if (!(start == end + 1))
		while (ft_checkset(set, s1[end]))
			end--;
	return (ft_substr(s1, start, end - start + 1));
}
