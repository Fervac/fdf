/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:10:17 by gjuste            #+#    #+#             */
/*   Updated: 2019/01/29 17:26:36 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	test_read(char *file)
{
	int		fd;

	if ((fd = open(file, O_DIRECTORY, O_RDONLY) < 0))
		return (1);
	close(fd);
	return (0);
}

static int	check_line(int x_nb, char *line)
{
	int		i;
	int		oc;
	int		count;

	i = 0;
	oc = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			oc = 0;
		else if (oc == 0)
		{
			count++;
			oc = 1;
		}
		i++;
	}
	return (x_nb != -1 && x_nb != count ? 0 : count);
}

static int	check_entry(char *file, t_mlx **mlx)
{
	char	*line;
	int		ret;
	int		x_nb;
	int		y_nb;
	int		fd;

	x_nb = -1;
	y_nb = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line)) && ret > 0)
	{
		if (!(x_nb = check_line(x_nb, line)))
		{
			y_nb = -y_nb;
			break ;
		}
		ft_strdel(&line);
		y_nb++;
	}
	(*mlx)->map.x_max = x_nb;
	(*mlx)->map.y_max = y_nb;
	ft_strdel(&line);
	close(fd);
	return (y_nb);
}

static int	*get_line(int fd, t_mlx **mlx)
{
	char	**str;
	char	*line;
	int		*tab;
	int		ret;
	int		i;

	i = 0;
	if ((ret = get_next_line(fd, &line)) && ret > 0)
	{
		if (!(tab = (int *)malloc(sizeof(int) * (*mlx)->map.x_max)))
			return (0);
		if (!(str = ft_strsplit(line, ' ')))
			return (0);
		while (str[i])
		{
			tab[i] = ft_atoi(str[i]);
			i++;
		}
		ft_tabdel(str);
		ft_strdel(&line);
	}
	else
		tab = NULL;
	return (tab);
}

int			parser(char *file, t_mlx **mlx)
{
	int		fd;
	int		*str;
	int		i;
	int		ret;

	if (!test_read(file))
		return (-1);
	if ((ret = check_entry(file, mlx)) <= 0)
		return (-1);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	if (!((*mlx)->z_tab = (int **)malloc(sizeof(int *) * ret)))
		return (-1);
	i = -1;
	while ((str = get_line(fd, mlx)))
		(*mlx)->z_tab[++i] = str;
	close(fd);
	return (1);
}
