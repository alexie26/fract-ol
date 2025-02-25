/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:38 by roalexan          #+#    #+#             */
/*   Updated: 2024/10/31 13:43:16 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	result;
	int		counter;

	i = 0;
	result = 0;
	counter = 0;
	while (str[i] != '\0' && (str[i] == 32
			|| str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] != '\0' && str[i] == '-')
		{
			counter = -1;
		}
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	if (counter == -1)
		return (result * -1);
	return (result);
}
