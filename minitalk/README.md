# minitalk – 42 School Project

## 📚 About

`minitalk` is a 42 School project focused on inter-process communication using **UNIX signals**. You'll build a message delivery system between a client and a server. This project introduces basic signal handling in C and challenges your ability to manage asynchronous communication.

---

## 📦 Project Overview

### ✅ Mandatory Part

You must implement two executables:
- `server`
- `client`

#### 🔹 Server
- Must print its **PID** when started.
- Waits for messages from the client, reconstructs the string from the bits sent.
- Displays the received string quickly (e.g., not taking 1 second to print 100 characters).
- Must handle messages from **multiple clients** without restarting.

#### 🔹 Client
- Takes **2 arguments**:
  1. The server PID
  2. The string to send
- Sends the string to the server **bit by bit** using only:
  - `SIGUSR1`
  - `SIGUSR2`

---

## 🔧 Allowed Functions

- `write`, `ft_printf` (or your own equivalent)
- `signal`, `sigaction`, `sigemptyset`, `sigaddset`
- `kill`, `getpid`
- `malloc`, `free`
- `pause`, `sleep`, `usleep`
- `exit`

You are allowed **one global variable per program** (client and server), with a justification.

`libft` is allowed.

---

## ⭐ Bonus Part

The bonus is optional and will be evaluated only if the mandatory part is 100% correct.

Possible bonus features:
- The **server acknowledges** each message by sending a signal back to the client.
- Support for **Unicode characters**.

---

## ⚙️ Compilation & Execution

Your project must include a `Makefile` with the following rules:
- `all`
- `clean`
- `fclean`
- `re`
- `bonus` (if bonus is implemented)

Compilation flags:
```bash
gcc -Wall -Wextra -Werror -o server server.c
gcc -Wall -Wextra -Werror -o client client.c
```

---

## 🚀 Example Usage

In two separate terminals:

**1. Run the server:**
```bash
./server
# Output: PID: 12345
```

**2. Run the client:**
```bash
./client 12345 "Hello, World!"
```

Expected result:
The server prints:
```bash
Hello, World!
```

---

## 🔍 Testing Tips

- Try sending short and long messages
- Send multiple messages from the same client
- Try different clients sending messages simultaneously
- Ensure the server doesn’t crash or leak memory

---

## 👨‍💻 Author

- [Datomi23](https://github.com/Datomi23)

---

## 📝 License

Project developed as part of the [42 School](https://42.fr/) curriculum. All rights reserved.

