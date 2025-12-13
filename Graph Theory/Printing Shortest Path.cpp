#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> g[N];
bool vis[N];
int parent[N];

void solve() {
    int n, m; cin >> n >> m;

    while(m--) {
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    queue<int> q;
    q.push(1); vis[1] = true;

    while(!q.empty()) {
    	int u = q.front();
    	q.pop();

    	for(auto v: g[u]) {
    		if(!vis[v]) {
    			q.push(v);
    			parent[v] = u;
    			vis[v] = true;
    		}
    	}
    }

    int v = 4;
    while(v != 1) {
        cout << v << ' ';
        v = parent[v];
    }

    cout << 1;
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