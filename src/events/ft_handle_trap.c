/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_trap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:20:26 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/05 19:50:08 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_traps(t_data *game)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	z = 0;
	while (game->map.map[i] && z < game->map.trap)
	{
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'T')
			{
				game->t_pos.x[z] = j;
				game->t_pos.y[z] = i;
				z++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_init_traps(t_data *game)
{
	game->t_pos.x = malloc((game->map.trap + 1) * sizeof(int));
	game->t_pos.y = malloc((game->map.trap + 1) * sizeof(int));
	if (!game->t_pos.x || !game->t_pos.y)
	{
		if (game->t_pos.x)
			free(game->t_pos.x);
		if (game->t_pos.y)
			free(game->t_pos.y);
		return (-1);
	}
	game->t_pos.x[game->map.trap] = 0;
	game->t_pos.y[game->map.trap] = 0;
	ft_set_traps(game);
	return (0);
}

static void	ft_update_trap(t_data *game, char *sprite)
{
	int		pixel;
	void	*new_trap;

	pixel = PIXEL;
	new_trap = mlx_xpm_file_to_image(game->mlx, sprite, &pixel, &pixel);
	if (!new_trap)
		return ;
	mlx_destroy_image(game->mlx, game->img.trap);
	game->img.trap = new_trap;
	ft_render(game);
}

int	ft_trap_anim(t_data *game)
{
	static int	x;

	if (x == 10000)
		ft_update_trap(game, "./sprites/enime_1.xpm");
	else if (x == 20000)
	{
		ft_update_trap(game, "./sprites/enime_0.xpm");
		x = 0;
	}
	x++;
	ft_move_trap(game);
	return (0);
}

void	ft_free_traps(t_data *game)
{
	if (game->t_pos.y)
	{
		free(game->t_pos.y);
		game->t_pos.y = NULL;
	}
	if (game->t_pos.x)
	{
		free(game->t_pos.x);
		game->t_pos.x = NULL;
	}
}
