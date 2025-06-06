/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:04:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/06 10:31:28 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_hit_wall(t_coor pos, t_map map)
{
	if (map.map_data[pos.x][pos.y] == '1')
		return (1);
	return (0);
}

void	set_step_side(t_x_y dir_vec, t_x_y pos_player, t_x_y delta_dist, t_x_y *step, t_x_y *side_dist)
{
	if (dir_vec.x < 0)
	{
		step->x = -1;
		side_dist->x = (pos_player.x - (int)pos_player.x) * delta_dist.x;
	}
	else
	{
		step->x = 1;
		side_dist->x = ((int)pos_player.x + 1.0 - pos_player.x) * delta_dist.x;
	}

	if (dir_vec.y < 0)
	{
		step->y = -1;
		side_dist->y = (pos_player.y - (int)pos_player.y) * delta_dist.y;
	}
	else
	{
		step->y = 1;
		side_dist->y = ((int)pos_player.y + 1.0 - pos_player.y) * delta_dist.y;
	}
}

t_type_wall	get_type_wall(char c, t_x_y direction)
{
	if (c == 'x' && direction.x < 0)
		return (SOUTH);
	if (c == 'x')
		return (NORTH);
	if (c == 'y' && direction.y < 0)
		return (EAST);
	return (WEST);
}

void	hit_wall(t_data dt, t_x_y direction, t_x_y delta_dist, t_type_wall *type_wall, double *dist)
{
	t_x_y	step;
	t_x_y	side_dist;
	t_coor	coor;
	char	c;

	c = 0;
	set_value_coor(&coor, dt.player->pos.x, dt.player->pos.y);
	set_step_side(direction, dt.player->pos, delta_dist, &step, &side_dist);
	while (!check_hit_wall(coor, *dt.map) && \
			(size_t)side_dist.x < dt.map->map_size_cols && \
			(size_t)side_dist.y < dt.map->map_size_rows)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			coor.x += step.x;
			c = 'x';
		}
		else
		{
			side_dist.y += delta_dist.y;
			coor.y += step.y;
			c = 'y';
		}
	}
	*dist = max_double(side_dist.x, side_dist.y);
	*type_wall = get_type_wall(c, direction);
}

t_x_y	get_delta_dist(t_x_y direction)
{
	t_x_y	delta_dist;

	delta_dist.x = 0;
	if (direction.x != 0)
		delta_dist.x = fabs(1 / direction.x);
	delta_dist.y = 0;
	if (direction.y != 0)
		delta_dist.y = fabs(1 / direction.y);
	return (delta_dist);
}

t_ray	*create_ray(t_data *dt, t_x_y direction)
{
	t_x_y		delta_dist;
	t_ray		*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	delta_dist = get_delta_dist(direction);
	hit_wall(*dt, direction, delta_dist, &ray->type_wall, &ray->dist);
	return (ray);
}

bool	create_array_ray(t_data *dt)
{
	(void)dt;
	return (0);
}
