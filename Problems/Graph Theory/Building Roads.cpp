// https://cses.fi/problemset/task/1666
// Solved in 20.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];

void dfs(int u) {
	vis[u] = true;

	for(auto v: graph[u]) {
		if(!vis[v])
			dfs(v);
	}
}
void solve() {
    int n, m; cin >> n >> m;

    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    int ans = 0;
    vector<int> path;
    for(int i = 1; i <= n; i++) {
    	if(!vis[i]) {
    		ans++;
    		path.push_back(i);
    		dfs(i);
    	}
    }

    cout << ans - 1 << '\n';
    for(int i = 0; i < path.size() - 1; i++) {
    	cout << path[i] << " " << path[i + 1] << '\n';
    }
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