/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_loader.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:27:49 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/03 11:17:59 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change_player_c(t_data *game, int pixel, char dir)
{
	if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_right_0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_right_1.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_left_0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_left_1.xpm", &pixel, &pixel);
	}
}

void	ft_change_player(t_data *game, int pixel, char dir)
{
	if (game->crystal == 1)
		ft_change_player_c(game, pixel, dir);
	else if (dir == 'r')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_right_0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_right_1.xpm", &pixel, &pixel);
	}
	else if (dir == 'l')
	{
		mlx_destroy_image(game->mlx, game->img.player_0);
		game->img.player_0 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_left_0.xpm", &pixel, &pixel);
		mlx_destroy_image(game->mlx, game->img.player_1);
		game->img.player_1 = mlx_xpm_file_to_image(game->mlx,
				"./sprites/swim_left_1.xpm", &pixel, &pixel);
	}
}

void	ft_create_images(t_data *game)
{
	int	pixel;

	pixel = PIXEL;
	game->img.floor = mlx_xpm_file_to_image(game->mlx,
			"./sprites/floor.xpm", &pixel, &pixel);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"./sprites/wall.xpm", &pixel, &pixel);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"./sprites/ice.xpm", &pixel, &pixel);
	game->img.trap = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enime_0.xpm", &pixel, &pixel);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exit_close.xpm", &pixel, &pixel);
	ft_create_player(game, pixel);
}

void	ft_create_player(t_data *game, int pixel)
{
	game->img.player_0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/fish_0.xpm", &pixel, &pixel);
	game->img.player_1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/fish_1.xpm", &pixel, &pixel);
}

void	ft_clear_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img.player_0);
	mlx_destroy_image(game->mlx, game->img.player_1);
	mlx_destroy_image(game->mlx, game->img.floor);
	mlx_destroy_image(game->mlx, game->img.collectible);
	mlx_destroy_image(game->mlx, game->img.trap);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.exit);
	free(game->t_pos.y);
	free(game->t_pos.x);
}
