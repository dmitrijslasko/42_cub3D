#ifndef SOUND_H
# define SOUND_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_mixer.h>
# include "cub3d.h"

Mix_Music	*init_audio(void);

# define BACKGROUND_MUSIC_VOLUME    64

#endif
