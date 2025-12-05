#include "so_long.h"

void	ft_destroy_all_images(t_data *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->img.player_0)
		mlx_destroy_image(game->mlx, game->img.player_0);
	if (game->img.player_1)
		mlx_destroy_image(game->mlx, game->img.player_1);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.trap)
		mlx_destroy_image(game->mlx, game->img.trap);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.exit_open_img)
		mlx_destroy_image(game->mlx, game->img.exit_open_img);
}

void	ft_exit_game(t_data *game, int exit_code)
{
	if (!game)
		exit(exit_code);
	if (game->mlx)
	{
		ft_destroy_all_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
	}
	ft_free_traps(game);
	ft_free_map(game);
	exit(exit_code);
}

void	ft_game_over(t_data *game)
{
	if (!game || game->game_over)
		return ;
	game->game_over = 1;
	ft_putstr_fd("You got caught! Game Over.\n", 1);
	ft_exit_game(game, EXIT_FAILURE);
}

void	ft_check_winner(t_data *game)
{
	if (!game || game->game_over)
		return ;
	if (game->map.collectible == 0)
	{
		game->game_over = 1;
		ft_putstr_fd("Congrats! You win!\n", 1);
		ft_putstr_fd("Total moves: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putstr_fd("\n", 1);
		ft_exit_game(game, EXIT_SUCCESS);
	}
}