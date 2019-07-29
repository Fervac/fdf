/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 11:29:34 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 16:57:14 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reset_aff(t_mlx *mlx)
{
	int	y_scale;

	y_scale = (mlx->height / mlx->map.y_max) / 2;
	mlx->scale = (mlx->width / mlx->map.x_max) / 2;
	mlx->x_theta = 0;
	mlx->y_theta = 0;
	mlx->z_theta = 0;
	mlx->z_heigth = 10;
	mlx->x_shift = (mlx->width) - ((mlx->map.x_max) * mlx->scale);
	mlx->y_shift = (mlx->height) - ((mlx->map.y_max) * y_scale);
}

static int	set_window(t_mlx *mlx, char *file)
{
	mlx->width = 1024;
	mlx->height = 720;
	reset_aff(mlx);
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->width,
		mlx->height, file)))
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf [file_path]");
		exit(EXIT_FAILURE);
	}
	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		set_error(NULL);
	mlx->z_tab = NULL;
	if (parser(av[1], &mlx) == -1)
		set_error(NULL);
	if (!(set_window(mlx, av[1])))
		set_error(mlx);
	set_img(mlx);
	fill_img_data(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 3, get_input, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
