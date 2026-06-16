/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 20:15:45 by asuarez           #+#    #+#             */
/*   Updated: 2026/06/16 19:46:33 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*&& interesante i oviado*/
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i + k] == to_find[k] && to_find[k])
			k ++;
		if(to_find[k] == '\0')
			return (&to_find[i]);
		i ++;
	}
	return (0);
}
