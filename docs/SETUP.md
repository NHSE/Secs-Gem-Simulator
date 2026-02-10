# 🛠 SETUP GUIDE

본 프로그램을 사용하기 전에 👉 [반도체 장비 시뮬레이터](https://github.com/NHSE/SemiConductor-Equipment)가 설치 및 실행되어 있어야 합니다.

---

## 🌐 Network 설정 방법

> **반도체 장비 시뮬레이터와의 통신을 위한 네트워크 설정 단계입니다.**

<p align="center">
<img width="621" height="109" alt="image" src="https://github.com/user-attachments/assets/aad22ef2-f0e0-4c42-a9ff-bb3219793019" />
</p>

1. 프로그램 상단 메뉴에서 **`Setting`** 을 클릭합니다.
2. 기본 네트워크 설정은 다음과 같습니다.
   - **IP** : `127.0.0.1`
   - **Port** : `5000`
   - **Device ID** : `10`
3. 반도체 장비 시뮬레이터와 **IP / Port / Device ID를 동일하게 설정**합니다.

📎 반도체 장비 시뮬레이터 네트워크 설정 방법은 아래 문서를 참고하세요.  
👉 [반도체 장비 시뮬레이터 IP 설정 방법](https://github.com/NHSE/SemiConductor-Equipment/blob/master/docs/Simulator_composition.md)

---

## ⏱ Time Out 설정 방법

> **SECS/GEM 통신에서 사용되는 Time Out 파라미터를 설정합니다.**

<p align="center">
<img width="622" height="399" alt="image" src="https://github.com/user-attachments/assets/d8c63208-1379-41f1-940b-606e4c2e1140" />
</p>

- 각 Time Out 항목의 의미와 설정 가능한 범위는  
  **노란색 박스 영역**에 안내되어 있습니다.
- 본 프로그램은 **Host 프로그램을 타겟**으로 개발되었으며  
  **T3, T5, T6** Time Out만 구현되어 있습니다.


---

## 🔌 반도체 장비 시뮬레이터 연결 방법

네트워크 및 Time Out 설정이 완료되었다면 메인 윈도우에서 **`Connect`** 버튼을 클릭하여 연결을 시도합니다.

연결 과정은 다음과 같습니다.

1. TCP/IP 연결 시도
2. Control Message **`Select.req`** 전송
3. 반도체 장비 시뮬레이터로부터 **`Select.res`** 수신

✔ `Select.res` 수신 시 **연결 성공**

---

## 📤 SECS/GEM 메시지 전송 방법

- SECS/GEM 메시지는 **SML 파일**을 통해 전송할 수 있습니다.
- 직접 SML 파일을 작성하려면 아래 문서를 참고하세요.

👉 [SECS/GEM SML 파일 형식](SML_FORMAT.md)

<p align="center">
<img width="468" height="400" alt="image" src="https://github.com/user-attachments/assets/ff7a5a06-6868-4585-a153-21164000ad80" />
</p>

1. **File 영역**에서 **`Open`** 클릭
2. `.sml` 파일 선택
3. 내부적으로 파일 파싱 진행
4. 전송 가능한 SECS/GEM 메시지가 상기 사진 내 
   **노란색 영역에 리스트업**

`Close 클릭 시 파일 파싱이 초기화되며 메세지 리스트가 초기화 됩니다.`

---

