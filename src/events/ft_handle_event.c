/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:20:35 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:20:36 by zimbo            ###   ########.fr       */
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