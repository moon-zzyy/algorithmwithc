#include <iostream>
using namespace std;

int cnt[10];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	
	int res = A * B * C;
	while (res > 0) {
		cnt[res % 10]++;
		res /= 10;
	}
	for (auto n : cnt)
		cout << n << '\n';
	
	return 0;
}