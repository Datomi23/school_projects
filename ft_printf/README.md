# ft_printf – 42 School Project

## 📚 About

`ft_printf` is a project that challenges you to recreate the behavior of the standard C `printf()` function. This exercise will deepen your understanding of **variadic functions**, string formatting, and low-level output in C. It’s a great opportunity to write extensible and modular code.

---

## 📦 Project Requirements

### ✅ Mandatory Part

You must implement the following function:

```c
int ft_printf(const char *format, ...);
```

Requirements:
- Reproduce the behavior of the original `printf()`.
- Do not implement original `printf` buffer management.
- You must handle the following format specifiers:
  - `%c`: character
  - `%s`: string
  - `%p`: pointer (printed in hexadecimal)
  - `%d`: signed decimal integer
  - `%i`: signed decimal integer
  - `%u`: unsigned decimal integer
  - `%x`: hexadecimal (lowercase)
  - `%X`: hexadecimal (uppercase)
  - `%%`: percent sign

### 🔹 Technical Constraints
- Use only the following functions: `malloc`, `free`, `write`, and the `stdarg.h` macros: `va_start`, `va_arg`, `va_copy`, `va_end`.
- Use `ar` to create a static library `libftprintf.a`.
- No use of `libtool`.
- Your project must be norm-compliant and memory-leak free.
- `libft` is allowed.

### 📁 File Structure
- `ft_printf.c` – core implementation
- `utils/` – any helper modules or sub-functions (if organized into folders)
- `ft_printf.h` – function prototype and includes
- `Makefile` – must include at least the following rules:
  - `$(NAME)`
  - `all`
  - `clean`
  - `fclean`
  - `re`

---

## ⚙️ How to Use

1. Compile the library:
```bash
make
```

2. Link and test it in a main program:
```c
#include "ft_printf.h"

int main(void) {
    ft_printf("Hello, %s! You are %d years old.\n", "Alice", 30);
    return 0;
}
```

---

## 🧪 Testing Suggestions

- Compare output and return values with the original `printf()`
- Test all format specifiers
- Test with edge cases (NULL pointers, empty strings, INT_MIN, etc.)
- Use public testers like:
  - [PrintfTester (gclabel)](https://github.com/gclabel/printf-tester)
  - [Mazoise's 42Tester](https://github.com/Mazoise/42TESTERS-CONSTITUTION)

---

## 👨‍💻 Author

- [Datomi23](https://github.com/Datomi23)

---

## 📝 License

Project developed as part of the [42 School](https://42.fr/) curriculum. All rights reserved.

