#!/bin/sh
rm udp_server 
gcc -o udp_server udp_server.c -lxnet
./udp_server 12000
