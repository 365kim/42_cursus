## Transport Layer
- 전송계층은 양 단의 사용자들이 신뢰성있는 데이터를 주고 받을 수 있도록 해줌
- **TCP** *(Transmission Control Protocol)*
    - 전송 제어 프로토콜, IP와 함께 TCP/IP라고도 불림
    - 일련의 옥텟을 안정적으로, 순서대로, 에러없이 교환할 수 있도록 해줌
    - 사용 : 웹브라우저에서 www 연결, 이메일전송, 파일전송 등
- **UDP** *(User Datagram Protocol)*
    - 사용자 데이터그램 프로토콜
    - 전송방식이 단순하여 순서가 바뀌거나 중복되거나 통보없이 누락되기도 함
    - 사용 : DNS, IPTV, VoIP, 온라인게임 등

    | TCP | UDP |
    |:--------|:--------|
    |양단 간 연결설정하여 양방향 데이터 전송|연결 설정하지 않고 단방향 데이터 전송|
    |(=브로드캐스팅 X)|(=브로드캐스팅 O)|
    |수신확인 O|수신확인 X|
    |정렬을 위해 순서 재조립|순서예측 불가|
<br>

### :speech_balloon: 연습문제 : TCP/UDP 특징
#### Q. Which of the following propositions is not true?
    - UDP is faster, simpler and more efficient than TCP
    - UDP only has the basic error control mechanism
    - UDP is a datagram oriented protocol
    - UDP does not support broadcasting


    Answer : UDP does not support broadcasting

#### Q. Which of the following propositions is not true?
    - TCP is a connection-oriented protocol
    - TCP does not support broadcasting
    - TCP provides extended error checking mechanisms, because it provides flow control and data acknowledgement
    - Data sequencing is a TCP feature (this means that packets arrive in order in the recipient)
    - The delivery of data to the destination cannot be guaranteed in TCP
    - TCP is reliable because it guarantees the delivery of data to the router of the destination


    Answer : The delivery of data to the destination cannot be guaranteed in TCP

#### Q. Which of the following propositions is not true?
    - UDP is faster, simpler and more efficient than TCP
    - UDP provides extended error checking mechanisms, because it provides flow control and data acknowledgement
    - UDP is a datagram oriented protocol
    - UDP supports broadcasting


    Answer : UDP provides extended error checking mechanisms, ~

#### Q. Which of the following propositions is not true?
    - TCP is a datagram oriented protocol
    - TCP does not support broadcasting
    - TCP provides extended error checking mechanisms, because it provides flow control and data acknowledgement
    - Data sequencing is a TCP feature (packets arrive in order in the recipient)
    - TCP is reliable because it guarantees the delivery of data to the router of the destination
    - TCP is comparatively slower than UDP


    Answer : TCP is a datagram oriented protocol

#### Q. Which of the following services use UDP? 1. DHCP 2. SMTP 3. FTP 4. HTTP
    - 3
    - 1
    - 2
    - All of the above


    Answer : 1


- Source : [adblanc/netwhat42-train](github.com/adblanc/netwhat42)
