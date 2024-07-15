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

typedef struct s_file
{
	char	*line;
	struct s_file *next;
}	t_file;

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


typedef struct s_map
{
	int	width;
	int	height;
	int	**mat;
}	t_map;

/*/////////////////////////////////////////////////////////////////////////*/
/*				VALIDATION / PARSING			   */
/*/////////////////////////////////////////////////////////////////////////*/
int	validate_args(int ac, char **av);
void	init_fdf(char *path, t_map *map, t_file **file);
void	store_file(char *path, t_file **file);
int	get_width(char *path);
void	get_height(t_file **file, t_map *map);
void	get_alt(t_file **file, t_map *map);
void	del(char *line);

/*/////////////////////////////////////////////////////////////////////////*/
/*				MLX AND HOOKS				   */
/*/////////////////////////////////////////////////////////////////////////*/
int	on_keypress(int keysym, t_data *data);
int	on_destroy(t_data *data);
void	init_window(char *path); //TEMPORARY

#endif
