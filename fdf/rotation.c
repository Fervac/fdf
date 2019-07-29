/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:21:27 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 12:22:13 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotation_z(t_mlx *mlx, int *x, int *y)
{
	int new_x;
	int new_y;

	new_x = ((sin(mlx->z_theta) * *y) + (cos(mlx->z_theta) * *x + 0));
	new_y = ((cos(mlx->z_theta) * *y) + (-sin(mlx->z_theta) * *x + 0));
	*x = new_x;
	*y = new_y;
}

static void	rotation_x(t_mlx *mlx, int *y, int *z)
{
	int	new_z;
	int new_y;

	new_y = ((cos(mlx->x_theta) * *y) + (-sin(mlx->x_theta) * *z));
	new_z = ((sin(mlx->x_theta) * *y) + (cos(mlx->x_theta) * *z));
	*y = new_y;
	*z = new_z;
}

static void	rotation_y(t_mlx *mlx, int *x, int *z)
{
	int	new_z;
	int new_x;

	new_x = ((cos(mlx->y_theta) * *x) + (sin(mlx->y_theta) * *z));
	new_z = ((-sin(mlx->y_theta) * *x) + (cos(mlx->y_theta) * *z));
	*x = new_x;
	*z = new_z;
}

void		set_rotation(t_mlx *mlx, int *x, int *y, int *z)
{
	rotation_z(mlx, x, y);
	rotation_x(mlx, y, z);
	rotation_y(mlx, x, z);
}
