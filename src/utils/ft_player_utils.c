/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:58:43 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 20:28:55 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_can_move(t_data *game, int new_y, int new_x)
{
	char	cell;

	if (new_y < 0 || new_y >= game->map.height
		|| new_x < 0 || new_x >= game->map.width)
		return (0);
	cell = game->map.map[new_y][new_x];
	if (cell == '1')
		return (0);
	if (cell == 'E' && game->map.collectible > 0)
		return (0);
	return (1);
}

static int	ft_process_target_cell(t_data *game, int new_y, int new_x)
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
		return (1);
	}
	else if (current_cell == 'E' && game->map.collectible == 0)
	{
		ft_check_winner(game);
		return (1);
	}
	return (0);
}

void	ft_handle_move(t_data *game, int new_y, int new_x)
{
	if (ft_process_target_cell(game, new_y, new_x))
		return ;
	game->map.map[game->p_pos.y][game->p_pos.x] = '0';
	game->p_pos.y = new_y;
	game->p_pos.x = new_x;
	game->map.map[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	ft_render(game);
}
