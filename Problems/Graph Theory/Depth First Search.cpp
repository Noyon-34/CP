// https://vjudge.net/problem/aizu-alds1_11_b
// Solved in 19.12.2025


#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N];
vector<pair<int, int>> vp(N);
int start = 1;

void dfs(int u) {
    vis[u] = true;
    vp[u].first = start;
    start++;

    for(auto v: graph[u]) {
        if(!vis[v])
            dfs(v);
    }

    vp[u].second = start;
    start++;
}
void solve() {
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
    	int u, k; cin >> u >> k;

    	for(int j = 1; j <= k; j++) {
    		int v; cin >> v;
            graph[u].push_back(v);
    	}
    }

    for(int u = 1; u <= n; u++) {
        if(!vis[u])
            dfs(u);
    }

    for(int v = 1; v <= n; v++) {
        cout << v << " " << vp[v].first << " " << vp[v].second << '\n';
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