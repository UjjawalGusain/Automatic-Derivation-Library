# Automatic Differentiation with Dual Numbers

## Overview
This project implements an automatic differentiation library using dual numbers in C++ to compute derivatives of mathematical functions. 

## Features
- Supports differentiation of various mathematical functions.

- Uses dual numbers for automatic differentiation(forward mode automatic differentiation).

## Dependencies
- C++ compiler (GCC, Clang, MSVC, etc.)

- AutoDiff.hpp (Custom header file implementing dual numbers)

- Standard C++ libraries (iostream, fstream, cmath)

## Installation
1. Clone the repository

    ```
    git clone https://github.com/UjjawalGusain/Automatic-Derivation-Library.git
    ```

    ```
    cd Automatic-Derivation-Library
    ```

2. Ensure `AutoDiff.hpp` is present in the project directory. 

## Compilation
To compile the project, use a C++ compiler:
```
g++ -o examples/main examples/main.cpp -Iinclude -std=c++17
```

## Functions available in the DualNumber class(Can be used for differentiation function):
1. Arithemtic: +, -, /, *
2. Power: pow function available
3. Trignometric: sin, cos, tan, sec, cot, csc

## Contributing
Feel free to open an issue or submit a pull request if you want to contribute improvements or additional features.


