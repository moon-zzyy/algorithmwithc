#include <iostream>
#include <list>
#include <string>
using namespace std;

// velog
list<char> L;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	cin >> S;
	for (auto c : S) L.push_back(c);
	auto iter = L.end();
	int N;
	cin >> N;
	while (N--) {
		char command;
		cin >> command;
		if (command == 'P') { // insert
			char c;
			cin >> c;
			L.insert(iter, c);
		}
		else if (command == 'B') { // delete
			if (iter != L.begin()) {
				iter = L.erase(--iter);
			}
		}
		else if (command == 'L') {
			if (iter != L.begin()) iter--;
		}
		else { // D
			if (iter != L.end()) iter++;
		}
	}
	for (auto c : L) cout << c;
	return 0;
}