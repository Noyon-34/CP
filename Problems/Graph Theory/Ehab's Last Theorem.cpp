// https://codeforces.com/problemset/problem/1325/F
// Solved in 27.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int n, m;
vector<int> graph[N];
int par[N], depth[N];
int require;
bool vis[N], flag = false;

void dfs(int u, int p) {
	if(flag)
		return;

	vis[u] = true;
	par[u] = p;
	depth[u] = depth[p] + 1;

	for(auto v: graph[u]) {
		if(flag)
			return;
		if(!vis[v]) {
			dfs(v, u);
		}
		else if(v != p){
			int cyc_len = depth[u] - depth[v] + 1;
			if(cyc_len >= require) {
				flag = true;
				cout << "2\n" << cyc_len << '\n';
				while(u != v)  {
					cout << u << ' ';
					u = par[u]; 
				}
				cout << v << ' ';
				return;
			}
		}
	}
}

int col[N];
void dfs2(int u) {
	vis[u] = true;

	set<int> not_color;
	for(auto v: graph[u]) {
		if(col[v]) {
			not_color.insert(col[v]);
		}
	}

	int smallest_col = 1;
	while(not_color.find(smallest_col) !=  not_color.end()) {
		smallest_col++;
	}
	col[u] = smallest_col;
	for(auto v: graph[u]) {
		if(!vis[v])
			dfs2(v);
	}
}

vector<int> nodes[N];
void solve() {
    cin >> n >> m;
    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    int k = 1;
    while(k * k < n) {
    	k++;
    }
    require = k;
    dfs(1, 0);

    if(flag)
    	return;

    memset(vis, false, sizeof vis);
    dfs2(1);
    for(int i = 1; i <= n; i++) {
    	nodes[col[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
    	if(nodes[i].size() >= require) {
    		cout << "1\n";
    		for(int j = 0; j < require; j++) {
    			cout << nodes[i][j] << " ";
    		}
    		return;
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