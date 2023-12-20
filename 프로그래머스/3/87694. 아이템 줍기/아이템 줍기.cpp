#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int board[101][101] = { 0, };
	int dist[101][101] = { 0, };
	int dX[4] = { 1,0,-1,0 };
	int dY[4] = { 0,1,0,-1 };
	bool visit[102][102] = { 0, };
	queue<pair<int, int>> q;
	int maxX = 0, maxY = 0;

	for (auto rctg : rectangle) {
		maxX = max(maxX, 2 * max(rctg[0], rctg[2]));
		maxY = max(maxY, 2 * max(rctg[1], rctg[3]));

		for (int x = 2 * min(rctg[0],rctg[2]); x <= 2 * max(rctg[0],rctg[2]); x++) {
			for (int y = 2 * min(rctg[1], rctg[3]); y <= 2 * max(rctg[1], rctg[3]); y++) {
				if (board[x][y] == -1)
					continue;

				if (x == 2 * rctg[0] || x == 2 * rctg[2] || y == 2 * rctg[1] || y == 2 * rctg[3]) {
					board[x][y] = 1;
				}
				else
					board[x][y] = -1;
			}
		}
	}

	q.push(make_pair(2 * characterX, 2 * characterY));
	visit[2 * characterX][2 * characterY];

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = curX + dX[i];
			int newY = curY + dY[i];

			if (newX < 1 || newX > maxX || newY < 1 || newY > maxY)
				continue;

			if (board[newX][newY] == 1 && !visit[newX][newY]) {
				visit[newX][newY] = 1;
				dist[newX][newY] = dist[curX][curY] + 1;

				if(newX != 2 * itemX || newY != 2 * itemY)
					q.push(make_pair(newX, newY));
			}
		}
	}

	answer = dist[2 * itemX][2 * itemY] / 2;
    
    return answer;
}