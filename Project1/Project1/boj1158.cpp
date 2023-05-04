#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	queue<int> Q;
	vector<int> answer;
	for (int i = 0; i < N; i++) Q.push(i+1);
	while (!Q.empty()) {
		for (int i = 0; i < K - 1; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		answer.push_back(Q.front());
		Q.pop();
	}
	cout << '<';
	for (auto n : answer) {
		cout << n;
		if (n != answer.back()) {
			cout << ", ";
		}
	}
	cout << '>';
}