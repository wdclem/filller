/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:51:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/09/09 13:24:51 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdarg.h>
# include <stdio.h> /* DELETE DELETE DELETE IDIOT */
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

/* Struct to keep miscelanous infos */
typedef struct	s_info{
				char	*line;
				int		player;
				int		col;
				int		row;
}				t_info;


int	main(int argc, char **argv);

#endif