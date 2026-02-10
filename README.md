# SECS-GEM-Host-Simulator

<p align="center">
<img width="400" height="600" alt="image" src="https://github.com/user-attachments/assets/3134dbbd-9e4d-422a-906f-192fb3519ee9" />
</p>

반도체 장비 제어를 위한 **SECS/GEM Host 시뮬레이터 프로그램**입니다.  
C++ / Qt 기반으로 HSMS 프로토콜을 직접 구현하여  
SECS-II 메시지 송수신, 타이머 관리, 메시지 파싱 기능을 제공합니다.

---

## 📑 목차
- [프로그램 설명](#-프로그램-설명)
- [목적](#-목적)
- [주요 기능](#-주요-기능)
- [HSMS 개요](#-hsms-개요)
- [다운로드](#-다운로드)
- [개발 환경](#-개발-환경)

---

## 📌 프로그램 설명

본 프로젝트는 **SECS/GEM 표준 통신 구조 학습 및 실습**을 목적으로 개발한  
SECS/GEM Host 시뮬레이터입니다.

HSMS 통신 구조를 기반으로 TCP/IP 연결, Control / Data Message 구분,  
SECS-II 메시지 파싱 및 Time Out 기능을 직접 구현하였습니다.

---

## 🎯 목적

- **SECS/GEM 표준 통신 구조 이해**
- **C++ / Qt 비동기 통신 설계 실습**
- **반도체 장비 통신 소프트웨어 직무 대비**
- **HSMS 프로토콜 기반 설계 경험 축적**

---

## ⭐ 주요 기능

- **TCP/IP 기반 HSMS 통신 구현**
- **Control Message 처리 (Select / Deselect / Linktest / Separate)**
- **Data Message 송수신 처리**
- **SECS-II 메시지 파싱**
- **SystemByte 기반 메시지 식별**
- **Timeout 처리**
- **로그 출력 및 상태 표시**

---

## 📘 HSMS 개요

**HSMS** (High-Speed SECS Message Services)는 SEMI E37 표준 기반의 프로토콜로,  
Ethernet 기반에서 반도체 장비와 Host 간 SECS 메시지를 주고받기 위한 통신 규약입니다.  
기존의 시리얼(SECS-I) 방식보다 **속도・신뢰성・다중 장비 지원** 측면에서 우수합니다.

### HSMS 메시지 구조

<p align="center">
<img width="600" height="109" alt="image" src="https://github.com/user-attachments/assets/a31537d1-e32d-45fe-a952-b600ecd52878" />
</p>

- **A 영역** : B+C 전체 길이 정보 (4byte)  
- **B 영역** : HSMS Header (10byte)  
- **C 영역** : Data Msg (SECS-II) (0~4GB)

### HSMS Header (10Bytes)
<p align="center">
<img width="1000" height="177" alt="image" src="https://github.com/user-attachments/assets/eb59b801-9c4e-4c70-8f47-84597daa0984" />
</p>

| Byte 위치 | 필드 | 설명 |
|-----------|------|------|
| 0–1       | SessionID | Device ID |
| 2         | Header Byte2 | 0 : Control Msg<br>0 이외의 값 : Stream Number<br>8개의 비트 중 가장 앞의 비트가 1일 경우 Wait bit 임을 나타냄 |
| 3         | Header Byte3 | 0 : Control Msg<br>0 이외의 값 : Function Number |
| 4         | PType | 0 : SECS-II |
| 5         | SType | 0 : Data Msg<br>0 이외의 값 : Control Msg |
| 6–9       | SystemByte | 통신 고유 ID값 |

#### Control Message

| SType | 의미 |
|-------|------|
| 1 | Select.req |
| 2 | Select.rsp |
| 3 | Deselect.req |
| 4 | Deselect.rsp |
| 5 | Linktest.req |
| 6 | Linktest.rsp |
| 7 | Reject.req |
| 9 | Separate.req |

---

## 📘 Data Msg (0~4GB)

Data Msg는 SECS-II 기반 **메시지 내용**를 정의하는 표준입니다.

<p align="center">
<img width="800" height="500" alt="image" src="https://github.com/user-attachments/assets/9f55fc81-41ae-4c85-bc26-61ebc54a0554" />
</p>

`Control Msg의 경우 해당 부분을 보내지 않고 헤더까지만 전송합니다.`

---

## 🕐 Time Out

Time Out이란 일정 시간 내 응답이 없을 경우, 시스템이 비정상 상태로 판단하도록 하는 시간 기준입니다.

| name | description | typical | value range |
|------|-------------|---------|-------------|
| T1 | Inter-character timeout<br>SECS-I 에서 데이터 문자열을 수신하는 도중 수신해야 하는 데이터가 남아있는데도 다음 데이터 문자열이 설정된 시간안에 도착하지 않았을 때 발생 | 0.5 | 0.1~10 |
| T2 | Control timeout<br>SECS-I 에서 Control Message를 보낸 후 대응하는 응답 rsp 메시지가 설정된 시간 안에 도착하지 않았을 때 발생 | 10 | 0.2~25 |
| T3 | Reply timeout<br>SECS-I, HSMS 에서 Primary Message를 전송한 다음 Reply Message를 설정된 시간안에 받지 못했을 때 발생 | 45 | 1~120 |
| T4 | Block timeout<br>SECS-I 에서 멀티 블럭 데이터를 수신하는 도중 다음 블럭 데이터가 설정된 시간 안에 도착하지 않았을 때 발생 | 30 | 1~120 |
| T5 | Connect Separation Timeout<br>HSMS 에서 소켓이 연결된 후 설정된 시간동안 selection handshaking을 진행하고 실패하면 connection을 끊고 재시도하기까지 기다리는 시간 | 10 | 1~240 |
| T6 | Control timeout<br>HSMS 에서 Control Message를 전송한 후 응답 rsp 메시지가 설정된 시간 안에 도착하지 않았을 때 발생 | 5 | 1~240 |
| T7 | Not selected timeout<br>HSMS 에서 소켓이 connect 된 후 설정된 시간 안에 select.req 메시지를 받지 못했을 때 발생 | 10 | 1~240 |
| T8 | Network Intercharacter Time<br>HSMS 에서 데이터 문자열을 수신 후 다음 데이터 문자열을 설정된 시간 안에 받지 못했을 때 발생 | 5 | 1~120 |

`해당 프로그램에서는 HSMS기반 Host 프로그램을 기준으로 개발하였기에 T3, T5, T6만 구현하였습니다`

---

## 🛠 다운로드

v1.0.0 : [다운로드](https://github.com/NHSE/Secs-Gem-Simulator/releases/tag/v1.0.0)


## 📡 SECS/GEM 프로그램 사용 방법
- [프로그램 실행 환경 설정](docs/GETTING_STARTED.md)
- [프로그램 사용 방법](docs/GETTING_STARTED.md)
- [SECS/GEM SML 파일 형식](docs/GETTING_STARTED.md)
- [프로그램 설계 방식](docs/GETTING_STARTED.md)

## 💻 개발 환경

Language : C++

Framework : Qt

OS : Windows

📬 개발자
Author : NHSE

GitHub : https://github.com/NHSE

Email : abcd2205@naver.com
