#include <bits/stdc++.h>
class Solution {
  public:
  
  
  
    void dfs (vector <vector <int>>& adj, vector <int>& vis, vector <int> &ans, int node) {
        if (!vis[node]) {
            vis[node] = 1;
            ans.push_back(node);
            for (auto i : adj[node]) {
                dfs(adj, vis, ans, i);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector <int> vis(n, 0);
        
        vector <int> ans;
        dfs(adj, vis, ans, 0);
        return ans;
    }
};