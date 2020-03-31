## Host address
- 호스트 주소 : 맨 앞의 네트워크 주소(1개)와 맨 뒤의 브로드캐스트 주소(1개)을 제외한 나머지
- 참고 : [솔루션](https://www.quora.com/Whats-the-maximum-number-of-IP-addresses-that-can-be-assigned-with-a-local-subnet-mask-of-255-255-255-224)
<br>

### :speech_balloon: 연습문제 : 호스트주소 수
#### Q. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.255.128.0 subnet mask?
    - 65536
    - 65532
    - 16380
    - 32768
    - 32770
    - 65530
    - 32766
    - 16382
    - 32764


    Answer : 32766
    Solution : 2^(32 - 17) - 2 = 32768 - 2 = 32766

#### Q. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.255.255.128 subnet mask?
    - 128
    - 60
    - 126
    - 62
    - 252
    - 258
    - 124
    - 58
    - 64


    Answer : 126
    Solution : 2^(32 - 25) - 2 = 128 - 2 = 126
    
#### Q. What is the maximum number of IP addresses that can be assigned to hosts on a local subnet using the 255.224.0.0 subnet mask?
    - 4194306
    - 4194302
    - 1048578
    - 4194300
    - 2097148
    - 4194298
    - 1048574
    - 2097150
    - 1048576


    Answer : 2097150
    Solution : 2^(32 - 11) - 2 = 2097152 - 2 = 2097150
    
#### Q. You have an interface on a router with the IP address of 124.144.156.248/21. Including the router interface, how many hosts can have IP addresses on the local network connected to the router interface?
    - 1020
    - 2050
    - 2044	
    - 4090
    - 2046
    - 2048
    - 4092
    - 2042
    - 4094


    Answer : 2046
    Solution : 2^(32 - 21) - 2 = 2048 - 2 = 2046

#### Q. You have an interface on a router with the IP address of 240.19.3.205/12. Including the router interface, how many hosts can have IP addresses on the local network connected to the router interface?
    - 1048576
    - 2097154
    - 1048574
    - 524284
    - 1048578
    - 2097148
    - 1048572


    Answer : 1048574
    Solution : 2^(32 - 12) - 2 = 1048576 - 2 = 1048574
<br>

### :speech_balloon: 연습문제 : 유효한 호스트주소 범위
#### Q. Which of the following proposals is the valid host range for the subnet on which the IP address 158.167.18.156/15 resides?

    - 158.166.0.1- 158.167.255.253
    - 158.165.255.253- 158.167.255.254
    - 158.166.0.1- 158.167.255.254
    - 158.166.0.2- 158.168.0.2


    Answer : 158.166.0.1- 158.167.255.254
    Solution : (Network)158.166.0.0 (Broadcast) 158.167.255.255

#### Q. Which of the following proposals is the valid host range for the subnet on which the IP address 1.93.149.6/17 resides?

    - 1.93.127.255- 1.93.255.250
    - 1.93.128.1- 1.94.0.1
    - 1.93.128.1- 1.93.255.251
    - 1.93.128.1- 1.93.255.254
    - 1.93.128.1- 1.94.0.3


    Answer : 1.93.128.1- 1.93.255.254
    Solution : (Network)1.93.128.0 (Broadcast) 1.93.255.255
    
#### Q. Which of the following proposals is the valid host range for the subnet on which the IP address 233.249.146.36/21 resides?

    - 233.249.143.255-233.249.151.250
    - 233.249.144.4-233.249.152.0
    - 233.249.144.1-233.249.151.254
    - 233.249.144.6-233.249.152.1
    - 233.249.144.0-233.249.151.249


    Answer : 233.249.144.1-233.249.151.254
    Solution : (Network)233.249.144.0 (Broadcast) 233.249.151.255

#### Q. If the IP address 123.48.189.194/21 is assigned to an Ethernet port of a router, what host address could communicate with it?
    - 101.219.223.235
    - 75.153.38.143
    - 5.200.165.154
    - 13.28.168.153
    - 172.1.223.196
    - 43.241.96.42
    - 123.48.189.109
    - 253.99.227.186


    Answer : 123.48.189.109
    Solution : (Network)123.48.184.0 (Broadcast) 123.48.191.255
    
- Source : [adblanc/netwhat42-train](github.com/adblanc/netwhat42)
