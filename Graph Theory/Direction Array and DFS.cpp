#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

int R, C;
vector<string> grid;
vector<vector<int>> vis;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int r, int c) {
    vis[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc] && grid[nr][nc] == '1') {
            dfs(nr, nc);
        }
    }
}

int main() {
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    R = grid.size();
    C = grid[0].size();
    vis.assign(R, vector<int>(C, 0));

    int islands = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (!vis[r][c] && grid[r][c] == '1') {
                ++islands;
                dfs(r, c);
            }
        }
    }
    cout << "Number of islands: " << islands << "\n";
    return 0;
}