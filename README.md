*This project has been created as part of the 42 curriculum by aalmoman.*

# so_long

## Description

so_long is a small 2D game where you control a character that needs to collect all the collectibles on the map and then reach the exit. The game is built using the MiniLibX graphics library.

The goal is simple: move around, grab all the gems, and get to the door. You can't leave until you've collected everything!

## Instructions

### Requirements

- Linux with X11
- gcc compiler
- make

### Compilation

```bash
make
```

This will compile the game and create the `so_long` executable.

### Running the game

```bash
./so_long <map_file.ber>
```

Example:
```bash
./so_long level.ber
```

### Controls

- `W` or `↑` - Move up
- `S` or `↓` - Move down
- `A` or `←` - Move left
- `D` or `→` - Move right
- `ESC` - Quit the game

### Map format

Maps are `.ber` files with the following characters:
- `1` - Wall
- `0` - Empty space
- `P` - Player starting position (only one)
- `C` - Collectible
- `E` - Exit (only one)

The map must be rectangular and surrounded by walls.

## Resources

### Documentation

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [X11 programming guide](https://tronche.com/gui/x/xlib/)

### AI Usage

AI assistance (GitHub Copilot) was used for:
- Debugging memory leaks and ensuring proper cleanup on allocation failures
- Generating XPM sprite files for the game textures
- Code formatting to comply with 42 norminette standards
- Writing this README file

All code logic and architecture was written and understood by the author.
