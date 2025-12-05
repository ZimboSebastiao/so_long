#include "so_long.h"

void	ft_change_player_c(t_data *game, int pixel, char dir)
{
	void	*new_player_0;
	void	*new_player_1;
	char	*path_0;
	char	*path_1;

	if (dir == 'r')
	{
		path_0 = "./sprites/swim_right_0.xpm";
		path_1 = "./sprites/swim_right_1.xpm";
	}
	else
	{
		path_0 = "./sprites/swim_left_0.xpm";
		path_1 = "./sprites/swim_left_1.xpm";
	}
	new_player_0 = mlx_xpm_file_to_image(game->mlx, path_0, &pixel, &pixel);
	new_player_1 = mlx_xpm_file_to_image(game->mlx, path_1, &pixel, &pixel);
	if (!new_player_0 || !new_player_1)
	{
		if (new_player_0)
			mlx_destroy_image(game->mlx, new_player_0);
		if (new_player_1)
			mlx_destroy_image(game->mlx, new_player_1);
		return ;
	}
	if (game->img.player_0)
		mlx_destroy_image(game->mlx, game->img.player_0);
	if (game->img.player_1)
		mlx_destroy_image(game->mlx, game->img.player_1);
	game->img.player_0 = new_player_0;
	game->img.player_1 = new_player_1;
}

void	ft_change_player(t_data *game, int pixel, char dir)
{
	if (game->crystal == 1)
		ft_change_player_c(game, pixel, dir);
	else if (dir == 'r')
		ft_change_player_c(game, pixel, 'r');
	else if (dir == 'l')
		ft_change_player_c(game, pixel, 'l');
}

void	ft_create_player(t_data *game, int pixel)
{
	game->img.player_0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/fish_0.xpm", &pixel, &pixel);
	game->img.player_1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/fish_1.xpm", &pixel, &pixel);
	if (!game->img.player_0 || !game->img.player_1)
	{
		ft_putstr_fd("Error\nFailed to load player images\n", 2);
		ft_exit_game(game, EXIT_FAILURE);
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
	game->img.exit_open_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/exit.xpm", &pixel, &pixel);
	if (!game->img.floor || !game->img.wall || !game->img.collectible ||
		!game->img.trap || !game->img.exit || !game->img.exit_open_img)
	{
		ft_putstr_fd("Error\nFailed to load game images\n", 2);
		ft_exit_game(game, EXIT_FAILURE);
	}
	ft_create_player(game, pixel);
}

void	ft_clear_images(t_data *game)
{
	ft_destroy_all_images(game);
	ft_free_traps(game);
}