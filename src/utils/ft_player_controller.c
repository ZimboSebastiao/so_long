/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:19:23 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:19:27 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_can_move(t_data *game, int new_y, int new_x)
{
	char	cell;

	if (new_y < 0 || new_y >= game->map.height || 
		new_x < 0 || new_x >= game->map.width)
		return (0);
	cell = game->map.map[new_y][new_x];
	if (cell == '1')
		return (0);
	if (cell == 'E' && game->map.collectible > 0)
		return (0);
	return (1);
}

static void	ft_handle_move(t_data *game, int new_y, int new_x)
{
	char	current_cell;
	
	current_cell = game->map.map[new_y][new_x];
	
	if (current_cell == 'C')
	{
		game->map.collectible--;
		game->crystal = 1;
		game->map.map[new_y][new_x] = '0';
		if (game->map.collectible == 0)
			ft_open_exit(game);
	}
	else if (current_cell == 'T')
	{
		ft_game_over(game);
		return ;
	}
	else if (current_cell == 'E' && game->map.collectible == 0)
	{
		ft_check_winner(game);
		return ;
	}
	
	game->map.map[game->p_pos.y][game->p_pos.x] = '0';
	game->p_pos.y = new_y;
	game->p_pos.x = new_x;
	game->map.map[new_y][new_x] = 'P';
	
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	ft_render(game);
}

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