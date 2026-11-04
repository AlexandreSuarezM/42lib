/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:35:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 17:07:07 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef pushswap
#define pushswap

typedef struct s_list
{
	int				content;
	struct s_list	*up;
	struct s_list	*down;
}	t_list;


#endif