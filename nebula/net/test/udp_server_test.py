#!/usr/bin/env python
import socket
address=('127.0.0.1',22345)
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.bind(address)
while 1:
    data,addr=s.recvfrom(2048)
    if not data:
        break
    print "got data from",addr
    print data
s.close()

