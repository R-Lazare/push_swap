/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluiz <rluiz@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:04:55 by rluiz             #+#    #+#             */
/*   Updated: 2023/09/18 19:30:39 by rluiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_nb_of_quartiles(int size)
{
	int	nb_of_quartiles;

	nb_of_quartiles = 3;
	if (size < 200)
		nb_of_quartiles = 6;
	else if (size < 600)
		nb_of_quartiles = 9;
	return (nb_of_quartiles);
}

void	partition_by_quartiles_a(t_piles *piles)
{
	int	initial_size_a;
	int	nb_of_quartiles;
	int	quartile_size;
	int	i;
	int	j;

	initial_size_a = piles->size_a;
	nb_of_quartiles = get_nb_of_quartiles(piles->size_a);
	quartile_size = piles->size_a / nb_of_quartiles;
	j = 1;
	while (j <= nb_of_quartiles)
	{
		i = -1;
		while (++i < initial_size_a)
		{
			if (piles->a[0] <= piles->sorted[j * quartile_size])
				pb(piles);
			else
				ra(piles);
		}
		initial_size_a = piles->size_a;
		j++;
	}
	while (piles->size_a > 0)
		pb(piles);
}

void	find_and_push_max_to_a(t_piles *piles)
{
	int	i;
	int	index_max;

	i = 0;
	while (piles->size_b > 0)
	{
		i = 0;
		index_max = 0;
		while (i++ < piles->size_b)
		{
			if (piles->b[i] > piles->b[index_max])
				index_max = i;
		}
		if (index_max < piles->size_b / 2)
		{
			while (index_max-- > 0)
				rb(piles);
		}
		else
		{
			while (index_max++ < piles->size_b)
				rrb(piles);
		}
		pa(piles);
	}
}

int	is_sorted(t_piles *piles)
{
	int	i;

	i = 0;
	while (i < piles->size_a - 1)
	{
		if (piles->a[i] > piles->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	list_to_positive(t_piles *piles)
{
	int	i;
	int	min;

	i = -1;
	min = piles->a[0];
	while (++i < piles->size_a)
	{
		if (piles->a[i] < min)
			min = piles->a[i];
	}
	if (min <= 0)
	{
		i = -1;
		while (++i < piles->size_a)
			piles->a[i] = piles->a[i] - min + 1;
	}
	return (1);
}
