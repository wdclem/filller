/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 21:51:51 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 12:36:10 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

int		try_positions(t_info *info, t_piece *piece, int row, int col)
{
	int	ret;
	int	i;
	int	j;
	int y;
	int x;

	ret = 0;
	y = row;
	i = 0;
	while (i < info->p_row)//&& row + info->s_row - info->s_row < info->row)
	{
		x = col;
		j = 0;
		while (j < info->p_col)
		{
			if (piece->shape[i][j] == '*')
				ret += (info->heatmap[y][x]);
			x++;
			j++;
		}
		y++;
		i++;
	}
//	fprintf(stderr, "teubi ret == %d\n", ret);
	if (ret < PLAYER)
		return(ret = ENEMY);
	else
		return(ret);
}

t_info	*save_best_position(t_info *info, int min_row, int min_col)
{
	int	final_y;
	int	final_x;

	final_y = min_row;// - info->s_row;
	final_x = min_col;// - info->s_col;
	info->b_row = final_y;
	info->b_col = final_x;
	return (info);
}

t_info	*set_position(t_info *info, t_piece *piece)
{
//	t_info	cur;
	int		ret;
	int		min_sum;
//	t_info	min;
	int		col;
	int		row;
//	int		sum;
	int		min_col;
	int		min_row;

	min_sum = ENEMY;
	min_col = info->col;
	min_row = 0;
	row = 0;
	while (row  <= (info->row - info->p_row))
	{
		col = 0;
		while (col <= (info->col - info->p_col))
		{
			ret = try_positions(info, piece, row, col);
			if (ret < min_sum || (ret == min_sum && col < min_col))
			{
//				fprintf(stderr, "teub de loup\n");
				min_sum = ret;
				min_col = col;
				min_row = row;
			}
			col++;
		}
		row++;
	}
	info->min_sum = min_sum;
//	fprintf(stderr, "min_sum = %d, min_col = %d, min_row = %d\n", min_sum, min_col, min_row);
	return (save_best_position(info, min_row, min_col));
}
