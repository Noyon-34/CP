// https://cses.fi/problemset/task/1192
// Solved in 19.01.2026

#include<bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
using ll = long long;

int R, C;
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int r, int c) {
	vis[r][c] = 1;

	for(int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];

		if(nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc] && grid[nr][nc] == '.') {
			dfs(nr, nc);
		}
	}
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
    	string s; cin >> s;
    	grid.push_back(s);
    }

    R = grid.size();
    C = grid[0].size();
    vis.assign(R, vector<int> (C, 0));

    int ans = 0;
    for(int r = 0; r < R; r++) {
    	for(int c = 0; c < C; c++) {
    		if(!vis[r][c] && grid[r][c] == '.') {
    			ans++;
    			dfs(r, c);
    		}
    	}
    }
    cout << ans << '\n';
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