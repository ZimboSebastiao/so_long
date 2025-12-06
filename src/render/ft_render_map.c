/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:19:44 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 20:18:23 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_exit(t_data *game)
{
	if (!game->map.exit_open)
	{
		game->map.exit_open = 1;
	}
}

static void	ft_render_map(t_data *game)
{
	int	y;
	int	x;

	if (game->map.collectible == 0)
		ft_open_exit(game);
	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			ft_draw_map(game, x, y);
			x++;
		}
		y++;
	}
}

static void	ft_render_moves(t_data *game)
{
	char	*show;

	show = ft_itoa(game->moves);
	if (!show)
		return ;
	mlx_string_put(game->mlx, game->win, 9, 13, 0x000000, show);
	mlx_string_put(game->mlx, game->win, 8, 12, 0xFFFFFF, show);
	free(show);
}

int	ft_render(t_data *game)
{
	if (!game->mlx || !game->win || game->game_over)
		return (0);
	ft_render_map(game);
	ft_render_moves(game);
	return (0);
}
