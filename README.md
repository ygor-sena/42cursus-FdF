<p align="center">
    <img src="https://user-images.githubusercontent.com/102881479/215300387-7f7f63bb-9481-4261-be3d-c3694726481a.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-blue.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

## 📣 Introduction
The fifth project of 42 curriculum introduces students to the fundamentals of graphic programming with [MiniLibX](https://github.com/42Paris/minilibx-linux). This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines. FdF is short for _fil de fer_ in French which means wireframe model.

## 💭 Project diagram

Since the project in quite big, the diagram below helps to get an overview of the whole project. Each `.c` file has functions that can be global or static, which means respectively the functions in red and blue. As you can see, the core of the project corresponds to five files:

- `fdf.h`: contains all the necessary functions and helpers to be called by the program.
- `instance.c`: inicializes all variables necessary to render the map.
- `file.c`: reads a file to get its dimension and coordinates values.
- `render.c`: renders the map with minilibx once the file has been successfully read.
- `events.c`: manages user events toggled by specific keys.

![FdF_diagram](https://user-images.githubusercontent.com/102881479/215330949-aed990c5-4f30-4580-8109-5b49050e9280.jpg)

## ⚒️ How to compile and run the project

#### 1) Copy this repository to your local workstation

```html
git clone git@github.com:ygor-sena/42cursus-FdF.git
```

#### 2) Compile the project with Makefile

```html
make
```

#### 3) Choose a map from folder `maps` to be rendered by the program

```html
./fdf maps/10-2.fdf
```

You can also run `make` and a number between 1 and 21 as a shortkey to render the files in folder `maps` with valgrind to check for memory leaks. For example, the command below is equivalent to `valgrind ./fdf maps/elem2.fdf`. To see other commands with `make`, refer to `Makefile`.

```
make 11
```

## 💡 How to use the project

| Key | Command |
|:----|:----|
| <kbd>←</kbd><kbd>↑</kbd><kbd>↓</kbd><kbd>→</kbd>  |  Moves the map to left, up, down and right. |
| <kbd>Esc</kbd>  | Closes the program.  |
| <kbd>-</kbd><kbd>+</kbd>  | Zooms the maps out and in. |
| <kbd>Z</kbd><kbd>X</kbd>  | Increases and decreases map altitude. |
| <kbd>O</kbd>  |  Renders the map in orthogonal projection. |
| <kbd>I</kbd>  |  Renders the map in isometric projection. |
| <kbd>A</kbd><kbd>S</kbd>  |  Rotates the X axis of the map, i.e. roll rotation. |
| <kbd>D</kbd><kbd>F</kbd>  |  Rotates the Y axis of the map, i.e. pitch rotation. |
| <kbd>G</kbd><kbd>H</kbd> | Rotates the Z axis of the map, i.e. yaw rotation.  |
| <kbd>R</kbd>  |  Resets the map to its original state. |


## 📖 References

- General references:
    - [Introduction to isometric projection in games](https://pikuma.com/blog/isometric-projection-in-games) by [Pikuma](https://www.youtube.com/@pikuma).
    - [X Windows System Basics](https://magcius.github.io/xplain/article/index.html) by Jasper Pierre.
    - [DDA vs. Bresenham](https://www.youtube.com/watch?v=K92zQcSrc7Y&list=PL9k0QJ76ydSTPF_cOXArVyae6VflQJFOH&index=3) by Koiti Yasojima.

- About algorithms to draw a line:
    - [Bresenham's Line Drawing Algorithm](https://www.youtube.com/watch?v=RGB-wlatStc&t=2286s) by [Abdul Bari](https://www.youtube.com/@abdul_bari).
    - [How to code your first algorithm - Draw a line](https://jstutorial.medium.com/how-to-code-your-first-algorithm-draw-a-line-ca121f9a1395) by Ghost.
    - [How to calculate the height and width of an isometric rectangle/square](https://stackoverflow.com/questions/4615116/how-to-calculate-the-height-and-width-of-an-isometric-rectangle-square) by Stack Overflow.

- About color rendering:
    - [A probably terrible way to render gradients](https://dev.to/freerangepixels/a-probably-terrible-way-to-render-gradients-1p3n) by Crystal Schuller.
- About roll, pitch and yaw rotations:
    - [Roll, pitch and yaw rotations](https://de.wikipedia.org/wiki/Roll-Nick-Gier-Winkel) by Wikipedia
    - [3D point rotation algorithm](https://stackoverflow.com/questions/34050929/3d-point-rotation-algorithm) by Stack Overflow
- Other interesting 42's students FdF:
    - [ailopez's FdF](https://github.com/ailopez-o/42Barcelona-FdF) by [Aitor Audícana](https://github.com/ailopez-o).
    - [caroldaniel's FdF](https://github.com/caroldaniel/42sp-cursus-fdf) by [Carol Daniel](https://github.com/caroldaniel/).
