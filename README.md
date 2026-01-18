# So Long - 2D Game Project

*This project has been created as part of the 42 curriculum by student*

---

## Description

A simple 2D game built using the MiniLibX graphical library. Navigate a hero through a map, collect all gems, and reach the exit door to win. The game features:

- Window management with MiniLibX
- Sprite-based graphics with XPM textures
- Keyboard controls (WASD or arrow keys)
- Map validation and path checking
- Move counter displayed in terminal

---

## Game Rules

- Use `W`, `A`, `S`, `D` or arrow keys to move
- Collect all gems (C) before the exit (E) opens
- Cannot walk through walls (1)
- Press `ESC` or close window to exit
- Move count is displayed after each step

---

## Map Format

Maps use the `.ber` extension with these characters:

| Character | Description |
|-----------|-------------|
| `0` | Empty floor |
| `1` | Wall |
| `C` | Collectible gem |
| `E` | Exit door |
| `P` | Player starting position |

### Map Requirements

- Must be rectangular
- Surrounded by walls on all edges
- Exactly one player (P) and one exit (E)
- At least one collectible (C)
- Valid path from player to all collectibles and exit

### Example Map

```
1111111
1P0C001
1011101
1C000E1
1111111
```

---

## Build Instructions

### Prerequisites

- GCC compiler
- Make
- MiniLibX library (place in `mlx/` directory)
- X11 development libraries

### Compilation

```bash
# Clone or copy MiniLibX to mlx/ folder first
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Running

```bash
./so_long path/to/map.ber
```

---

## Project Structure

```
game_2d/
├── Makefile
├── README.md
├── game_2d.h          # Header file
├── launcher.c         # Main entry point
├── setup.c            # Game initialization
├── gnl_reader.c       # Get next line implementation
├── str_tools.c        # String utilities
├── arr_tools.c        # Array utilities (split, free)
├── board_loader.c     # Map file parsing
├── board_checker.c    # Map validation
├── grid_utils.c       # Grid utility functions
├── path_finder.c      # Path validation (flood fill)
├── display.c          # Rendering functions
├── controls.c         # Input handling
├── hero_motion.c      # Player movement logic
├── level.ber          # Sample map
├── mlx/               # MiniLibX library
└── sprites/           # Game textures
    ├── brick.xpm
    ├── ground.xpm
    ├── hero.xpm
    ├── gem.xpm
    └── door.xpm
```

---

## Error Handling

The program handles errors gracefully:

- Invalid arguments: `Usage: ./so_long <map.ber>`
- Invalid map extension: `Map must have .ber extension`
- Map errors (shape, walls, entities, path): `Error`

All memory is properly freed on exit.

---

## Resources

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- 42 Project Guidelines
- No AI was used in the core algorithm design

---

## Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move up |
| `A` / `←` | Move left |
| `S` / `↓` | Move down |
| `D` / `→` | Move right |
| `ESC` | Exit game |

---

## Author

42 Student
