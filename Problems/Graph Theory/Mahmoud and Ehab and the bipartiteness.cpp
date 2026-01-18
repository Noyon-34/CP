// https://codeforces.com/problemset/problem/862/B
// Solved in 19.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];
int col[N];

void dfs(int u) {
	vis[u] = true;

	for(auto v: graph[u]) {
		if(!vis[v]) {
			col[v] = col[u] ^ 1;
			dfs(v);
		}
	}
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    dfs(1);

    ll cn1 = 0, cn2 = 0;
    for(int i = 1; i <= n; i++) {
    	if(col[i] == 1)
    		cn1++;
    	else
    		cn2++;
    }

    cout << (cn1 * cn2) - n + 1 << '\n';
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