#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        
        // Step 1: Create adjacency list (undirected graph)
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Step 2: Distance array
        // Initially all nodes unreachable → mark as INT_MAX
        vector<int> dist(V, INT_MAX);
        
        // Step 3: BFS setup
        queue<int> q;
        q.push(src);
        dist[src] = 0;   // distance to itself = 0
        
        // Step 4: BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Explore neighbors
            for (auto neigh : adj[node]) {
                
                // If not visited yet (distance not assigned)
                if (dist[neigh] == INT_MAX) {
                    
                    // First time reaching → shortest path found
                    dist[neigh] = dist[node] + 1;
                    
                    q.push(neigh);
                }
            }
        }
        
        // Step 5: Replace unreachable nodes with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        
        return dist;
    }
};