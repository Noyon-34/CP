// https://vjudge.net/problem/lightoj-1257
// Solved in 22.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
using ll = long long;

vector<pair<int, int>> graph[N];
ll depth1[N], depth2[N];
ll mx = INT_MIN;
int node;

void dfs1(int u, int par, int weight) {
	depth1[u] = depth1[par] + weight;
	if(mx < depth1[u]) {
		mx = depth1[u];
		node = u;
	}
	for(auto [v, w]: graph[u]) {
		if(v != par)
			dfs1(v, u, w);
	}
}

void dfs2(int u, int par, int weight) {
	depth1[u] = depth1[par] + weight;
	if(mx < depth1[u]) {
		mx = depth1[u];
		node = u;
	}
	for(auto [v, w]: graph[u]) {
		if(v != par)
			dfs2(v, u, w);
	}
}

void dfs3(int u, int par, int weight) {
	depth2[u] = depth2[par] + weight;
	for(auto [v, w]: graph[u]) {
		if(v != par)
			dfs3(v, u, w);
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
    for(int i = 1; i <= n; i++) {
    	depth1[i] = 0;  
    }
    mx = 0;
    dfs2(node, 0, 0);
    dfs3(node, 0, 0);

    cout  << "Case " << cs << ": \n";
    for(int i = 1; i <= n; i++) {
    	cout << max(depth1[i], depth2[i]) << '\n';
    }

    for(int i = 1; i <= n; i++) {
    	graph[i].clear();
    	depth1[i] = 0;
    	depth2[i] = 0;  
    }
    mx = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}