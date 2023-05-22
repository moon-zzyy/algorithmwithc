// ºÎºÐÇÕ
// °ñµå
#include <iostream>
using namespace std;

int answer = INT32_MAX;
int n, s;
int arr[100001];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n >>s;
  for(int i=0; i<n;i++)
	cin >> arr[i];

	int st=0, en=0;
	int res=arr[0];
	while(st<=en && en<n){
		if (res>=s){
			answer = min(answer, en-st+1);
			res -= arr[st++];
			continue;
		}
		res += arr[++en];
	}
	if (answer == INT32_MAX) answer = 0;
	cout << answer;

}