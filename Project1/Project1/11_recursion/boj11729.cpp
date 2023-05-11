// �ϳ��� ž �̵� ����
// �ǹ�
#include <iostream>
using namespace std;

void move(int a, int b, int n) { // ���� n���� a������ b������ �ű�� ��� ���
  if (n == 1) {
    cout << a << ' ' << b << '\n'; // ������ ���� �̵�
    return;
  }
  move(a, 6 - a - b, n - 1);
  cout << a << ' ' << b << '\n'; // n�� ���� �̵�
  move(6 - a - b, b, n - 1);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << (1 << k)-1 << '\n'; // <<: left shift
  move(1, 3, k); // k�� ������ 3���� �ű��
}