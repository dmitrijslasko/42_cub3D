# 15/06/2025 Next steps
# Mandatory

- Remember our inspiration:
Castle Wolfstein
https://www.retrogames.cz/play_408-DOS.php

- Refactor !!!

- FV: Connect the minilibx library

- FV: Fix the sliding textures (they should stay in place)
DL: seemingly done, but there is another problem

- FV: Wall texture edge thickening (probably due to wall percentage miscalculations)

- FV: angle distortions on the wall line

- DL: the walls disappear on looking down (when screen_center < 0)
We should consider limiting how far up/down the player should be able to look anyways.

- FV: Map parsing
1. Test for different player initialisation directions (N, S, E, W) - works, but add this into parsing
1. Add textures (has to be reworked to be code-efficient)
1. FV: ensure that the textures from map parsing go into the dt->map->textures[4] struct

- Fix inverted textures

- DL: Test with sin and cos lookup tables (see if helps the CPU) - DL: check if it is coming from when wall height is much higher than window height
The game actually works better in FLOOR 3 cluster.

- DL: Wall slides (allow sliding along the wall)

✅ DL: think about the ways to hadle keypresses more accurately - can't remember what it was about but seemingly done?

✅ Remove the usleep function from frame rendering - DONE

- Introduce sprites

- Try to do thin walls (that will also be used to make doors)


# Crazy stuff
- Add wall shadows (one shader is already done)

- Fix jerky mouse movements

- Loading screen (game menu)

- Add floor & ceiling tiles

- Add dome sky

- Make it cross-platform (Linux & MacOS)

- Introduce transparentcy into colors

- Minimap: Redo the map to move around the player

- Minimap: Place the map into a circle (GTA style)

✅ Make forward moving faster than moving backwards and sideways - DONE
