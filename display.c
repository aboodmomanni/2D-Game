/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/19 01:41:01 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

void	assets_load(t_game *gm)
{
	int	dim;

	dim = CELL_SIZE;
	gm->tex.brick = mlx_xpm_file_to_image(gm->mlx, "sprites/brick.xpm",
			&dim, &dim);
	gm->tex.ground = mlx_xpm_file_to_image(gm->mlx, "sprites/ground.xpm",
			&dim, &dim);
	gm->tex.hero = mlx_xpm_file_to_image(gm->mlx, "sprites/hero.xpm",
			&dim, &dim);
	gm->tex.gem = mlx_xpm_file_to_image(gm->mlx, "sprites/gem.xpm",
			&dim, &dim);
	gm->tex.door = mlx_xpm_file_to_image(gm->mlx, "sprites/door.xpm",
			&dim, &dim);
	if (!gm->tex.brick || !gm->tex.ground || !gm->tex.hero
		|| !gm->tex.gem || !gm->tex.door)
		cleanup_exit(gm);
	gm->cell_dim = dim;
}

static void	draw_cell(t_game *gm, int col, int row)
{
	int		px;
	int		py;
	char	cell;

	px = col * gm->cell_dim;
	py = row * gm->cell_dim;
	cell = gm->grid[row][col];
	mlx_put_image_to_window(gm->mlx, gm->win, gm->tex.ground, px, py);
	if (cell == '1')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->tex.brick, px, py);
	else if (cell == 'P')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->tex.hero, px, py);
	else if (cell == 'C')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->tex.gem, px, py);
	else if (cell == 'E')
		mlx_put_image_to_window(gm->mlx, gm->win, gm->tex.door, px, py);
}

void	render_board(t_game *gm)
{
	int	col;
	int	row;

	row = 0;
	while (gm->grid[row])
	{
		col = 0;
		while (gm->grid[row][col])
		{
			draw_cell(gm, col, row);
			col++;
		}
		row++;
	}
}
