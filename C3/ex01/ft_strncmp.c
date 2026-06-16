/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:51:33 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/16 19:13:18 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (i == n - 1)
			return (0);
		i ++;
	}
	return (0);
}
/*
int main(int car, char **bar){

	int n ;
	if (car < 3)
		return 1;
	n = ft_strncmp(bar[1],bar[2],5);
	printf("%d",n);
}
*/
