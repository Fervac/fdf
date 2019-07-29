/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 10:52:23 by abechet           #+#    #+#             */
/*   Updated: 2019/01/29 16:52:33 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "define.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct		s_map
{
	int				x_max;
	int				y_max;
	int				xi;
	int				yi;
	int				xf;
	int				yf;
	int				xinc;
	int				yinc;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
	int				height;
	int				width;
	int				scale;
	int				y_shift;
	int				x_shift;
	double			x_theta;
	double			y_theta;
	double			z_theta;
	int				z_heigth;
	unsigned int	color;
	t_map			map;
	int				**z_tab;
}					t_mlx;

int					parser(char *file, t_mlx **mlx);
void				set_img(t_mlx *mlx);
void				fill_img_data(t_mlx *mlx);
void				print_img(t_mlx *mlx);
void				set_rotation(t_mlx *mlx, int *x, int *y, int *z);
int					get_input(int key, t_mlx *mlx);
void				reset_aff(t_mlx *mlx);
void				print_line(t_mlx *mlx);
void				ft_tabdel(char **tab);
void				set_error(t_mlx *mlx);
void				free_all(t_mlx *mlx);

#endif
