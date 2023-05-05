// ž
// ���
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
		// height ���� ũ�ų� ���� ���̰� ���� ������
		while (height > S.top().first) 
			S.pop();
		cout << S.top().second << " ";
		S.push({ height,i });
	}
}