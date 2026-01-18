/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/19 02:03:36 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2d.h"

static void	finish_game(t_game *gm, int nc, int nr)
{
	if (gm->gems_left == 0)
	{
		gm->steps++;
		ft_putnbr_fd(gm->steps, 1);
		write(1, "\n", 1);
		cleanup_exit(gm);
	}
	else
	{
		gm->on_door = 1;
		gm->grid[gm->hero_row][gm->hero_col] = '0';
		gm->hero_col = nc;
		gm->hero_row = nr;
		gm->grid[gm->hero_row][gm->hero_col] = 'P';
		gm->steps++;
		ft_putnbr_fd(gm->steps, 1);
		write(1, "\n", 1);
		render_board(gm);
	}
}

static void	regular_move(t_game *gm, int nc, int nr)
{
	gm->hero_col = nc;
	gm->hero_row = nr;
	gm->grid[gm->hero_row][gm->hero_col] = 'P';
	gm->steps++;
	ft_putnbr_fd(gm->steps, 1);
	write(1, "\n", 1);
	render_board(gm);
}

void	hero_step(t_game *gm, int dcol, int drow)
{
	int	nc;
	int	nr;

	nc = gm->hero_col + dcol;
	nr = gm->hero_row + drow;
	if (gm->grid[nr][nc] == '1')
		return ;
	else if (gm->grid[nr][nc] == 'C')
		gm->gems_left--;
	else if (gm->grid[nr][nc] == 'E')
	{
		finish_game(gm, nc, nr);
		return ;
	}
	if (gm->on_door == 0)
		gm->grid[gm->hero_row][gm->hero_col] = '0';
	else
	{
		gm->grid[gm->hero_row][gm->hero_col] = 'E';
		gm->on_door = 0;
	}
	regular_move(gm, nc, nr);
}
