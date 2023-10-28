# Minimal cmake C boilerplate


## Prerequisites

### CMake

```sh
sudo apt install cmake
```

### clang

#### clangd

Install [clangd](https://clangd.llvm.org/installation.html).

`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```sh
ln -s build/compile_commands.json .
```

#### clang-format

```sh
sudo apt install clang-format
```
## Build

### build.sh script

Create `build` and `bin` directory in the root directory. Run `build.sh` to configure build and build and execute tests and main program.

### vscode

#### Using the `launch.json` and `launch.task`

This project includes a configuration for launching and building C/C++ programs using Visual Studio Code. The configuration is defined in the `launch.json` file and utilizes a prelaunch task in the `launch.task` file.

1. Open this project in Visual Studio Code.

2. To run/debug specific programs within the project, set the `"program"` field in `launch.json` to the name of the directory you want to run, e.g., `"program": "${workspaceFolder}/bin/03_select"`. Additionally, update the `"args"` array entry to match the directory build, e.g., `"args": ["03_select"]`.

3. Press F5 to build and launch your C/C++ program. The `launch.json` configuration handles the build and execution process.

