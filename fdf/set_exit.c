/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 19:30:52 by gjuste            #+#    #+#             */
/*   Updated: 2019/01/29 16:59:16 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_tabdel(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	free_z_tab(t_mlx *mlx)
{
	int		i;

	if (mlx->z_tab)
	{
		i = 0;
		while (i < mlx->map.y_max)
		{
			free(mlx->z_tab[i]);
			mlx->z_tab[i] = NULL;
			i++;
		}
		free(mlx->z_tab);
		mlx->z_tab = NULL;
	}
}

void		free_all(t_mlx *mlx)
{
	if (mlx->img_ptr && mlx->mlx_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr && mlx->mlx_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->img_ptr = NULL;
	mlx->img_data = NULL;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	free_z_tab(mlx);
	free(mlx);
	mlx = NULL;
}

void		set_error(t_mlx *mlx)
{
	if (mlx)
		free_all(mlx);
	ft_putendl("error");
	exit(EXIT_FAILURE);
}
