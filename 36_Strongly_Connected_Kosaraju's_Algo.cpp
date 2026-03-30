#include <bits/stdc++.h>
using namespace std;

class Solution {

  private:

    void dfs (int node, vector <int> &vis, vector <vector <int>>& adj, stack <int>& s) {
        vis[node] = 1;

        for (auto i : adj[node]) {
            if (!vis[i]) {
                dfs(i, vis, adj, s);
            }
        }

        s.push(node);
    }

    void dfs2(int node, vector <int>& vis, vector <vector <int>>& adj2) {

        vis[node] = 1;

        for (auto i : adj2[node])  {
            if (!vis[i]) {
                dfs2(i, vis, adj2);
            }
        }
    }

  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        
        vector <int> vis(V, 0);
        vector <vector <int>> adj (V);

        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
        }

        stack <int> s;
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, s);
            }
        }

        vector <vector <int>> adj2(V);
        for (int i = 0; i < adj.size(); i++) {
            vis[i] = 0;
            for (auto j : adj[i]) {
                adj2[j].push_back(i);
            }
        }
        
        int cnt = 0;

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!vis[node]) {
                cnt++;
                dfs2(node, vis, adj2);
            }
        }

        return cnt;
        
    }
};