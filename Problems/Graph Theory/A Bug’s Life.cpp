// https://vjudge.net/problem/spoj-buglife
// Solved in 15.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];
int col[N], bicolor;

void dfs(int u) {
	vis[u] = true;

	for(auto v: graph[u]) {
		if(!vis[v]) {
			col[v] = col[u] ^ 1;
			dfs(v);
		}
		else if(col[v] == col[u]) {
			bicolor = false;
		}
	}
}
void solve(int cs) {
	int n, m; cin >> n >> m;
	while(m--) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
						    	
	bicolor  = true;
	for(int u = 1; u <= n; u++) {
		if(!vis[u])
			dfs(u);
	}

	cout << "Scenario #" << cs << ":\n";
	if(bicolor)
		cout << "No suspicious bugs found!\n";
	else
		cout << "Suspicious bugs found!\n";

	for(int i = 1; i <= n; i++) {
		graph[i].clear();
		vis[i] = false;
		col[i] = 0;
	}
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