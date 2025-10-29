#include "so_long.h"

int	ft_game_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	ft_update_animation(game);
	ft_render_player(game);

	return (0);
}

int main(void)
{
	t_game game;

	ft_init_game(&game);

	mlx_loop_hook(game.mlx, ft_game_loop, &game);
	mlx_hook(game.win, 2, 1L<<0, ft_key_press, &game);
	mlx_hook(game.win, 3, 1L<<1, ft_key_release, &game);
	mlx_hook(game.win, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}