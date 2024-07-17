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
# include <math.h>

/*/////////////////////////////////////////////////////////////////////////*/
/*				STRUCTS | LL				   */
/*/////////////////////////////////////////////////////////////////////////*/

typedef struct s_map
{
	int	width;
	int	height;
	int	**mat;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	float		zoom;
	int		color;
	int	pos_x;
	int	pos_y;
	float	rot;
	t_map	*map;
}	t_data;



/*/////////////////////////////////////////////////////////////////////////*/
/*			IDK IF THIS IS ALLOWED				   */
/*/////////////////////////////////////////////////////////////////////////*/
# define MAX(i, j) ((i > j) ? i : j)
# define ABS(Value) ((Value < 0) ? -(Value) : (Value))
# define MOD(a) ((a < 0) ? -a : a)

/*/////////////////////////////////////////////////////////////////////////*/
/*				FREES | MEMORY				   */
/*/////////////////////////////////////////////////////////////////////////*/
void	free_ll(t_file **file);
void	free_map(t_map *map);
void	free_program(t_map *map, t_file **file);

/*/////////////////////////////////////////////////////////////////////////*/
/*				READ MAP | GNL				   */
/*/////////////////////////////////////////////////////////////////////////*/
int		read_file(char *path, t_file **file);

/*/////////////////////////////////////////////////////////////////////////*/
/*				VALIDATION / PARSING			   */
/*/////////////////////////////////////////////////////////////////////////*/
int		validate_args(int ac, char **av);
int		init_fdf(char *path, t_file **file);
void	get_width(t_file **file, t_map *map);
void	get_height(t_file **file, t_map *map);
void	init_matrix(t_file **file, t_map *map);

/*/////////////////////////////////////////////////////////////////////////*/
/*				MLX AND HOOKS				   */
/*/////////////////////////////////////////////////////////////////////////*/
int		on_keypress(int keysym, t_data *data);
int		on_destroy(t_data *data);
void	init_window(t_map *map); //TEMPORARY
void	algo(float x, float y, float x1, float y1, t_data *data, t_map *map);
void	draw(t_data *data, t_map *map);

#endif
