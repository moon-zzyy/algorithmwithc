// 탑
// 골드
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<int, int>> S;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	S.push({ 100000001 ,0 });
	for (int i =1; i <= N; i++) {
		int height;
		cin >> height;
		// height 보다 크거나 같은 높이가 나올 때까지
		while (height > S.top().first) 
			S.pop();
		cout << S.top().second << " ";
		S.push({ height,i });
	}
}