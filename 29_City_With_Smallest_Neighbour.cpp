#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // using warshalls algo make the matrix and then just count number of cities
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector <vector <int>> adj(n, vector <int>(n, 1e5));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            adj[u][v] = weight;
            adj[v][u] = weight;
            adj[u][u] = adj[v][v] = 0;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (adj[i][via] != 1e5 && adj[via][j] != 1e5) {
                        adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                    }
                }
            }
        }

        int minCnt = n + 1, node = -1;
        for (int i = 0; i < n; i++) {
            int curr = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold) curr++;
            }
            if (curr <= minCnt) {
                minCnt = curr;
                node = i;
            }
        }

        return node;
    }
};