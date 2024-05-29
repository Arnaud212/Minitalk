# Minitalk

## Summary

The Minitalk project involves creating a small communication program between a client and a server using UNIX signals. The server receives and displays messages sent by the client.

## Features

- **Server:**
  - Must be launched first.
  - Displays its PID after launching.
  - Receives character strings from multiple clients in succession without needing to be restarted.
  - Quickly displays the received strings.

- **Client:**
  - Takes the server's PID and a string as arguments.
  - Transmits the string to the server using UNIX signals.

## Technical Instructions

- Communications are done exclusively using `SIGUSR1` and `SIGUSR2` signals.
- Proper error handling is required to avoid unexpected crashes.
- One global variable is allowed per program (one for the client and one for the server).
- No memory leaks are tolerated.
- Allowed functions include: `write`, `signal`, `sigaction`, `kill`, `getpid`, `malloc`, `free`, `pause`, `sleep`, `usleep`, `exit`.

## Usage

### Compilation

To compile the `client` and `server` programs, use the provided `Makefile`. Run the following command in the project directory:

```sh
make
```

### Execution

#### Start the server

Run the server to get its PID:
```sh
./server
```
The server will display something like this:
```sh
Server PID: 12345
```

#### Send a message with the client

Use the PID displayed by the server and a string to run the client:
```sh
./client 12345 "Your message here"
```
The server will display the received message.
