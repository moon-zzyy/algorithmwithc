// 두 수의 합
#include <iostream>
using namespace std;

int arr[1000000];
bool check[2000000]; // 숫자 존재 여부
int answer;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, X;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> X;
	
	for (int i = 0; i < N; i++) {
		if (X-arr[i]>0 && check[X-arr[i]]) 
			answer++;
		check[arr[i]] = true; // 방문 표시
	}
	cout << answer;
	return 0;
}