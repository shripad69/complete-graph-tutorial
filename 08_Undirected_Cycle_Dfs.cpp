#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
    
    
    bool dfs (int node, vector <int>& vis, vector <vector <int>>& adj, int parent)  {
        vis[node] = 1;
        
        for (auto i : adj[node]) {
            
            if (!vis[i]) {
                if (dfs(i, vis, adj, node)) return true;
            }
            else if (parent != i) return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector <int>vis (V, 0);
        vector <vector <int>> adj (V);
        for (int i = 0; i < edges.size(); i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, adj, -1)) return true;
            }
        }
        
        return false;
    }
};