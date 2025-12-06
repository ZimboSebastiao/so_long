/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:19:23 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 20:23:43 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_data *game)
{
	int	new_y;
	int	new_x;

	if (game->game_over)
		return ;
	new_y = game->p_pos.y - 1;
	new_x = game->p_pos.x;
	if (ft_can_move(game, new_y, new_x))
		ft_handle_move(game, new_y, new_x);
}

void	ft_move_down(t_data *game)
{
	int	new_y;
	int	new_x;

	if (game->game_over)
		return ;
	new_y = game->p_pos.y + 1;
	new_x = game->p_pos.x;
	if (ft_can_move(game, new_y, new_x))
		ft_handle_move(game, new_y, new_x);
}

void	ft_move_right(t_data *game)
{
	int	new_y;
	int	new_x;

	if (game->game_over)
		return ;
	new_y = game->p_pos.y;
	new_x = game->p_pos.x + 1;
	if (ft_can_move(game, new_y, new_x))
	{
		game->dir = 'r';
		ft_change_player(game, PIXEL, 'r');
		ft_handle_move(game, new_y, new_x);
	}
}

void	ft_move_left(t_data *game)
{
	int	new_y;
	int	new_x;

	if (game->game_over)
		return ;
	new_y = game->p_pos.y;
	new_x = game->p_pos.x - 1;
	if (ft_can_move(game, new_y, new_x))
	{
		game->dir = 'l';
		ft_change_player(game, PIXEL, 'l');
		ft_handle_move(game, new_y, new_x);
	}
}

void	ft_move(int key, t_data *game)
{
	if (key == 'w' || key == UP)
		ft_move_up(game);
	else if (key == 's' || key == DOWN)
		ft_move_down(game);
	else if (key == 'd' || key == RIGHT)
		ft_move_right(game);
	else if (key == 'a' || key == LEFT)
		ft_move_left(game);
}
