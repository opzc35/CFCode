/*

* @Author: opzc35
* @Date:   2025-09-16 14:31:31
* @Last Modified by:   HP
* @Last Modified time: 2025-09-16 15:11:51

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

int T = 1;

int ans;
int n, m;

int f[100005];
bool vis[100005];
set<pair<int, int> > s;
struct line {
	int u, v;
};
vector<line> le;

int fnd(int u) {
	return f[u] == u ? u : f[u] = fnd(f[u]);
}

void clear() {

}
vector<int> primary;
void work() {
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++){
		vis[i] = 0;
	}
	for(int i = 1 ; i <= m ; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		vis[v] = 1;
	}
	int flag = 0;
	for(int i = 1 ; i <= n ; i ++){
		if(!vis[i]){
			flag = i;
		}
	}
	for(int i = 1 ; i <= n ; i ++){
		if(flag != i){
			cout<< i << " " << flag << endl;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		clear();
		work();
		// cout << "\n";
	}
}