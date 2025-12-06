/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:36:01 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:38:54 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init_game(t_data *game, char *map)
{
	ft_memset(game, 0, sizeof(t_data));
	if (ft_check_error(game, map) < 0)
		return (-1);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("Error\nFailed to initialize MLX\n", game));
	game->win = mlx_new_window(game->mlx,
			game->map.width * PIXEL,
			game->map.height * PIXEL, "so_long");
	if (!game->win)
		return (ft_error("Error\nFailed to create window\n", game));
	ft_create_images(game);
	if (game->map.trap > 0 && ft_init_traps(game) < 0)
		return (ft_error("Error\nFailed to initialize traps\n", game));
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		return (ft_putstr_fd("Error\nUsage: ./so_long <map.ber>\n", 2), 1);
	if (ft_init_game(&game, argv[1]) < 0)
		return (EXIT_FAILURE);
	mlx_loop_hook(game.mlx, ft_trap_anim, &game);
	mlx_hook(game.win, 2, 1L << 0, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_press_x, &game);
	ft_render(&game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
