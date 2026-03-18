#include <bits/stdc++.h>
using namespace std;

// 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({{i,j},0});
            }
        }

        int ans = 0;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(!q.empty()){

            auto fr = q.front();
            q.pop();

            int i = fr.first.first;
            int j = fr.first.second;
            int dist = fr.second;

            for(int k=0;k<4;k++){

                int ni = i + dx[k];
                int nj = j + dy[k];

                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){

                    grid[ni][nj] = 2;
                    q.push({{ni,nj},dist+1});
                    ans = max(ans, dist+1);

                }
            }
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) return -1;

        return ans;
    }
};