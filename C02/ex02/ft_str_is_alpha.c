/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 14:01:26 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/14 18:30:46 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*boolean logic goes on 0 1
 * taking multiple ope
 * rand <> in one go makes i tautological*/
/*el espacio se consider
 * a un caracter alfanumerico*/
int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str < 65 || *str > 90) && (*str < 97 || *str > 122))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*

int main(int car, char **bar) {

	int i;
	if (car < 1)
		return 1;
	i = ft_str_is_alpha(bar[1]);
	printf("%d",i);
	return 0;
}
*/
