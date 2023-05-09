// ºÒ!
// °ñµå
#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int board[500][500];
bool visited[500][500];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int BFS(int i, int j) {
  queue<pair<int, int>> Q;
  visited[i][j] = 1;
  Q.push({ i,j });
  int area = 0;
  while (!Q.empty()) {
    area++;
    pair<int, int> cur = Q.front(); Q.pop();
    for (int k = 0; k < 4; k++) {
      int nx = cur.X + dx[k];
      int ny = cur.Y + dy[k];
      if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
      if (visited[nx][ny] || board[nx][ny] == 0) continue;
      visited[nx][ny] = 1;
      Q.push({ nx, ny });
    }
  }
  return area;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

}