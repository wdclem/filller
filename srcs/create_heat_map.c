/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:07:26 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/24 16:50:36 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
static int		check_zero(t_info *info, int x, int y)
{
	if ((x + 1) < info->col && info->heatmap[y][x + 1] == 20000)
		return (0);
	if ((x - 1) >= 0 && info->heatmap[y][x - 1] == 20000)
		return (0);
	if ((y + 1) < info->row && info->heatmap[y + 1][x] == 20000)
		return (0);
	if ((y - 1) >= 0 && info->heatmap[y - 1][x] == 20000)
		return (0);
	return (20000);
}

static int		check_val(t_info *info, int x, int y, int i)
{
	int		value;
	int		arr[5];

	value = 1000;
	while (++i < 5)
		arr[i] = 1000;
	i = -1;
	if ((x + 1) < info->col &&
			info->heatmap[y][x + 1] < info->heatmap[y][x])
		arr[0] = info->heatmap[y][x + 1] + 1;
	if ((x - 1) >= 0 && info->heatmap[y][x - 1] < info->heatmap[y][x])
		arr[1] = info->heatmap[y][x - 1] + 1;
	if ((y + 1) < info->row &&
			info->heatmap[y + 1][x] < info->heatmap[y][x])
		arr[2] = info->heatmap[y + 1][x] + 1;
	if ((y - 1) >= 0 && info->heatmap[y - 1][x] < info->heatmap[y][x])
		arr[3] = info->heatmap[y - 1][x] + 1;
	arr[4] = check_zero(info, x, y);
	while (++i < 5)
	{
		if (arr[i] < value)
			value = arr[i];
	}
	return (value);
}

void			create_heat_map(t_info *info)
{
	int	y;
	int	x;
	int	i;

	i = -1;
	y = -1;
	while (++y < info->row)
	{
		x = -1;
		while (++x < info->col)
		{
			if (info->heatmap[y][x] == 10000)
				continue ;
			if (info->heatmap[y][x] == 20000)
				continue ;
			info->heatmap[y][x] = check_val(info, x, y, i);
		}
	}
}
*/
static void	init_heat_map(t_info *info)
{
	int	i;
	int j;

	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			if (info->heatmap[i][j] == 2000)
			{
				if (j + 1 < info->col && info->heatmap[i][j + 1] == 100)
					info->heatmap[i][j + 1] = 0;
				if (j > 0 && info->heatmap[i][j - 1] == 100)
					info->heatmap[i][j - 1] = 0;
				if (i + 1 < info->row && info->heatmap[i + 1][j] == 100)
					info->heatmap[i + 1][j] = 0;
				if (i > 0 && info->heatmap[i - 1][j] == 100)
					info->heatmap[i - 1][j] = 0;
			}
			j++;
		}
		i++;
	}
}

/*
 * Set value of empty cell on the board according the next/previous cell value
 */

static int		set_cell_value(t_info *info, int val, int check)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
		//	fprintf(stderr, "%d\n", map[i][j]);
			if (info->heatmap[i][j] == val)
			{
				check = 1;
				if (j + 1 < info->col && info->heatmap[i][j + 1] == 100)
					info->heatmap[i][j + 1] = val + 1;
				if (j > 0 && info->heatmap[i][j - 1] == 100)
					info->heatmap[i][j - 1] = val + 1;
				if (i + 1 < info->row && info->heatmap[i + 1][j] == 100)
					info->heatmap[i + 1][j] = val + 1;
				if (i > 0 && info->heatmap[i - 1][j] == 100)
					info->heatmap[i - 1][j] = val + 1;
			}
			j++;
		}
		i++;
	}
	return (check);
}

void	create_heat_map(t_info *info)
{
	int	val;
//	int	i;
//	int j;

	init_heat_map(info);
	/*
	i = 0;
	while (i < info->ro)
	{
		j = 0;
		while (j < info->col)
		{
			fprintf(stderr, "%d", map[i][j]);
			j++;
		}
		fprintf(stderr, "\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "\n");
		i++;
	}
	*/
	val = 0;
	while ((set_cell_value(info, val, 0)) == 1) 
		val++;
	/*
	i = 0;
    while (i < info->row)
     {
         j = 0;
         while (j < info->col)
         {
             fprintf(stderr, "%d", info->heatmap[i][j]);
             j++;
         }
         fprintf(stderr, "\n");
         i++;
	 }
	 */
}
