/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:51:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 11:43:26 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdarg.h>
# include <stdio.h> /* DELETE DELETE DELETE IDIOT */
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# define ENEMY 20000
# define PLAYER 10000
# define EMPTY 100 

/* Struct to keep miscelanous infos */
typedef struct	s_info{
				char	player;
				char	enemy;
				int		col;
				int		row;
				int		elem;
				int		v;
				int		p_col;
				int		p_row;
				int		s_row;
				int		s_col;
				int		e_row;
				int		e_col;
				int		b_row;
				int		b_col;
				int		min_sum;
				char	**map;
				char	**piece;
				int		heatmap[100][100];
}				t_info;

typedef struct	s_piece
{
				int	b_row;
				int b_col;
				int	e_row;
				int e_col;
//				int	**shape;
				char **shape;
				char **fshape;
}				t_piece;

/*
typedef struct	s_piece
{
				int	row;
				int col;
				struct s_piece	*next;
}				t_piece;
*/				

typedef	struct	s_coord{
				int	x;
				int	y;
}				t_coord;

typedef struct	s_plateau{
				char	**plateau;
}				t_plateau;

int	main(int argc, char **argv);
int	player_info(t_info *info);
int	get_map_dim(t_info *info);
int	map_info(t_info *info);
int	piece_info(t_info *info, t_piece *piece);
//void    heat_map_init(t_info *info, int **map);
void    create_heat_map(t_info *info);
//int	check_value(t_info *info, t_piece *piece);
t_info	*set_position(t_info *info, t_piece *piece);
//void	set_piece(t_info *info);
//t_piece *add_node(void);
//int  solve(t_info *info, int **map);
//int	heat_map_fill(t_info *info, int val, int check);



#endif
