/*

* @Author: opzc35
* @Date:   2025-09-15 14:41:22
* @Last Modified by:   HP
* @Last Modified time: 2025-09-15 15:10:17

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int T = 1;

int ans;
int a, b;

void clear() {
	ans = -1;
}

void work() {
	cin >> a >> b;

	if ( a % 2 == 0 && b % 2 == 1) {
		cout << "-1";
	} else if (a % 2 == 1 && b % 2 == 1) {
		cout << a*b + 1;
	} else if (a % 2 == 1 && b % 2 == 0) {
		if (b % 4 == 2) {
			cout << "-1";
		} else {
			cout << a*b / 2 + 2;
		}
	} else {
		cout << a*b / 2 + 2;
	}
}

signed main() {
	cin >> T;
	while (T--) {
		clear();
		work();
		cout << endl;
	}
}