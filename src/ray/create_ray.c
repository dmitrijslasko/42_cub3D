/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 20:04:57 by fvargas           #+#    #+#             */
/*   Updated: 2025/06/07 16:25:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	update_ray(t_data dt, t_ray *ray, t_x_y direction, t_x_y delta_dist, t_x_y	step, t_x_y	side_dist)
{
	//t_ray	*ray;
	t_coor	coor_map;
	char	c;
	int		i;

	i = 0;
	c = initialize_wall_hit(side_dist);
	coor_map = get_updated_coor_player(dt.player->pos, direction, 1);
	coor_map = get_updated_coor_player_(coor_map, direction, -1);
	while (!check_hit_wall(coor_map, *dt.map) && i < 2 * max_double(dt.map->map_size_cols, dt.map->map_size_rows))
	{
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
	}
	ray->distance_to_wall = get_dist_wall(c, side_dist);
	ray->wall_type = get_type_wall(c, direction);
	ray->percentage_of_image = get_perc_wall(dt.player->pos, direction, ray->distance_to_wall, ray->wall_type);
}

void	update_single_ray(t_data *dt, t_ray *ray, t_x_y direction)
{
	t_x_y	step;
	t_x_y	side_dist;
	t_x_y	delta_dist;

	// Delta distance
	set_delta_dist(&delta_dist, direction);
	//printf("delta_x = %f and delta_y = %f\n", delta_dist.x, delta_dist.y);

	// Step
	set_step(&step, direction);
	//printf("step_x = %f and step_y = %f\n", step.x, step.y);

	// Step distance
	set_side_dist(&side_dist, direction, dt->player->pos, delta_dist);
	//printf("side_dist_x = %f and side_dist_y = %f\n", side_dist.x, side_dist.y);

	// Create ray & print out its information
	update_ray(*dt, ray, direction, delta_dist, step, side_dist);
	//print_single_ray_info(*ray);
}

t_ray	*calculate_all_rays(t_data *dt)
{
	size_t	i;
	t_x_y 	vet;
	double	angle;
	t_coor pt1;

	printf(TXT_GREEN "Calculating all rays...\n" TXT_RESET);

	set_coor_values(&pt1, dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE);

	i = 0;

	angle = -FIELD_OF_VIEW_DEG / 2;
	while (i < CASTED_RAYS_COUNT)
	{
		vet = rotate_vector(dt->player->direction_vet, angle);
		//printf("Ray #%zu: angle = %f, X Y = %f %f\n", i, angle, vet.x, vet.y);
		update_single_ray(dt, &dt->rays[i], vet);
		if (i == CASTED_RAYS_COUNT / 2)
			printf("Ray distance: %f\n", dt->rays[i].distance_to_wall);
		draw_vector(dt, pt1, vet, 1);
		angle += FIELD_OF_VIEW_DEG / (CASTED_RAYS_COUNT);
		i++;
	}

	// direction vector
	t_x_y vet2 = rotate_vector(dt->player->direction_vet, 0);
	t_coor origin = get_values_coor(dt->player->pos.x * DEF_GRID_SIZE, dt->player->pos.y * DEF_GRID_SIZE);
	draw_vector(dt, origin, vet2, 0);

	return (dt->rays);
}

