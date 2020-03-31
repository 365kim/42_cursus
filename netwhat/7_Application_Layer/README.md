## Application Layer
- 응용계층은 기반이 되는 전송계층을 사용하여 호스트 간 연결을 확립함
- **DNS** *(Domain Name System)*
    - google.com(도메인 이름) ↔ 127.217.25.78(IP 주소)를 갖고있는 일종의 전화번호부
- **DHCP** *(Dynamic Host Configuration Protocl)*
    - 동적 호스트 설정 프로토콜
    - PC사용자에게 IP주소, 서브넷마스크, 게이트웨이 주소, DNS와 같은 정보를 자동으로 할당해 주고, 사용하지 않으면 반환받아 다른 컴퓨터가 사용할 수 있도록 해줌
- 참고 : [DNS의 원리](https://opentutorials.org/course/3276/20299), [DHCP의 원리](https://opentutorials.org/course/3265/20039)
<br>

### :speech_balloon: 연습문제 : DNS/DHCP 특징
#### Q. ____ translates Internet domain names and host names into IP addresses
    - Network time protocol
    - Default routing protocol
    - Domain name system
    - OSI model system


    Answer : Domain name system


#### Q. You want to implement a mechanism that automates IP configuration, including IP address, subnet mask, default gateway and DNS information. What protocol will you use to achieve this?
    - SNMP
    - DHCP
    - SMTP
    - ARP


    Answer : DHCP

#### Q. What DHCP protocol does it use at the transport layer level?
    - ICMP
    - TCP
    - FTP
    - UDP


    Answer : UDP

#### Q. What type of address is supported by DHCP?
    - IPV4
    - IPV6
    - IPV4 and IPV6
    - None of them


    Answer : IPV4 and IPV6

- Source : [adblanc/netwhat42-train](github.com/adblanc/netwhat42)
