/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:49:04 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/14 18:31:39 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *dest)
	{
		if (*src)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
		i ++;
	}
	return (dest);
}
/*
int main(int car, char **bar)
{
	int n = 5;
	char k[2000];
	
	if (car < 1){
		return 0;	
	}
	ft_strncpy(k,bar[1],10);

	printf("%s",k);
	return 0;
}
*/
