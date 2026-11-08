/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 15:52:56 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/05 15:53:00 by asuarez          ###   ########.fr       */
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
		if(lst > lst->down)
			msitakes++;
		total++;
		lst = lst->down;
	}
	return (((double)mistakes)/total);
}



