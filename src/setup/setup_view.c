#include "cub3d.h"

void	setup_view(t_data *dt)
{
	dt->view->screen_center_y = WINDOW_H / 2;
	dt->view->show_minimap = 0;
	dt->view->show_debug_info = 0;
	dt->view->show_door_open_message = 0;
}
