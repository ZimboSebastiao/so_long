/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:31:19 by zalberti          #+#    #+#             */
/*   Updated: 2025/10/28 18:33:36 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "libft.h"
# include "mlx.h"
# define PLAYER_PATH "./assets/sprites/player.xpm"

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
	void	*sprite;
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
void	ft_render_player(t_game *game);
void	ft_init_player(t_game *game);
void	ft_init_game(t_game *game);

#endif