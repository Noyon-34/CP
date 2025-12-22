// https://codeforces.com/problemset/problem/580/C
// Solved in 22.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int a[N];
vector<int> graph[N];
bool vis[N];
int ans = 0;

void dfs(int u, int cn, int m) {
	vis[u] = true;
	if(a[u] == 1) {
		cn++;
	}
	else {
		cn = 0;
	}
	if(cn > m) {
		return;
	}

	bool leaf = true;
	for(auto v: graph[u]) {
		if(!vis[v]) {
			leaf = false;
			dfs(v, cn, m);
		}
	}

	if(leaf)
		ans++;
}
void solve() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    for(int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    dfs(1, 0, m);

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}