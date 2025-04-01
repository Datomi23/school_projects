# Libft – 42 School Project

## 📚 About

Libft is my first project at 42 School. It consists of building a C library by re-implementing standard library functions (`libc`), along with additional and bonus functions. This library will serve as a foundation for many future C projects.

---

## 📦 Library Contents

### ✅ Mandatory Part

#### 🔹 Libc Functions
Re-implementation of standard functions (prefixed with `ft_`):

- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Strings: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`
- Memory: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Conversions: `ft_toupper`, `ft_tolower`, `ft_atoi`

#### 🔹 Additional Functions
Utility functions not directly available in the `libc`:

- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_itoa`, `ft_strmapi`, `ft_striteri`
- Output to file descriptors: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

---

### ⭐ Bonus (Linked List Functions)

If the mandatory part is perfectly completed, you can implement additional functions to manipulate linked lists:

```c
typedef struct s_list {
    void *content;
    struct s_list *next;
} t_list;
```

Implemented functions:

- Creation and management: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`
- Iteration and mapping: `ft_lstiter`, `ft_lstmap`
- Deletion: `ft_lstdelone`, `ft_lstclear`

---

## ⚙️ How to Use

Clone the repository and compile with:

```bash
make
```

To compile including the bonus functions:

```bash
make bonus
```

To clean object files:

```bash
make clean
make fclean
```

To recompile from scratch:

```bash
make re
```

---

## 📁 Project Structure

- `libft.h`: Header file with function declarations
- `ft_*.c`: Source files with function implementations
- `Makefile`: Includes rules (`all`, `clean`, `fclean`, `re`, `bonus`) and uses `-Wall -Wextra -Werror`

---

## 🧪 Testing

You are encouraged to write your own tests or use public testers (e.g., libft-war-machine, francinette, moulitest) to verify the correctness of the functions.

---

## 📝 Notes

- All code conforms to the [Norm](https://github.com/42School/norminette).
- Only allowed external functions are used (`malloc`, `free`, `write`, etc.).
- No global variables are declared.
- All dynamically allocated memory is properly freed.

---

## 👨‍💻 Author

- [Datomi23](https://github.com/Datomi23)

---

## 📄 License

Project created as part of the [42 School](https://42.fr/) curriculum. All rights reserved.

