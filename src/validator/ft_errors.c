/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zimbo <zimbo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:40:28 by zimbo             #+#    #+#             */
/*   Updated: 2025/12/06 00:28:36 by zimbo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_map_rectangle(t_data *game)
{
	int	y;
	int	first_width;

	if (game->map.height == 0)
		return (ft_putstr_fd("Error\nEmpty map\n", 2), -1);
	first_width = ft_strlen(game->map.map[0]);
	if (first_width == 0)
		return (ft_putstr_fd("Error\nFirst line is empty\n", 2), -1);
	y = 0;
	while (y < game->map.height)
	{
		if ((int)ft_strlen(game->map.map[y]) != first_width)
			return (ft_putstr_fd("Error\nMap is not rectangular\n", 2), -1);
		y++;
	}
	game->map.width = first_width;
	return (0);
}

int	ft_error(char *msg, t_data *game)
{
	ft_putstr_fd(msg, 2);
	ft_exit_game(game, EXIT_FAILURE);
	return (-1);
}

char	**duplicate_map(t_data *game)
{
	char	**dup;
	int		i;

	dup = malloc(sizeof(char *) * (game->map.height + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < game->map.height)
	{
		dup[i] = ft_strdup(game->map.map[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int	ft_check_extention(const char *file)
{
	int		len;
	char	*ext;

	if (!file || !*file)
		return (ft_putstr_fd("Error\nNo map file provided\n", 2), -1);
	len = ft_strlen(file);
	if (len < 5)
		return (ft_putstr_fd("Error\nInvalid file name\n", 2), -1);
	ext = (char *)file + len - 4;
	if (ft_strncmp(ext, ".ber", 5) != 0)
		return (ft_putstr_fd("Error\nFile must have .ber extension\n", 2), -1);
	return (0);
}

int	ft_check_requirements(t_data *game)
{
	if (game->map.player != 1)
	{
		if (game->map.player == 0)
			ft_putstr_fd("Error\nMissing player (P)\n", 2);
		else
			ft_putstr_fd("Error\nToo many players (P)\n", 2);
		return (-1);
	}
	if (game->map.exit != 1)
	{
		if (game->map.exit == 0)
			ft_putstr_fd("Error\nMissing exit (E)\n", 2);
		else
			ft_putstr_fd("Error\nToo many exits (E)\n", 2);
		return (-1);
	}
	if (game->map.collectible < 1)
	{
		ft_putstr_fd("Error\nNo collectibles (C)\n", 2);
		return (-1);
	}
	return (0);
}
