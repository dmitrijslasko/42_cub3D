# 10/06/2025 Next steps
# Mandatory
- FV: Connect the minilibx library
- FV: Fix the sliding textures (they should stay in place)
- Refactor !!!
- Add textures (has to be reworked to be code-efficient).
- Fix inverted textures
- DL: Test with sin and cos lookup tables (see if helps the CPU) - DL: check if it is coming from when wall height is much higher than window height
The game actually works better in FLOOR 3 cluster.

- DL: Wall slides (allow sliding along the wall)

- FV: Map parsing
- Test for different player initialisation directions (N, S, E, W) - works, but add this into parsing
- DL: thinks about the ways to hadle keypresses more accurately - can't remember what it was about but seemingly done?

✅ Remove the usleep function from frame rendering - DONE
- Introduce sprites

# Crazy stuff
- Add wall shadows
- Fix jerky mouse movements
- Loading screen )game menu)
- Add floor & ceiling tiles
- Make it cross-platform (Linux & MacOS)
- Introduce transparentcy into colors

- Minimap: Redo the map to move around the player
- Minimap: Place the map into a circle (GTA style)

✅ Make forward moving faster than moving backwards and sideways - DONE
