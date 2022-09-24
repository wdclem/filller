/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:23:14 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/24 16:53:40 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>

void		check_cell(t_info *info, t_piece *piece, int row, int col)
{
	int		i;
	int		j;
	int		elem;
	int		v;

	elem = 0;
	i = info->s_row;
	v = 0;
//	fprintf(stderr, "info p_row = %d\n", info->p_row);
//	fprintf(stderr, "info i = %d\n", i);
	while (i < info->p_row && row + i - info->s_row < info->row)
	{
//		fprintf(stderr, "la taupe est dans le 1 er trou\n");
		j = info->s_col;
		while (col + j - info->s_col < info->col && j < info->p_col)
		{
			if (piece->shape[i][j] == '*' && elem++ > -1)
			{
//				fprintf(stderr, "la taupe est dans le 2nd trou\n");
				v = v + info->heatmap[row + i  - info->s_row][col + j - info->s_col];
//				fprintf(stderr, "v= %d\n", v);
			}
			j++;
		}
		i++;
	}
//	fprintf(stderr, "v= %d\n", v);
	if (info->elem == elem && v < 2000 && v > 1000)// && v <= 2000)
	{
		info->v = v;
		info->b_row = row  - info->s_row;
		info->b_col = col - info->s_col;
	}
//	fprintf(stderr, "v= %d\n", v);
//	fprintf(stderr, "info->v= %d\n", info->v);
//	fprintf(stderr, "info b_row = %d\n", info->b_row);
//	fprintf(stderr, "info b_col = %d\n", info->b_col);

}
/*
** This is where we go through the whole map and try to place the piece to the
** lowest value position. We can also add a function to check direction on cases
** where there are two values that are equal.
*/
int	check_value(t_info *info, t_piece *piece)
{
	int	row;
	int	col;

	row = 0;
	info->b_row = -1;
	info->b_col  = -1;
	while (row < info->row)
	{
		col = 0;
		while (col < info->col)
		{
			check_cell(info, piece, row, col);
			col++;
		}
		row++;
	}
	return (1);
}
