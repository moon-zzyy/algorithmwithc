// AC
// 골드
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

void print(deque<int>& dq) {
	cout << "[";
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i];
		if (i < dq.size() - 1)	cout << ",";
	}
	cout << "]\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		deque<int> dq;
		int n;
		string oper, str, s = "";
		cin >> oper >> n >> str;
		for (int i = 0; i < str.length(); i++) {
			if (isdigit(str[i])) {
				s += str[i];
				continue;
			}
			if (!s.empty()) {
				dq.push_back(stoi(s));
				s = "";
			}
		}

		bool isError = false, flag = false; // flag: 뒤집기 여부
		for (auto c : oper) {
			if (c == 'R') flag = !flag;
			else {
				if (!dq.empty()) {
					if (flag) dq.pop_back();
					else dq.pop_front();
				}
				else {
					isError = true;
					break;
				}
			}
		}
		if (isError) cout << "error\n";
		else {
			if (flag) reverse(dq.begin(), dq.end());
			print(dq);
		}
	}
}