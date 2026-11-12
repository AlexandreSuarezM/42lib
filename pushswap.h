/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuarez <asuarez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:35:59 by asuarez           #+#    #+#             */
/*   Updated: 2026/11/12 19:29:06 by asuarez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>


typedef struct s_list
{
	char			*content;
	int				rel_pos;     
	struct s_list	*up;
	struct s_list	*down;
}	t_list;

unsigned int	ft_lstsize(t_list *lst);
void	showlist(t_list *a);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(char *content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_top(t_list **lst, t_list *new);
double	disorder(t_list *lst);
void	ft_lstdelfirst(t_list **lst);
void	push(t_list **, t_list **);
void	rotatedown(t_list **lst);
void	rotateup(t_list **lst);
void	swap(t_list **lst);
void	selectionsort(t_list **a, t_list **b, int size);
double	disorder(t_list *lst);
int		compare(char *a, char *b);
int		ft_strcmp(char *s1, char *s2);
void	Radix(t_list **a, t_list **b, int size);

int	ft_printf(const char *str, ...);
int	ft_putstr(const char *str);
int	ft_hextoa(unsigned int num);
int	ft_hextoa_upper(unsigned int num);
int	ft_pointtoa(unsigned long long num);
int	ft_conv(char c, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putcharc(char c);
int	ft_putnbr_signed(int n, int count);
int	ft_putnbr_unsigned(unsigned int n, int count);
int	ft_putstr(const char *str);


#endif