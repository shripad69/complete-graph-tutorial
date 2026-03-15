#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        // a vistited array to track the traversal
        int n = adj.size();
        vector <int> vis (n);
        
        vector <int> bfs;
        queue <int> q;
        q.push(0);
        vis[0] = 1;
        
        while (!q.empty()) {
            int fr = q.front();
            q.pop();
            bfs.push_back(fr);
            
            
            for (auto i : adj[fr]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        
        return bfs;
    }

};