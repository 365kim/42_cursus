## Subnet mask
- 여러 조합이 나올 수 있는 IP주소의 대역을 나누기 위한 보조적 성격의 주소체계
- 표기법
    - 슬래시 뒤에 2진수 표기일 때 '1'인 비트 수를 써서 표기할 수 있음
    - 255.000.000.000 == 11111111 00000000 00000000 00000000 == /**8**
    - 255.255.000.000 == 11111111 11111110 00000000 00000000 == /**15**
    - 255.255.255.255 == 11111111 11111111 11111111 11111111 == /**32**
- 참고 : [서브넷마스크](https://namu.wiki/w/%EC%84%9C%EB%B8%8C%EB%84%B7%20%EB%A7%88%EC%8A%A4%ED%81%AC), [CIDR(클래스 없는 도메인간 라우팅 기법)](https://ko.wikipedia.org/wiki/%EC%82%AC%EC%9D%B4%EB%8D%94_(%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%82%B9))
<br>

### :speech_balloon: 연습문제 : CIDR표기
#### Q. What is the CIDR notation of the 255.255.128.0 subnet mask?
    - /8
    - /16
    - /9
    - /17


    Answer : /17
    
#### Q. What is the CIDR notation of the 255.255.192.0 subnet mask?
    - /5
    - /31
    - /18
    - /14


    Answer : /18

#### Q. What is the subnet mask of /24?
    - 255.255.255.255
    - 255.255.255.0
    - 255.0.0.0
    - 255.255.128.0
    - 255.192.0.0
    - 255.224.0.0


    Answer : 255.255.255.0

- Source : [adblanc/netwhat42-train](github.com/adblanc/netwhat42)
