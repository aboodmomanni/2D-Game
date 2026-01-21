/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/21 21:51:44 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

static int	is_rectangular(char **grid)
{
	int	row;
	int	next;

	if (!grid || !grid[0])
		return (0);
	row = 0;
	next = 1;
	while (grid[next])
	{
		if (ft_strlen(grid[row]) != ft_strlen(grid[next]))
			return (0);
		next++;
	}
	return (1);
}

static int	borders_sealed(char **grid)
{
	int	r;
	int	c;
	int	total_rows;
	int	total_cols;

	r = 0;
	total_rows = grid_height(grid);
	total_cols = grid_width(grid);
	while (grid[r])
	{
		c = 0;
		while (grid[r][c])
		{
			if (r == 0 || r == total_rows - 1 || c == 0 || c == total_cols - 1)
				if (grid[r][c] != '1')
					return (0);
			c++;
		}
		r++;
	}
	return (1);
}

static int	entities_valid(char **grid)
{
	int	r;
	int	c;
	int	heroes;
	int	doors;

	r = 0;
	heroes = 0;
	doors = 0;
	while (grid[r])
	{
		c = 0;
		while (grid[r][c])
		{
			if (grid[r][c] == 'P')
				heroes++;
			else if (grid[r][c] == 'E')
				doors++;
			c++;
		}
		r++;
	}
	if (heroes == 1 && doors == 1)
		return (1);
	return (0);
}

static int	has_gems(char **grid)
{
	int	r;
	int	c;
	int	gem_count;

	r = 0;
	gem_count = 0;
	while (grid[r])
	{
		c = 0;
		while (grid[r][c])
		{
			if (grid[r][c] == 'C')
				gem_count++;
			c++;
		}
		r++;
	}
	if (gem_count != 0)
		return (1);
	return (0);
}

int	board_validate(char **grid)
{
	if (!is_rectangular(grid) || !borders_sealed(grid))
		return (0);
	if (!entities_valid(grid) || !has_gems(grid) || !grid_char_ok(grid))
		return (0);
	return (1);
}
