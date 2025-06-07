/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:16:09 by dmlasko           #+#    #+#             */
/*   Updated: 2025/06/06 23:52:06 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif

// window name
# define WINDOW_NAME         "cub3d - fvargas & dmlasko @ 42Berlin"
# define VERSION_INFO        "cub3d project - 42 Berlin - fvargas & dmlasko, v1.0"

// window size
# define WINDOW_W 	1200
# define WINDOW_H 	900
# define DEF_GRID_SIZE	40
# define DEF_GRID_COLOR	GREY

// dummy map
# define DUMMY_MAP_TOP		"111111111111"
# define DUMMY_MAP_MID		"100000000001"
# define DUMMY_MAP_PLAYER	"1000000N0001"

// default scale
# define X_CENTER 	600
# define Y_CENTER 	450
# define XY_DIST    100
# define Z_DIST 	1
# define PLAYER_STEP	0.5f
# define PLAYER_ROTATION_STEP 5
# define PLAYER_SIZE_PX 10
# define PLAYER_COLOR 	WHITE
#define MIN_DISTANCE_TO_WALL 0.1f

// offsets
# define DEF_OFFSET_X       	0
# define DEF_OFFSET_Y       	0

// colors
# define DEF_BG_COLOR		BLACK


// default rotation (degrees)
# define DEF_ISO_ROT_X		0
# define DEF_ISO_ROT_Y		0
# define DEF_ISO_ROT_Z       0
# define DEF_ISO_ANGLE   	30


// zoom settings
# define MAX_ZOOM			5
# define MIN_ZOOM			0.5f
# define KEYBOARD_ZOOM		0.1f
# define DEF_STARTING_ZOOM   0.5f

// mouse sensitivity
# define MOUSE_SENS_ROTATE 	0.2f
# define MOUSE_SENS_DRAG	0.7f
# define MOUSE_SENS_SCROLL 	0.1f

// menu & UI
# define DEF_MENU_ROW_H 	15
# define MENU_WIDTH_PX      200
# define UI_CLR_1    	    WHITE
# define UI_CLR_2    	    GOLD

// bounding box
# define BBOX_COLOR			GREEN
# define CENTER_LINE_PX     50
# define CL_MARGIN          20

// map parsing
# define PARSE_MAP			TRUE
# define TEST_MAP_X			10
# define TEST_MAP_Y		    10
# define TEST_MAP_Z         0

// welcome screen
# define WELCOME_IMAGE       "./assets/images/intro.xpm"
# define SHOW_WELCOME_IMAGE  0

#endif
