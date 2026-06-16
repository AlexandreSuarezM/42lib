/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:02:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/16 19:15:33 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	while (*dest)
		i ++;
	while (*src && j < nb)
	{
		dest[i + j] = src[j];
		j ++;
	}
	return (dest);
}
