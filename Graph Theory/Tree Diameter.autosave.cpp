#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
int depth[N];
int mx = INT_MIN, ans = INT_MIN, node;

void dfs1(int u, int par) {
	depth[u] = depth[par] + 1;
	if(depth[u] > mx) {
		mx = depth[u];
		node = u;
	}
	for(auto v: graph[u]) {
		if(v != par)
			dfs1(v, u);
	}
}

void dfs2(int u, int par) {
	depth[u] = depth[par] + 1;
	ans = max(ans, depth[u] - 1);
	for(auto v: graph[u]) {
		if(v != par)
			dfs2(v, u);
	}
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(node, 0);

    cout << ans << '\n';
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