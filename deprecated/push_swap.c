/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:20:27 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/23 19:16:47 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//flag snifer detects the flags counts the flags 
//because remembering the flag and checking it is the same
// we keep no track of were the flah was found

// redirects to the desired algoritm 
// this should loop the args and redirect to the desired algortims
// looping the arg

// once the program is well set look the 
//static void	algo_decision(char **argv)
//{
//	while ()
//	else if (argv[i] == "--complex" )
//	// call complex 
//	else if (argv[i] == "--medium" )
//	// meidum
//	else if (argv[i] == "--simple" )
//	// simple
//	else if (argv[i] == "--adaptive")
//	else 
//	{
//		return;
//		write(2, "Error\n", 6);
//	}
//	if (argv[0] == "--bench" || argv[1] == "--bench")
//		// call bench
//}
// take the input
// 
int	main(int argc, char **argv)
{
	int	list_size;
	t_list	*new;
	t_list	*alst;
	t_list	*aux;
	t_list	*blst;

	if(argc < 2)
		write(2, "Error\n", 6);
	if(argc < 2)
		return (1);
	list_size = 2; 
	alst = NULL;
	blst = NULL;

	// check flag count
	flagcount(&argv);
	// creates a lsit 
	init_list(argv, &alist);

	check_dupes(&alist);

	
		Radix(&alst,&blst, argc - 2);
	//if (ft_strcmp(argv[1],"--simple") == 0)
	//write(1, "Selec\n", 6 );
	//	selectionsort(&alst, &blst, argc - 2);
	//if (argv[1] == "medium")
	//Chunk-based sorting — O(n√n).
	
	//if (argv[1] == "adaptive")
	// adaptive
	//if (argv[1] == "checkers")
	//else
	//	return (0);

	//showlist(alst);
	printf("%d\n",dis)
	
	ft_lstclear(&alst);
	return (0);
}

// if no parameters the prompt must be returned as it comes 

//  funcion qu eme tome los argumentos
//  --bench  "1  3   6 " 12     "" 




// 
static void	init_list(char **argv, t_list **alst)
{
	size_t	i;
	char 	**args;
	size_t	j;
	
	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i]);
		j = 0;
		while (args[j])
		{
			if(skypflag(args[j]))
				j++;
			else
			{
				ft_lstmew(ft_atoi(args[j]));
				ft_lstadd_top(alst); // 
				j++;
			}
		}
		i++;
	}
	if(complex == 0)  // if no arguments return the same promp wich is char * separted by space.
	{
		while(argv[i])
			ft_printf("%s' '",argv[i]);
	}
}

// checks for known flags returns 1-1 for goo ones 
static int skypflag(char *arg)
{
	int	i;

	if (ft_strcmp(arg, "--complex"))
		return (1);
	if (ft_strcmp(arg, "--simple"))
		return (1);
	if (ft_strcmp(arg, "--bench"))
		return (-1);
	if (ft_strcmp(arg, "--adaptive"))
		return (1);
	if(ft_strcmp(arg, "--medium"))
		return (1);
	return (0);
}


// takes argv
// counts total flags 
//  exits if too many 
// program can run with no flags 
static	void	flagcount(char **argv)
{
	int flag;
	int flag2;

	fllag = 0;
	flag2 = 0;
	while (argv[i])
	{
		if(skypflag(argv[i]) == 1)
			flag++;
		if(skypflag(argv[i]) == -1)
			flag2++;
	}
	if (flag > 1 || flag2 > 1)
		exit (1);
	//gives prompt back
	while (**argv)
	{
		argv++;
		ft_printf("%s' '",*argv);
	}
}

// checks for dupes on the list
// to iterate the list 
// alist rel poss count 
static void check_dupes(t_list **alst)
{
	t_list	aux;
	t_list	aux2;

	aux = alst;
	while (aux->down != alst)
	{
		aux2 = aux->down;
		while (aux2 != aux)
		{
			if (aux->content == aux2->content)
				{
					// free & exit & write;
				}
			if (aux->content > aux2->content)
				(*aux)->rel_pos++;
			aux2 = aux2->down;
		}
		aux = aux->down;
	}
}

// check that the arguments needed are well established
//void    check_args(int argc, char **argv)
//{
//    int i;
//    int pass;
//
//    i = 1;
//	pass = 0;
//    while (i < argc)
//    {
//        if (!ft_strcmp(argv[i], "--simple")
//			|| !ft_strcmp(argv[i], "--complex")
//            || !ft_strcmp(argv[i], "--mediu")
//            || !ft_strcmp(argv[i], "--adaptive"))
//        else if (!ft_strcmp(argv[i], "--bench"))
//            bench = -bench;
//        i++;
//    }
//}