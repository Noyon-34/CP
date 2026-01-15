// https://vjudge.net/problem/uva-10004
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
void solve() {
    while(1) {
    	int n; cin >> n;
    	if(!n)
    		break;
    	int m; cin >> m;
    	while(m--) {
    		int u, v; cin >> u >> v;
    		u++, v++;
    		graph[u].push_back(v);
    		graph[v].push_back(u);
    	}
    	
    	bicolor  = true;
    	dfs(1);

    	if(bicolor)
    		cout << "BICOLORABLE.\n";
    	else
    		cout << "NOT BICOLORABLE.\n";

    	for(int i = 1; i <= n; i++) {
    		graph[i].clear();
    		vis[i] = false;
    		col[i] = 0;
    	}
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