// 토마토
// 골드
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
string board[MAX];
int visited[MAX][MAX];

void BFS(int i, int j) {
  visited[i][j] = true;
  queue<pair<int, int>> q;
  q.push({ i,j });
  char color = board[i][j]; // 같은 색만 방문 표시
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    int x = cur.first, y = cur.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; // out of bound
      if (!visited[nx][ny] && color == board[nx][ny]) {
        visited[nx][ny] = true;
        q.push({ nx,ny });
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

}