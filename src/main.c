#include "mlx.h"

int main(void)
{
	void *mlx;
	void *mlx_win;
	
	
	// inicialização da lib
	mlx = mlx_init();

	// criação da janela
	mlx_win = mlx_new_window(mlx, 420, 380, "Zimbo Sebastiao");

	// renderização da janela
	mlx_loop(mlx);

	(void)mlx_win;
	return (0);
}