// 하노이 탑 이동 순서
// 실버
#include <iostream>
using namespace std;

void move(int a, int b, int n) { // 원판 n개를 a번에서 b번으로 옮기는 방법 출력
  if (n == 1) {
    cout << a << ' ' << b << '\n'; // 마지막 원판 이동
    return;
  }
  move(a, 6 - a - b, n - 1);
  cout << a << ' ' << b << '\n'; // n번 원판 이동
  move(6 - a - b, b, n - 1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << (1 << k)-1 << '\n'; // <<: left shift
  move(1, 3, k); // k개 원판을 3으로 옮긴다
}