/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:49:04 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 17:25:19 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_top_elements(int *arr, int size)
{
	int	temp;

	if (size < 2)
		return ;
	temp = arr[0];
	arr[0] = arr[1];
	arr[1] = temp;
}

void	sa(t_piles *piles)
{
	swap_top_elements(piles->a, piles->size_a);
	ft_printf("sa\n");
}

void	sb(t_piles *piles)
{
	swap_top_elements(piles->b, piles->size_b);
	ft_printf("sb\n");
}

void	ss(t_piles *piles)
{
	sa(piles);
	sb(piles);
}

void	pa(t_piles *piles)
{
	int	i;

	if (piles->size_b == 0)
		return ;
	piles->size_a++;
	i = piles->size_a - 1;
	while (i-- > 0)
		piles->a[i] = piles->a[i - 1];
	piles->a[0] = piles->b[0];
	i = -1;
	while (++i < piles->size_b - 1)
		piles->b[i] = piles->b[i + 1];
	piles->size_b--;
	ft_printf("pa\n");
}
