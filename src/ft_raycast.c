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


//voy a empezar con cinco rayos bien b'asicos lanzadados desde 5,4 o algo as'i

void	ft_traverse_map(t_data *data)
{
	int		map_x;
	int		map_y;

	map_x = (int)data->ray->origin.x;
	map_y = (int)data->ray->origin.y;
//	while (data->map[map_y][map_x] == '0')
	while (map_y > 0 && map_y < 9 &&  //este seguro solo sirve para tama;o 10x10 que no crashee, habria que hacerlo dinamico al tama;o del cuadro.
		map_x > 0 && map_x < 9 && data->map[map_y][map_x] == '0')
	{
		if (fabs(data->ray->first_x) < fabs(data->ray->first_y)) // posible necesidad de epsilon
		{
			data->ray->length = data->ray->first_x * cos(data->ray->angle - (data->playa->angle)); // era hacer esto primero, loco.
			data->ray->first_x += data->ray->delta_x;
			map_x += data->ray->x_sign;
			data->ray->last_cross = 0;
		}
		else
		{
			data->ray->length = data->ray->first_y * cos(data->ray->angle - data->playa->angle);
			data->ray->first_y += data->ray->delta_y;
			map_y += data->ray->y_sign;
			data->ray->last_cross = 1;
		}
		printf("LENGTH INTRA %.2f | COORDINATES %i %i | X Y %.2f %.2f | PPOS %.2f %.2f || Last %i \n",
			data->ray->length, map_x, map_y, data->ray->first_x,
			data->ray->first_y, data->playa->pos->x, data->playa->pos->y, data->ray->last_cross);
	}
}

void	ft_ray_direction(t_data *data)
{
	data->ray->x_sign = 1;
	data->ray->y_sign = 1;
	if (data->ray->dir.x < 0)
		data->ray->x_sign = -1;
	if (data->ray->dir.y < 0)
		data->ray->y_sign = -1;
	data->ray->first_x = (ceil(data->ray->origin.x) - data->ray->origin.x)
		* data->ray->delta_x;
	if (data->ray->dir.x < 0)
		data->ray->first_x = (data->ray->origin.x - floor(data->ray->origin.x))
			* data->ray->delta_x;
	data->ray->first_y = (data->ray->origin.y - floor(data->ray->origin.y))
		* data->ray->delta_y;
	if (data->ray->dir.y > 0)
		data->ray->first_y = (ceil(data->ray->origin.y) - data->ray->origin.y)
			* data->ray->delta_y;
}

void	ft_init_ray(t_data *data, int i)
{
	data->ray->deltaang = (PI / 2) / (WIDTH - 1);
	data->ray->angle = data->playa->angle -(PI/4) + (i * data->ray->deltaang);
	data->ray->dir.x = cos(data->ray->angle);
	data->ray->dir.y = sin(data->ray->angle);
	data->ray->origin = *data->playa->pos;
	data->ray->delta_x = fabs(1 / data->ray->dir.x);
	data->ray->delta_y = fabs(1 / data->ray->dir.y);
}

void	ft_rayete(t_data *data, int i)
{
	ft_init_ray(data, i);
	ft_ray_direction(data);
	ft_traverse_map(data);
	data->ray->wall_collision.x = data->ray->origin.x + data->ray->length
		* data->ray->dir.x;
	data->ray->wall_collision.y = data->ray->origin.y + data->ray->length
		* data->ray->dir.y;
	printf("Ray %d: Angle = %.4f, Hit Wall at (NA, NA), Coordinates (%.2f, %.2f), Distance = %.2f\n",
		i, data->ray->angle, data->ray->wall_collision.x,
		data->ray->wall_collision.y, data->ray->length);
}
