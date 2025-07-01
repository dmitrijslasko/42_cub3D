// #include "cub3d.h"

// // TODO DL: rename curr_col to curr_row BECAUSE IT IS A ROW!
// // TODO DL: replace strcpy with ft_strcpy
// t_map	*load_dummy_map(void)
// {
// 	t_map	*map;

// 	printf("Loading dummy map->..");
// 	map = malloc(sizeof(t_map));
// 	if (!map)
// 		return (NULL);

// 	map->map_size_rows = ft_strlen(DUMMY_MAP_TOP);
// 	map->map_size_cols = ft_strlen(DUMMY_MAP_TOP);
// 	map->map_data = malloc((map->map_size_cols + 1) * sizeof(char *));
// 	if (!map->map_data)
// 		return (NULL);
// 	map->map_data[map->map_size_cols] = NULL;  // null-terminate row array

// 	for (size_t curr_col = 0; curr_col < map->map_size_cols; curr_col++)
// 	{
// 		map->map_data[curr_col] = malloc((map->map_size_rows + 1) *
// 			sizeof(char));  // +1 for '\0'
// 		if (!map->map_data[curr_col])
// 			return (NULL); // ideally free previously malloc'd rows
// 		if (curr_col == 0 || curr_col == map->map_size_rows - 1)
// 			strcpy(map->map_data[curr_col], DUMMY_MAP_TOP);
// 		else if (curr_col == 4)
// 			strcpy(map->map_data[curr_col], DUMMY_MAP_PLAYER);
// 		else if (curr_col % 2)
// 			strcpy(map->map_data[curr_col], DUMMY_MAP_MID);
// 		else
// 			strcpy(map->map_data[curr_col], DUMMY_MAP_MID_2);
// 		}
// 	// NOTE DL: extra cells on the map to make our lives more difficult
// 	//map->map_data[5][3] = '1';
// 	map->map_data[1][1] = 'S';
// 	printf(" Done!\n");
// 	return (map);
// }
