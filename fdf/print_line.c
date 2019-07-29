/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:15:57 by gjuste            #+#    #+#             */
/*   Updated: 2019/01/29 12:35:55 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_point(t_mlx *mlx, int x, int y, unsigned int color)
{
	x += mlx->x_shift;
	y += mlx->y_shift;
	if (y >= 0 && x >= 0 && y < mlx->height && x < mlx->width)
		mlx->img_data[x + (y * mlx->width)] = color;
}

static void	print_x(t_mlx *mlx)
{
	int		i;
	int		cumul;
	int		dx;
	int		dy;

	dx = abs(mlx->map.xf - mlx->map.xi);
	dy = abs(mlx->map.yf - mlx->map.yi);
	cumul = dx / 2;
	i = 1;
	while (i <= dx)
	{
		mlx->map.xi += mlx->map.xinc;
		cumul += dy;
		if (cumul >= dy)
		{
			cumul -= dx;
			mlx->map.yi += mlx->map.yinc;
		}
		put_point(mlx, mlx->map.xi, mlx->map.yi, mlx->color);
		i++;
	}
}

static void	print_y(t_mlx *mlx)
{
	int		i;
	int		cumul;
	int		dx;
	int		dy;

	dx = abs(mlx->map.xf - mlx->map.xi);
	dy = abs(mlx->map.yf - mlx->map.yi);
	cumul = dy / 2;
	i = 1;
	while (i <= dy)
	{
		mlx->map.yi += mlx->map.yinc;
		cumul += dx;
		if (cumul >= dy)
		{
			cumul -= dy;
			mlx->map.xi += mlx->map.xinc;
		}
		put_point(mlx, mlx->map.xi, mlx->map.yi, mlx->color);
		i++;
	}
}

void		print_line(t_mlx *mlx)
{
	int dx;
	int dy;

	dx = abs(mlx->map.xf - mlx->map.xi);
	dy = abs(mlx->map.yf - mlx->map.yi);
	mlx->map.xinc = (mlx->map.xi < mlx->map.xf) ? 1 : -1;
	mlx->map.yinc = (mlx->map.yi < mlx->map.yf) ? 1 : -1;
	if (dy == 0)
		mlx->map.yinc = 0;
	put_point(mlx, mlx->map.xi, mlx->map.yi, mlx->color);
	if (dx > dy)
		print_x(mlx);
	else
		print_y(mlx);
}
