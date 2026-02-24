*This project has been created as part of the 42 curriculum by lmouta-g.*

---

## Description

**minitalk** is a UNIX inter-process communication project using signals.
The goal is to create a **server** and a **client** that communicate using only `SIGUSR1` and `SIGUSR2`.

The client sends a string to the server by encoding each character in binary.
The server reconstructs the message bit by bit and displays it.

This project introduces signal handling, process communication, and bitwise operations.

---

## Instructions

### Compilation

```bash
make
```

This generates two executables:

* `server`
* `client`

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

## Resources

- [signal(7) - Linux manual page](https://man7.org/linux/man-pages/man7/signal.7.html)
- [sigaction(2) - Linux manual page](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [kill(2) - Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html)
- [Bitwise Operators in C - GeeksforGeeks](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)
- [Libft - My personnal libft](https://github.com/lu-value/libft)