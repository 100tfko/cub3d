/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:56:21 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/12/19 12:56:22 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/cub3d.h"

void	ft_error(int i, t_data *data)
{
	ft_putstr_fd("ERROR", 2);
	(void)data;
	exit(i);
}

void	ft_paint_walls(t_data *f, float wall, int col) //abr'ia que a;adirle la colision
{
	int	j;
	int	top;
	int	bot;

	top = HEIGHT / 2 - wall / 2;
	if (top < 0)
		top = 0;
	bot = top + wall;
	j = 0;
//	ft_init_pixel(coll, wall, info); esto pa decidir que pixeles, la textura
	while (j < HEIGHT)
	{
		if (j < top)
			mlx_put_pixel(f->img, col, j, (255 << 24 | 255 << 16 | 255 << 8 | 150));
		else if (j > bot)
			mlx_put_pixel(f->img, col, j, 99999999);
		else if (f->ray->x_sign == 1 && f->ray->last_cross == 0)
			mlx_put_pixel(f->img, col, j, (255 << 24 | 0 << 16 | 0 << 8 | 100));
		else if (f->ray->x_sign == -1 && f->ray->last_cross == 0)
			mlx_put_pixel(f->img, col, j, 22222222);
		else if (f->ray->y_sign == 1 && f->ray->last_cross == 1)
			mlx_put_pixel(f->img, col, j, 33333333);
		else if (f->ray->y_sign == -1 && f->ray->last_cross == 1)
			mlx_put_pixel(f->img, col, j, 44444444);
		j++;

	}
//	ft_draw_walls(info, coll, col, top);
}

void	ft_hook(void *param)
{
	t_data	*f;
	int		i;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	if (mlx_is_key_down(f->mlx, MLX_KEY_W))
		f->playa->pos->x += 0.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
		f->playa->pos->x -= 0.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		f->playa->pos->y += 0.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_A))
		f->playa->pos->y -= 0.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_E))
		f->playa->angle += 0.05;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Q))
		f->playa->angle -= 0.05;
	i = 0;
	while (i < 1080)
	{
		ft_rayete (f, i);
		ft_paint_walls(f, (WALL_H - (f->ray->length) * 40), i); // habia uqe a;adirle datos de colision
		i += 1;
	}
}

void	ft_init_f(t_data *f)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true); //de momento no ase farta hay que mirar que hace
	f->mlx = mlx_init(WIDTH, HEIGHT, "VENTANA", false);
	if (!f->mlx)
		ft_error(MLX_ERROR, f);
//	if (ft_check_monitor(info->mlx) == 0) //esto es de elisa que no se que sera
//		return (-1);
//	mlx_set_window_limit(f->mlx, 500, 500, 2560, 1440); //esto va junto con el estirar verdad?
// nu ze si la imagen me est'a haciendo algo ahora la verdat
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->prueba = 0;
	f->playa->angle = 0;
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error(IMG_ERROR, f);
}

void	ft_openwindow(t_data *f)
{
	ft_init_f(f);
	mlx_loop_hook(f->mlx, &ft_hook, f);
	mlx_loop(f->mlx);
	mlx_delete_image(f->mlx, f->img);
	mlx_terminate(f->mlx);
}

int	main(void)
{
	t_data	data;
	int		i;

	data.ray = malloc(sizeof(t_ray) + 1);
	data.map = malloc(10 * sizeof(char *) + 1);
	data.playa = malloc(1 * sizeof(t_player));
	data.playa->pos = malloc(512);
	data.playa->pos->x = 6.5;
	data.playa->pos->y = 6.5;
	i = -1;
	while (data.map[++i])
		data.map[1] = ft_calloc(11, 1);
	data.map[0] = "1111111111";
	data.map[1] = "1000000001";
	data.map[2] = "1011100001";
	data.map[3] = "1010100001";
	data.map[4] = "1011100001";
	data.map[5] = "1000000001";
	data.map[6] = "1000000001";
	data.map[7] = "1000000001";
	data.map[8] = "1100000001";
	data.map[9] = "1111111111";
	data.map[10] = 0;
	i = -1;
	ft_openwindow(&data);
	return (0);
}




//tendre segmentos de  (π/2)/x donde x son los huevos (rayos - 1)