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

void	ft_rayete(t_data data, int i)
{
	data.ray->deltaang = (PI / 2) / 4; //5 - 1 porque 5 rayos, 4 huecos
	data.ray->angle = (0 - PI / 2) + (i * data.ray->deltaang); 
	data.ray->dir.x = cos(data.ray->angle);
	data.ray->dir.y = sin(data.ray->angle);
	data.ray->origin = *data.playa->pos;

	// Incremental steps for grid traversal
	double	delta_x = fabs(1 / data.ray->dir.x);
	double	delta_y = fabs(1 / data.ray->dir.y);

	// Step direction (+1 or -1) and initial distance to grid boundary
	int		step_x = (data.ray->dir.x < 0) ? -1 : 1;
	int		step_y = (data.ray->dir.y < 0) ? -1 : 1;
	double	side_x = (data.ray->dir.x < 0) ? (data.ray->dir.x - floor(data.ray->origin.x)) * delta_x : (ceil(data.ray->origin.x) - data.ray->origin.x) * delta_x;
	double	side_y = (data.ray->dir.y < 0) ? (data.ray->dir.y - floor(data.ray->origin.y)) * delta_y : (ceil(data.ray->origin.y) - data.ray->origin.y) * delta_y;

	// Traverse the grid until a wall is hit
	int		map_x = (int)data.ray->origin.x;
	int		map_y = (int)data.ray->origin.y;
	while (data.map[map_y][map_x] != '1')
	{
		if (side_x < side_y)
		{
			side_x += delta_x;
			map_x += step_x;
		}
		else
		{
			side_y += delta_y;
			map_y += step_y;
		}
	}
	// Calculate the distance to the wall
//	double	dist = (side_x < side_y) ? side_x - delta_x : side_y - delta_y;
	double	dist = fabs(1/cos((side_x)));
	// Print results
	printf("Ray %d: Angle = %.2f, Hit Wall at (%d, %d), Distance = %.2f\n", 
		i, data.ray->angle, map_x, map_y, dist);

//	ft_putstr_fd(data.map[1], 1);
//	ft_putchar_fd('\n', 1);
}

int	main(void)
{
	t_data	data;
	int		i;

	data.map = malloc(10 * sizeof(char *) + 1);
	data.playa = malloc(1 * sizeof(t_player));
	data.playa->pos = malloc(512);
	data.playa->pos->x = 4.5;
	data.playa->pos->y = 4.5;
	i = -1;
	while (data.map[++i])
		data.map[1] = ft_calloc(11, 1);
	data.map[1] = "1111111111";
	data.map[2] = "1000000001";
	data.map[3] = "1000000001";
	data.map[4] = "1000000001";
	data.map[5] = "1000000001";
	data.map[6] = "1000000001";
	data.map[7] = "1000000001";
	data.map[8] = "1000000001";
	data.map[9] = "1000000001";
	data.map[10] = "1111111111";
	data.map[11] = 0;
	i = -1;
	while (++i < 5)
		ft_rayete(data, i);
	return (0);
}

//tendre segmentos de  (π/2)/x donde x son los huevos (rayos - 1)