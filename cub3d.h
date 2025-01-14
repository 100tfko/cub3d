/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:33:38 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/12/19 11:33:39 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# include <fcntl.h>
# include <limits.h>
# define _USE_MATH_DEFINES
# include <math.h>
# include <memory.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*--------------------------------   MACROS   --------------------------------*/
/*SIZE*/
# define WIDTH 1080
# define HEIGHT 700
// esto copiadito de la elisa
# define WALL_H 500 // altura del muro, puse eso por probar xd
# define WALL_W 500 // ancho del muro, puse eso por probar xd
# define FOV 90 // campo de visión
//ERORS
# define MLX_ERROR 1
# define IMG_ERROR 2
/*PI*/
# define PI 3.14159265358979323846 //existe el M_PI pero me puedo fiar?

/*--------------------------------   STRUCTS   -------------------------------*/

typedef struct s_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_rgb;

typedef struct s_coordinate
{
	double	x; //como lo calculo esto ser'ia la magnitud del rayo por undiad de x
	double	y; //lo mismo con y
}	t_coordinate;

typedef struct s_player
{
	t_coordinate	*pos;
	t_coordinate	*center;
	mlx_image_t		*player_img;
	mlx_image_t		*line_img;
	mlx_t			*mlx;
	int				color;
	double			mov_speed;
	double			rot_speed;
	int				angle;
	int				size;
}	t_player;

typedef struct s_collision
{
	t_coordinate	coordinate;
	double			hypotenuse;
	// eli marca una distancia, que quiza sea pa evitar el ojo de pez
}	t_collision;


typedef struct s_ray
{
	double			angle;
	double			deltaang;
	t_coordinate	origin;
	t_coordinate	dir;
	double			delta_x; //this is the absolute distance that the ray has to traverse for a collision with the grid.
	double			delta_y;
	double			first_x;
	double			first_y;
	double			length;
	int				x_sign; // initiate at 1 and then if chage to -1 to fix direction
	int				y_sign;
	int				last_cross; //0 si toco x, 1 si toco y. Asi se puede restar el ultimo paso
	t_coordinate	wall_collision;
}	t_ray;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_ray		*ray;
	t_player	*playa;	
	char		**map;
	int			prueba;
}	t_data;

/*-------------------------------   FUNCTIONS   ------------------------------*/

// main file
int	main(void);

// aux file

// error file

// fractals file

// color file

//hook file

#endif
