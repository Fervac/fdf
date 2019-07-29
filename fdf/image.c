/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:41:13 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 12:13:56 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	reset_img(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < (mlx->height * mlx->width))
	{
		mlx->img_data[i] = 0;
		i++;
	}
}

void		print_img(t_mlx *mlx)
{
	reset_img(mlx);
	fill_img_data(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

void		set_img(t_mlx *mlx)
{
	char	*img_data;
	void	*img_ptr;
	int		bpp;
	int		endian;
	int		size_line;

	img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	img_data = mlx_get_data_addr(img_ptr, &(bpp), &(size_line), &(endian));
	mlx->img_data = (int *)img_data;
	mlx->img_ptr = img_ptr;
}
