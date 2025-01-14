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

//voy a empezar con cinco rayos bien b'asicos lanzadados desde 5,4 o algo as'i

void	ft_rayete(t_data *data, int i)
{
	data->ray->deltaang = (PI / 2) / (WIDTH - 1); //5 - 1 porque 5 rayos, 4 huecos
//	data->ray->angle = (-PI/4) + (i * data->ray->deltaang);
	data->ray->angle = data->playa->angle + (i * data->ray->deltaang);
	data->ray->dir.x = cos(data->ray->angle); //distancias del rayo por unidad de grid
	data->ray->dir.y = sin(data->ray->angle);
	data->ray->origin = *data->playa->pos;
	data->ray->delta_x = fabs(1 / data->ray->dir.x);
	data->ray->delta_y = fabs(1 / data->ray->dir.y);

	data->ray->x_sign = 1; // podr'ia resumirlo dentro de dir creo.
	data->ray->y_sign = 1;

	// esto podria quedarse con los propiofs if mas tarde, ahora mismo es ruido
	if (data->ray->dir.x < 0)
		data->ray->x_sign = -1;
	if (data->ray->dir.y < 0)
		data->ray->y_sign = -1;

// teniendo las cosas unitarias podemos determinar el priemr triangulito al ser simple sacar la primra x e y.
// aqui estoy mirando la magnitud al primer cruce. pero no he visto el punto de cruce?
	data->ray->first_x = (data->ray->origin.x - ceil(data->ray->origin.x)) * data->ray->delta_x;
	//esti habr;ia que invertirlo por el tema del origen del cero. de momento trabajamos en cartesianos
	if (data->ray->dir.x < 0) //podria hacerlo con el cos y blabla
		data->ray->first_x = (data->ray->origin.x - floor(data->ray->origin.x)) * data->ray->delta_x;
	data->ray->first_y = (data->ray->origin.y - ceil(data->ray->origin.y)) * data->ray->delta_y;
	if (data->ray->dir.y > 0)
		data->ray->first_y = (data->ray->origin.y - floor(data->ray->origin.y)) * data->ray->delta_y;

	// Traverse the grid until a wall is hit
	int		map_x = (int)data->ray->origin.x;
	int		map_y = (int)data->ray->origin.y;

	// va comparando la magnitud del rayete y va comrpobando el peque;o, que sera la colision mas cercaan
	while (data->map[map_y][map_x] == '0')
	{
		if (fabs(data->ray->first_x) < fabs(data->ray->first_y))
		{
			data->ray->first_x += data->ray->delta_x;
			map_x += data->ray->x_sign;
			data->ray->length = data->ray->first_x;
			data->ray->last_cross = 0;
		}
		else
		{
			data->ray->first_y += data->ray->delta_y;
			map_y += data->ray->y_sign;
			data->ray->length = data->ray->first_y;
			data->ray->last_cross = 1;
		}
		printf("LENGTH INTRA %.2f | COORDINATES %i %i | X Y %.2f %.2f\n", data->ray->length, map_x, map_y, data->ray->first_x, data->ray->first_y);
//		printf("Map Pos: (%d, %d), first_x: %.2f, first_y: %.2f\n", 
//		map_x, map_y, data->ray->first_x, data->ray->first_y);
	}
	//if (data->ray->last_cross == 0)

	// Print results
	data->ray->wall_collision.x = data->ray->origin.x + data->ray->length * data->ray->dir.x; //esto serian el cos
	data->ray->wall_collision.y = data->ray->origin.y + data->ray->length * data->ray->dir.y; // esto el seno

	printf("Ray %d: Angle = %.2f, Hit Wall at (%d, %d), Coordinates (%.2f, %.2f), Distance = %.2f\n", 
		i, data->ray->angle, map_x, map_y, data->ray->wall_collision.x, data->ray->wall_collision.y, data->ray->length);

	//habr'ai que ver si return de distancia y con la orientacion o que
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
			mlx_put_pixel(f->img, col, j, 55555555);
		else if (j > bot)
			mlx_put_pixel(f->img, col, j, 99999999);
		else if (f->ray->x_sign == 1 && f->ray->last_cross == 0)
			mlx_put_pixel(f->img, col, j, 11111111);
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
		f->playa->pos->x += 0.1; // no funciona porque el bucle se reinicia.
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
		f->playa->pos->x -= 0.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		f->playa->pos->y += 0.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_A))
		f->playa->pos->y -= 0.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_E))
		f->playa->angle += 0.1;
	if (mlx_is_key_down(f->mlx, MLX_KEY_Q))
		f->playa->angle -= 0.1;
	//podr'ia concentrarlo todo en un funcion y tirarlo a mlx_key_hook

//	ft_key_control(f);
//	mlx_scroll_hook(f->mlx, &ft_scroll_hook, f);
//	ft_fractol(f);
	i = 0;
	while (i < 1080)
	{
	ft_rayete (f, i);
	ft_paint_walls(f, (WALL_H - (f->ray->length) * 30), i); // habia uqe a;adirle datos de colision
	i += 1;
	}
}

void	ft_openwindow(t_data *f)
{
//	ft_initiate_f(f);
	mlx_set_setting(MLX_STRETCH_IMAGE, true); //de momento no ase farta
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
	data.playa->pos->x = 2.5;
	data.playa->pos->y = 4.5;
	i = -1;
	while (data.map[++i])
		data.map[1] = ft_calloc(11, 1);
	data.map[0] = "1111111111";
	data.map[1] = "1000000001";
	data.map[2] = "1000000001";
	data.map[3] = "1000000001";
	data.map[4] = "1000000001";
	data.map[5] = "1000000001";
	data.map[6] = "1000000001";
	data.map[7] = "1000000001";
	data.map[8] = "1000000001";
	data.map[9] = "1111111111";
	data.map[10] = 0;
	i = -1;
//	while (++i < 20)
//		ft_rayete(data, i);
	ft_openwindow(&data);
	return (0);
}




//tendre segmentos de  (π/2)/x donde x son los huevos (rayos - 1)