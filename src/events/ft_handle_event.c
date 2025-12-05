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