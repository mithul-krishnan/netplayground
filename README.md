# NetPlayground

A tiny TCP client-server demo written in C.

The client sends a matrix to the server, and the server replies whether the matrix is upper triangular, lower triangular, or diagonal.

## Tech
- C
- TCP sockets (socket, bind, listen, accept, connect)
- Linux / GCC

## How to run
Open two terminals.

Terminal 1 (server):
gcc server.c -o server
./server

Terminal 2 (client):
gcc client.c -o client
./client

## What I learned
- Creating and connecting TCP sockets in C
- Client-server communication and data exchange
