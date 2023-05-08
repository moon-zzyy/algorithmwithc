// 토마토
// 골드
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;
int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		int x = cur.first, y = cur.second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			// 토마토가 익지 않고 방문하지 않음
			if (board[nx][ny] == 0 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				board[nx][ny] = board[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if(board[i][j]==1)	
				q.push({ i, j });
	BFS();

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {// 다 익지 못한 토마토 있음
				cout << -1;
				return 0;
			} 
			answer = max(answer, board[i][j]);
		}
	}
	cout << answer-1;
}