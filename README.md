# Liberty CCS Pruner (pruneccs)

A tool to reduce the size of Liberty (`.lib`) files by pruning unnecessary Composite Current Source (CCS).

## Build Instructions

This project uses OpenSTA as a submodule.

**Clone:**
```bash
git clone --recursive https://github.com/vs34/pruneccs.git
cd pruneccs
```

**Build using CMake:**
```bash
mkdir build
cd build
cmake ..
make
```

The executable `pruneccs` will be created in the `build` directory.

## Usage

Run the tool by providing an input `.lib` file and an output destination.

```bash
./build/pruneccs [input_file.lib] > [output_file.lib]
```

## Testing

```bash
cd test
./regression
````
