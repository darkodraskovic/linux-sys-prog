# Minimal cmake C boilerplate

## Build

Create `build` and `bin` directory in the root directory. Run `build.sh` to configure build and build and execute tests and main program.

## clangd

Install [clangd](https://clangd.llvm.org/installation.html).

`compile_commands.json` will be created in `build` directory. Symlink it (or simply copy it) to the root directory. To symlink it, `cd` to the root and

```
ln -s build/compile_commands.json .
```
