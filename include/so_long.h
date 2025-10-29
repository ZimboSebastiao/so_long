/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:19 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/29 16:21:41 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# define PLAYER_WALK_1 "./assets/sprites/player_walk_1.xpm"
# define PLAYER_WALK_2 "./assets/sprites/player_walk_2.xpm"
# define PLAYER_WALK_3 "./assets/sprites/player_walk_3.xpm"
# define PLAYER_WALK_4 "./assets/sprites/player_walk_4.xpm"
# define PLAYER_WALK_5 "./assets/sprites/player_walk_5.xpm"
# define PLAYER_WALK_6 "./assets/sprites/player_walk_6.xpm"
# define PLAYER_WALK_7 "./assets/sprites/player_walk_7.xpm"
# define ANIMATION_FRAMES 7
# define ANIMATION_SPEED 5

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	void	**sprites;
	int		current_frame;
	int		frame_count;
	int		is_moving;
	int		direction;
	int		x;
	int		y;
	int		width;
	int		height;
}	t_player;

typedef	struct s_game
{
	void		*mlx;
	void		*win;
	t_player	player;
}	t_game;

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int	ft_key_release(int keycode, t_game *game);
int	ft_key_press(int keycode, t_game *game);
void	ft_render_player(t_game *game);
void	ft_init_player(t_game *game);
void	ft_init_game(t_game *game);
void	ft_update_animation(t_game *game);
void	ft_cleanup_player(t_game *game);
int	ft_game_loop(t_game *game);
int	ft_close_game(t_game *game);

#endif