/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:06 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 17:24:39 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb(t_piles *piles)
{
	int	i;

	if (piles->size_a == 0)
		return ;
	piles->size_b++;
	i = piles->size_b - 1;
	while (i > 0)
	{
		piles->b[i] = piles->b[i - 1];
		i--;
	}
	piles->b[0] = piles->a[0];
	i = -1;
	while (++i < piles->size_a - 1)
		piles->a[i] = piles->a[i + 1];
	piles->size_a--;
	ft_printf("pb\n");
}

void	rotate(int *arr, int size)
{
	int	i;
	int	temp;

	if (size == 0)
		return ;
	temp = arr[0];
	i = 0;
	while (i < size - 1)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[size - 1] = temp;
}

void	ra(t_piles *piles)
{
	rotate(piles->a, piles->size_a);
	ft_printf("ra\n");
}

void	rb(t_piles *piles)
{
	rotate(piles->b, piles->size_b);
	ft_printf("rb\n");
}

void	rr(t_piles *piles)
{
	ra(piles);
	rb(piles);
}
