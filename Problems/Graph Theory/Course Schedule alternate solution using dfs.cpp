// https://cses.fi/problemset/task/1679
// Solved in 03.02.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N], finish_time;
int col[N];
bool cycle = false;

void dfs(int u) {
    col[u] = 1;

    for(auto v: graph[u]) {
        if(col[v] == 0)
            dfs(v);
        else if(col[v] == 1)
            cycle = true;
    }
    col[u] = 2;
    finish_time.push_back(u);
}
void solve() {
    int n, m; cin >> n >> m;

    while(m--) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) {
        if(col[i] == 0)
            dfs(i);
    }

    if(cycle) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    reverse(finish_time.begin(), finish_time.end());
    for(auto it: finish_time) {
        cout << it << " ";
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