/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:27:58 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/16 18:24:09 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	heat_map_init(t_info *info, int **map)
{
	int	i;
	int	j;
	
	i = 0;
	while(i <= info->row)
	{
		j  = 0;
		while (j <= info->col)
		{
			if (map[i][j] == 1)
			{
				if (j + 1 < info->col && map[i][j + 1] == 0)
					map[i][j + 1] = 0;
				if (j > 0 && map[i][j - 1] == 0)
					map[i][j - 1] = 0;
				if (i + 1 < info->row && map[i + 1][j] == 0)
					map[i + 1][j] = 0;
				if (i > 0 && map[i - 1][j] == 0)
					map[i - 1][j] = 0;
			}
			i++;
		}
		j++;
	}
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			fprintf(stderr, "%d ", map[i][j]);
			j++;
		}
		fprintf(stderr, "\n ");
		i++;
	}
}

void		copy_map(t_info *info)
{
	int		x;
	int		y;
	int		i;
	int 	j;
	int		**map;

	map = (int **)malloc(sizeof(int *) * info->row);
	y  = 0;
	while (y  < info->row)
	{
		x = 0;
//		fprintf(stderr , "infiltre 1\n");
		while (x < info->col)
		{
			map[y] = (int*)malloc(sizeof(int) * info->col);
//			ft_memset(map[y], 0, sizeof(info->col));
			fprintf(stderr , "enemy = %c map = %c\n", info->enemy, info->map[y][x]);
			if (info->map[y][x] == info->enemy) 
			{
				fprintf(stderr, "hello\n");
				map[y][x] = 1;
			}
			else if (info->map[y][x] == info->player) 
				map[y][x] = 2;
			else
				map[y][x] = 0;
			fprintf(stderr , "map = %c\n", map[y][x]);
			x++;
		}
		y++;
	}
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			fprintf(stderr, "%d ", map[i][j]);
			j++;
		}
		fprintf(stderr, "\n");
		i++;
	}
				printf("hello");
	heat_map_init(info, map);
}
