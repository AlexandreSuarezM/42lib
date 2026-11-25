/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 14:00:00 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/25 14:00:00 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// moved here unchanged from push_swap.c so push_swap AND checker can use them
// (only "static" removed from skypflag, init_list and check_dupes)

// checks for known flags returns 1-1 for goo ones 
int	skypflag(char *arg)
{
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (-1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if(ft_strcmp(arg, "--medium") == 0)
		return (1);
	return (0);
}


// frees every word from ft_split and then the array itself
static void	free_split(char **args)
{
	size_t	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

//
void	init_list(char **argv, t_list **alst, int *size)
{
	size_t	i;
	char 	**args;
	size_t	j;
	t_list	*node;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args && args[j])
		{
			if(skypflag(args[j]))
				j++;
			else
			{
				node = ft_lstnew(ft_atoi(args[j], alst, args));
				ft_lstadd_top(alst, node);
				j++;
				(*size)++;
			}
		}
		free_split(args);
		i++;
	}

}


// checks for dupes on the list
// to iterate the list 
// alist rel poss count 
// outer loop: visit each of the size nodes once (aux)
// inner loop: compare aux with the other size - 1 nodes (aux2)
void	check_dupes(t_list **alst, int size)
{
	t_list	*aux;
	t_list	*aux2;
	int		i;
	int		j;

	if(!*alst)
		exit(0);
	aux = *alst;
	i = 0;
	while (i < size)
	{
		aux2 = aux->down;
		j = 0;
		while (j < size - 1)
		{
			if (aux->content == aux2->content)
				{
					write(2, "Error\n", 6);
					ft_lstclear(alst, NULL);
					exit(1);
				}
			if (aux->content > aux2->content)
				aux->rel_pos++;
			aux2 = aux2->down;
			j++;
		}
		aux = aux->down;
		i++;
	}
}
