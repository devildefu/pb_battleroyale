# Perypetie Boba Battle Royale
"Don't expect us to finish this project" ~no one, 2019

## About
Perypetie Boba but battle royale + open source, the game is written in C++ using SFML (because most of us know C++ well).

[Link to the original game](https://pb.olekolek1000.pl)

## Getting Started
These instructions will show you how to install the necessary stuff and compile the project.

### Prerequisites
- C++ Compiler (GCC recommended)
- SFML
- CMake

### Compiling
Compilation is very easy. Just open the terminal and go to the project directory, enter `cmake -Bbuild -G Ninja -DCMAKE_BUILD_TYPE=Debug` and then `cmake --build build`. CMake will do the rest. After completing the compilation, you should find `pb_battleroyale.exe` or `pb_battleroyale` in the build folder.

### Built Using
- [inih](https://github.com/benhoyt/inih) - .ini file parser
- [spdlog](https://github.com/gabime/spdlog) - logging
- [pbloader](https://github.com/CodersArmyTeam/pbloader) - my old project to add a modapi to PB. Part of the code 
and the knowledge of how PB works comes from this project.
