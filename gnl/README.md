# get_next_line – 42 School Project

## 📚 About

`get_next_line` is a project at 42 School that teaches you how to read a file line by line in C. The main goal is to implement the `get_next_line` function, which returns the next line from a file descriptor each time it is called. You'll also learn about a crucial C concept: **static variables**.

---

## 📦 Project Requirements

### ✅ Mandatory Part

- Implement the following function:

```c
char *get_next_line(int fd);
```

- It must read from a file descriptor one line at a time, and return it, including the trailing `\n` (if present).
- Return `NULL` when there’s nothing more to read or on error.
- Handle reading from both files and standard input.
- Use `read()`, `malloc()` and `free()` only.
- You **cannot** use `libft`, `lseek()`, or global variables.
- Use a compile-time macro `BUFFER_SIZE` to define the read buffer.

Example compilation:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### 🔹 File Structure

- `get_next_line.c`: main logic of the function
- `get_next_line_utils.c`: helper functions
- `get_next_line.h`: header file with function prototypes and macros

---

## ⭐ Bonus Part

The bonus part is optional and evaluated only if the mandatory part is 100% correct.

Features:
- Use only **one static variable** in your implementation.
- Support **multiple file descriptors** simultaneously.
- Create separate files:
  - `get_next_line_bonus.c`
  - `get_next_line_bonus.h`
  - `get_next_line_utils_bonus.c`

---

## ⚙️ Usage

1. Compile with your desired buffer size:
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

2. Example use:
```c
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd))) {
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 🔍 Testing Tips

- Test with various `BUFFER_SIZE` values: 1, 10, 9999...
- Try files with:
  - Very long lines
  - No newline at EOF
  - Empty files
  - Standard input (`fd = 0`)

---

## 📁 Project Structure

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

---

## 📄 Makefile

Must include the following rules:
- `all`
- `clean`
- `fclean`
- `re`

Compile with `-Wall -Wextra -Werror`. No relinking allowed.

---

## 👨‍💻 Author

- [Datomi23](https://github.com/Datomi23)

---

## 📝 License

Project developed as part of the [42 School](https://42.fr/) curriculum. All rights reserved.

