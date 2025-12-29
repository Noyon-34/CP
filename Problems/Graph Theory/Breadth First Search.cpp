// https://vjudge.net/problem/aizu-alds1_11_c
// Solved in 29.12.2025

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
    	int u, k; cin >> u >> k;
    	while(k--) {
    		int v; cin >> v;
    		graph[u].push_back(v);
    	}
    }

    vector<int> dis(n + 1, -1);
    queue<int> q;
    q.push(1); vis[1] = true, dis[1] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
    
        for(auto v: graph[u]) {
        	if(!vis[v]) {
        		q.push(v);
        		dis[v] = dis[u] + 1;
        		vis[v] = true;
        	}
        }
    }

    for(int i = 1; i <= n; i++) {
    	cout << i << " " << dis[i] << '\n';
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