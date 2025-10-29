/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:52:40 by zimbo             #+#    #+#             */
/*   Updated: 2025/10/29 16:49:36 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void	ft_load_player_sprites(t_game *game)
{
	char	*paths[ANIMATION_FRAMES] = 
	{
		PLAYER_WALK_1, PLAYER_WALK_2, PLAYER_WALK_3, PLAYER_WALK_4, PLAYER_WALK_5, PLAYER_WALK_6,
		PLAYER_WALK_7
	};
	int		i;
	int		width;
	int		height;

	game->player.sprites = malloc(sizeof(void *) * ANIMATION_FRAMES);
	if (!game->player.sprites)
	{
		ft_putstr_fd("Error: Memory allocation failed for player sprites\n", 2);
		exit(1);
	}
	i = 0;
	while (i < ANIMATION_FRAMES)
	{
		game->player.sprites[i] = mlx_xpm_file_to_image(game->mlx, paths[i], &width, &height);
		if (!game->player.sprites[i])
		{
			ft_putstr_fd("Error: Could not load player sprite\n", 2);
			exit(1);
		}
		i++;
	}
}

void	ft_init_player(t_game *game)
{
	ft_load_player_sprites(game);
	game->player.current_frame = 0;
	game->player.frame_count = 0;
	game->player.is_moving = 0;
	game->player.direction = 0;

	game->player.x = 10;
	game->player.y = 350;
	game->player.width = 64;
	game->player.height = 64;
}

void	ft_update_animation(t_game *game)
{
	if (!game->player.is_moving)
	{
		game->player.current_frame = 0;
		game->player.frame_count = 0;
		return ;
	}

	game->player.frame_count++;
	if (game->player.frame_count >= ANIMATION_SPEED)
	{
		game->player.frame_count = 0;
		game->player.current_frame++;
		if (game->player.current_frame >= ANIMATION_FRAMES)
			game->player.current_frame = 0;
	}
}

void	ft_render_player(t_game *game)
{
	if (game->player.sprites && game->player.current_frame < ANIMATION_FRAMES)
	{
		mlx_put_image_to_window(
			game->mlx,
			game->win,
			game->player.sprites[game->player.current_frame],
			game->player.x,
			game->player.y
		);
	}
}

void ft_cleanup_player(t_game *game)
{
	int	i;

	if (game->player.sprites)
	{
		i = 0;
		while (i < ANIMATION_FRAMES)
		{
			if (game->player.sprites[i])
				mlx_destroy_image(game->mlx, game->player.sprites[i]);
			i++;
		}
		free(game->player.sprites);
		game->player.sprites = NULL;
	}
}