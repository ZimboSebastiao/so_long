/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:28:39 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/01 05:45:37 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments.\n", 2);
		return (0);
	}
	if (ft_check_error(&game, argv[1]) < 0)
		return (0);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		ft_putstr_fd("Error\nMissing graphical interface.\n", 2);
		ft_free_map(&game);
		ft_free_traps(&game);
		return (0);
	}
	game.win = mlx_new_window(game.mlx, game.map.width * PIXEL,
			game.map.height * PIXEL, "So Long!");
	ft_create_images(&game);
	mlx_loop_hook(game.mlx, &ft_trap_anim, &game);
	mlx_expose_hook(game.win, &ft_render, &game);
	mlx_key_hook(game.win, ft_key_press, &game);
	mlx_hook(game.win, 17, 0, ft_press_x, &game);
	mlx_loop(game.mlx);
}
