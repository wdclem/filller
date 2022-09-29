/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:51:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/29 18:24:21 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdarg.h>
# include <stdio.h> /* DELETE DELETE DELETE IDIOT */
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# define ENEMY 90000
# define PLAYER 10000
# define EMPTY 100 

/* Struct to keep miscelanous infos */
typedef struct	s_info{
				char	player;
				char	enemy;
				int		col;
				int		row;
				int		elem;
				int		p_col;
				int		p_row;
				int		s_row;
				int		s_col;
				int		b_row;
				int		b_col;
				int		sum;
				char	**map;
				char	**piece;
				int		heatmap[100][100];
}				t_info;

typedef struct	s_piece
{
				int	row;
				int	col;
				char **shape;
}				t_piece;

int	main(int argc, char **argv);
int	player_info(t_info *info);
int	get_map_dim(t_info *info);
int	map_info(t_info *info);
int	piece_info(t_info *info, t_piece *piece);
void    create_heat_map(t_info *info);
int	set_position(t_info *info, t_piece *piece);

#endif
