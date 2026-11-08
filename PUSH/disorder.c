/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:52:56 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/08 13:41:09 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	disorder(t_list *lst)
{
	int		total;
	int		mistakes;
	t_list	*aux;

	mistakes = 0;
	total = 0;
	aux = lst;
	while(lst->down != aux)
	{
		if(compare(lst,lst->down) < 0)
			msitakes++;
		total++;
		lst = lst->down;
	}
	return (((double)mistakes)/total);
}



