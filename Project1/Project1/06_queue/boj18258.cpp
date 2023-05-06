// Å¥2
// ½Ç¹ö
#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string oper;
		cin >> oper;

		if (oper == "size") {
			cout << q.size() << '\n';
		}
		else if (oper == "empty") {
			cout << (int)q.empty() << '\n';
		}
		else if (oper == "front") {
			int front = -1;
			if (!q.empty()) front = q.front();
			cout << front << '\n';
		}
		else if (oper == "back") {
			int back = -1;
			if (!q.empty()) back = q.back();
			cout << back << '\n';
		}
		else if (oper == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		else {//pop
			int front = -1;
			if (!q.empty()) {
				front = q.front();
				q.pop();
			}
			cout << front << '\n';
		}
	}
}