#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
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

    dfs(1);

    for(int i = 1; i <= n; i++) {
    	if(!vis[i]) {
    		cout << "Disconnected\n";
    		return;
    	}
    }
    cout << "Connected\n";
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