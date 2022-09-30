/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:51:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/30 17:35:15 by ccariou          ###   ########.fr       */
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
				int		s_row;
				int		s_col;
				int		b_row;
				int		b_col;
				int		sum;
				char	**map;
				int		**heatmap;
}				t_info;

typedef struct	s_piece
{
				int	row;
				int	col;
				char **shape;
}				t_piece;

int	main(void);
int	player_info(t_info *info);
int	get_map_dim(t_info *info);
int	map_info(t_info *info);
int	piece_info(t_info *info, t_piece *piece);
int	create_heat_map(t_info *info);
int	set_position(t_info *info, t_piece *piece);

#endif
