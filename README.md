## ▼ ▼ ▼ ▼ ▼ ▼
## THIS IS A WIP
## ▲ ▲ ▲ ▲ ▲ ▲

# Pixel Platformer Game

Welcome to the Pixel Platformer game project! This 2D platformer game is built using SDL2 and C. In this README, you'll find instructions on how to compile and run the game.

## Prerequisites

Before you can compile and run the game, you'll need to ensure the following dependencies are installed on your system:

- CMake (version 3.5.1 or higher)
- SDL2
- SDL2_image
- SDL2_net
- SDL2_mixer
- SDL2_ttf

### Installing Dependencies

#### macOS (using Homebrew)

If you're on macOS and have Homebrew installed, you can install the required dependencies with the following commands:

```bash
brew install cmake sdl2 sdl2_image sdl2_net sdl2_mixer sdl2_ttf
```

#### Arch Linux (using Pacman)

If you're using Arch Linux, you can use Pacman to install the dependencies:

```bash
sudo pacman -S cmake sdl2 sdl2_image sdl2_net sdl2_mixer sdl2_ttf
```

#### Other Linux Distributions

For other Linux distributions, you can use your respective package manager to install the dependencies. The package names may vary depending on your distribution.

### Compilation

To compile the game, follow these steps:

1. Clone the project repository to your local machine:

   ```bash
   git clone https://github.com/gideonmt/pixel-platformer.git
   ```

2. Navigate to the project directory:

   ```bash
   cd pixel-platformer
   ```

3. Create a build directory and navigate into it:

   ```bash
   mkdir build
   cd build
   ```

4. Run CMake to generate the build files:

   ```bash
   cmake ..
   ```

5. Build the project using your preferred build system (e.g., make):

   ```bash
   make
   ```

## Running the Game

After successfully compiling the project, you can run the game by executing the following command:

```bash
./bin/pixel-platformer
```

This will launch the game in a new window.

## Gameplay

- Use the arrow keys to move your character left and right.
- Press the spacebar to jump.
- You can also use a dash ability (provide details if applicable).

## Contributions

Contributions to the project are welcome. This project is a WIP right now so many things do not work. 