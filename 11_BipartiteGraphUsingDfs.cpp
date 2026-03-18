#include <bits/stdc++.h>
using namespace std;



// logic -->
    // odd length chi cycle asli ke bipartite nahiye
    // mhnun side che nodes la 0, 1 as colour krt chal and mg cycle asli and same colour asla tr falsee return kra


class Solution {
public:



    bool dfs (int node, vector <int>& vis, vector <vector <int>>& graph, int col, int prev) {
        vis[node] = col;

        for (auto i : graph[node]) {

            if (vis[i] == -1) {
                if (dfs(i, vis, graph, 1 - col, node) == false) return false;
            }

            // prev node nahiy and color same ahey 
            else if (i != prev && vis[i] == col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector <int> vis(n , -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, vis, graph, 0, -1)) return false; 
            }
        }

        return true;
    }
};