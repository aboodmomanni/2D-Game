/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmoman <aalmoman@amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 10:00:00 by student           #+#    #+#             */
/*   Updated: 2026/01/21 21:50:45 by aalmoman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2D_H
# define GAME_2D_H

# include "mlx.h"
# include "libft/libft.h"

# define CELL_SIZE 64

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_assets
{
	void	*brick;
	void	*ground;
	void	*hero;
	void	*gem;
	void	*door;
}			t_assets;
typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**grid;
	int			height;
	int			width;
	int			hero_row;
	int			hero_col;
	int			gems_left;
	int			steps;
	int			on_door;
	int			cell_dim;
	t_assets	tex;
}				t_game;
char	**board_parse(char *filepath);
int		board_validate(char **grid);
int		board_path_check(char **grid);
int		grid_height(char **grid);
int		grid_width(char **grid);
int		grid_char_ok(char **grid);
void	locate_hero(int *col, int *row, char **grid);
void	arr_destroy(char **arr);
int		game_setup(t_game *gm, char **grid);
void	assets_load(t_game *gm);
void	render_board(t_game *gm);
int		key_press(int keycode, t_game *gm);
int		window_close(t_game *gm);
void	cleanup_exit(t_game *gm);
void	hero_step(t_game *gm, int dcol, int drow);

#endif
