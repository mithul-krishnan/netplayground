# netplayground
Tiny TCP client-server demo in C.  
Client asks, server tells if the matrix is upper, lower, or diagonal.

## Run
```bash
gcc matrix-server.c -o server -lws2_32
gcc matrix-client.c -o client -lws2_32
./server
./client
