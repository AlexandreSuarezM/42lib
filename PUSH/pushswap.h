/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:35:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/05 15:04:56 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>


typedef struct s_list
{
	int				content;
	int				rel_pos;     
	struct s_list	*up;
	struct s_list	*down;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_up(t_list **lst, t_list *new);
double	disorder(t_list *lst);
void	ft_lstdelfirst(t_list **lst);

#endif