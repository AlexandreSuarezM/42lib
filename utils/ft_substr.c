/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 12:29:11 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/24 18:55:51 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strlen2(char *str)
{
	int	k;

	k = 0;
	while (*str)
	{
		str ++;
		k ++;
	}
	return (k);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	a;

	a = 0;
	if (siz > 0)
	{
		while (a < siz - 1 && src[a])
		{
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (ft_strlen2(src));
}

static char	*ft_strdup(const char *s)
{
	char	*rt;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen2(s);
	rt = malloc(i + 1);
	if (rt == NULL)
		return (NULL);
	while (j < i)
	{
		rt[j] = s[j];
		j++;
	}
	rt[j] = '\0';
	return (rt);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen2(s);
	if (start >= size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
