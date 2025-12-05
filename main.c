#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long <map.ber>\n", 2);
		return (EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_data));
	if (ft_check_error(&game, argv[1]) < 0)
		return (EXIT_FAILURE);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr_fd("Error\nFailed to initialize MLX\n", 2);
		ft_free_map(&game);
		return (EXIT_FAILURE);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * PIXEL,
			game.map.height * PIXEL, "so_long");
	if (!game.win)
	{
		ft_putstr_fd("Error\nFailed to create window\n", 2);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		ft_free_map(&game);
		return (EXIT_FAILURE);
	}
	ft_create_images(&game);
	if (game.map.trap > 0 && ft_init_traps(&game) < 0)
	{
		ft_putstr_fd("Error\nFailed to initialize traps\n", 2);
		ft_exit_game(&game, EXIT_FAILURE);
	}
	mlx_loop_hook(game.mlx, &ft_trap_anim, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_press_x, &game);
	ft_render(&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}