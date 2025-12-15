#include <bits/stdc++.h>
using namespace std;

int main() {
    int R = 5, C = 5;
    pair<int,int> src = {0, 0}, dst = {4, 4};
    vector<string> grid;

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int,int>>q;
    dist[src.first][src.second] = 0;
    q.push(src);

    while(!q.empty()) {
        auto [r,c] = q.front(); q.pop();
        if (r == dst.first && c == dst.second) break;
        for (int i = 0; i < 8; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && grid[nr][nc] == '.' && dist[nr][nc] == -1) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    cout << "Distance: " << dist[dst.first][dst.second] << "\n";
    return 0;
}