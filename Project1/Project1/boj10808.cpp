#include <iostream>
#include <algorithm>
using namespace std;

int alpha[26];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;

	for (auto c : S) {
		//int x = count(S.begin(), S.end(), a);
		alpha[c-'a'] ++;
	}
	for (auto i : alpha) {
		cout << i << ' ';
	}
	return 0;
}