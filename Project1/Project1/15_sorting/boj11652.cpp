// 카드
// 실버
// int로 하면 overflow 발생
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<long long, int> m; 
int maxCount;
long long answer, x;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    cin >> x;
    m[x] ++;
  }

  // map에서 최대개수 찾기
  for (auto x : m) {
    if (maxCount < x.second) {
      answer = x.first;
      maxCount = x.second;
    }
  }
  cout << answer;

}