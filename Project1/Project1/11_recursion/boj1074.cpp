// Z
// 실버
#include <iostream>
using namespace std;

int answer;
void recur(int n, int r, int c) {
  if (n == 1) return;
  int half = n / 2;
  if (r < half && c < half) {// 1 사분면
    recur(half, r, c);
  }
  else if (r < half && c >= half) {// 2 사분면
    answer += half * half * 1;
    recur(half, r, c - half);
  }
  else if (r >= half && c < half) {// 3 사분면
    answer += half * half * 2;
    recur(half, r - half, c);
  }
  else {// 4 사분면
    answer += half * half * 3;
    recur(half, r - half, c - half);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, r, c;
  cin >> n >> r >> c;
  recur((1 << n), r, c);
  cout << answer;
}