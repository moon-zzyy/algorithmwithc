// 키로거
#include <iostream>
#include <list>
#include <string>
using namespace std;

// velog
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	while (N--) {
		list<char> L = {};// password
		auto cursor = L.begin();
		string S;
		cin >> S;
		for (auto c : S) {
			if (c == '<') {//move left
				if (cursor != L.begin()) cursor--;
			}
			else if (c == '>') {//move right
				if (cursor != L.end()) cursor++;
			}
			else if (c == '-') {// backspace
				if (cursor != L.begin()) {
					cursor = L.erase(--cursor);
				}
			}
			else {// 알파벳, 숫자
				L.insert(cursor, c);
			}
		}
		for (auto c : L) cout << c;
		cout << '\n';
	}

	return 0;
}