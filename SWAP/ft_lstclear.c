/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 14:14:03 by asuarez           #+#    #+#             */
/*   Updated: 2026/10/31 18:06:43 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*porque me ha costado \
tonteria basica basica variable **a;
a es pointer to pointer to variable
but 
**a is the content and a is the memory
then the . has prio
then i just save the thingui and im good 
beacause its a void an i want to make it go trough i use poitners
Then i have to make the aux match 
aux is for save nex so i can delete with no loss
**lst.next enters to next wich is *sizet

*/

#include "libft.h"

void	*del(void * a)
{
	int *i;
	i = (int *)a;
	a = 0;
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (lst && del)
	{
		while (*lst)
		{
			aux = ((**lst).next);
			del((**lst).content);
			free(*lst);
			*lst = aux;
		}
		*lst = NULL;
	}
}
