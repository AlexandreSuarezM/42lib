/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:24:26 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/16 19:09:00 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	k;
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			k = s1[i] - s2[i];
		i ++;
	}
	return (k);
}
/*
int main(int car, char **bar){

        int k;
        if(car <2) 
                return 1;
        k = ft_strcmp(bar[1],bar[2]);
        printf("%d",k);
        return 0;
}
*/
