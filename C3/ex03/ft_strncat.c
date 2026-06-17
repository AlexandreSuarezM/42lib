/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:02:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/17 16:16:15 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	j;

	while (dest[i])
		i ++;
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j ++;
	}
	return (dest);
}
