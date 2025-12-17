#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
int col[N], par[N];
bool cycle;

void dfs(int u) {
	col[u] = 1;

	for(auto v: graph[u]) {
		if(col[v] == 0) {
			par[v] = u;
			dfs(v);
		}
		else if(col[v] == 1) {
			cycle = true;
			//Track the cycle path
		}
	}
	col[u] = 2;
}
void solve() {
    int n, m; cin >> n >> m;

    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    }

    cycle = false;
    for(int i = 1; i <= n; i++) {
    	if(col[i] == 0)
    		dfs(i);
    }

    cout << (cycle ? "YES\n" : "NO\n");
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