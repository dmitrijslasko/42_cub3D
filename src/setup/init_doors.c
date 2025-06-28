#include <cub3d.h>

void init_doors(t_data *dt)
{
	t_door 	*door;
	size_t  door_count;
	size_t 	i;
	size_t 	curr_row;
	size_t 	curr_col;

	// malloc
	print_separator_default();
	printf(TXT_YELLOW ">>> INITIALISING DOORS\n" TXT_RESET);
	door_count = count_elements_in_the_map(&dt->map, "|-");
	printf("Doors found: %zu\n", door_count);

	dt->doors = malloc(sizeof(t_door) * door_count);
	dt->door_count = door_count;

	i = 0;
	curr_row = 0;
	while (curr_row < dt->map.map_size_rows)
	{
		curr_col = 0;
		while (curr_col < dt->map.map_size_cols)
		{
			if (ft_strchr("|-", get_cell_type_by_coordinates(&dt->map, curr_row, curr_col)))
			{
				door = &dt->doors[i];
				door->id = i;
				door->cell_x = curr_col;
				door->cell_y = curr_row;
				door->pos_x = DEF_DOOR_OFFSET_X;
				door->pos_y = DEF_DOOR_OFFSET_Y;
				door->open_progress = 0.0f;
				door->speed = 1.0f;
				door->state = 0;
				printf("Door [%zu] at X Y (%zu, %zu) added with id:\t%zu\n", i, curr_col, curr_row, door->id);
				i++;
			}
			curr_col++;
		}
		curr_row++;
	}
	printf(TXT_GREEN "Done!\n" TXT_RESET);
}
