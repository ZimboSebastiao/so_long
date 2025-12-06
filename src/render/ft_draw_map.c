/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:13:05 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 20:17:24 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_tile(t_data *game, int x, int y)
{
	char	tile;

	tile = game->map.map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, x * PIXEL, y * PIXEL);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.floor, x * PIXEL, y * PIXEL);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * PIXEL, y * PIXEL);
	else if (tile == 'T')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.trap, x * PIXEL, y * PIXEL);
	else if (tile == 'E')
	{
		if (game->map.exit_open)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.exit_open_img, x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.exit, x * PIXEL, y * PIXEL);
	}
}

void	ft_draw_player(t_data *game, int x, int y)
{
	if (game->moves % 2 == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player_0, x * PIXEL, y * PIXEL);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player_1, x * PIXEL, y * PIXEL);
}

void	ft_draw_map(t_data *game, int x, int y)
{
	ft_draw_tile(game, x, y);
	if (game->p_pos.x == x && game->p_pos.y == y)
		ft_draw_player(game, x, y);
}
