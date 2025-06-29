#include "cub3d.h"

Mix_Music *init_audio(void)
{
    Mix_Music *background_music;

    print_separator_default();
	printf(TXT_YELLOW ">>> LOADING BACKGROUND MUSIC\n" TXT_RESET);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_VolumeMusic(BACKGROUND_MUSIC_VOLUME);  // Set music to 50% volume
    background_music = Mix_LoadMUS("./sounds/music.wav");
    Mix_PlayMusic(background_music, -1); // Loop
    printf(TXT_GREEN "Done!\n" TXT_RESET);
    return (background_music);
}

