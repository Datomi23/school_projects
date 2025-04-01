# fract'ol – 42 School Project

## 📚 About

`fract'ol` is a 42 School computer graphics project focused on rendering **fractal sets** using the **MiniLibX** graphics library. You'll explore the fascinating mathematical world of fractals by building an interactive visualization program for sets such as **Mandelbrot** and **Julia**.

---

## 📆 Objectives

- Learn to use the **MiniLibX** graphical library (window, image, events)
- Implement rendering algorithms for fractals (Mandelbrot and Julia)
- Practice event handling (keyboard, mouse)
- Apply mathematical concepts like **complex numbers** and recursion/iteration

---

## 📂 Project Overview

### ✅ Mandatory Features

#### Fractal Sets
- Implement and display:
  - **Mandelbrot set**
  - **Julia set** (accept parameters to customize it)

#### User Interaction
- **Zoom** in and out using the **mouse wheel**
- If invalid parameters are passed (or none), print usage instructions and exit
- Use multiple colors to show fractal depth (psychedelic colors encouraged!)

#### Graphic Window Management
- Display fractals in a **MiniLibX window**
- Smooth window handling (e.g., minimize, alt-tab, etc.)
- Pressing `ESC` or clicking the window's close button exits the program cleanly

#### Technical Requirements
- Forbidden: global variables
- Use only:
  - MiniLibX functions
  - Standard I/O and memory functions: `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
  - Math library functions (with `-lm` flag)
  - Your own version of `ft_printf`
- Include a **Makefile** with rules: `all`, `clean`, `fclean`, `re`, `bonus`
- `libft` is allowed

---

## ✨ Bonus Suggestions

> Bonus features are evaluated only if the mandatory part is **100% correct**.

You can earn bonus points by adding:

- Additional fractals (more than 100 types exist online!)
- **Zoom that follows the mouse position**
- **Arrow keys to move the view**
- Color range shifting / animation

---

## ⚙️ Compilation

Link with MiniLibX and the math library:
```bash
gcc -Wall -Wextra -Werror -lm -lmlx -lXext -lX11 *.c -o fractol
```
(Adjust the command depending on your OS and MLX installation)

You can also use:
```bash
make
./fractol mandelbrot
./fractol julia 0.285 0.01
```

---

## 🖥️ How to Install MiniLibX on Linux

You can install and use MiniLibX with the following steps:

```bash
# Clone the official MiniLibX repository
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux

# Compile it
make

# Optionally install dependencies
sudo apt-get install libx11-dev libxext-dev libbsd-dev
```

To compile your project with it:
```bash
gcc -Wall -Wextra -Werror -Imlx -Lmlx -lmlx -lXext -lX11 -lm *.c -o fractol
```
Make sure the folder is named `mlx` or adjust paths accordingly in your Makefile.

---

## 🧪 Usage

```bash
./fractol <type> [options]

# Examples:
./fractol mandelbrot
./fractol julia 0.285 0.01
```

If no parameters are passed or they're invalid, the program will show usage instructions and exit.

---

## 👨‍💻 Author

- [Datomi23](https://github.com/Datomi23)

---

## 📄 License

Project developed as part of the [42 School](https://42.fr/) curriculum. All rights reserved.

