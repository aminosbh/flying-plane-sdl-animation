# Flying plane SDL animation

This project is written in C and uses [CMake][] as a build system.<br>
It shows how we can make a basic animation using [SDL2][SDL] : Flying plane.

## Dependencies

- [Git][]
- C Compiler (gcc, ...)
- [CMake][]
- [SDL2][SDL] library
- [SDL2_image][] library
- [SDL2_gfx][] library

**On Debian/Ubuntu based distributions, use the following command:**

```sh
sudo apt install git build-essential pkg-config cmake cmake-data libsdl2-dev libsdl2-image-dev libsdl2-gfx-dev
```

**Optional packages:**

- [SDL2_ttf][] library

```sh
sudo apt install libsdl2-ttf-dev
```

## Build instructions

```sh
# Clone this repo
git clone https://gitlab.com/aminosbh/flying-plane-sdl-animation.git
cd flying-plane-sdl-animation

# Create a build folder
mkdir build
cd build

# Build
cmake ..
make

# Run
./flying-plane-sdl-animation
```

***Note:*** To use SDL2_ttf you should uncomment
some instructions in the CMakeLists.txt file and re-execute `cmake ..` and `make`

### Open the project with an IDE under Linux

See [IDE_USAGE.md](IDE_USAGE.md) for details.

## License

Author: Amine B. Hassouna [@aminosbh](https://gitlab.com/aminosbh)

This project is distributed under the terms of the MIT license
[&lt;LICENSE&gt;](LICENSE).


The images under the assets directory are distributed under different licenses:

- `plane.png` and `plane-shadow.png`:
  Author: Amine B. Hassouna [@aminosbh](https://gitlab.com/aminosbh)
  License: [Creative Commons Attribution 4.0 International License.](CCBY)

- `ocean.jpg`:
  Author: [the3rdSequence.com](https://www.the3rdsequence.com)
  License: [Creative Commons Attribution 4.0 International License.](CCBY)
  Site: https://www.the3rdsequence.com/texturedb/texture/23/sea+water



[SDL]: https://www.libsdl.org
[CMake]: https://cmake.org
[Git]: https://git-scm.com
[SDL2_image]: https://www.libsdl.org/projects/SDL_image
[SDL2_ttf]: https://www.libsdl.org/projects/SDL_ttf
[SDL2_gfx]: http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx
[CCBY]: http://creativecommons.org/licenses/by/4.0/
