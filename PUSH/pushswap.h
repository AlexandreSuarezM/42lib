/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:35:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 18:56:54 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef pushswap
# define pushswap

typedef struct s_list
{
	int				content;     
	struct s_list	*up;
	struct s_list	*down;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_up(t_list **lst, t_list *new);


#endif