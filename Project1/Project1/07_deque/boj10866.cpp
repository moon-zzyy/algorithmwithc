// µ¦
// ½Ç¹ö
#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> dq;
int front, back, k;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string oper;
		cin >> oper;
		if (oper == "size") {
			cout << dq.size() << '\n';
		}
		else if (oper == "empty") {
			cout <<dq.empty() << '\n';
		}
		else if (oper == "front") {
			front = -1;
			if (!dq.empty()) front = dq.front();
			cout << front << '\n';
		}
		else if (oper == "back") {
			back = -1;
			if (!dq.empty()) back = dq.back();
			cout << back << '\n';
		}
		else if (oper == "push_front") {
			cin >> k;
			dq.push_front(k);
		}
		else if (oper == "push_back") {
			cin >> k;
			dq.push_back(k);
		}
		else if (oper == "pop_front") {
			front = -1;
			if (!dq.empty()) {
				front = dq.front();
				dq.pop_front();
			}
			cout << front << '\n';
		}
		else { //pop_back
			back = -1;
			if (!dq.empty()) {
				back = dq.back();
				dq.pop_back();
			}
			cout << back << '\n';
		}
	}
}