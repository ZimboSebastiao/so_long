#include "so_long.h"

int main(void)
{
	t_game game;

	ft_init_game(&game);

	ft_render_player(&game);
	mlx_loop(game.mlx);
	return (0);
}