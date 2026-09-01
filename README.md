# minitalk

<p>
  <img src="https://img.shields.io/badge/language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/output-server%20%2B%20client-4c1?style=flat-square" alt="server + client">
  <img src="https://img.shields.io/badge/flags--Wall%20--Wextra%20--Werror-4c1?style=flat-square" alt="Flags">
</p>

*This project has been created as part of the 42 curriculum by lmouta-g (dop42).*

---

## Description

**minitalk** is a UNIX inter-process communication project using signals.
The goal is to create a **server** and a **client** that communicate using only
`SIGUSR1` and `SIGUSR2`.

The client sends a string to the server by encoding each character in binary.
The server reconstructs the message bit by bit and displays it.

This project introduces signal handling, process communication, and bitwise
operations.

---

## Instructions

### Compilation

```bash
make
```

This generates two executables:

* `server`
* `client`

Useful rules:

```bash
make clean
make fclean
make re
```

### Usage

1. Start the server:

```bash
./server
```

It will display its PID.

2. Run the client with the server PID and a message:

```bash
./client <server_pid> "Your message"
```

The message will be displayed on the server side.

---

## Structure

```text
includes/minitalk.h   prototypes and structs
src/server.c          receives the bits and rebuilds the message
src/client.c          encodes the message and sends it bit by bit
utils/send.c          signal sending helper
lib/                  the libft (helpers)
```

---

## Resources

- [signal(7) - Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html)
- [sigaction(2) - Linux manual page](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill(2) - Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html)
- [Bitwise Operators in C - GeeksforGeeks](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
- [**libft**](https://github.com/dop42/libft) — this project relies on my own libft.
