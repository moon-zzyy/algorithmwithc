// 수 고르기
// 골드
#include <iostream>
#include <algorithm>
using namespace std;

int answer = INT32_MAX;
int n, m;
int arr[100001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && arr[en] - arr[st] < m) 	en++;
		if (en == n) break;
		answer = min(answer, arr[en] - arr[st]);
	}
	cout << answer;

}