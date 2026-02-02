// https://vjudge.net/problem/uva-10305
// Solved in 03.02.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;
using ll = long long;

vector<int> graph[N], finish_time;
bool vis[N];

void dfs(int u) {
    vis[u] = true;

    for(auto v: graph[u]) {
        if(!vis[v])
            dfs(v);
    }

    finish_time.push_back(u);
}
void solve() {
    while(1) {
    	int n, m; cin >> n >> m;
    	if(n == 0)
    		break;

    	while(m--) {
    		int u, v; cin >> u >> v;
    		graph[u].push_back(v);
    	}

    	for(int i = 1; i <= n; i++) {
            if(!vis[i])
                dfs(i);
        }

        reverse(finish_time.begin(), finish_time.end());
    	for(auto it: finish_time) {
    		cout << it << " ";
    	}

    	cout << '\n';

        finish_time.clear();
    	for(int i = 1; i <= n; i++) {
    		graph[i].clear();
    		vis[i] = false;
    	}
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}