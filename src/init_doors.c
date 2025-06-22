#include <cub3d.h>

void init_doors(t_data *dt)
{
    // Example: placing a vertical door in cell (5,5)
    t_door *door;
    size_t  door_count;
    size_t i;

    door_count = count_elements_in_the_map(&dt->map, "|-");
    printf("Doors found: %zu\n", dt->door_count);
    door_count = 1;
    dt->doors = malloc(sizeof(t_door) * door_count);
    dt->door_count = door_count;

    i = 0;
    while (i < door_count)
    {
        door = &dt->doors[i];

        door->cell_x = 5;
        door->cell_y = 5;
        door->pos_x = 0.5;    // Center of cell
        door->pos_y = 0.5;
        door->orientation = 0; // Vertical
        door->open_progress = 0.0;
        door->speed = 1.0f;
        door->state = 0;
        door->is_open = 0;
        door->width = 0.2f;
        printf("Door [%zu] added!\n", i);
        i++;
    }
}
