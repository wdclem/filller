/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:07:05 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/17 18:05:30 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	piece_info()
{
	t_piece	piece;
	char	*line;
	int		**shape;
	int		i;
	int		j;

	line = NULL;
	i = 0;

	get_next_line(0, &line);
	fprintf(stderr, "piece_info stdo ==  %s\n\n", line);
	piece.row = ft_atoi(&line[6]);
	fprintf(stderr , "info->piecerow= %d\n", piece.row);
	piece.col= ft_atoi(&line[8]);//adjust stdo to numblen
	fprintf(stderr , "info->piececol= %d\n", piece.col);
	shape = (int**)malloc(sizeof(int *) * piece.row);
	while (i < piece.row)
	{
//		fprintf(stderr , "tu as un gros piece mon loulou\n\n");
//		if ((i + 1) < piece.row)
			get_next_line(0, &line);
		fprintf(stderr, "piece_info stdo ==  %s\n\n", line);
		shape[i] = (int *)malloc(sizeof(int) * piece.col);
		j = 0;
		while (j < piece.col)
		{
			if (line[j] == '.')
				shape[i][j] = 0;
			else
				shape[i][j] = 1;
			j++;
		}
		ft_strdel(&line);
		// check to remove the row number
	//	fprintf(stderr , "info->piece = %s\n", info->piece[i]);
		i++;
	}
	i = 0;
	while (i < piece.row)
	{
		j = 0;
		while (j < piece.col)
		{
			fprintf(stderr , "info->piece = %i\n", shape[i][j]);
			j++;

		}
		fprintf(stderr, "\n");
		i++;
	}
//	pieces_coord(&piece);
//	while (stdo[0] != "*" || stdo[0] != ".")
//		get_next_line(0, &stdo);
	return (0);
}
