#ifndef SETTINGS_H
# define SETTINGS_H

#ifndef M_PI
# define M_PI 3.14
#endif

# define GRID_SIZE  64

# define SHOW_CALCULATION_LOGS	1

# define SHOW_DEBUG_INFO 	0

// window name
# define WINDOW_NAME         "cub3d - fvargas & dmlasko @ 42Berlin"
# define VERSION_INFO        "cub3d project - 42 Berlin - fvargas & dmlasko, v1.0"

// window size
# define WINDOW_W		1200
# define WINDOW_H		WINDOW_W / 4 * 3

# define TRACKED_KEYS	70000

// fps and casted rays count
# define FPS					30

# define PRECALCULATED_TRIG		3600


// TODO DL: add the ability to limit the number of rays (essentially resolution)
# define CASTED_RAYS_COUNT		600

// dummy map
# define DUMMY_MAP_TOP		"1111111111111111111111111111111"
# define DUMMY_MAP_MID		"1000001001001000000000001001001"
# define DUMMY_MAP_MID_2	"1000001000000000000000000000001"
# define DUMMY_MAP_PLAYER	"10N0000000000000000000000000001"

// Minimap settings
# define MINIMAP_OFFSET_X					20
# define MINIMAP_OFFSET_Y					50

# define MINIMAP_BACKGROUND_COLOR			ORANGE

# define MINIMAP_GRID_SIZE					20
# define MINIMAP_GRID_COLOR					NAVY
# define MINIMAP_GRID_ENABLE				0

# define MINIMAP_WALL_CELL_COLOR			NAVY
# define MINIMAP_PLAYER_SPAWN_CELL_COLOR	LIME
# define MINIMAP_DOOR_COLOR					BLUE

# define MINIMAP_PLAYER_SIZE_PX 			4
# define MINIMAP_PLAYER_DISPLAY_STYLE 		CIRCLE
# define MINIMAP_PLAYER_COLOR 				WHITE

# define MINIMAP_RAY_LENGTH		            2
# define MINIMAP_DIRECTION_RAY_ENABLE       1
# define MINIMAP_DIRECTION_RAY_COLOR		MAGENTA

# define MINIMAP_RENDER_RAYS_ENABLE         1
# define MINIMAP_RENDER_RAY_COLOR		    YELLOW

// gameplay
# define FIELD_OF_VIEW_DEG					60.0f
# define SCALING				            500

// colors
# define DEF_BG_COLOR			BLACK
# define DEF_CEILING_COLOR			GREEN
# define DEF_FLOOR_COLOR			BLUE
# define DEF_WALL_COLOR				PINK

# define MIN_DISTANCE_TO_WALL					0.4f

// default scale
# define KEYBOARD_PLAYER_STEP_FORWARD			0.1f
# define KEYBOARD_PLAYER_STEP_BACKWARD			0.05f
# define KEYBOARD_PLAYER_STEP_SIDE 				0.05f
# define KEYBOARD_PLAYER_ROTATION_STEP 			2.0f
# define KEYBOARD_PLAYER_VERTICAL_LOOK_STEP 	10.0f
# define MOVE_SPEED_MULTIPLIER_SLOW 			0.4f
# define MOVE_SPEED_MULTIPLIER_FAST				1.5f

# define ENABLE_VERTICAL_LOOK					1
# define LOCK_VERTICAL_LOOK_UP					100
# define LOCK_VERTICAL_LOOK_DOWN				100

// separator
# define DEF_SEPARATOR_CHAR		"-"
# define DEF_SEPARATOR_WIDTH	80
# define DEF_SEPARATOR_COUNT	1

// mouse sensitivity
# define MOUSE_SENS_ROTATE 	2.0f
//# define MOUSE_SENS_DRAG	0.05f
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
