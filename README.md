# 💬 minitalk

> A small client-server communication project using UNIX signals. Part of the 1337 curriculum.

## 📌 Description

The **minitalk** project consists of creating two programs: a server and a client. The client sends messages to the server using UNIX signals (`SIGUSR1` and `SIGUSR2`). The server receives the signals and reconstructs the message.

## ⚙️ Program Overview

- **Server:** Waits for signals and rebuilds the message bit by bit.
- **Client:** Sends a string to the server via signals.
- Communication is done one bit at a time using `SIGUSR1` and `SIGUSR2`.

## 📁 File Structure

```
minitalk/
├── client.c
├── server.c
├── minitalk.h
├── Makefile
└── README.md
```

## 🧪 Usage Example

1. Run the server (it will print its PID):

```bash
$ ./server
Server PID: 12345
```

2. Run the client and send a message:

```bash
$ ./client 12345 "Hello, 1337!"
```

## 🔧 Compilation

```bash
make
./server
./client <server_pid> "<message>"
```

## ✅ Features

- Sends messages using UNIX signals.
- Handles messages of arbitrary length.
- Simple and efficient communication.
- Complies with 1337 coding norms.

## 👨‍💻 Author

- GitHub: [OB4413](https://github.com/OB4413)
****
