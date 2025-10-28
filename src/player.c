/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:52:40 by zimbo             #+#    #+#             */
/*   Updated: 2025/10/28 18:33:45 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_init_player(t_game *game)
{
	game->player.sprite = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &game->player.width, &game->player.height);

	if (!game->player.sprite)
	{
		ft_putstr_fd("Error: Could not load player sprite", 2);
		exit(1);
	}

	game->player.x = 0;
	game->player.y = 0;
}

void	ft_render_player(t_game *game)
{
	if (game->player.sprite)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.sprite, game->player.x, game->player.y);
	}
}