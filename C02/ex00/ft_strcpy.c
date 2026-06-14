/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:44:45 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/14 16:22:33 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*parsing punteros a fucntiones sin malloc o
  dimension finita accede a memorias malas en string*/
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i ++;
	}
	i ++;
	dest[i] = '\0';
	return (dest);
}
/*
int main(int car, char **bar)
{

	char dest[2000];
	if(car < 2)
		return 0;
	printf("destination: %s\n", dest);
	ft_strcpy(dest, bar[1]);

	printf("destination: %s\n", dest);
}
*/
