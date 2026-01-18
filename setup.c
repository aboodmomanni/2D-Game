/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/19 01:41:20 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

int	game_setup(t_game *gm, char **grid)
{
	int	win_width;
	int	win_height;

	win_width = grid_width(grid) * CELL_SIZE;
	win_height = grid_height(grid) * CELL_SIZE;
	gm->mlx = mlx_init();
	if (!gm->mlx)
		return (0);
	gm->win = mlx_new_window(gm->mlx, win_width, win_height, "game_2d");
	if (!gm->win)
	{
		mlx_destroy_display(gm->mlx);
		free(gm->mlx);
		return (0);
	}
	return (1);
}
