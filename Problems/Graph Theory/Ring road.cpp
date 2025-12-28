// https://codeforces.com/problemset/problem/24/A
// Solved in 28.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 100 + 7;
using ll = long long;

vector<pair<int, int>> graph[N];
bool vis[N];
int ans, total = 0, cn = 0;

void dfs(int u, int p) {
	vis[u] = true;
	for(auto [v, w]: graph[u]) {
		if(!vis[v]) {
			cn += w;
			dfs(v, u);
		}
        else if(v == 1 and p != 1)
            cn += w;
	}
}
void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
    	int u, v, w; cin >> u >> v >> w;
    	graph[u].push_back({v, w});
        graph[v].push_back({u, 0});

    	total += w;
    }

    dfs(1, 0);

    cout << min(cn, total - cn);
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