/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:39:37 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 17:00:31 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_pad(int key, t_mlx *mlx)
{
	if (key == KEY_PAD_ADD)
		mlx->scale += 2;
	if (key == KEY_PAD_SUB)
		if (mlx->scale >= 3)
			mlx->scale -= 2;
	if (key == KEY_PAD_1)
		if (mlx->z_heigth >= 2)
			mlx->z_heigth--;
	if (key == KEY_PAD_3)
		if (mlx->z_heigth <= 25)
			mlx->z_heigth++;
	if (key == KEY_PAD_4)
		mlx->z_theta -= 0.1;
	if (key == KEY_PAD_6)
		mlx->z_theta += 0.1;
}

static void	arrows(int key, t_mlx *mlx)
{
	if (key == KEY_LEFT)
		mlx->y_theta -= 0.1;
	if (key == KEY_RIGHT)
		mlx->y_theta += 0.1;
	if (key == KEY_DOWN)
		mlx->x_theta -= 0.1;
	if (key == KEY_UP)
		mlx->x_theta += 0.1;
}

static void	escape(t_mlx *mlx)
{
	free_all(mlx);
	exit(EXIT_SUCCESS);
}

int			get_input(int key, t_mlx *mlx)
{
	if (key == KEY_PAD_1 || key == KEY_PAD_3 || key == KEY_PAD_4
	|| key == KEY_PAD_6 || key == KEY_PAD_ADD || key == KEY_PAD_SUB)
		key_pad(key, mlx);
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN
		|| key == KEY_UP)
		arrows(key, mlx);
	if (key == KEY_A)
		mlx->x_shift -= 15;
	if (key == KEY_S)
		mlx->y_shift += 15;
	if (key == KEY_D)
		mlx->x_shift += 15;
	if (key == KEY_W)
		mlx->y_shift -= 15;
	if (key == KEY_ESCAPE)
		escape(mlx);
	if (key == KEY_R)
	{
		mlx->scale = 10;
		reset_aff(mlx);
	}
	print_img(mlx);
	return (0);
}
