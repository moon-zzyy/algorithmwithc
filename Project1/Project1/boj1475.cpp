#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int num[10];
int answer;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	for (auto c : S) {
		if (c == '6' || c == '9')
			num[6]++;
		else
			num[c - '0']++;
	}
	num[6] = (int)(num[6] + 1) / 2;

	//for (auto n : num) {
	//	cout << n << ' ';
	//}
	cout << *(max_element(num, num + 10));
	return 0;
}