// 적록색약
// 골드
#include <iostream>
#include <queue>
#include <string>
#include <regex>
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
  cin >> n;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    board[i] = row;
  }
  int count1 = 0, count2 = 0;
  // 정상
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!visited[i][j]) {
        BFS(i, j);
        count1++;
      }
  // 적록색약 G -> R 변경
  for (int i = 0; i < n; i++) {
    board[i] = regex_replace(board[i], regex("G"), "R");
    fill(visited[i], visited[i] + n, false);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!visited[i][j]) {
        BFS(i, j);
        count2++;
      }
  cout << count1 << " " << count2;
}