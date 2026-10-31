
// make the list circular y / n 
// if y i need to keep a and actualize
// or jsut make this repeat 


// para rotatos ciero el bucle i sellect 

void	rotate(**lst)
{
	t_list *aux;
	aux = *lst;

	while((*lst)->next)
		*lst=(*lst)->next;
	ft_lstadd_front(lst,*lst);
}
