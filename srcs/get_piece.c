/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:07:05 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/24 16:07:22 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
/*
void	shape_info(t_info *info, t_piece *piece)
{
	int	i;
	int	j;

	piece->b_row = info->p_row;
	piece->b_col  = info->p_col;
	i = 0;
	piece->e_row = 0;
	piece->e_col = 0;
	while (i < info->p_row)
	{
		j = 0;
		while (j < info->p_col)
		{
			if (piece->shape[i][j] == 1)
			{
				
//				y_st = (i < info->begin_y) ? i : info->begin_y;
//				x_st = (j < info->begin_x) ? j : info->begin_x;
//				tinfo->end_y = (i > tinfo->end_y) ? i : tinfo->end_y;
//				tinfo->end_x = (j > tinfo->end_x) ? j : tinfo->end_x;
				if (i < piece->b_row)
					piece->b_row = i; 
				if (j  < piece->b_col)
					piece->b_col = j;
				if (i > piece->e_row)
					piece->e_row = i;
				if (j > piece->e_col)
					piece->e_col = j;
				else
				{
					piece->b_row = info->p_row; 
					piece->e_row = 0;
					piece->b_col = info->p_col;
					piece->e_col = 0;
				}
			}
			j++;
		}
		i++;
	}
	info->p_row = piece->e_row- piece->b_row + 1;
	info->p_col= piece->e_col - piece->b_col + 1;
	fprintf(stderr, "piece_col post shape==  %d\n\n", info->row);
	fprintf(stderr, "piece_row post shape==  %d\n\n", info->col);
}
*//*
int		**mod_piece(t_info *info, t_piece *piece)
{
	int	row;
	int	col;
	int	**cut;
	int	i;
	int	j;

	shape_info(info, piece);
	cut =(int **)malloc(sizeof(int *) * info->p_row);
	i = piece->b_row;
	row = 0;
	cut[0] =(int *)malloc(sizeof(int) * info->p_col); 
	while (row < info->p_row)
	{
		col  = 0;
		j = piece->b_col;
		while (col < info->p_col)
		{
			cut[row][col] = piece->shape[i][j];
			j++;
			col++;
		}
		i++;
		row++;
	}
	return (cut);
}
*/
/*
int	save_shape(t_info *info, int **shape, t_piece *piece)
{
	int i;
	int j;

	i = 0;
	shape_info(info, shape, piece);
*/
/*
t_piece	*add_node(void)
{
	t_piece	*piece;

	if (!(piece = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	piece->row= 0;
	piece->col = 0;
	piece->next = NULL;
	return (piece);
}
*/
/*
void	test_position(t_info *info, t_piece *piece, int **map)
{
	int i;
	int j;

	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			if (map[i][j] == -1)
			{
				calculate_best(map ....)
*/
/*static void	save_coord(t_piece *piece, t_piece *coord)
{
	int		col_dif;
	int		row_dif;

	row_dif = piece->row;
	col_dif = piece->col;
	while (piece->next != NULL)
	{
		coord->row = piece->row - row_dif;
		coord->col = piece->col - col_dif;
		if (!(coord->next = add_node()))
			return ;
		piece = piece->next;
		coord = coord->next;
	}
	coord->next = NULL;
}
*/
/*
 * Check the information of the piece receive by the VM, s_col and s_row retain the starting point of the piece
 * (if piece start on second row, second col ect ect ...)
 */
int	piece_info(t_info *info, t_piece *piece)
{
	char	*line;
//	int		row;
//	int		col;
//	char	**shape;
	int		i;
	int		j;

	line = NULL;
	i = 0;
	info->elem = 0;
//	info->s_row = 100;
//	info->s_col = 100;
	get_next_line(0, &line);
//	fprintf(stderr, "piece_info stdo ==  %s\n\n", line);
	info->p_row = ft_atoi(&line[6]);
	fprintf(stderr , "info->piecerow= %d\n", info->p_row);
	info->p_col= ft_atoi(&line[8]);//adjust stdo to numblen
	fprintf(stderr , "info->piececol= %d\n", info->p_col);
	piece->shape = (char **)malloc(sizeof(char *) * info->p_row);
	while (i < info->p_row)
	{
//		fprintf(stderr , "tu as un gros piece mon loulou\n\n");
//		if ((i + 1) < piece.row)
		get_next_line(0, &line);
		piece->shape[i] = ft_strdup(line);
//		fprintf(stderr, "piece_info stdo ==  %s\n\n", line);
//		piece->shape[i] = (int *)malloc(sizeof(int) * info->p_col);
		j = 0;
		while (j < info->p_col)
		{
			if (piece->shape[i][j] == '*')
			{
				if (j < info->s_col)
					info->s_col = j;
				if (i < info->s_row)
					info->s_row = i;
				info->elem++;
				fprintf(stderr, "s_row == %d\n", info->s_row);
				fprintf(stderr, "s_col == %d\n", info->s_col);
				fprintf(stderr, "elem == %d\n", info->elem);
			}
//				piece->shape[i][j] = 1;
		//	else
//				piece->shape[i][j] = 0;
			j++;
		}
		ft_strdel(&line);
		// check to remove the row number
//		fprintf(stderr , "info->piece = %s\n", info->piece[i]);
		i++;
	}
	i = 0;
	while (i < info->p_row)
	{
		fprintf(stderr , "info->piece = %s\n", piece->shape[i]);
		i++;
	}
	/*
	i = 0;
	while (i < info->p_row)
	{
		j = 0;
		while (j < info->p_col)
		{
			fprintf(stderr , "info->piece = %i\n", piece->shape[i][j]);
			j++;

		}
		fprintf(stderr, "\n");
		i++;
	}
	piece->shape = mod_piece(info, piece);
//	shape_info(shape, &piece);
//	pieces_coord(&piece);
//	while (stdo[0] != "*" || stdo[0] != ".")
//		get_next_line(0, &stdo);
//		*/
	return (1);
}
