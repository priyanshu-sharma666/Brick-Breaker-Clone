# Brick Breaker Clone

A classic 2D Brick Breaker style arcade game built using C++ and the SFML (Simple and Fast Multimedia Library) graphics framework. 

The player controls a moving paddle at the bottom of the screen to bounce a dynamic ball upward, hitting boundaries to stay alive and rack up points.


### Source Code:
* `main.cpp` - Contains the entire self-contained game initialization, event loop, physics engine updates, and window rendering logic.

### Assets:
* `TTD Compadre-Regular.otf` - The specific typography asset required to render your active score tracker and the large "GAME OVER" message screen.

## Prerequisites
To compile or run this project on your system, you need:
* A C++ compiler supporting **C++17** or higher.
* **SFML 2.6.2** installed on your computer.
* Visual Studio Code with the C/C++ extension pack installed.

## Build and Run Configuration

This project is built using VS Code and GCC/MinGW. Follow these steps to compile and run the game on Windows.

### 1. Configure Compiler Paths
Your `.vscode/tasks.json` file handles compilation. Ensure the include (`-I`) and library (`-L`) paths match your local SFML installation folder:
* `"C:/SFML-2.6.2/include"`   
* `"C:/SFML-2.6.2/lib"`
*(Note: Swap these default paths if you downloaded SFML into a different hard drive directory).*

### 2. Building the Project
1. Open the project folder inside VS Code.
2. Press `Ctrl + Shift + B` to trigger your "Build SFML" task.
3. This will compile your code and generate a standalone `main.exe` executable inside your workspace directory.

### 3. Required DLL Files (CRITICAL)
Before launching `main.exe`, you **must copy the required SFML DLL files** into the exact same folder directory where your newly generated `main.exe` sits. If skipped, Windows will throw a missing `.dll` launch system error.

Go to your local installation folder (`SFML-2.6.2/bin/`) and copy these **3 DLL files** into your game project workspace folder:
* `sfml-graphics-2.dll`
* `sfml-window-2.dll`
* `sfml-system-2.dll`

### 4. Run the Game
Ensure your font asset (`TTD Compadre-Regular.otf`) is sitting in the root folder alongside your `main.exe` and your `.dll` configuration. Double-click `main.exe` to launch the game!
you can download the font from anywhere online!

## Controls
* `A` - Move paddle left.
* `D` - Move paddle right.
