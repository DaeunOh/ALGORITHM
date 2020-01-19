#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXNM = 22;
const int MAXNUM = 210;

int T;
int N, M;
int map[MAXNM][MAXNM];
int visitedYX[MAXNM][MAXNM];
int visitedNum[MAXNUM];
int totalRoute;
int myMax;

int dy[2] = { 1, 0 };
int dx[2] = { 0, 1 };

void DFS(int y, int x, int sum) {
	if (y == N - 1 && x == M - 1) {
		if (myMax < sum) myMax = sum;
		totalRoute++;
		return;
	}
	else {
		visitedYX[y][x] = true;
		visitedNum[map[y][x]] = true;

		for (int i = 0; i<2; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];

			if (nextY < 0 || nextY > N - 1 || nextX < 0 || nextX > M - 1) continue;

			if (!visitedYX[nextY][nextX] && !visitedNum[map[nextY][nextX]]) {
				DFS(nextY, nextX, sum + map[nextY][nextX]);

				visitedYX[nextY][nextX] = false;
				visitedNum[map[nextY][nextX]] = false;
			}
		}
	}
}

int main() {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		memset(map, 0, sizeof(map));
		memset(visitedYX, 0, sizeof(visitedYX));
		memset(visitedNum, 0, sizeof(visitedNum));
		totalRoute = 0;
		myMax = -987987987;

		scanf("%d %d", &N, &M);

		for (int i = 0; i<N; i++) {
			for (int j = 0; j<M; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		DFS(0, 0, map[0][0]);

		if (totalRoute == 0) printf("#%d %d -1\n", t, totalRoute);
		else printf("#%d %d %d\n", t, totalRoute, myMax);
	}

	return 0;
}