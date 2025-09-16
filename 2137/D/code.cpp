/*

* @Author: opzc35
* @Date:   2025-09-15 17:21:12
* @Last Modified by:   HP
* @Last Modified time: 2025-09-16 14:19:24

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int T = 1;

int n;
int a[200005];
int ans[200005];
int t[200005];
int sum;
int maxv;
int top;
queue<int> q[200005];
void clear() {
	sum = 0;
	// memset(t, 0, sizeof t);
	top = 1;
	maxv = 0;
}
void work() {
	cin >> n;
	for (int i = 1 ; i <= n ; i ++) {
		cin >> a[i];
		q[a[i]].push(i);
		sum += a[i];
		maxv = max(maxv, a[i]);
	}
	for (int i = 1; i <= maxv; i ++) {
		if ( q[i].size() % i != 0) {
			cout << -1;
			for (int j = 1 ; j <= maxv ; j ++) {
				while (!q[j].empty()) {
					q[j].pop();
				}
			}
			return;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		while (!q[i].empty()) {
			for (int j = 1 ; j <= i ; j ++) {
				ans[q[i].front()] = top;
				q[i].pop();
			}
			++top;
		}
	}
	for (int i = 1 ; i <= n ; i++) {
		cout << ans[i] << " ";
	}
}

signed main() {
	cin >> T;
	while (T--) {
		clear();
		work();
		cout << "\n";
	}
}