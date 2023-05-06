// 회전하는 큐
// 실버
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

deque<int> dq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n>>m;
	// 초기 위치
	for (int i = 1; i <= n; i++) dq.push_back(i);

	int count = 0;
	while (m--) {
		int k;
		cin >> k;
		int idx = find(dq.begin(), dq.end(), k) - dq.begin();

		while (dq.front() != k) {
			if (idx < dq.size() - idx) { // 2
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else { // 3
				dq.push_front(dq.back());
				dq.pop_back();
			}
			count++;
		}
		dq.pop_front(); // 1

	}
	cout << count;
}