/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:04:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/06 18:46:08 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_hit_wall(t_coor coord, t_map map)
{
	if (map.map_data[coord.y][coord.x] == '1')
		return (1);
	return (0);
}

t_type_wall	get_type_wall(char c, t_x_y direction)
{
	if (c == 'y' && direction.y < 0)
		return (NORTH);
	if (c == 'y')
		return (SOUTH);
	if (c == 'x' && direction.x < 0)
		return (EAST);
	return (WEST);
}

double	get_dist_wall(char c, t_x_y side_dist)
{
	if (c == 'y')
		return (side_dist.y);
	return (side_dist.x);
}

char	initialize_wall_hit(t_x_y side_dist)
{
	if (side_dist.x < side_dist.y)
		return ('x');
	return ('y');
}

t_ray	*create_ray(t_data dt, t_x_y direction, t_x_y delta_dist, t_x_y	step, t_x_y	side_dist)
{
	t_ray	*ray;
	t_coor	coor_map;
	char	c;
	int		i;

	i = 0;
	c = initialize_wall_hit(side_dist);
	coor_map = get_updated_coor_player(dt.player->pos, direction, 1);
	coor_map = get_updated_coor_player_(coor_map, direction, -1);
	while (!check_hit_wall(coor_map, *dt.map) && i < 2 * max_double(dt.map->map_size_cols, dt.map->map_size_rows))
	{
		printf(" coord. x = %d  coord. y = %d\n", coor_map.x, coor_map.y);
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			coor_map.x += step.x;
			c = 'x';
		}
		else
		{
			side_dist.y += delta_dist.y;
			coor_map.y += step.y;
			c = 'y';
		}
		printf("        loop %d side_dist_x = %f and side_dist_y = %f in %c\n", ++i, side_dist.x, side_dist.y, c);
		printf("        coord. x = %d  coord. y = %d\n", coor_map.x, coor_map.y);
	}
	printf("        !HIT A WALL!\n");
	ray = constructor_ray(get_dist_wall(c, side_dist), get_type_wall(c, direction));
	ray->perc_img = get_perc_wall(dt.player->pos, direction, ray->dist, ray->type_wall);
	return (ray);
}

void	print_ray(t_ray ray)
{
	printf("ray distance is %f \n", ray.dist);
	printf("Wall type ");
	if (ray.type_wall == NORTH)
		printf("NORTH\n");
	if (ray.type_wall == WEST)
		printf("WEST\n");
	if (ray.type_wall == EAST)
		printf("EAST\n");
	if (ray.type_wall == SOUTH)
		printf("SOUTH\n");
	printf("ray has %f percentage \n", ray.perc_img);
}

t_ray	*calculate_ray(t_data dt, t_x_y direction)
{
	t_x_y	step;
	t_x_y	side_dist;
	t_x_y	delta_dist;
	t_ray	*ray;

	set_delta_dist(&delta_dist, direction);
	printf("delta_x = %f and delta_y = %f\n", delta_dist.x, delta_dist.y);
	set_step(&step, direction);
	printf("step_x = %f and step_y = %f\n", step.x, step.y);
	set_side_dist(&side_dist, direction, dt.player->pos, delta_dist);
	printf("side_dist_x = %f and side_dist_y = %f\n", side_dist.x, side_dist.y);
	ray = create_ray(dt, direction, delta_dist, step, side_dist);
	print_ray(*ray);
	return (ray);
}

bool	create_array_ray(t_data dt)
{
	printf("map[%d][%d] = %c\n", 1, 4,  dt.map->map_data[1][4]);
	printf("map[%d][%d] = %c\n", 4, 1,  dt.map->map_data[4][1]);
	printf("\nRAAAAAYS: \n");
	printf(TXT_GREEN "← 1-Direction (-1, 0)\n" TXT_RESET);
	calculate_ray(dt, dt.player->direction_vet);
	printf("\n\n");
	printf(TXT_GREEN"→ 2-Direction (1, 0)\n"TXT_RESET);
	calculate_ray(dt, get_values_x_y(1, 0));
	printf("\n\n");
	printf(TXT_GREEN"↑ 3-Direction (0, -1)\n"TXT_RESET);
	calculate_ray(dt, get_values_x_y(0, -1));
	printf("\n\n");
	printf(TXT_GREEN"↓ 4-Direction (0, 1)\n"TXT_RESET);
	calculate_ray(dt, get_values_x_y(0, 1));
	printf("\n\n");
	printf(TXT_GREEN"↙ 5-Direction (-0.707, 0.707)\n"TXT_RESET);
	calculate_ray(dt, get_values_x_y(-0.707, -0.707));
	printf("\n\n");
	return (0);
}
