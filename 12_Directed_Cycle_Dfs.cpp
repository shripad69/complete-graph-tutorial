#include <bits/stdc++.h>
using namespace std;

// logic :-
    // jar node visited alsi and ti current path mdhe pn asli tr mg cycle ahe 



class Solution {
public:

    bool dfs(int node, vector<int>& vis, vector<int>& path, vector<vector<int>>& adj) {
        vis[node] = 1;
        path[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(nei, vis, path, adj)) return true;
            }
            else if (path[nei]) {
                return true; // cycle found
            }
        }

        path[node] = 0; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0), path(V, 0);

        // check all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj)) return true;
            }
        }

        return false;
    }
};