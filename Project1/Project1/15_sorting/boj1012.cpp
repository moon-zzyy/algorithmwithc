// 시리얼 번호
// 실버
#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <string>
using namespace std;

vector<string> v;
int sum(string s) {
  int result = 0;
  for (char c : s) 
    if (isdigit(c)) result += c-'0';
  return result;
}

bool cmp(string a, string b) {
  int sizeA = a.size(), sizeB = b.size();
  if (sizeA != sizeB) return sizeA < sizeB; // 길이비교
  int sumA = sum(a), sumB = sum(b);
  if (sumA != sumB) return sumA < sumB; // 숫자비교
  return a < b; // 사전순
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end(), cmp);
  for (auto s : v)
    cout << s << '\n';
}