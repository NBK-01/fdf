/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkanaan <nkanaan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 20:55:06 by nkanaan           #+#    #+#             */
/*   Updated: 2024/07/11 10:07:20 by nkanaan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../mlx/mlx.h"
# include "../lib/lib.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
}	t_data;

/*/////////////////////////////////////////////////////////////////////////*/
/*				VALIDATION / PARSING			   */
/*/////////////////////////////////////////////////////////////////////////*/
int	validate_args(int ac, char **av);
void	init_fdf(char *av);

/*/////////////////////////////////////////////////////////////////////////*/
/*				MLX AND HOOKS				   */
/*/////////////////////////////////////////////////////////////////////////*/
int	on_keypress(int keysym, t_data *data);
int	on_destroy(t_data *data);
void	init_window(char *av); //TEMPORARY

// TEMPO
 
// TEST 1
typedef struct s_map
{
	int	x;
	int	y;
	int	z;
}	t_map;

// TEST 2
typedef struct s_colors
{
	int	r;
	int	g;
	int	b;
}	t_colors;

#endif
