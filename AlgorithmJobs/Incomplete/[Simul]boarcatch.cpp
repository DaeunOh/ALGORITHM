/*

시간제한 1초

문제
밀렵꾼은 야간에 멧돼지 포획에 나섰다. 
밀렵꾼이 있는 장소를 R*C의 격자판으로 표현할 수 있다. 
각 격자칸에 멧돼지 정보가 주어지며, 밀렵꾼은 (R+1, 0) 부터 (R+1, C)까지 1초에 한 칸씩 움직인다. 
움직일때마다 각 col 을 손전등으로 확인하고 눈 앞에 보이는 멧돼지 한 마리를 포획한다.

boar_catch1
[그림 1]

멧돼지의 정보는 총 5가지로 이루어져있다. 
멧돼지의 위치 y, x 와 멧돼지가 달리고 있는 방향 d, 달리는 속력 f, 멧돼지의 무게 w 이다. 
멧돼지는 바라보는 방향 d를 향해 초당 f 칸 만큼 이동한다. 
멧돼지가 이동한 후 같은 격자 칸에 2마리 이상의 멧돼지가 있을 경우 
가장 무게가 많이 나가는 멧돼지가 다른 멧돼지들을 먹는다. 
[그림 1]의 멧돼지들의 정보는 [그림 2]에서 각 멧돼지 아래에 멧돼지 구분자, 속력, 크기 순서대로 적혀있다. 
[그림 3]은 [그림 2]에서 1초가 지난 뒤 모습이다. 
멧돼지가 이동한 [그림 3] 모습 직후 밀렵꾼이 한 칸 이동하여 손전등을 비춰서 멧돼지를 확인한다. 
보이는 멧돼지가 없기때문에 1초 후 포획되는 멧돼지는 없다.

boar_catch2
[그림 2]boar_catch3
[그림 3]boar_catch4
[그림 4]

멧돼지의 정보가 주어졌을때, 포획된 멧돼지들의 무게 합을 구해보자. 
[그림 4] 이후 1초씩 지난 상황은 다음과 같다.

boar_catch5
[그림 5]boar_catch6
[그림 6]boar_catch7
[그림 7]boar_catch8
[그림 8]boar_catch9
[그림 9]boar_catch10
[그림 10]

포획된 멧돼지의 무게 합은 10이다.

 

입력
첫 번째 줄에 테스트 케이스의 개수 T가 주어진다. 
다음 줄부터 T개의 테스트 케이스에 대한 정보가 주어진다. 
각각의 테스트 케이스의 첫 번째 줄에 장소의 크기 R, C 와 멧돼지의 마릿수 M 이 공백을 통해 구분하여 주어진다. 
두 번째 줄부터 M 개의 줄에 걸쳐 멧돼지 정보가 공백을 통해 구분하여 주어진다. 
멧돼지의 위치 y, x 와 멧돼지가 달리고 있는 방향 d, 달리는 속력 f, 멧돼지의 무게 w 이다. 
초기 멧돼지의 위치는 서로 겹치지 않으며, 같은 무게를 가진 멧돼지는 없다. 
멧돼지가 달리고 있는 방향은 1부터 4까지의 정수이며, 숫자 순서대로 상하좌우를 의미한다. 
(3 ≤ R, C ≤ 100, 1 ≤ M ≤ R*C, 1 ≤ y ≤ R, 1 ≤ x ≤ C, 1 ≤ d ≤ 4, 0 ≤ f ≤ 1000, 1 ≤ w ≤ 10000)

 

출력
각 테스트 케이스에 대해 포획된 멧돼지의 무게 합을 출력한다. 
각 테스트 케이스의 출력 양식은 "#t r"이다. 
t는 테스트 케이스의 번호이며, 1부터 시작한다. 
r은 문제에 대한 결과값을 뜻한다.

 

예제 입력
5
5 7 6
1 6 3 3 9
2 1 4 8 3
2 4 3 7 5
3 7 1 4 1
4 3 2 10 4
4 5 4 5 2
9 3 4
2 2 1 0 6
5 2 4 15 7
8 3 4 10 1
6 1 1 16 5
8 5 4
3 5 2 4 6
2 3 4 0 2
8 5 4 8 7
2 4 4 15 9
5 9 15
1 4 1 15 94
4 7 2 4 32
5 2 3 11 85
4 4 2 18 33
2 8 4 14 87
1 7 3 14 100
4 8 1 10 63
1 6 2 0 4
1 1 2 19 95
4 3 2 17 19
5 9 1 12 17
4 9 3 0 60
3 6 2 1 23
2 7 4 0 58
1 9 4 3 53
7 9 8
4 3 2 2 1
7 8 1 5 47
3 7 2 18 61
2 6 2 19 14
1 3 1 6 93
3 2 3 13 65
5 3 4 16 69
6 8 2 11 54
예제 출력
#1 10
#2 8
#3 16
#4 498
#5 287

*/