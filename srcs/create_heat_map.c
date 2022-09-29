/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:07:26 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 15:44:00 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_heat_map(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	while (++i < info->row)
	{
		j = -1;
		while (++j < info->col)
		{
			if (info->heatmap[i][j] == ENEMY)
			{
				if (j + 1 < info->col && info->heatmap[i][j + 1] == EMPTY)
					info->heatmap[i][j + 1] = 0;
				if (j > 0 && info->heatmap[i][j - 1] == EMPTY)
					info->heatmap[i][j - 1] = 0;
				if (i + 1 < info->row && info->heatmap[i + 1][j] == EMPTY)
					info->heatmap[i + 1][j] = 0;
				if (i > 0 && info->heatmap[i - 1][j] == EMPTY)
					info->heatmap[i - 1][j] = 0;
			}
		}
	}
}

/*
 * Set value of empty cell on the board according the next/previous cell value
 */

static void	set_cell_value(t_info *info, int val, int i, int j)
{
//	i = 0;
//	while (i < info->row)
//	{
//		j = 0;
//		while (j < info->col)
//		{
			if (info->heatmap[i][j] == val)
			{
//				check = 1;
				if (j + 1 < info->col && info->heatmap[i][j + 1] == EMPTY)
					info->heatmap[i][j + 1] = val + 1;
				if (j > 0 && info->heatmap[i][j - 1] == EMPTY)
					info->heatmap[i][j - 1] = val + 1;
				if (i + 1 < info->row && info->heatmap[i + 1][j] == EMPTY)
					info->heatmap[i + 1][j] = val + 1;
				if (i > 0 && info->heatmap[i - 1][j] == EMPTY)
					info->heatmap[i - 1][j] = val + 1;
			}
//			j++;
//		}
//		i++;
//	}
//	return (//check);
}

void	create_heat_map(t_info *info)
{
	int	val;
	int	i;
	int	j;

	i = -1;
	init_heat_map(info);
	val = 0;
	while (++i < info->row)
	{
		j = -1;
		while (++j < info->col)
			set_cell_value(info, val, i, j);
		val++;
	}
//	while ((set_cell_value(info, val, 0)) == 1)
//		val ++;
}
