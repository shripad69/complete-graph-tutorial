#include <bits/stdc++.h>
using namespace std;

/*
    LOGIC:
    --------
    A graph is bipartite if we can color it using 2 colors (0 and 1)
    such that no two adjacent nodes have the same color.

    - If we ever find an adjacent node with same color → return false
    - Works for disconnected graphs as well
*/

class Solution {
public:

    /*
        DFS:
        -----
        node → current node
        vis  → stores color (-1 = unvisited, 0/1 = colored)
        col  → current color
    */
    bool dfs(int node, vector<int>& vis, vector<vector<int>>& graph, int col) {

        // Assign color to current node
        vis[node] = col;

        // Traverse all neighbors
        for (auto i : graph[node]) {

            // If not visited → assign opposite color
            if (vis[i] == -1) {
                if (!dfs(i, vis, graph, 1 - col))
                    return false;
            }
            // If already visited and same color → NOT bipartite
            else if (vis[i] == col) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 → unvisited
        vector<int> vis(n, -1);

        // Handle disconnected components
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, vis, graph, 0))
                    return false;
            }
        }

        return true;
    }
};