#include "cub3d.h"

void start_music(void)
{
    system("(while true; do aplay sounds/shot.wav; done) &");
    // or use ffplay if available
    // system("ffplay -nodisp -autoexit -loglevel quiet -loop 0 sounds/music.wav &");
}

void stop_music(void)
{
    system("killall aplay");
    // or killall ffplay
}
