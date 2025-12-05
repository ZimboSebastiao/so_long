/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:19:44 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:19:48 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map(t_data *game, int x, int y)
{
	if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.wall,
			x * PIXEL, y * PIXEL);
	else if (game->map.map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img.floor,
			x * PIXEL, y * PIXEL);
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, x * PIXEL, y * PIXEL);
	else if (game->map.map[y][x] == 'T')
		mlx_put_image_to_window(game->mlx, game->win, game->img.trap,
			x * PIXEL, y * PIXEL);
	else if (game->map.map[y][x] == 'E')
	{
		if (game->map.exit_open)
			mlx_put_image_to_window(game->mlx, game->win,
				game->img.exit_open_img, x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
				x * PIXEL, y * PIXEL);
	}
	else if (game->map.map[y][x] == 'P')
	{
		if (game->moves % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img.player_0,
				x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img.player_1,
				x * PIXEL, y * PIXEL);
	}
	
	if (game->p_pos.x == x && game->p_pos.y == y)
	{
		if (game->moves % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->img.player_0,
				x * PIXEL, y * PIXEL);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img.player_1,
				x * PIXEL, y * PIXEL);
	}
}

void	ft_open_exit(t_data *game)
{
	if (!game->map.exit_open)
	{
		game->map.exit_open = 1;
	}
}

int	ft_render(t_data *game)
{
	int		y;
	int		x;
	char	*show;

	if (!game->mlx || !game->win || game->game_over)
		return (0);
	if (game->map.collectible == 0)
		ft_open_exit(game);
	y = 0;
	while (game->map.map[y] != NULL)
	{
		x = 0;
		while (game->map.map[y][x] != '\0')
		{
			ft_draw_map(game, x, y);
			x++;
		}
		y++;
	}
	show = ft_itoa(game->moves);
	if (show)
	{
		mlx_string_put(game->mlx, game->win, 9, 13, 0x000000, show);
		mlx_string_put(game->mlx, game->win, 8, 12, 0xFFFFFF, show);
		free(show);
	}
	return (0);
}