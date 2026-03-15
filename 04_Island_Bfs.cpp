#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    void bfs(vector <vector <char>>& grid, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        queue <pair <int, int>> q;
        q.push({i , j});
        grid[i][j] = '0';

        int dx[4] = {-1 , 1, 0 , 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            pair <int, int> fr = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = fr.first + dx[k];
                int nj = fr.second + dy[k];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') {
                    q.push({ni, nj});
                    grid[ni][nj] = '0';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        

        int cnt = 0, n = grid.size(), m = grid[0].size();

        for (int i = 0; i< n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};