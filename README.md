# 15/06/2025 Next steps
# Mandatory

- Remember our inspiration:
Castle Wolfstein
https://www.retrogames.cz/play_408-DOS.php

- Refactor !!!

- FV: Fix the sliding textures (they should stay in place)
DL: seemingly done, but there is another problem

- FV: Wall texture edge thickening (probably due to wall percentage miscalculations)

- FV: angle distortions on the wall line

- Fix inverted textures

- DL: Test with sin and cos lookup tables (see if helps the CPU) - DL: check if it is coming from when wall height is much higher than window height
The game actually works better in FLOOR 3 cluster.

✅ DL: think about the ways to hadle keypresses more accurately - can't remember what it was about but seemingly done?

✅ Remove the usleep function from frame rendering - DONE

# Crazy stuff
- Add wall shadows (one shader is already done)

- Fix jerky mouse movements
