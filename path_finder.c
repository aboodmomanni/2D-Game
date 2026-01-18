/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/19 02:16:16 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

static char	**grid_duplicate(char **grid)
{
	char	**clone;
	int		idx;

	idx = 0;
	clone = malloc(sizeof(char *) * (grid_height(grid) + 1));
	if (!clone)
		return (NULL);
	while (grid[idx])
	{
		clone[idx] = ft_strdup(grid[idx]);
		if (!clone[idx])
		{
			arr_destroy(clone);
			return (NULL);
		}
		idx++;
	}
	clone[idx] = NULL;
	return (clone);
}

static void	spread_mark(char **grid, int col, int row)
{
	if (col < 0 || row < 0 || !grid[row] || !grid[row][col])
		return ;
	if (grid[row][col] == '1' || grid[row][col] == 'X')
		return ;
	grid[row][col] = 'X';
	spread_mark(grid, col, row - 1);
	spread_mark(grid, col, row + 1);
	spread_mark(grid, col - 1, row);
	spread_mark(grid, col + 1, row);
}

static int	all_reached(char **grid)
{
	int	r;
	int	c;
	int	doors;
	int	gems;

	r = 0;
	gems = 0;
	doors = 0;
	while (grid[r])
	{
		c = 0;
		while (grid[r][c])
		{
			if (grid[r][c] == 'C')
				gems++;
			else if (grid[r][c] == 'E')
				doors++;
			c++;
		}
		r++;
	}
	return (gems == 0 && doors == 0);
}

int	board_path_check(char **grid)
{
	char	**clone;
	int		col;
	int		row;

	clone = grid_duplicate(grid);
	if (!clone)
		return (0);
	locate_hero(&col, &row, clone);
	spread_mark(clone, col, row);
	if (all_reached(clone))
	{
		arr_destroy(clone);
		return (1);
	}
	arr_destroy(clone);
	return (0);
}
