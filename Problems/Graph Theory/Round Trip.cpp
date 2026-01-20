// https://cses.fi/problemset/task/1669
// Solved in 21.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

vector<int> graph[N];
vector<int> cycle_path;
int col[N], par[N], save = 0;
bool cycle = false;

void dfs(int u) {
	col[u] = 1;

	for(auto v: graph[u]) {
		if(!col[v]) {
			par[v] = u;
			dfs(v);
			if(cycle)
				return;
		}
		else if(col[v] == 1 && v != par[u]) {
			cycle = true;
			int c = u;
    		cycle_path.push_back(v);
    		while(c != v) {
    			cycle_path.push_back(c);
    			c = par[c];
    		}
    		cycle_path.push_back(v);
    		return;
		}
	}
	col[u] = 2;
}
void solve() {
    int n, m; cin >> n >> m;

    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
    	if(!col[i]) {
    		dfs(i);
    		if(cycle)
    			break;
    	}
    }

    if(cycle) {
    	cout << cycle_path.size() << '\n';
    	for(auto it: cycle_path) {
    		cout << it << " ";
		}
    }
    else {
    	cout << "IMPOSSIBLE\n";
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