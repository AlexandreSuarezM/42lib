/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:20:27 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/26 20:45:03 by asuarez          ###   ########.fr       */
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

// if no parameters the prompt must be returned as it comes 

//  funcion qu eme tome los argumentos
//  --bench  "1  3   6 " 12     "" 





// takes argv
// counts total flags 
//  exits if too many 
// program can run with no flags 
static	void	flagcount(char **argv)
{
	int flag;
	int flag2;
	int	i;

	i = 0;
	flag = 0;
	flag2 = 0;
	while (argv[i])
	{
		if(skypflag(argv[i]) == 1)
			flag++;
		if(skypflag(argv[i]) == -1)
			flag2++;
		i++;
	}
	if (flag > 1 || flag2 > 1)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

// returns the complexity flag as text ("--simple", "--medium", ...)
// no complexity flag -> "--adaptive". Also turns bench_on to 1 on --bench.
// skypflag: 1 = complexity flag, -1 = --bench
static char	*get_flag(char **argv, int *bench_on)
{
	int		i;
	char	*flag;

	i = 1;
	flag = "--adaptive";
	*bench_on = 0;
	while (argv[i])
	{
		if (skypflag(argv[i]) == 1)
			flag = argv[i];
		else if (skypflag(argv[i]) == -1)
			*bench_on = 1;
		i++;
	}
	return (flag);
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

// no numbers to sort no error give back

// ./push_swap [--simple|--medium|--complex|--adaptive] [--bench] numbers...
// operations -> stdout, bench -> stderr
int	main(int argc, char **argv)
{
	int		list_size;
	int		bench_on;
	char	*flag;
	char	*used;
	double	dis;
	t_list	*alst;
	t_list	*blst;

	if (argc < 2)
		return (0);
	list_size = 0;
	alst = NULL;
	blst = NULL;
	flagcount(argv);
	flag = get_flag(argv, &bench_on);
	init_list(argv, &alst, &list_size);
	if (!alst)
		return (0);
	check_dupes(&alst, list_size);
	dis = disorder(alst);
	used = sort_stack(&alst, &blst, list_size, flag);
	if (bench_on)
		bench(dis, flag, used);
	ft_lstclear(&alst, NULL);
	return (0);
}
