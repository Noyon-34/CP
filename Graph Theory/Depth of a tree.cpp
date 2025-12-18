#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
int depth[N];

void dfs(int u, int par) {
	depth[u] = depth[par] + 1;
	for(auto v: graph[u]) {
		if(v != par)
			dfs(v, u);
	}
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;

    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
    	cout << depth[i] << '\n';
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