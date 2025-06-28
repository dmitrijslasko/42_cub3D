#ifndef SETTINGS_H
# define SETTINGS_H

#ifndef M_PI
# define M_PI 3.14
#endif

# define GRID_SIZE  						64

# define SHOW_CALCULATION_LOGS				1

# define SHOW_DEBUG_INFO 					0

// window name
# define WINDOW_NAME         				"cub3d - fvargas & dmlasko @ 42Berlin"
# define VERSION_INFO        				"cub3d project - 42 Berlin - fvargas & dmlasko, v1.0"

// window size
# define WINDOW_W							1200
# define WINDOW_H							WINDOW_W / 4 * 3

# define TRACKED_KEYS						70000

// fps and casted rays count
# define FPS								30

# define PRECALCULATED_TRIG					3600


// TODO DL: add the ability to limit the number of rays (essentially resolution)
# define CASTED_RAYS_COUNT					400

// dummy map
# define DUMMY_MAP_TOP						"1111111111111111111111111111111"
# define DUMMY_MAP_MID						"1000001001001000000000001001001"
# define DUMMY_MAP_MID_2					"1000001000000000000000000000001"
# define DUMMY_MAP_PLAYER					"10N0000000000000000000000000001"

// Minimap settings
# define MINIMAP_OFFSET_X					20
# define MINIMAP_OFFSET_Y					20

# define MINIMAP_BACKGROUND_COLOR			ORANGE

# define MINIMAP_SIZE                       300
# define MINIMAP_GRID_SIZE					40
# define MINIMAP_GRID_COLOR					0xFF8800
# define MINIMAP_GRID_ENABLE				1

# define MINIMAP_WALL_CELL_COLOR			BLACK

# define MINIMAP_PLAYER_SPAWN_CELL_COLOR	0xFFBB00
# define MINIMAP_DOOR_COLOR					GREY
# define MINIMAP_THIN_WALL_COLOR			BLACK
# define MINIMAP_DOOR_THICKNESS_PX			3

# define MINIMAP_PLAYER_SIZE_PX 			1
# define MINIMAP_PLAYER_DISPLAY_STYLE 		CIRCLE
# define MINIMAP_PLAYER_COLOR 				WHITE

# define MINIMAP_RAY_LENGTH		            2

# define MINIMAP_DIRECTION_RAY_ENABLE       1
# define MINIMAP_DIRECTION_RAY_COLOR		MAGENTA

# define MINIMAP_RENDER_RAYS_ENABLE         1
# define MINIMAP_RENDER_RAY_COLOR		    YELLOW

// gameplay
# define FIELD_OF_VIEW_DEG					60.0f
# define FIELD_OF_VIEW_SCALE				0.577 //tan(FIELD_OF_VIEW_DEG / 2)
# define SCALING				            500

# define DEF_DOOR_OFFSET_X					0.5f
# define DEF_DOOR_OFFSET_Y					0.5f

// colors
# define DEF_BG_COLOR			    		BLACK
# define DEF_CEILING_COLOR					GREEN
# define DEF_FLOOR_COLOR					BLUE
# define DEF_WALL_COLOR						PINK

# define MIN_DISTANCE_TO_WALL				0.4f

// default scale
# define KEYBOARD_PLAYER_STEP_FORWARD		0.1f
# define KEYBOARD_PLAYER_STEP_BACKWARD		0.05f
# define KEYBOARD_PLAYER_STEP_SIDE 			0.05f
# define KEYBOARD_PLAYER_ROTATION_STEP 		2.0f
# define KEYBOARD_PLAYER_VERTICAL_LOOK_STEP 10.0f
# define MOVE_SPEED_MULTIPLIER_SLOW 		0.4f
# define MOVE_SPEED_MULTIPLIER_FAST			1.5f

# define ENABLE_VERTICAL_LOOK				1
# define LOCK_VERTICAL_LOOK_UP				100
# define LOCK_VERTICAL_LOOK_DOWN			100

// mouse sensitivity
# define ENABLE_MOUSE       				1
# define MOUSE_SENS_ROTATE 					2.0f
//# define MOUSE_SENS_DRAG					0.05f
# define MOUSE_SENS_SCROLL 					0.1f
# define DEFAULT_CROSSHAIR_COLOR			WHITE
# define DEFAULT_CROSSHAIR_SIZE				5

// separator
# define DEF_SEPARATOR_CHAR					"-"
# define DEF_SEPARATOR_WIDTH				80
# define DEF_SEPARATOR_COUNT				1

// menu & UI
# define DEBUG_MENU_NL	 					10
# define DEBUG_MENU_NL_2					20
# define UI_CLR_1    	    				WHITE
# define UI_CLR_2    	    				GOLD
# define DEBUG_FIELD_1_OFFSET_X				270
# define DEBUG_FIELD_2_OFFSET_X				90
# define DEBUG_FIELD_OFFSET_Y				20

// welcome screens
# define WELCOME_IMAGE       				"./assets/images/intro.xpm"
# define SHOW_WELCOME_IMAGE  				0

//parsing
# define PUT_DOOR				            1
# define NUMBER_TEXTURES    	            6 // four walls + celling + floor even if is a color
# define WHITE_SPACE        	            " \a\b\t\n\v\f\r"
# define SPRITES_TYPES     	 	            "spq"



// shaders
# define ENABLE_SHADERS					1
# define DISTANCE_SHADOW_STRENGTH 		0.2f

#endif
