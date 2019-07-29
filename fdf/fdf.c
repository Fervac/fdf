/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 10:56:45 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 16:50:48 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_color(t_mlx *mlx, int zi, int zf)
{
	if (zi != 0)
		mlx->color = 0xa03f9b;
	else
		mlx->color = 0xffffff;
	if (zi != zf)
		mlx->color = 0xe6c9ff;
}

static void	set_point(t_mlx *mlx)
{
	int		zi;
	int		zf;

	zi = (mlx->z_tab[mlx->map.yi][mlx->map.xi]) * mlx->scale / mlx->z_heigth;
	zf = (mlx->z_tab[mlx->map.yf][mlx->map.xf]) * mlx->scale / mlx->z_heigth;
	set_color(mlx, zi, zf);
	mlx->map.xi -= mlx->map.x_max / 2;
	mlx->map.xf -= mlx->map.x_max / 2;
	mlx->map.yi -= mlx->map.y_max / 2;
	mlx->map.yf -= mlx->map.y_max / 2;
	mlx->map.xi *= mlx->scale;
	mlx->map.yi *= mlx->scale;
	mlx->map.xf *= mlx->scale;
	mlx->map.yf *= mlx->scale;
	set_rotation(mlx, &mlx->map.xi, &mlx->map.yi, &zi);
	set_rotation(mlx, &mlx->map.xf, &mlx->map.yf, &zf);
	print_line(mlx);
}

static void	set_line_x(t_mlx *mlx, int x, int y)
{
	mlx->map.xi = x;
	mlx->map.yi = y;
	mlx->map.xf = x + 1;
	mlx->map.yf = y;
	set_point(mlx);
}

static void	set_line_y(t_mlx *mlx, int x, int y)
{
	mlx->map.xi = x;
	mlx->map.yi = y;
	mlx->map.xf = x;
	mlx->map.yf = y + 1;
	set_point(mlx);
}

void		fill_img_data(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < mlx->map.y_max)
	{
		x = 0;
		while (x < mlx->map.x_max)
		{
			if (x < mlx->map.x_max - 1)
				set_line_x(mlx, x, y);
			if (y < mlx->map.y_max - 1)
				set_line_y(mlx, x, y);
			x++;
		}
		y++;
	}
}
