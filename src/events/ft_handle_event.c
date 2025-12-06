/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:20:35 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 20:01:56 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_press(int key, t_data *game)
{
	if (key == ESC)
		ft_exit_game(game, EXIT_SUCCESS);
	else if (!game->game_over)
		ft_move(key, game);
	return (0);
}

int	ft_press_x(t_data *game)
{
	ft_exit_game(game, EXIT_SUCCESS);
	return (0);
}

void	ft_get_player_paths(char dir, char **p0, char **p1)
{
	if (dir == 'r')
	{
		*p0 = "./sprites/swim_right_0.xpm";
		*p1 = "./sprites/swim_right_1.xpm";
	}
	else
	{
		*p0 = "./sprites/swim_left_0.xpm";
		*p1 = "./sprites/swim_left_1.xpm";
	}
}
