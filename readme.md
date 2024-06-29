# " read me " document in mark - down format

## using: Extensions for ms - vscode ( Microsoft Windows and GNU Linuxes )

- <https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack>
- <https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools>
- <https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools>

## using: msys and mingw ( Microsoft Windows only )

- <https://www.msys2.org>
- <https://www.msys2.org/docs/cmake/>

```console
# make cmake ninja packages from pacman ( package manager of MSYS2 with MinGW64 )

pacman -S mingw-w64-x86_64-make mingw-w64-x86_64-cmake mingw-w64-x86_64-ninja
```

## using: Ubuntu or Kubuntu ( Ubuntu is a GNU Linux OS that is derived from Debian GNU Linux )

```console
# installed packages: C and C++ GNU compilers and make-related build tools

sudo apt install gcc g++ make cmake ninja-build
```

```console
# installed packages: lib sdl2 development files ( SDL base and SDL image related )

sudo apt install libsdl2-dev libsdl2-image-dev
```
