#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        
        int n = dist.size();
        
        // via 0, 1, 2, 3, apply brute force 
        // TC v^3
        // SC v^2
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    
                    if (dist[i][via] != 100000000 && dist[via][j] != 100000000) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};