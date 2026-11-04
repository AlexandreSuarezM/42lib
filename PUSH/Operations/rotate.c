/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:34:35 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/04 21:36:26 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//because rotating is jsut readjusting the index of the list
// last becomes first so we rotated down
void	rotatedown(t_list **lst)
{
	*lst = (*lst)->up;
}