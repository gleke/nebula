#!/usr/bin/env python
import socket
addr=('127.0.0.1', 50001)
s=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
while 1:
    data=raw_input()
    #print data
    if not data:
        break
    s.sendto(data,addr)
    data2,addr=s.recvfrom(2048)
    if not data2:
       break
    # print "got data2 from", addr
    print data2
s.close()
