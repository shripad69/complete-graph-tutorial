// User function Template for C++
#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here

        int n = grid.size();
        int m = grid[0].size();

        queue < pair <pair <int, int>, int>> q;
        vector <vector <int>> vis (n, vector <int>(m , 0));

        q.push({{source.first, source.second}, 0});
        vis[source.first][source.second] = 1;
        while (!q.empty()) {

            if (q.front().first == destination) return q.front().second;

            int cx = q.front().first.first;
            int cy = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            
            int dx [4] = {-1, 1, 0, 0 };
            int dy[4] = {0, 0, -1, 1};

            for (int p = 0; p < 4; p++) {
                int nx = cx + dx[p];
                int ny = cy + dy[p];

                if (!vis[nx][ny] && nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    vis[nx][ny] = 1;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return -1;
        
    }
};
