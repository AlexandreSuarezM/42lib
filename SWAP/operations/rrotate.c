


in main 
	t_list *lsit;
	rrotate(&list);

// rotate up so fast is first.
void rrotate(t_list **list)
{
	ft_lstadd_back(list,*list);
}

// push up 
so first becomes last 
so now first points 