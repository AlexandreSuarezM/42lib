/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:34:35 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/10 17:17:35 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
//because rotating is jsut readjusting the index of the list
// last becomes first so we rotated down
void	rotatedown(t_list **lst)
{
	*lst = (*lst)->up;
}