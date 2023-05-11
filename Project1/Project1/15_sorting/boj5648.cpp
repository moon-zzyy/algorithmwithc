// 역원소 정렬
// 실버
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <string>
using namespace std;

vector<long long> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    v.push_back(stoll(s)); // string to long long
  }
  sort(v.begin(), v.end());
  for (auto n : v)
    cout << n << '\n';
}