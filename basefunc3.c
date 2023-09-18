/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basefunc3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:01 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 16:22:22 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(int *arr, int size)
{
	int	i;
	int	temp;

	if (size == 0)
		return ;
	temp = arr[size - 1];
	i = size - 1;
	while (i > 0)
	{
		arr[i] = arr[i - 1];
		i--;
	}
	arr[0] = temp;
}

void	rra(t_piles *piles)
{
	reverse_rotate(piles->a, piles->size_a);
	ft_printf("rra\n");
}

void	rrb(t_piles *piles)
{
	reverse_rotate(piles->b, piles->size_b);
	ft_printf("rrb\n");
}

void	rrr(t_piles *piles)
{
	rra(piles);
	rrb(piles);
	ft_printf("rrr\n");
}
