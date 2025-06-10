/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:16:09 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/10 16:41:05 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

#ifndef M_PI
# define M_PI 3
#endif

# define SHOW_CALCULATION_LOGS	1

# define SHOW_DEBUG_INFO 	0

// window name
# define WINDOW_NAME         "cub3d - fvargas & dmlasko @ 42Berlin"
# define VERSION_INFO        "cub3d project - 42 Berlin - fvargas & dmlasko, v1.0"

// window size
# define WINDOW_W		1020
# define WINDOW_H		WINDOW_W / 4 * 3

# define TRACKED_KEYS	70000

// fps and casted rays count
# define FPS					60

# define PRECALCULATED_TRIG		3600


// TODO DL: add the ability to limit the number of rays (essentially resolution)
# define CASTED_RAYS_COUNT	1020

// dummy map
# define DUMMY_MAP_TOP		"1111111111111"
# define DUMMY_MAP_MID		"1010101010101"
# define DUMMY_MAP_MID_2	"1000000000001"
# define DUMMY_MAP_PLAYER	"1000N00000001"

// minimap
# define MINIMAP_OFFSET_X					0
# define MINIMAP_OFFSET_Y					0
# define MINIMAP_GRID_SIZE					(WINDOW_W / 40)
# define MINIMAP_GRID_COLOR					GREY
# define MINIMAP_BACKGROUND_COLOR			DARKGREY
# define MINIMAP_WALL_CELL_COLOR			ORANGE
# define MINIMAP_PLAYER_SPAWN_CELL_COLOR	LIME
# define MINIMAP_PLAYER_SIZE_PX 			4
# define MINIMAP_PLAYER_DISPLAY_STYLE 		CIRCLE
# define MINIMAP_PLAYER_COLOR 				WHITE

# define FIELD_OF_VIEW_DEG		75.0f
# define SCALING	200

// colors
# define DEF_CEILING_COLOR		BLUE
# define DEF_FLOOR_COLOR		GREEN
# define DEF_WALL_COLOR			PINK

# define MIN_DISTANCE_TO_WALL	1.0f

// default scale
# define KEYBOARD_PLAYER_STEP			0.05f
# define KEYBOARD_PLAYER_STEP_FORWARD	0.05f
# define KEYBOARD_PLAYER_STEP_BACKWARD	0.025f
# define KEYBOARD_PLAYER_STEP_SIDE 		0.025f
# define KEYBOARD_PLAYER_ROTATION_STEP 	2.5f


// colors
# define DEF_BG_COLOR		BLACK

// separator
# define DEF_SEPARATOR_CHAR		"-"
# define DEF_SEPARATOR_WIDTH	80

// zoom settings
# define MAX_ZOOM			5
# define MIN_ZOOM			0.5f
# define KEYBOARD_ZOOM		0.1f
# define DEF_STARTING_ZOOM   0.5f

// mouse sensitivity
# define MOUSE_SENS_ROTATE  2.5f
# define MOUSE_SENS_DRAG	0.7f
# define MOUSE_SENS_SCROLL 	0.1f

// menu & UI
# define DEF_MENU_ROW_H 	15
# define MENU_WIDTH_PX      200
# define UI_CLR_1    	    WHITE
# define UI_CLR_2    	    GOLD

// map parsing
# define PARSE_MAP			TRUE
# define TEST_MAP_X			10
# define TEST_MAP_Y		    10
# define TEST_MAP_Z         0

// welcome screen
# define WELCOME_IMAGE       "./assets/images/intro.xpm"
# define SHOW_WELCOME_IMAGE  0

#endif
