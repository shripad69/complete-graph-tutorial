#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();
        vector <vector <int>> vis(n, vector <int> (m , INT_MAX));

        queue <pair <pair <int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        int ans2 = 0;
        while (!q.empty()) {

            pair < pair <int, int>, int> fr = q.front();
            q.pop();

            int dx [4] = {-1, 1, 0, 0};
            int dy [4] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int ci = fr.first.first;
                int cj = fr.first.second;
                int dist = fr.second;

                for (int k = 0; k < 4; k++) {
                    int ni = ci + dx[k];
                    int nj = cj + dy[k];

                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        vis[ni][nj] = min(dist + 1, vis[ni][nj]);
                        q.push({{ni, nj}, dist + 1});
                        ans2 = max(ans2, dist + 1);
                    }

                }

            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) return -1;
            }
        }
        return ans2;
    }
};