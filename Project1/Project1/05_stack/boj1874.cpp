// 스택 수열
// 실버
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> S;
	int N;
	cin >> N;
	int cnt = 1;
	string answer;
	while (N--) {
		int n;
		cin >> n;
		while (cnt <= n) {
			S.push(cnt++);
			answer += "+\n";
		}
		if (S.top() != n) {
			cout << "NO";
			return 0;
		}
		S.pop();
		answer += "-\n";
	}
	cout << answer;
}