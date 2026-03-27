// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector <int> dist(V, INT_MAX);
        dist[src] = 0;

        // relax for n - 1 times 
        for (int i = 0; i < V  - 1; i++) {

            for (auto i : edges) {
                int u = i[0];
                int v = i[1];
                int weight = i[2];

                if (dist[u] != INT_MAX) {

                    // got the shorter distance so relax the node
                    int newDist = weight + dist[u];
                    if (newDist < dist[v]) {
                        dist[v] = newDist;
                    }
                }
            }
        }

        // if now any node get relaxed then there is the negative weight cycle 
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            int weight = i[2];
            if (dist[u] != INT_MAX) {
                int newDist = weight + dist[u];
                if (newDist < dist[v]) {
                    return {-1};
                }
            }
        }
        

        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = 1e8;
            }
        }

        return dist;
    }
};
