/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/21 21:51:44 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

int	grid_height(char **grid)
{
	int	count;

	if (!grid || !grid[0])
		return (0);
	count = 0;
	while (grid[count])
		count++;
	return (count);
}

int	grid_width(char **grid)
{
	int	count;

	if (!grid || !grid[0])
		return (0);
	count = 0;
	while (grid[0][count])
		count++;
	return (count);
}

int	grid_char_ok(char **grid)
{
	int	r;
	int	c;

	r = 0;
	while (grid[r])
	{
		c = 0;
		while (grid[r][c])
		{
			if (grid[r][c] != '0' && grid[r][c] != '1' && grid[r][c] != 'C'
				&& grid[r][c] != 'E' && grid[r][c] != 'P')
				return (0);
			c++;
		}
		r++;
	}
	return (1);
}

void	locate_hero(int *col, int *row, char **grid)
{
	int	r;
	int	c;

	r = 0;
	while (grid[r])
	{
		c = 0;
		while (grid[r][c])
		{
			if (grid[r][c] == 'P')
			{
				*row = r;
				*col = c;
				return ;
			}
			c++;
		}
		r++;
	}
}

void	arr_destroy(char **arr)
{
	int	idx;

	idx = 0;
	if (!arr)
		return ;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}
