// https://vjudge.net/problem/aizu-alds1_11_a
// Solved in 19.12.2025


#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

void solve() {
    int n; cin >> n;

    int graph[n + 1][n + 1] = {0};
    for(int i = 1; i <= n; i++) {
    	int u, k; cin >> u >> k;

    	for(int j = 1; j <= k; j++) {
    		int v; cin >> v;
    		graph[u][v] = 1;
    	}
    }

    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= n; j++) {
    		cout << graph[i][j];
    		if(j != n)
    			cout << " ";
    	}
    	cout << '\n';
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