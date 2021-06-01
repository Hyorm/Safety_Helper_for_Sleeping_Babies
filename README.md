# Safety_Helper_for_Sleeping_Babies
17-2 OpenCV Personal Project

## 문제 선택 동기 및 접근방식 
### 1) 제목
Face detection을 이용한 아기 안전 카메라

### 2) 설명
- 갓난 아기 혹은 생후 5개월 내외의 아기들은 스스로 뒤집었거나 다른 이유로 몸이 뒤집혔을 경우 숨을 쉬지 못하는 상황이 발생할 수 있다. 
- 이때 주변에 사람이 없거나 주의가 팔려 있을 경우 아기의 응급상황 발생을 빠르게 알아 차릴 수 없으므로 프로그램이 아기가 뒤집힌 상태를 인식한 뒤 알림을 울리게 한다.

### 3) 접근 방식
- Face detection: 아이의 얼굴이 여전히 나타나는지 확인한다.
- Object tracking: 아이의 뒤척임이 있을 경우에도 아이의 얼굴을 인식한다.
- Log transform: 아이가 자고 있을 경우나 밤에는 영상이 어둡게 나타날 경우를 대비한다.

## System Flow
<p align="center"><img width="514" alt="image" src="https://user-images.githubusercontent.com/28642467/120351050-7b5acd80-c33a-11eb-82e6-003a9f1a2d34.png"></p>
<p align="center">figure 1. System Flow</p>
