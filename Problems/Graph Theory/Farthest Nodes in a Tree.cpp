// https://vjudge.net/problem/lightoj-1094
// Solved in 22.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 3e4 + 7;
using ll = long long;

vector<pair<int, int>> graph[N];
int depth[N];
int mx = INT_MIN, ans = INT_MIN, node;

void dfs1(int u, int par, int weight) {
	depth[u] = depth[par] + weight;
	if(mx < depth[u]) {
		mx = depth[u];
		node = u;
	}
	for(auto [v, w]: graph[u]) {
		if(v != par)
			dfs1(v, u, w);
	}
}

void dfs2(int u, int par, int weight) {
	depth[u] = depth[par] + weight;
	ans = max(ans, depth[u]);
	for(auto [v, w]: graph[u]) {
		if(v != par)
			dfs2(v, u, w);
	}
}

void solve(int cs) {
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++) {
    	int u, v, w; cin >> u >> v >> w;
    	u++, v++;
    	graph[u].push_back({v, w});
    	graph[v].push_back({u, w});
    }

    dfs1(1, 0, 0);
    dfs2(node, 0, 0);

    cout  << "Case " << cs << ": " << ans << '\n';

    for(int i = 1; i <= n; i++) {
    	graph[i].clear();
    	depth[i] = 0; 
    }
    mx = INT_MIN, ans = INT_MIN;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1,cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}