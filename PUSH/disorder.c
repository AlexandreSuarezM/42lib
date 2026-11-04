// the code has to +1 for bad sort and + 1 if not 
// for that take all the arguments 
// give them relative size. idfk its odd 
// mistakes / total < return 
// msitake = misplaced element = can compare in chuncks
// 1 2 3 or maybe they really jsut ask for order 1 2 and all g

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



// atoi guard for no nunmbers repated is done or 