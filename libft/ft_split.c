/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalexan <roalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:14:38 by roalexan          #+#    #+#             */
/*   Updated: 2024/11/19 20:37:36 by roalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// size_t	ft_strlen(const char *str)
// {
// 	int	c;

// 	c = 0;
// 	while (str[c] != '\0')
// 		c++;
// 	return (c);
// }
// void	ft_bzero(void *s, size_t c)
// {
// 	size_t	i;
// 	char	*str;

// 	str = s;
// 	i = 0;
// 	while (i < c)
// 	{
// 		str[i] = 0;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t nitems, size_t size)
// {
// 	void	*array;

// 	array = (void *)malloc(nitems * size);
// 	if (array == NULL)
// 	{
// 		return (NULL);
// 	}
// 	ft_bzero(array, (nitems * size));
// 	return (array);
// }

static	int	word_count(const char *str, const char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static char	*ft_fillword(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static void	*ft_free(char **str, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static void	initialize(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	int		j;
	int		s_word;

	initialize(&i, &j, &s_word);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			res[j] = ft_fillword(s, s_word, i);
			if (!(res[j]))
				return (ft_free(res, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (res);
}

// void leaks ()
// {
//     system("leaks a.out");
// }

// int main()
// {
// 	char *tosplit = "hi this is me good bye";
// 	char **result; 
// 	int i;
// 	atexit(leaks);
// 	i = 0;
// 	result = ft_split(tosplit, ' ');
// 	while(result[i])
// 	{
// 		printf("Result: %s\n", result[i]);
// 		i++;
// 	}
// 	ft_free(result, i);
// 	return (0);
// }