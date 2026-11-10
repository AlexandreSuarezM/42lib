/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:20:27 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:44:13 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_list	*new;
	t_list	*alst;
	t_list	*aux;
	t_list	*blst;

	if(argc < 2)
		return (0);
	i = 2;
	while (i < argc)
	{ 
		new = ft_lstnew((argv[i]));
		ft_lstadd_top(&alst, new);
		i++;
	}
	new = alst;
	while(new->down)
	{
		aux = new->down;
		while (aux)
		{
			if (aux->content == new->content)
				break;
			if (compare(aux->content,new->content) < 0)
				new->rel_pos++;
			aux = aux->down;
		}
		new = new->down;
	}
	if (ft_strcmp(argv[1],"simple"))
		selectionsort(&alst, &blst, argc - 2);
	//if (argv[1] == "medium")
	//Chunk-based sorting — O(n√n).
	if (ft_strcmp(argv[1],"complex"))
		Radix(&alst,&blst, argc - 2);
	//if (argv[1] == "adaptive")
	// adaptive
	//if (argv[1] == "checkers")
	else
		return (0);
	
	ft_lstclear(&alst);
	return (0);
}





