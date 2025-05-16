# 📡 minitalk

> A small message-passing project using UNIX signals. Built as part of the 1337 curriculum.

## 📌 Description

**minitalk** is a pair of programs (server & client) that communicate by sending characters bit by bit using UNIX signals (`SIGUSR1` and `SIGUSR2`). It demonstrates inter-process communication (IPC) without using sockets or pipes.

## 🧠 What I Learned

- Sending and receiving UNIX signals
- Encoding characters into binary using signals
- Writing signal handlers in C
- Asynchronous programming
- Managing signal timing and synchronization

## 🛠️ How It Works

- The server listens for signals and reconstructs characters
- The client encodes each character into binary and sends 8 signals per char
- After each char is received, the server can optionally send an acknowledgment

## 🗂️ Project Structure


## 🚀 How to Compile

```bash
make

./server
Server PID: 12345
./client 12345 "Hello from client!"
