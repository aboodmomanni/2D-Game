/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by aalmoman          #+#    #+#             */
/*   Updated: 2026/01/21 21:51:44 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

void	cleanup_exit(t_game *gm)
{
	if (gm->grid)
		arr_destroy(gm->grid);
	if (gm->mlx)
	{
		if (gm->tex.door)
			mlx_destroy_image(gm->mlx, gm->tex.door);
		if (gm->tex.ground)
			mlx_destroy_image(gm->mlx, gm->tex.ground);
		if (gm->tex.hero)
			mlx_destroy_image(gm->mlx, gm->tex.hero);
		if (gm->tex.brick)
			mlx_destroy_image(gm->mlx, gm->tex.brick);
		if (gm->tex.gem)
			mlx_destroy_image(gm->mlx, gm->tex.gem);
		if (gm->win)
			mlx_destroy_window(gm->mlx, gm->win);
		mlx_destroy_display(gm->mlx);
		free(gm->mlx);
	}
	exit(0);
}

int	window_close(t_game *gm)
{
	cleanup_exit(gm);
	return (0);
}

int	key_press(int keycode, t_game *gm)
{
	if (keycode == KEY_ESC)
		cleanup_exit(gm);
	else if (keycode == KEY_W || keycode == KEY_UP)
		hero_step(gm, 0, -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		hero_step(gm, 0, 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		hero_step(gm, -1, 0);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		hero_step(gm, 1, 0);
	return (0);
}
