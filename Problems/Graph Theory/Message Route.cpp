// https://cses.fi/problemset/task/1667
// Solved in 29.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];

void solve() {
    int n, m; cin >> n >> m;
    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    vector<int> dist(n + 1, 0);
    vector<int> par(n + 1);
    queue<int> q;
    q.push(1); vis[1] = true;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
    
        for(auto v: graph[u]) {
        	if(!vis[v]) {
        		q.push(v);
        		dist[v] = dist[u] + 1;
        		par[v] = u;
        		vis[v] = true;
        	}
        }
    }

    if(!dist[n]) {
    	cout << "IMPOSSIBLE\n";
    	return;
    }

    int k = dist[n] + 1;
    vector<int> path(k + 1);
    int v = n;
    while(v != 1) {
    	path[k] = v;
    	k--;
    	v = par[v];
    }
    path[k] = 1;

    int l = dist[n] + 1;
    cout << l << '\n';
    for(int i = 1; i <= l; i++)
    	cout << path[i] << " ";
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