// 미로
// 실버
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int board[MAX][MAX];
bool visited[MAX][MAX];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS(int i, int j) {
  visited[i][j] = true;
  queue<pair<int, int>> Q;
  Q.push({ i,j });
  while (!Q.empty()) {
    pair<int, int> cur = Q.front(); Q.pop();
    int x = cur.first;
    int y = cur.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      // 길이고 방문하지 않음
      if (board[nx][ny] == 1 && !visited[nx][ny]) {
        visited[nx][ny] = true;
        board[nx][ny] = board[x][y] + 1;
        Q.push({ nx, ny });
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  // 한줄씩 string형에 저장
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < m; j++) // int 형으로 변환
      board[i][j] = row[j] - '0';
  }

  BFS(0, 0);
  cout << board[n - 1][m - 1];
}