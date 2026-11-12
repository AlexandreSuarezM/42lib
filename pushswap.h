/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:35:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/11 14:21:32 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>


typedef struct s_list
{
	char			*content;
	int				rel_pos;     
	struct s_list	*up;
	struct s_list	*down;
}	t_list;

t_list	*ft_lstnew(char *content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_top(t_list **lst, t_list *new);
double	disorder(t_list *lst);
void	ft_lstdelfirst(t_list **lst);
void	push(t_list **, t_list **);
void	rotatedown(t_list **lst);
void	rotateup(t_list **lst);
void	swap(t_list **lst);
int		selectionsort(t_list **a, t_list **b, int size);
double	disorder(t_list *lst);
int		compare(char *a, char *b);
int		ft_strcmp(char *s1, char *s2);
void	Radix(t_list **a, t_list **b, int size);


#endif