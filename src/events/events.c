/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:02:06 by zimbo             #+#    #+#             */
/*   Updated: 2025/10/29 16:10:39 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_game(t_game *game)
{
	ft_cleanup_player(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (keycode == 65363)
	{
		game->player.is_moving = 1;
		game->player.x += 5;
	}
	return (0);
}

int	ft_key_release(int keycode, t_game *game)
{
	if (keycode == 65363)
		game->player.is_moving = 0;
	return (0);
}