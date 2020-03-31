# Network/Boradcast address
- **네트워크 주소** : 하나의 네트워크를 통칭하기 위함
    - 해당 네트워크의 첫번째 IP주소
    - 계산방법 : IP주소와 서브넷마스크의 AND연산
    
- **브로드캐스트 주소** : 네트워크에 있는 클라이언트 모두에게 데이터를 보내기 위함
    - 해당 네트워크의 마지막 IP주소
    - 계산방법 : 서브넷 마스크의 '0'인 부분을 모두 1로 바꿈
    
- **참고** : [계산방법 상세](https://sambalim.tistory.com/39)
<br>

### :speech_balloon: 연습문제 : 네트워크 주소 구하기
#### Q. What is the network address of a host with an IP address of 182.161.121.118/24?
    - 180.0.0.0
    - 182.161.121.64
    - 182.161.120.0
    - 182.161.121.116
    - 0.0.0.0
    - 182.161.96.0
    - 182.160.0.0
    - 182.161.121.0


    Answer : 182.161.121.0
    Solution : (182.161.121.118) & (255.255.255.0) = 182.161.121.0
    
#### Q. What is the network address of a host with an IP address of 107.212.146.212/25?
    - 107.212.146.208
    - 107.128.0.0
    - 0.0.0.0
    - 64.0.0.0
    - 107.212.128.0
    - 107.212.146.128
    - 107.212.0.0
    - 107.208.0.0
    - 107.212.146.192


    Answer : 107.212.146.128
    Solution : (107.212.146.212) & (255.255.255.128) = 107.212.146.128
    
#### Q. What is the network address of a host with an IP address of 166.175.144.121/23?
166.128.0.0
    - 166.175.144.0
    - 166.175.144.96
    - 128.0.0.0
    - 166.174.0.0
    - 166.0.0.0
    - 166.0.0.0
    - 166.175.144.120


    Answer : 166.175.144.0
    Solution : (166.175.144.121) & (255.255.254.0) = 166.175.144.0
    
#### Q. What is the network address of a host with an IP address of 116.45.224.50/8?
    - 116.0.1.0
    - 116.0.0.0
    - 116.255.255.0
    - 116.255.255.255


    Answer : 116.0.0.0
    Solution : (116.45.224.50) & (255.0.0.0) = 116.0.0.0
    
#### Q. What is the network address of a host with an IP address of 45.195.37.187/16?
    - 45.194.37.187
    - 45.0.0.0
    - 45.194.0.0
    - 45.195.0.0


    Answer : 45.195.0.0
    Solution : (45.195.37.187) & (255.255.0.0) = 45.195.0.0
<br>

### :speech_balloon: 연습문제 : 브로드캐스트 주소 구하기
#### Q. What is the broadcast address of a host with an IP address of 51.254.122.100/24?
    - 51.254.122.0
    - 51.254.122.1
    - 51.254.122.254
    - 51.254.122.255

    Answer : 51.254.122.255
    

- Source : [adblanc/netwhat42-train](github.com/adblanc/netwhat42)
