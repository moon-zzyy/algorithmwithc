// Ω∫≈√ 
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> S;
	int N;
	cin >> N;
	while (N--) {
		string oper;
		cin >> oper;
		if (oper == "top") {
			int top = -1;
			if (!S.empty()) top = S.top();
			cout << top << '\n';
		}
		else if (oper == "empty") {
			cout << (int)S.empty() << '\n';
		}
		else if (oper == "size") {
			cout << S.size() << '\n';
		}
		else if (oper == "push") {
			int n;
			cin >> n;
			S.push(n);
		}
		else {// pop
			int n = -1;
			if (!S.empty()) {
				n = S.top();
				S.pop();
			}
			cout << n << '\n';
		}
	}
}