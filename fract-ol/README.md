# Fract-ol

<p align="center">
	<img src="img/fract-olm.png" alt="Fractol Badge" width="15%">
</p>

Fract-ol is a project from the 42 curriculum that focuses on exploring fractals and creating visually stunning representations of mathematical sets. The goal of this project is to deepen your understanding of algorithms, mathematics, and graphical programming using the MiniLibX library.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Credits](#credits)

## Introduction

Fract-ol allows you to generate and explore fractals such as the Mandelbrot set, Julia set, and others. By manipulating parameters, you can zoom, pan, and modify the fractals to create unique and mesmerizing visuals.

This project is an excellent opportunity to learn about:
- Complex numbers and their operations.
- Recursive algorithms.
- Graphical rendering using MiniLibX.

## Features

- Render multiple types of fractals (e.g., Mandelbrot, Julia).
- Zoom and pan functionality for detailed exploration.
- Customizable parameters for Julia fractals.
- Smooth color gradients for enhanced visuals.

## Installation

1. Clone the repository:
	```bash
	git clone https://github.com/yourusername/fract-ol.git
	cd fract-ol
	```

2. Compile the project:
	```bash
	make
	```

3. Ensure you have the MiniLibX library installed. If not, follow the instructions provided in the 42 documentation.

## Usage

Run the program with the following syntax:
```bash
./fractol <fractal_name> [parameters]
```

### Examples:
- Mandelbrot set:
  ```bash
  ./fractol mandelbrot
  ```
- Julia set with custom parameters:
  ```bash
  ./fractol julia 0.285 0.01
  ```

## Controls

- **Mouse Scroll**: Zoom in/out.
- **Arrow Keys**: Pan the view.
- **C**: Change color scheme.
- **R**: Reset view.
- **ESC**: Exit the program.

## Credits

This project was developed as part of the 42 curriculum. Special thanks to the 42 community and the creators of MiniLibX for providing the tools and resources to make this project possible.
