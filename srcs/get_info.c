/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:48:15 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/17 13:16:24 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	player_info(t_info *info)
{
	char	*stdo;
	int		player;

	stdo = NULL;
	get_next_line(0, &stdo);
	player = stdo[10] - '0';
	fprintf(stderr , "player = %i\n", player);
	if (player == 1)
	{
		info->player = 'O';
		info->enemy = 'X';
	}
	else if (player == 2)
	{
		info->player = 'X';
		info->enemy = 'O';
	}	
	fprintf(stderr , "enemy = %c\n", info->enemy);
	free(stdo);
	return (0); //tutto va bene need to make error checks ?
}

int	map_info(t_info *info)
{
	char	*stdo;
//	char	*line;
	int		i;
	int		x;
	int		y;
	int		j;

	stdo = NULL;
	i = 0;
	get_next_line(0, &stdo);
	info->row  = ft_atoi(&stdo[8]);
	fprintf(stderr , "info->row= %d\n", info->row);
	info->col = ft_atoi(&stdo[11]);//adjust stdo to numblen
	fprintf(stderr , "info->col= %d\n", info->col);
	get_next_line(0, &stdo);
	ft_strdel(&stdo);
	get_next_line(0, &stdo);
	info->map = (int **)malloc(sizeof(int *) * info->row);
	y  = 0;
//	info->map[y] = (int*)malloc(sizeof(int) * info->col);
	while (y  < info->row)
	{
		info->map[y] = (int*)malloc(sizeof(int) * info->col);
		x = 0;
//		line  = ft_strsub(stdo, 4 , info->col);
//		fprintf(stderr , "infiltre 1\n");
		while (x < info->col)
		{
	//		info->map[y] = (int*)malloc(sizeof(int) * info->col);
//			ft_memset(info->map[y], 0, sizeof(info->col));
//			fprintf(stderr , "enemy = %c map = %c\n", info->enemy, line[x]);
			if (stdo[x + 4] == info->enemy) 
			{
//				fprintf(stderr, "hello\n");
				info->map[y][x] = 1;
			}
			else if (stdo[x + 4] == info->player) 
				info->map[y][x] = 2;
			else
			{
				info->map[y][x] = 0;
//				fprintf(stderr, "culotte\n");
			}
//			fprintf(stderr , "map = %c\n", info->map[y][x]);
//			fprintf(stderr , "map = %s\n", stdo);
			fprintf(stderr , "x = %d\n", x);
			fprintf(stderr , "y = %d\n", y);
			x++;
		}
		ft_strdel(&stdo);
//		free(line);
		get_next_line(0, &stdo);
		y++;
	}
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			fprintf(stderr, "%d", info->map[i][j]);
			j++;
		}
		fprintf(stderr, "\n");
		i++;
	}

	return (0);
}
//	heat_map_init(info, map);
/*	info->map = (char **)malloc((info->row + 1) * sizeof(char *));
	while (i < info->row)
	{
		get_next_line(0, &stdo);
		info->map[i] = ft_strsub(stdo, 4 , info->col);
		fprintf(stderr, "mapinfo stdo ==  %s\n\n", info->map[i]);
		i++;
	}
	copy_map(info);
	return (0); //tutto va bene need to make error checks ?
	// can probably check with stdo[0] == "P"
}
*/
/* x >>> y ^*/
/*
static int	pieces_coord(t_piece *piece)
{
	int		x;
	int		y;
	int		i;
	t_coord *coord;

	y = 0;
	i = 0;
	coord = (t_coord*)malloc((sizeof (*coord)) * (piece->row * piece->col)); 
//	fprintf(stderr, "_y==  %d\n\n", y);
	while (y < piece->row)
	{
		x = -1;
		while (x < piece->col)
		{
//			fprintf(stderr, "piece[y]==  %s\n\n", &info->piece[y][x]);
			if (ft_strcmp(&piece->shape[y][x], "*") == 0)
			{
				fprintf(stderr, "couille de loup");
				coord[i].x = x;
				coord[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	fprintf(stderr, "piece_x==  %d\n\n", coord[0].x);
	fprintf(stderr, "piece_y==  %d\n\n", coord[0].y);
	return(0);
}
*/
/*
int	pieces_info()
{
	t_piece	piece;
	char	*line;
	int		i;
	int		size;
	int		row;

	line = NULL;
	i = 0;

	get_next_line(0, &line);
	fprintf(stderr, "piece_info stdo ==  %s\n\n", line);
	piece.row = ft_atoi(&line[6]);
	fprintf(stderr , "info->piecerow= %d\n", piece.row);
	piece.col= ft_atoi(&line[8]);//adjust stdo to numblen
	fprintf(stderr , "info->piececol= %d\n", piece.col);
	row = piece.row;
	size = row;
	piece.shape = malloc((piece.row * piece.col) * sizeof(int));
	while (i < size)
	{
//		fprintf(stderr , "tu as un gros piece mon loulou\n\n");
		get_next_line(0, &line);
		fprintf(stderr, "piece_info stdo ==  %s\n\n", line);
		piece.shape[i] = ft_strdup(line);
		// check to remove the row number
	//	fprintf(stderr , "info->piece = %s\n", info->piece[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		fprintf(stderr , "info->piece = %s\n", piece.shape[i]);
		i++;
	}
//	pieces_coord(&piece);
	*
	while (stdo[0] != "*" || stdo[0] != ".")
		get_next_line(0, &stdo);
	return (0);
}
*/
