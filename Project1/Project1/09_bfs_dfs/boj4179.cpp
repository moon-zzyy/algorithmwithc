// ��!
// ���
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000;
int fire[MAX][MAX]; // �� �̵��ð�
int board[MAX][MAX]; // ���� �̵��ð�
int r, c;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> fire_q;
queue<pair<int, int>> q;

void fire_BFS() {
  while (!fire_q.empty()) {
    pair<int, int> cur = fire_q.front(); fire_q.pop();
    int x = cur.first, y = cur.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (fire[nx][ny]==-1) {// ���� �ƴϰ� �湮���� ����
        fire[nx][ny] = fire[x][y] + 1;
        fire_q.push({ nx, ny });
      }
    }
  }
}

void BFS() {
  while (!q.empty()) {
    pair<int, int> cur = q.front(); q.pop();
    int x = cur.first, y = cur.second;
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      if (nx<0 || nx >= r ||  ny<0 || ny >= c) { // �̷� Ż��
        cout << board[x][y] + 1;
        return;
      }
      if (board[nx][ny] == -1 && ( fire[nx][ny]==-1 || board[x][y] + 1 < fire[nx][ny]) ) {// ���� �ƴϰ� �湮���� �ʰ� ���� �� ���ų� ���� ���� ��
          board[nx][ny] = board[x][y] + 1;
          q.push({ nx, ny });
        }
      }
    }
  cout << "IMPOSSIBLE";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  // �ʱ�ȭ
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      fire[i][j] = -1;
      board[i][j] = -1;
    }

  for (int i = 0; i < r; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < c; j++) {
      if (row[j] == '#') { // ��
        fire[i][j] = -2; board[i][j] = -2;
      }
      else if (row[j] == 'J') { // ���� ��ġ ����
        board[i][j] = 0;
        q.push({ i,j });
      }
      else if (row[j] == 'F') { // �� ��ġ ����
        fire[i][j] = 0;
        fire_q.push({ i,j });
      }
    }
  }
  fire_BFS();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      cout << fire[i][j]<<' ';
    cout << '\n';
  }
  BFS();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      cout << board[i][j] << ' ';
    cout << '\n';
  }
}