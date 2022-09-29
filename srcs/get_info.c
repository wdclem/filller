/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:48:15 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 12:31:19 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	player_info(t_info *info)
{
	int		player;
	char	*stdo;

	stdo = NULL;
	get_next_line(0, &stdo);
//	fprintf(stderr , "stdo = %s\n", stdo);
	player = stdo[10] - '0';
//	fprintf(stderr , "player = %i\n", player);
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
//	fprintf(stderr , "enemy = %c\n", info->enemy);
	ft_strdel(&stdo);
	return (1); //tutto va bene need to make error checks ?
}

int	get_map_dim(t_info *info)
{
	char	*stdo;
	int		i;

	stdo = NULL;
	i = 0;
	get_next_line(0, &stdo);
//	info->row  = ft_atoi(&stdo[8]);
	while (!ft_isdigit(stdo[i]))
		i++;
	info->row  = ft_atoi(&stdo[i]);
//	fprintf(stderr , "info->row= %d\n", info->row);
	while (ft_isdigit(stdo[i]))
		i++;
	info->col = ft_atoi(&stdo[i]);//adjust stdo to numblen
//	fprintf(stderr , "info->col= %d\n", info->col);
	ft_strdel(&stdo);
	return (0);
}

int	map_info(t_info *info)
{
//	int		i;
	int		x;
	int		y;
	char	*stdo;
//	int		j;


	stdo = NULL;
	get_next_line(0, &stdo);
//	fprintf(stderr, "in map info= %s\n", stdo);
//	get_map_dim(info, stdo);
//	get_next_line(0, &stdo);
	while (ft_strncmp(stdo, "000 ", 4) != 0)
	{
//		fprintf(stderr, "in while map info  = %s\n", stdo);
		ft_strdel(&stdo);
		if (get_next_line(0, &stdo) < 1)
			return (0);
	}
/*
	stdo = NULL;
//	i = 0;
	get_next_line(0, &stdo);
//	info->row  = ft_atoi(&stdo[8]);
	while (!ft_isdigit(*stdo))
		stdo++;
	info->row  = ft_atoi(stdo);
	fprintf(stderr , "info->row= %d\n", info->row);
	while (ft_isdigit(*stdo))
		stdo++;
	info->col = ft_atoi(stdo);//adjust stdo to numblen
	fprintf(stderr , "info->col= %d\n", info->col);
	get_next_line(0, &stdo);
	ft_strdel(&stdo);
	get_next_line(0, &stdo);
	*/
//	fprintf(stderr , "stdo = %s\n", stdo);
//	fprintf(stderr , "stdo = %s\n", stdo);
	if (!(info->map = (char **)malloc(sizeof(char *) * info->row)))
		exit(1);
	if (info->map == NULL)
		fprintf(stderr , "bite en bois\n");
//	fprintf(stderr , "stdo = %s\n", stdo);
	y  = 0;
//	info->map[y] = (int*)malloc(sizeof(int) * info->col);
	while (y < info->row)
	{
		x = 0;
		//fprintf(stderr , "stdo = %s\n", stdo);
		if ((info->map[y]= ft_strdup(stdo + 4)) == NULL)
			exit (1);
//		fprintf(stderr , "infiltre 1\n");
		while (x < info->col)
		{
//			fprintf(stderr , "info->map [y] = %s\n", info->map[y]);
	//		info->map[y] = (int*)malloc(sizeof(int) * info->col);
//			ft_memset(info->map[y], 0, sizeof(info->col));
//			fprintf(stderr , "enemy = %c map = %c\n", info->enemy, line[x]);
			if (info->map[y][x] == info->enemy) 
			{
//				fprintf(stderr, "hello\n");
				info->heatmap[y][x] = ENEMY;
			}
			else if (info->map[y][x] == info->player) 
				info->heatmap[y][x] = PLAYER;
			else
			{
				info->heatmap[y][x] = EMPTY;
//				fprintf(stderr, "culotte\n");
			}
//			fprintf(stderr , "map = %c\n", info->map[y][x]);
//			fprintf(stderr , "map = %s\n", stdo);
	//		fprintf(stderr , "x = %d\n", x);
	//		fprintf(stderr , "y = %d\n", y);
			x++;
		}
//		ft_strdel(&stdo);
//		free(line);
		if ((y + 1) < info->row)
			get_next_line(0, &stdo);
		y++;
	}
	/*
	i = 0;
	while (i < info->row)
	{
		fprintf(stderr, "%s", info->map[i]);
		fprintf(stderr, "\n");
		i++;
	}
		fprintf(stderr, "\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "\n");
		fprintf(stderr, "\n");
		*/
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
	/*
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			fprintf(stderr, "%d", map[i][j]);
			if (map[i][j] > 99 || map[i][j] < 0)
				fprintf(stderr, "  ");
			else
				fprintf(stderr, " ");
			j++;

		}
		fprintf(stderr, "\n");
		i++;
	}
	*/
	ft_strdel(&stdo);
	return (1);
}
//	hedddat_map_init(info, map);
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
