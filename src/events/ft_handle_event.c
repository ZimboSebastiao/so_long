/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:07 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/01 05:58:00 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_winner(t_data *game)
{
	if (game->map.collectible == 0)
	{
		ft_putstr_fd("Congrats! You win!\n", 2);
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_game_over(t_data *game)
{
	ft_putstr_fd("You got caught! You suck.\n", 2);
	ft_clear_images(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_FAILURE);
}

int	ft_key_press(int key, t_data *game)
{
	if (key == ESC)
	{
		ft_clear_images(game);
		ft_free_map(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else
		ft_move(key, game);
	return (0);
}

int	ft_press_x(t_data *game)
{
	ft_key_press(ESC, game);
	return (0);
}
