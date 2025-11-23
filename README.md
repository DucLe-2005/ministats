# ministats

A small C command-line utility that reads one or more text files containing whitespace-separated numeric values and prints basic statistics for each file: count, sum, mean, minimum, maximum, and standard deviation.

## Building

This project uses `gcc` and `make`.

```sh
make
```

The compiled binary is placed at `./ministats`.

## Usage

Provide one or more files to analyze. Each file should contain numbers separated by whitespace (spaces or newlines).

```sh
./ministats data.txt [more_files...]
```

For every file, the program prints either the computed statistics or an error if the file cannot be opened or contains no valid numeric data.

## Cleaning build artifacts

To remove the compiled binary and object files, run:

```sh
make clean
```
