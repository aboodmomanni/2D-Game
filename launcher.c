/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/21 21:38:42 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

static int	tally_gems(t_game *gm)
{
	int	r;
	int	c;
	int	total;

	r = 0;
	total = 0;
	while (gm->grid[r])
	{
		c = 0;
		while (gm->grid[r][c])
		{
			if (gm->grid[r][c] == 'C')
				total++;
			c++;
		}
		r++;
	}
	return (total);
}

static void	check_args(int argc, char *file)
{
	int	len;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long <map.ber>\n", 27);
		exit(1);
	}
	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 4], ".ber", 4))
	{
		write(2, "Map must have .ber extension\n", 29);
		exit(1);
	}
}

static void	init_game_state(t_game *gm, char **grid)
{
	gm->grid = grid;
	gm->height = grid_height(gm->grid);
	gm->width = grid_width(gm->grid);
	gm->steps = 0;
	gm->on_door = 0;
	gm->gems_left = tally_gems(gm);
	locate_hero(&gm->hero_col, &gm->hero_row, gm->grid);
}

static int	close_and_exit(t_game *gm)
{
	arr_destroy(gm->grid);
	mlx_destroy_window(gm->mlx, gm->win);
	mlx_destroy_display(gm->mlx);
	free(gm->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	char	**grid;
	t_game	gm;

	ft_bzero(&gm, sizeof(t_game));
	check_args(argc, argv[1]);
	grid = board_parse(argv[1]);
	if (!grid)
		return (write(2, "Error\n", 6));
	if (!board_validate(grid) || !board_path_check(grid) || !game_setup(&gm,
			grid))
	{
		arr_destroy(grid);
		return (write(2, "Error\n", 6));
	}
	gm.grid = grid;
	init_game_state(&gm, grid);
	assets_load(&gm);
	render_board(&gm);
	mlx_key_hook(gm.win, key_press, &gm);
	mlx_hook(gm.win, 17, 0, window_close, &gm);
	mlx_loop(gm.mlx);
	close_and_exit(&gm);
}
