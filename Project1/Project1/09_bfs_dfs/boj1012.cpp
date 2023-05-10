// 유기농 배추
// 실버
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k; // 행, 열, 배추 위치 개수
int board[MAX][MAX];
int visited[MAX][MAX];

void BFS(int i, int j) {
  queue<pair<int, int>> q;
  q.push({ i,j });
  visited[i][j] = true;
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    int x = cur.first, y = cur.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // out of bound
      if (!visited[nx][ny] && board[nx][ny] == 1) {
        visited[nx][ny] = true;
        q.push({ nx,ny });
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    while (k--) {
      int x, y;
      cin >> y >> x;
      board[x][y] = 1; // 배추있음
    }
    int count = 0; // 배추흰지렁이 개수
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!visited[i][j] && board[i][j] == 1) {
          BFS(i, j);
          count++;
        }
    cout << count << '\n';
    // 초기화
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        board[i][j] = 0;
        visited[i][j] = false;
      }
    }
  }
}